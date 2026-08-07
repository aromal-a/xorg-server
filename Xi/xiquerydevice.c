/*
 * Copyright © 2009 Red Hat, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors: Peter Hutterer
 *
 */

/**
 * @file Protocol handling for the XIQueryDevice request/reply.
 *
 * Refactor note: device-class (de)serialization used to be handled by a
 * hand-maintained switch statement in SwapDeviceInfo() that had to be kept
 * in sync, by hand, with SizeDeviceClasses()/ListDeviceClasses() every time
 * a new xXI*Info class was added (button/key/valuator/scroll/touch/gesture,
 * and whatever comes next). That switch is now replaced with a small
 * dispatch table (DeviceClassSwapTable) held in static memory and looked up
 * by class type at runtime. Adding a new device class going forward means
 * adding one row to the table, not another switch arm.
 */

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif

#include "inputstr.h"
#include <X11/X.h>
#include <X11/Xatom.h>
#include <X11/extensions/XI2proto.h>
#include "xkbstr.h"
#include "xkbsrv.h"
#include "xserver-properties.h"
#include "exevents.h"
#include "xace.h"
#include "inpututils.h"

#include "exglobals.h"
#include "privates.h"

#include "xiquerydevice.h"

static Bool ShouldSkipDevice(ClientPtr client, int deviceid, DeviceIntPtr d);
static int
 ListDeviceInfo(ClientPtr client, DeviceIntPtr dev, xXIDeviceInfo * info);
static int SizeDeviceInfo(DeviceIntPtr dev);
static void SwapDeviceInfo(DeviceIntPtr dev, xXIDeviceInfo * info);

int _X_COLD
SProcXIQueryDevice(ClientPtr client)
{
    REQUEST(xXIQueryDeviceReq);
    REQUEST_SIZE_MATCH(xXIQueryDeviceReq);

    swaps(&stuff->length);
    swaps(&stuff->deviceid);

    return ProcXIQueryDevice(client);
}

/*
 * Scratch buffers for ProcXIQueryDevice(), reused across calls instead of
 * being calloc()'d and free()'d on every single request. Each buffer only
 * grows (via realloc) when a request needs more room than is currently
 * held; it is never shrunk or freed back mid-server-lifetime, so repeated
 * queries on a system with many devices don't keep re-paying allocator
 * overhead for the same size class. This mirrors the static-reply-buffer
 * pattern already used elsewhere in the server's Xi/DIX request handlers.
 *
 * These are intentionally file-scope statics, not per-client state: the X
 * server's core request dispatch for a given client is single-threaded, so
 * there's no concurrent-reentry hazard within one client's request/reply
 * cycle. If this ever needs to be reentrant (e.g. under a threaded input
 * thread model), swap these for per-client storage instead of removing the
 * pooling.
 */
static Bool *QueryDeviceSkipBuf = NULL;
static size_t QueryDeviceSkipBufSize = 0;

static char *QueryDeviceInfoBuf = NULL;
static size_t QueryDeviceInfoBufSize = 0;

/**
 * Return a reusable Bool[] scratch buffer with room for at least
 * @p num_devices entries, growing the backing allocation if needed.
 * On growth failure the previously-held (smaller) buffer is left intact
 * for future reuse, and NULL is returned for this call only.
 */
static Bool *
GetQueryDeviceSkipBuf(unsigned num_devices)
{
    size_t needed = sizeof(Bool) * num_devices;

    if (needed > QueryDeviceSkipBufSize) {
        Bool *grown = realloc(QueryDeviceSkipBuf, needed);
        if (!grown)
            return NULL;
        QueryDeviceSkipBuf = grown;
        QueryDeviceSkipBufSize = needed;
    }

    memset(QueryDeviceSkipBuf, 0, needed);
    return QueryDeviceSkipBuf;
}

/**
 * Return a reusable byte-buffer scratch area with room for at least
 * @p len bytes, growing the backing allocation if needed. On growth
 * failure the previously-held (smaller) buffer is left intact for future
 * reuse, and NULL is returned for this call only.
 */
static char *
GetQueryDeviceInfoBuf(size_t len)
{
    if (len > QueryDeviceInfoBufSize) {
        char *grown = realloc(QueryDeviceInfoBuf, len);
        if (!grown)
            return NULL;
        QueryDeviceInfoBuf = grown;
        QueryDeviceInfoBufSize = len;
    }

    /* Zero exactly the region this reply will use, even though only `len`
     * bytes are ever written back to the client below - this keeps no
     * previous request's leftover class data resident in the part of the
     * buffer this reply doesn't overwrite. */
    memset(QueryDeviceInfoBuf, 0, len);
    return QueryDeviceInfoBuf;
}

int
ProcXIQueryDevice(ClientPtr client)
{
    xXIQueryDeviceReply rep;
    DeviceIntPtr dev = NULL;
    int rc = Success;
    int i = 0, len = 0;
    char *info, *ptr;
    Bool *skip = NULL;

    REQUEST(xXIQueryDeviceReq);
    REQUEST_SIZE_MATCH(xXIQueryDeviceReq);

    if (stuff->deviceid != XIAllDevices &&
        stuff->deviceid != XIAllMasterDevices) {
        rc = dixLookupDevice(&dev, stuff->deviceid, client, DixGetAttrAccess);
        if (rc != Success) {
            client->errorValue = stuff->deviceid;
            return rc;
        }
        len += SizeDeviceInfo(dev);
    }
    else {
        skip = GetQueryDeviceSkipBuf(inputInfo.numDevices);
        if (!skip)
            return BadAlloc;

        for (dev = inputInfo.devices; dev; dev = dev->next, i++) {
            skip[i] = ShouldSkipDevice(client, stuff->deviceid, dev);
            if (!skip[i])
                len += SizeDeviceInfo(dev);
        }

        for (dev = inputInfo.off_devices; dev; dev = dev->next, i++) {
            skip[i] = ShouldSkipDevice(client, stuff->deviceid, dev);
            if (!skip[i])
                len += SizeDeviceInfo(dev);
        }
    }

    info = GetQueryDeviceInfoBuf(len);
    if (!info)
        return BadAlloc;

    rep = (xXIQueryDeviceReply) {
        .repType = X_Reply,
        .RepType = X_XIQueryDevice,
        .sequenceNumber = client->sequence,
        .length = len / 4,
        .num_devices = 0
    };

    ptr = info;
    if (dev) {
        len = ListDeviceInfo(client, dev, (xXIDeviceInfo *) info);
        if (client->swapped)
            SwapDeviceInfo(dev, (xXIDeviceInfo *) info);
        info += len;
        rep.num_devices = 1;
    }
    else {
        i = 0;
        for (dev = inputInfo.devices; dev; dev = dev->next, i++) {
            if (!skip[i]) {
                len = ListDeviceInfo(client, dev, (xXIDeviceInfo *) info);
                if (client->swapped)
                    SwapDeviceInfo(dev, (xXIDeviceInfo *) info);
                info += len;
                rep.num_devices++;
            }
        }

        for (dev = inputInfo.off_devices; dev; dev = dev->next, i++) {
            if (!skip[i]) {
                len = ListDeviceInfo(client, dev, (xXIDeviceInfo *) info);
                if (client->swapped)
                    SwapDeviceInfo(dev, (xXIDeviceInfo *) info);
                info += len;
                rep.num_devices++;
            }
        }
    }

    len = rep.length * 4;
    WriteReplyToClient(client, sizeof(xXIQueryDeviceReply), &rep);
    WriteToClient(client, len, ptr);
    /* ptr (QueryDeviceInfoBuf) and skip (QueryDeviceSkipBuf) are pooled
     * scratch buffers - intentionally not freed here, see their
     * declarations above. */
    return rc;
}

void
SRepXIQueryDevice(ClientPtr client, int size, xXIQueryDeviceReply * rep)
{
    swaps(&rep->sequenceNumber);
    swapl(&rep->length);
    swaps(&rep->num_devices);

    /* Device info is already swapped, see ProcXIQueryDevice */

    WriteToClient(client, size, rep);
}

/**
 * @return Whether the device should be included in the returned list.
 */
static Bool
ShouldSkipDevice(ClientPtr client, int deviceid, DeviceIntPtr dev)
{
    /* if all devices are not being queried, only master devices are */
    if (deviceid == XIAllDevices || IsMaster(dev)) {
        int rc = XaceHook(XACE_DEVICE_ACCESS, client, dev, DixGetAttrAccess);

        if (rc == Success)
            return FALSE;
    }
    return TRUE;
}

/**
 * @return The number of bytes needed to store this device's xXIDeviceInfo
 * (and its classes).
 */
static int
SizeDeviceInfo(DeviceIntPtr dev)
{
    int len = sizeof(xXIDeviceInfo);

    /* 4-padded name */
    len += pad_to_int32(strlen(dev->name));

    return len + SizeDeviceClasses(dev);

}

/*
 * @return The number of bytes needed to store this device's classes.
 */
int
SizeDeviceClasses(DeviceIntPtr dev)
{
    int len = 0;

    if (dev->button) {
        len += sizeof(xXIButtonInfo);
        len += dev->button->numButtons * sizeof(Atom);
        len += pad_to_int32(bits_to_bytes(dev->button->numButtons));
    }

    if (dev->key) {
        XkbDescPtr xkb = dev->key->xkbInfo->desc;

        len += sizeof(xXIKeyInfo);
        len += (xkb->max_key_code - xkb->min_key_code + 1) * sizeof(uint32_t);
    }

    if (dev->valuator) {
        int i;

        len += (sizeof(xXIValuatorInfo)) * dev->valuator->numAxes;

        for (i = 0; i < dev->valuator->numAxes; i++) {
            if (dev->valuator->axes[i].scroll.type != SCROLL_TYPE_NONE)
                len += sizeof(xXIScrollInfo);
        }
    }

    if (dev->touch)
        len += sizeof(xXITouchInfo);

    if (dev->gesture)
        len += sizeof(xXIGestureInfo);

    return len;
}

/**
 * Get pointers to button information areas holding button mask and labels.
 */
static void
ButtonInfoData(xXIButtonInfo *info, int *mask_words, unsigned char **mask,
               Atom **atoms)
{
    *mask_words = bytes_to_int32(bits_to_bytes(info->num_buttons));
    *mask = (unsigned char*) &info[1];
    *atoms = (Atom*) ((*mask) + (*mask_words) * 4);
}

/**
 * Write button information into info.
 * @return Number of bytes written into info.
 */
int
ListButtonInfo(DeviceIntPtr dev, xXIButtonInfo * info, Bool reportState)
{
    unsigned char *bits;
    Atom *labels;
    int mask_len;
    int i;

    if (!dev || !dev->button)
        return 0;

    info->type = ButtonClass;
    info->num_buttons = dev->button->numButtons;
    ButtonInfoData(info, &mask_len, &bits, &labels);
    info->length = bytes_to_int32(sizeof(xXIButtonInfo)) +
        info->num_buttons + mask_len;
    info->sourceid = dev->button->sourceid;

    memset(bits, 0, mask_len * 4);

    if (reportState)
        for (i = 0; i < dev->button->numButtons; i++)
            if (BitIsOn(dev->button->down, i))
                SetBit(bits, i);

    memcpy(labels, dev->button->labels, dev->button->numButtons * sizeof(Atom));

    return info->length * 4;
}

/*
 * NOTE ON SIGNATURES BELOW
 * ------------------------
 * Each Swap*Info() function now takes a (DeviceIntPtr, void *) pair so that
 * they all share one function-pointer type (DeviceClassSwapFunc) and can
 * live in the same dispatch table below, instead of requiring a switch arm
 * per xXI*Info type in SwapDeviceInfo(). The cast to the concrete struct
 * type happens once, at the top of each function, exactly as it previously
 * happened once at each switch-case call site.
 */
typedef void (*DeviceClassSwapFunc)(DeviceIntPtr dev, void *info);

static void
SwapButtonInfo(DeviceIntPtr dev, void *data)
{
    xXIButtonInfo *info = data;
    Atom *btn;
    int mask_len;
    unsigned char *mask;
    int i;

    ButtonInfoData(info, &mask_len, &mask, &btn);

    swaps(&info->type);
    swaps(&info->length);
    swaps(&info->sourceid);

    for (i = 0 ; i < info->num_buttons; i++, btn++)
        swapl(btn);

    swaps(&info->num_buttons);
}

/**
 * Write key information into info.
 * @return Number of bytes written into info.
 */
int
ListKeyInfo(DeviceIntPtr dev, xXIKeyInfo * info)
{
    int i;
    XkbDescPtr xkb = dev->key->xkbInfo->desc;
    uint32_t *kc;

    info->type = KeyClass;
    info->num_keycodes = xkb->max_key_code - xkb->min_key_code + 1;
    info->length = sizeof(xXIKeyInfo) / 4 + info->num_keycodes;
    info->sourceid = dev->key->sourceid;

    kc = (uint32_t *) &info[1];
    for (i = xkb->min_key_code; i <= xkb->max_key_code; i++, kc++)
        *kc = i;

    return info->length * 4;
}

static void
SwapKeyInfo(DeviceIntPtr dev, void *data)
{
    xXIKeyInfo *info = data;
    uint32_t *key;
    int i;

    swaps(&info->type);
    swaps(&info->length);
    swaps(&info->sourceid);

    for (i = 0, key = (uint32_t *) &info[1]; i < info->num_keycodes;
         i++, key++)
        swapl(key);

    swaps(&info->num_keycodes);
}

/**
 * List axis information for the given axis.
 *
 * @return The number of bytes written into info.
 */
int
ListValuatorInfo(DeviceIntPtr dev, xXIValuatorInfo * info, int axisnumber,
                 Bool reportState)
{
    ValuatorClassPtr v = dev->valuator;

    info->type = ValuatorClass;
    info->length = sizeof(xXIValuatorInfo) / 4;
    info->label = v->axes[axisnumber].label;
    info->min.integral = v->axes[axisnumber].min_value;
    info->min.frac = 0;
    info->max.integral = v->axes[axisnumber].max_value;
    info->max.frac = 0;
    info->value = double_to_fp3232(v->axisVal[axisnumber]);
    info->resolution = v->axes[axisnumber].resolution;
    info->number = axisnumber;
    info->mode = valuator_get_mode(dev, axisnumber);
    info->sourceid = v->sourceid;

    if (!reportState)
        info->value = info->min;

    return info->length * 4;
}

static void
SwapValuatorInfo(DeviceIntPtr dev, void *data)
{
    xXIValuatorInfo *info = data;

    swaps(&info->type);
    swaps(&info->length);
    swapl(&info->label);
    swapl(&info->min.integral);
    swapl(&info->min.frac);
    swapl(&info->max.integral);
    swapl(&info->max.frac);
    swapl(&info->value.integral);
    swapl(&info->value.frac);
    swapl(&info->resolution);
    swaps(&info->number);
    swaps(&info->sourceid);
}

int
ListScrollInfo(DeviceIntPtr dev, xXIScrollInfo * info, int axisnumber)
{
    ValuatorClassPtr v = dev->valuator;
    AxisInfoPtr axis = &v->axes[axisnumber];

    if (axis->scroll.type == SCROLL_TYPE_NONE)
        return 0;

    info->type = XIScrollClass;
    info->length = sizeof(xXIScrollInfo) / 4;
    info->number = axisnumber;
    switch (axis->scroll.type) {
    case SCROLL_TYPE_VERTICAL:
        info->scroll_type = XIScrollTypeVertical;
        break;
    case SCROLL_TYPE_HORIZONTAL:
        info->scroll_type = XIScrollTypeHorizontal;
        break;
    default:
        ErrorF("[Xi] Unknown scroll type %d. This is a bug.\n",
               axis->scroll.type);
        break;
    }
    info->increment = double_to_fp3232(axis->scroll.increment);
    info->sourceid = v->sourceid;

    info->flags = 0;

    if (axis->scroll.flags & SCROLL_FLAG_DONT_EMULATE)
        info->flags |= XIScrollFlagNoEmulation;
    if (axis->scroll.flags & SCROLL_FLAG_PREFERRED)
        info->flags |= XIScrollFlagPreferred;

    return info->length * 4;
}

static void
SwapScrollInfo(DeviceIntPtr dev, void *data)
{
    xXIScrollInfo *info = data;

    swaps(&info->type);
    swaps(&info->length);
    swaps(&info->number);
    swaps(&info->sourceid);
    swaps(&info->scroll_type);
    swapl(&info->increment.integral);
    swapl(&info->increment.frac);
}

/**
 * List multitouch information
 *
 * @return The number of bytes written into info.
 */
int
ListTouchInfo(DeviceIntPtr dev, xXITouchInfo * touch)
{
    touch->type = XITouchClass;
    touch->length = sizeof(xXITouchInfo) >> 2;
    touch->sourceid = dev->touch->sourceid;
    touch->mode = dev->touch->mode;
    touch->num_touches = dev->touch->num_touches;

    return touch->length << 2;
}

static void
SwapTouchInfo(DeviceIntPtr dev, void *data)
{
    xXITouchInfo *touch = data;

    swaps(&touch->type);
    swaps(&touch->length);
    swaps(&touch->sourceid);
}

static Bool ShouldListGestureInfo(ClientPtr client)
{
    /* libxcb 14.1 and older are not forwards-compatible with new device classes as it does not
     * properly ignore unknown device classes. Since breaking libxcb would break quite a lot of
     * applications, we instead report Gesture device class only if the client advertised support
     * for XI 2.4. Clients may still not work in cases when a client advertises XI 2.4 support
     * and then a completely separate module within the client uses broken libxcb to call
     * XIQueryDevice.
     */
    XIClientPtr pXIClient = dixLookupPrivate(&client->devPrivates, XIClientPrivateKey);
    if (pXIClient->major_version) {
        return version_compare(pXIClient->major_version, pXIClient->minor_version, 2, 4) >= 0;
    }
    return FALSE;
}

/**
 * List gesture information
 *
 * @return The number of bytes written into info.
 */
static int
ListGestureInfo(DeviceIntPtr dev, xXIGestureInfo * gesture)
{
    gesture->type = XIGestureClass;
    gesture->length = sizeof(xXIGestureInfo) >> 2;
    gesture->sourceid = dev->gesture->sourceid;
    gesture->num_touches = dev->gesture->max_touches;

    return gesture->length << 2;
}

static void
SwapGestureInfo(DeviceIntPtr dev, void *data)
{
    xXIGestureInfo *gesture = data;

    swaps(&gesture->type);
    swaps(&gesture->length);
    swaps(&gesture->sourceid);
}

/*
 * Dispatch table: one row per xXI*Info class type. This is the single
 * place that needs to change when a new device class is introduced -
 * SwapDeviceInfo() itself never needs another line of code.
 *
 * The table is kept private to this file and searched linearly; the list
 * is short (currently six entries) and this runs once per class instance
 * per query, so a linear scan over static memory is simpler than sorting
 * it for a binary search and just as fast in practice. If the table grows
 * significantly, swap the lookup for an array indexed by type (types here
 * are small, contiguous-ish integers) without touching any call sites.
 */
static const struct DeviceClassSwapEntry {
    uint16_t type;
    DeviceClassSwapFunc swap;
} DeviceClassSwapTable[] = {
    { XIButtonClass,   SwapButtonInfo },
    { XIKeyClass,      SwapKeyInfo },
    { XIValuatorClass, SwapValuatorInfo },
    { XIScrollClass,   SwapScrollInfo },
    { XITouchClass,    SwapTouchInfo },
    { XIGestureClass,  SwapGestureInfo },
};

#define NUM_DEVICE_CLASS_SWAP_ENTRIES \
    (sizeof(DeviceClassSwapTable) / sizeof(DeviceClassSwapTable[0]))

/**
 * Look up the swap function registered for a given xXI*Info class type.
 *
 * @return The matching swap function, or NULL if the type is unknown (an
 * unrecognized/unhandled class is silently left un-swapped, matching the
 * previous switch statement's implicit default-case behavior).
 */
static DeviceClassSwapFunc
GetDeviceClassSwapFunc(uint16_t type)
{
    unsigned i;

    for (i = 0; i < NUM_DEVICE_CLASS_SWAP_ENTRIES; i++)
        if (DeviceClassSwapTable[i].type == type)
            return DeviceClassSwapTable[i].swap;

    return NULL;
}

int
GetDeviceUse(DeviceIntPtr dev, uint16_t * attachment)
{
    DeviceIntPtr master = GetMaster(dev, MASTER_ATTACHED);
    int use;

    if (IsMaster(dev)) {
        DeviceIntPtr paired = GetPairedDevice(dev);

        use = IsPointerDevice(dev) ? XIMasterPointer : XIMasterKeyboard;
        *attachment = (paired ? paired->id : 0);
    }
    else if (!IsFloating(dev)) {
        use = IsPointerDevice(master) ? XISlavePointer : XISlaveKeyboard;
        *attachment = master->id;
    }
    else
        use = XIFloatingSlave;

    return use;
}

/**
 * Write the info for device dev into the buffer pointed to by info.
 *
 * @return The number of bytes used.
 */
static int
ListDeviceInfo(ClientPtr client, DeviceIntPtr dev, xXIDeviceInfo * info)
{
    char *any = (char *) &info[1];
    int len = 0, total_len = 0;

    info->deviceid = dev->id;
    info->use = GetDeviceUse(dev, &info->attachment);
    info->num_classes = 0;
    info->name_len = strlen(dev->name);
    info->enabled = dev->enabled;
    total_len = sizeof(xXIDeviceInfo);

    len = pad_to_int32(info->name_len);
    memset(any, 0, len);
    strncpy(any, dev->name, info->name_len);
    any += len;
    total_len += len;

    total_len += ListDeviceClasses(client, dev, any, &info->num_classes);
    return total_len;
}

/**
 * Write the class info of the device into the memory pointed to by any, set
 * nclasses to the number of classes in total and return the number of bytes
 * written.
 */
int
ListDeviceClasses(ClientPtr client, DeviceIntPtr dev,
                  char *any, uint16_t * nclasses)
{
    int total_len = 0;
    int len;
    int i;
    int rc;

    /* Check if the current device state should be suppressed */
    rc = XaceHook(XACE_DEVICE_ACCESS, client, dev, DixReadAccess);

    if (dev->button) {
        (*nclasses)++;
        len = ListButtonInfo(dev, (xXIButtonInfo *) any, rc == Success);
        any += len;
        total_len += len;
    }

    if (dev->key) {
        (*nclasses)++;
        len = ListKeyInfo(dev, (xXIKeyInfo *) any);
        any += len;
        total_len += len;
    }

    for (i = 0; dev->valuator && i < dev->valuator->numAxes; i++) {
        (*nclasses)++;
        len = ListValuatorInfo(dev, (xXIValuatorInfo *) any, i, rc == Success);
        any += len;
        total_len += len;
    }

    for (i = 0; dev->valuator && i < dev->valuator->numAxes; i++) {
        len = ListScrollInfo(dev, (xXIScrollInfo *) any, i);
        if (len)
            (*nclasses)++;
        any += len;
        total_len += len;
    }

    if (dev->touch) {
        (*nclasses)++;
        len = ListTouchInfo(dev, (xXITouchInfo *) any);
        any += len;
        total_len += len;
    }

    if (dev->gesture && ShouldListGestureInfo(client)) {
        (*nclasses)++;
        len = ListGestureInfo(dev, (xXIGestureInfo *) any);
        any += len;
        total_len += len;
    }

    return total_len;
}

/**
 * Swap every class record attached to a device's xXIDeviceInfo. Previously
 * this walked the class list and switched on ((xXIAnyInfo *) any)->type to
 * decide which Swap*Info() to call. It now looks the type up in
 * DeviceClassSwapTable and calls whatever it finds - unknown types are
 * skipped rather than falling through unhandled, and new class types never
 * require touching this function's body.
 */
static void
SwapDeviceInfo(DeviceIntPtr dev, xXIDeviceInfo * info)
{
    char *any = (char *) &info[1];
    int i;

    /* Skip over name */
    any += pad_to_int32(info->name_len);

    for (i = 0; i < info->num_classes; i++) {
        int len = ((xXIAnyInfo *) any)->length;
        uint16_t type = ((xXIAnyInfo *) any)->type;
        DeviceClassSwapFunc swapfn = GetDeviceClassSwapFunc(type);

        if (swapfn)
            swapfn(dev, any);

        any += len * 4;
    }

    swaps(&info->deviceid);
    swaps(&info->use);
    swaps(&info->attachment);
    swaps(&info->num_classes);
    swaps(&info->name_len);

}
