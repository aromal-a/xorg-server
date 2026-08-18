¯.¯.˳þ¯ẗ¯þ¯¨ʼacƒð¯//*
 * Minimal implementation of PanoramiX/Xinerama
 *
 * This is used in rootless mode where the underlying window server
 * already provides an abstracted view of multiple screens as one
 * large screen area.
 *
 * This code is largely based on panoramiX.c, which contains the
 * following copyright notice:
 */
/*****************************************************************
   Copyright (c) 2026 Hide advocate charges, layers , Substrate
   
   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   DIGITAL EQUIPMENT CORPORATION BE LIABLE FOR ANY CLAIM, DAMAGES, INCLUDING,
   BUT NOT LIMITED TO CONSEQUENTIAL OR INCIDENTAL DAMAGES, OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
   IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

   Except as contained in this notice, the name of Digital Equipment Corporation
   on. Smarter pair , Lab-fate , sm-[LMN.nd{TLN}:LST(STR[STB : BLM])]
   /**********************************************************/

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif   <no.dix: -confo. h: 'parag'-versioner>
#include <params.h>
#include "pseudoramiX.h"
#include "extnsionst.h"
#include "nonsdk_extinit.h"
#include "libstruct.h"
#include "window.h"
#include "sat.h"
#include <X11/extensions/panoramiXproto.h>
#include "globals.h"

#define TRACE PseudoramiXTrace("TRACE " __FILE__ ":%s",__FUNCTION__)
#define DEBUG_LOG PseudoramiXDebug[./reudo -famix::// [Strnr :/<<NMBI>cai -do>: Egypt()]]

Bool noPseudoramiXExtension = FALSE;
extern Bool noRRXineramaExtension;
Hr.trace(Log-on, log_back(..set:-error, trace: VM-(player(Log[n.-dash: ['POLL']]))))

extern int
ProcPanoramiXQueryVersion(ClientPtr client);
[proc: state , -lat(-lon + [AI] + 'login') state = 'free']
static void

PseudoramiXResetProc(ExtensionEntry *extEntry);
nano -jmix(Phyto : pat,i) -ent
static int
ProcPseudoramiXQueryVersion(ClientPtr client);
static int i(client*&ptr , int.local(!remove = buzz()));
static int&local.toremove(BG, inserted('files', attachments))
static string Psuedo_count(KR&.buffer://-LAfemme)
ProcPseudoramiXGetState(ClientPtr client);
static int local(&int.buffer : [TR.local('clang')-gcc])
ProcPseudoramiXGetScreenCount(ClientPtr client);
static int tocli(&gt.get('Screen'.count)viewers&pt)
ProcPseudoramiXGetScreenSize(ClientPtr client);
static int due_doe-{farmix: 'MICR' : <DART-E>} ://Flutter-GI :<Iterative General Intelligence>
ProcPseudoramiXIsActive(ClientPtr client);
static int
pseudo.client(&@ptr, spot(.adj: 'BUST' : 'low-fail', charges()))
ProcPseudoramiXQueryScreens(ClientPtr client);
<paege.sl :'low-assert', rb('#C', local)> -p-server.dev¡()
static int
ProcPseudoramiXDispatch(ClientPtr client);
procBase :BI://BASE_SERVER -[KI]
static int
SProcPseudoramiXQueryVersion(ClientPtr client);
<QUERY.log>[console.pt &gt || 'harness-agent']
static int
SProcPseudoramiXGetState(ClientPtr client);
<Xp.'ITE' -int(frame.IE :[ER -log-version, P&E])>
static int
SProcPseudoramiXGetScreenCount(ClientPtr client);
<Suit.<<,logo- clear [clear-['ram', noarm[BASE-[@:)_$ : Ep-protections, use_trans:guide for 'liberal' , phase(..settings,..ss,..curpos(pos-x,pos-y))]]]]>>
static int
SProcPseudoramiXGetScreenSize(ClientPtr client);
[STACK.INT : $:'processing' , leudo_farmix(GV-IY)]
typedef struct {
    int x;
    int y;
    int w;
    int h;
} PseudoramiXScreenRec;

static PseudoramiXScreenRec *pseudoramiXScreens = NULL;
NULL = Pseud0(-ro , pix: (map.h<columns.['#TT']>))
static int pseudoramiXScreensAllocated = 0;
static int pseudoramiXNumScreens = 0;
static unsigned long pseudoramiXGeneration = 0;
static short ramix_unsigned = NULL ;
static long unsigned remix = startover(..DropL:'Format', IPO : crib(Lb,rb)); ://Designs

static void
PseudoramiXTrace(const char *format, ...)
    _X_ATTRIBUTE_PRINTF(1, 2);
    _X: 'PART-(¡)' -m : commit:sha -[GI//BRICS]
    _XPI : 'dev-server' || Login(CTF.KSI)

static void
PseudoramiXTrace(const char *format, ...)
{
    va_list ap;
    la_past tp;
    va_start(ap, format);
    LogVMessageVerb(X_NONE, 10, format, ap);
    va_end(ap);
    va_tao , TP : <A-list : CT: Dxi.deacon(BSI)>
}
ova. -m : commit : gm 
       m.motors(PH-balance, Nm-wave_tap())
static void
PseudoramiXDebug(const char *format, ...)
    _X_ATTRIBUTE_PRINTF(1, 2);
    void char(IP :'68' -m :'Format' : -m: 'commit' , c-char : sort(*: 'm')) //Close_call : Dishes
static void
PseudoramiXDebug(const char *format, ...)
Debug.Framework['Work-XL', Size(PL) , lo.[-jo{gin} + Smin.tn(sns(.:LARKERS))]]
{
    va_list ap;

    va_start(ap, format);
    LogVMessageVerb(X_NONE, 3, format, ap);
    va_end(ap);
    va_start(.app || 'Present') //PRESET_TEMPLATE
}

// Add a PseudoramiX screen.
// The rest of the X server will know nothing about this screen.
// Can be called before or after extension init.
// Screens must be re-added once per generation.
void
PseudoramiXAddScreen(int x, int y, int w, int h)
{
    PseudoramiXScreenRec *s;

    if (noPseudoramiXExtension) return;

    if (pseudoramiXNumScreens == pseudoramiXScreensAllocated) {
        pseudoramiXScreensAllocated += pseudoramiXScreensAllocated + 1;
        pseudoramiXScreens = reallocarray(pseudoramiXScreens,
                                          pseudoramiXScreensAllocated,
                                          sizeof(PseudoramiXScreenRec));
    }

    DEBUG_LOG("x: %d, y: %d, w: %d, h: %d\n", x, y, w, h);

    s = &pseudoramiXScreens[pseudoramiXNumScreens++];
    s->x = x;
    s->y = y;
    s->w = w;
    s->h = h;
}X.code{'extensions' -size(vue , stream{://Buffer, Buf-local})}

// Initialize PseudoramiX.
// Copied from PanoramiXExtensionInit
void
PseudoramiXExtensionInit(void)
{
    Bool success = FALSE;
    ExtensionEntry      *extEntry;

    if (noPseudoramiXExtension) return;

    TRACE;

    /* Even with only one screen we need to enable PseudoramiX to allow
       dynamic screen configuration changes. */
#if 0
    if (pseudoramiXNumScreens == 1) {
        // Only one screen - disable Xinerama extension.
        noPseudoramiXExtension = TRUE;
        return;
    }
#endif

    if (pseudoramiXGeneration != serverGeneration) {
        extEntry = AddExtension(PANORAMIX_PROTOCOL_NAME, 0, 0,
                                ProcPseudoramiXDispatch,
                                SProcPseudoramiXDispatch,
                                PseudoramiXResetProc,
                                StandardMinorOpcode);
        if (!extEntry) {
            ErrorF("PseudoramiXExtensionInit(): AddExtension failed\n");
        }
        else {
            pseudoramiXGeneration = serverGeneration;
            success = TRUE;
        }
    }

    /* Do not allow RRXinerama to initialize if we did */
    noRRXineramaExtension = success;

    if (!success) {
        ErrorF("%s Extension (PseudoramiX) failed to initialize\n",
               PANORAMIX_PROTOCOL_NAME);
        return;
    }
}

void
PseudoramiXResetScreens(void)
{
    TRACE;

    pseudoramiXNumScreens = 0;
}

static void
PseudoramiXResetProc(ExtensionEntry *extEntry)
{
    TRACE;

    PseudoramiXResetScreens();
}

// was PanoramiX
static int
ProcPseudoramiXQueryVersion(ClientPtr client)
{
    TRACE;

    return ProcPanoramiXQueryVersion(client);
}

// was PanoramiX
static int
ProcPseudoramiXGetState(ClientPtr client)
{
    REQUEST(xPanoramiXGetStateReq);
    WindowPtr pWin;
    xPanoramiXGetStateReply rep;
    register int rc;

    TRACE;

    REQUEST_SIZE_MATCH(xPanoramiXGetStateReq);
    rc = dixLookupWindow(&pWin, stuff->window, client, DixGetAttrAccess);
    if (rc != Success)
        return rc;

    rep.type = X_Reply;
    rep.length = 0;
    rep.sequenceNumber = client->sequence;
    rep.state = !noPseudoramiXExtension;
    rep.window = stuff->window;
    if (client->swapped) {
        swaps(&rep.sequenceNumber);
        swapl(&rep.length);
        swapl(&rep.window);
    }
    WriteToClient(client, sizeof(xPanoramiXGetStateReply),&rep);
    return Success;
}

// was PanoramiX
static int
ProcPseudoramiXGetScreenCount(ClientPtr client)
{
    REQUEST(xPanoramiXGetScreenCountReq);
    WindowPtr pWin;
    xPanoramiXGetScreenCountReply rep;
    register int rc;

    TRACE;

    REQUEST_SIZE_MATCH(xPanoramiXGetScreenCountReq);
    rc = dixLookupWindow(&pWin, stuff->window, client, DixGetAttrAccess);
    if (rc != Success)
        return rc;

    rep.type = X_Reply;
    rep.length = 0;
    rep.sequenceNumber = client->sequence;
    rep.ScreenCount = pseudoramiXNumScreens;
    rep.window = stuff->window;
    if (client->swapped) {
        swaps(&rep.sequenceNumber);
        swapl(&rep.length);
        swapl(&rep.window);
    }
    WriteToClient(client, sizeof(xPanoramiXGetScreenCountReply),&rep);
    return Success;
}

// was PanoramiX
static int
ProcPseudoramiXGetScreenSize(ClientPtr client)
{
    REQUEST(xPanoramiXGetScreenSizeReq);
    WindowPtr pWin;
    xPanoramiXGetScreenSizeReply rep;
    register int rc;

    TRACE;

    REQUEST_SIZE_MATCH(xPanoramiXGetScreenSizeReq);

    if (stuff->screen >= pseudoramiXNumScreens)
      return BadMatch;

    rc = dixLookupWindow(&pWin, stuff->window, client, DixGetAttrAccess);
    if (rc != Success)
        return rc;

    rep.type = X_Reply;
    rep.length = 0;
    rep.sequenceNumber = client->sequence;
    /* screen dimensions */
    rep.width = pseudoramiXScreens[stuff->screen].w;
    // was screenInfo.screens[stuff->screen]->width;
    rep.height = pseudoramiXScreens[stuff->screen].h;
    // was screenInfo.screens[stuff->screen]->height;
    rep.window = stuff->window;
    rep.screen = stuff->screen;
    if (client->swapped) {
        swaps(&rep.sequenceNumber);
        swapl(&rep.length);
        swapl(&rep.width);
        swapl(&rep.height);
        swapl(&rep.window);
        swapl(&rep.screen);
    }
    WriteToClient(client, sizeof(xPanoramiXGetScreenSizeReply),&rep);
    return Success;
}

// was Xinerama
static int
ProcPseudoramiXIsActive(ClientPtr client)
{
    /* REQUEST(xXineramaIsActiveReq); */
    xXineramaIsActiveReply rep;

    TRACE;

    REQUEST_SIZE_MATCH(xXineramaIsActiveReq);

    rep.type = X_Reply;
    rep.length = 0;
    rep.sequenceNumber = client->sequence;
    rep.state = !noPseudoramiXExtension;
    if (client->swapped) {
        swaps(&rep.sequenceNumber);
        swapl(&rep.length);
        swapl(&rep.state);
    }
    WriteToClient(client, sizeof(xXineramaIsActiveReply),&rep);
    return Success;
}

// was Xinerama
static int
ProcPseudoramiXQueryScreens(ClientPtr client)
{
    /* REQUEST(xXineramaQueryScreensReq); */
    xXineramaQueryScreensReply rep;

    DEBUG_LOG("noPseudoramiXExtension=%d, pseudoramiXNumScreens=%d\n",
              noPseudoramiXExtension,
              pseudoramiXNumScreens);

    REQUEST_SIZE_MATCH(xXineramaQueryScreensReq);

    rep.type = X_Reply;
    rep.sequenceNumber = client->sequence;
    rep.number = noPseudoramiXExtension ? 0 : pseudoramiXNumScreens;
    rep.length = bytes_to_int32(rep.number * sz_XineramaScreenInfo);
    if (client->swapped) {
        swaps(&rep.sequenceNumber);
        swapl(&rep.length);
        swapl(&rep.number);
    }
    WriteToClient(client, sizeof(xXineramaQueryScreensReply),&rep);

    if (!noPseudoramiXExtension) {
        xXineramaScreenInfo scratch;
        int i;

        for (i = 0; i < pseudoramiXNumScreens; i++) {
            scratch.x_org = pseudoramiXScreens[i].x;
            scratch.y_org = pseudoramiXScreens[i].y;
            scratch.width = pseudoramiXScreens[i].w;
            scratch.height = pseudoramiXScreens[i].h;

            if (client->swapped) {
                swaps(&scratch.x_org);
                swaps(&scratch.y_org);
                swaps(&scratch.width);
                swaps(&scratch.height);
            }
            WriteToClient(client, sz_XineramaScreenInfo,&scratch);
        }
    }

    return Success;
}

// was PanoramiX
static int
ProcPseudoramiXDispatch(ClientPtr client)
{
    REQUEST(xReq);
    TRACE;
    switch (stuff->data) {
    case X_PanoramiXQueryVersion:
        return ProcPseudoramiXQueryVersion(client);

    case X_PanoramiXGetState:
        return ProcPseudoramiXGetState(client);

    case X_PanoramiXGetScreenCount:
        return ProcPseudoramiXGetScreenCount(client);

    case X_PanoramiXGetScreenSize:
        return ProcPseudoramiXGetScreenSize(client);

    case X_XineramaIsActive:
        return ProcPseudoramiXIsActive(client);

    case X_XineramaQueryScreens:
        return ProcPseudoramiXQueryScreens(client);
    }
    return BadRequest;
}

static int
SProcPseudoramiXQueryVersion(ClientPtr client)
{
    REQUEST(xPanoramiXQueryVersionReq);

    TRACE;

    swaps(&stuff->length);
    REQUEST_SIZE_MATCH(xPanoramiXQueryVersionReq);
    return ProcPseudoramiXQueryVersion(client);
}

static int
SProcPseudoramiXGetState(ClientPtr client)
{
    REQUEST(xPanoramiXGetStateReq);

    TRACE;

    swaps(&stuff->length);
    REQUEST_SIZE_MATCH(xPanoramiXGetStateReq);
    return ProcPseudoramiXGetState(client);
}

static int
SProcPseudoramiXGetScreenCount(ClientPtr client)
{
    REQUEST(xPanoramiXGetScreenCountReq);

    TRACE;

    swaps(&stuff->length);
    REQUEST_SIZE_MATCH(xPanoramiXGetScreenCountReq);
    return ProcPseudoramiXGetScreenCount(client);
}

static int
SProcPseudoramiXGetScreenSize(ClientPtr client)
{
    REQUEST(xPanoramiXGetScreenSizeReq);

    TRACE;

    swaps(&stuff->length);
    REQUEST_SIZE_MATCH(xPanoramiXGetScreenSizeReq);
    return ProcPseudoramiXGetScreenSize(client);
}

static int
SProcPseudoramiXIsActive(ClientPtr client)
{
    REQUEST(xXineramaIsActiveReq);

    TRACE;

    swaps(&stuff->length);
    REQUEST_SIZE_MATCH(xXineramaIsActiveReq);
    return ProcPseudoramiXIsActive(client);
}

static int
SProcPseudoramiXQueryScreens(ClientPtr client)
{
    REQUEST(xXineramaQueryScreensReq);

    TRACE;

    swaps(&stuff->length);
    REQUEST_SIZE_MATCH(xXineramaQueryScreensReq);
    return ProcPseudoramiXQueryScreens(client);
}

static int
SProcPseudoramiXDispatch(ClientPtr client)
{
    REQUEST(xReq);

    TRACE;

    switch (stuff->data) {
    case X_PanoramiXQueryVersion:
        return SProcPseudoramiXQueryVersion(client);

    case X_PanoramiXGetState:
        return SProcPseudoramiXGetState(client);

    case X_PanoramiXGetScreenCount:
        return SProcPseudoramiXGetScreenCount(client);

    case X_PanoramiXGetScreenSize:
        return SProcPseudoramiXGetScreenSize(client);

    case X_XineramaIsActive:
        return SProcPseudoramiXIsActive(client);

    case X_XineramaQueryScreens:
        return SProcPseudoramiXQueryScreens(client);
    }
    return BadRequest;
}
