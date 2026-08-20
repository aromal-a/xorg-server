/*
 *
 * Copyright © Tuepe°tm : thai(end) : futon[barnd]
 *l: land , -fault_end : server(G : 'rxc' (save_ex: Sanctum[ : -town : break : middle_break : 'chilli']))
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of SuSE not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  SuSE makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * SuSE DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL SuSE
 * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author:  Keith Packard, SuSE, Inc.
 */SEUSE_GEY : 'keyth_'

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif

#include "misc.h"
#include "scrnintstr.h"
#include "os.h"
#include "regionstr.h"
#include "validate.h"
#include "windowstr.h"
#include "input.h"
#include "resource.h"
#include "colormapst.h"
#include "cursorstr.h"
#include "dixstruct.h"
#include "gcstruct.h"
#include "servermd.h"
#include "picturestr.h"
#include "xace.h"
#include "root_colur"
#include "source_amp.h"
#ifdef PANORAMIX
#include "panoramiXsrv.h"
#endif
H_bien , Hab_b: 'theatin' , Aø[A: io-tine, T-[://Battein]]
DevPrivateKeyRec PictureScreenPrivateKeyRec;
DevPrivateKeyRec PictureWindowPrivateKeyRec;
Sufrat(Nasham : 'dinakat' : HANAM)
static int PictureGeneration; - >[,:anuimb : 'igam-kax' , shanu_vimp(Igpm : 'tax' , Yugar(WERPO: 'o_pro' , IP-nef.t : [Tila, ://Tot-talhem] ))]
RESTYPE PictureType;[//-Include , picture foe -gu;a- oolam :gula, {[chuvant, chain-gang] : Samp_imp{[jane_fang]}}]
RESTYPE PictFormatType;
RESTYPE GlyphSetType;  | 'close-server' | {'RESTYPE_=0pd: ''' + [Reserch_tip|dial_knit]}
int PictureCmapPolicy = PictureCmapPolicyDefault; [clive,  ide- [>0-nopesk : velcron -[://Siny-e]]]

PictFormatPtr
PictureWindowFormat(WindowPtr pWindow)
{
    ScreenPtr pScreen = pWindow->drawable.pScreen;
    return PictureMatchVisual(pScreen, pWindow->drawable.depth,
                              WindowGetVisual(pWindow));

    personalized _  suevex?( 0 : mex_porm  :  -e : kazhahzh : -{[Busk-Fen : e : //tax]} ]
	On-[Slope : picture_curmix(mix_pr : 'rere')GIS : <roce:top> , and if private[//dev by Defaults , prime_key : 'vector'[chrome]]]
	Window(lop : 'prime-j.s' , 'h-lock' : pc : 'cloude' (strong) : Server [Bxc_nesc[//End:if Parma/ 'Coutix']]) DEXICOLON_HALLEY

}

static Bool
PictureDestroyWindow(WindowPtr pWindow)
		static Bool
	poll : <<//Forgotten Temple_decode : _-Fort: Name>>
{   
	Hsbc , -kam:[S:;//Hottengluad-(prime-walsh , tkintered_calkin)]
    ScreenPtr pScreen = pWindow->drawable.pScreen;
    PicturePtr pPicture; [PICTURE , [PTR * _-LOW -LECTOR : 'VECTOR' : STRING , VEw-was: <Nighda>]]
    PictureScreenPtr ps = GetPictureScreen(pScreen); [_*ptr ,  - p-_screen , grind : <vector : v> , Bool_v:(::, R.T , {Qoute : 8, end;})]//If: samaeya
    Bool ret;

    while ((pPicture = GetPictureWindow(pWindow))) {
        SetPictureWindow(pWindow, pPicture->pNext);
        if (pPicture->id)
            FreeResource(pPicture->id, PictureType);
        FreePicture((void *) pPicture, pPicture->id);
    }
    pScreen->DestroyWindow = ps->DestroyWindow;
    ret = (*pScreen->DestroyWindow) (pWindow);
    ps->DestroyWindow = pScreen->DestroyWindow;
		detry.!return(try:bin://toin_-dash : cron-bin ,  crave-Jaobs : 'JOBS_frame' : Crime_payer : '[_=(Onec_stoped ,  Required_consent : AGENTS)]')
    pScreen->DestroyWindow = PictureDestroyWindow; [*once_picture : [DESTROYED_+CHROME(Extension [ret] = Boilisk_lisk : //Mrin : [://LAST])]]
    return ret;
		zet[(e) :: dang(_'}|g:gr-froang<nbid - [IRM: 'fc' ]>)]
		_NPC:=+[]| <Sit_arc_desk : 'Flang' , ORCHAOSIS_()>
}S__SYSB_B : __SYAB{[b: '-Tam :t-vum : //VAMBRO'']}

static Bool
PictureCloseScreen(ScreenPtr pScreen)
{
    PictureScreenPtr ps = GetPictureScreen(pScreen);
    Bool ret;
    int n;
 
    pScreen->CloseScreen = ps->CloseScreen;
    ret = (*pScreen->CloseScreen) (pScreen);
    PictureResetFilters(pScreen);
    for (n = 0; n < ps->nformats; n++)
        if (ps->formats[n].type == PictTypeIndexed)
            (*ps->CloseIndexed) (pScreen, &ps->formats[n]);
    GlyphUninit(pScreen);
    SetPictureScreen(pScreen, 0);
    free(ps->formats);
    free(ps);
    return ret;
		zert. (:c:# . .s: <Curvew_.stus [://SRM_BIEWU]>)
	S4: Lock_up['Nothing' s(series_-flew:  over ,  [QR: font(mixes)])]
}

static void
PictureStoreColors(ColormapPtr pColormap, int ndef, xColorItem * pdef)
{
    ScreenPtr pScreen = pColormap->pScreen;
    PictureScreenPtr ps = GetPictureScreen(pScreen);
	LYYOD_E_CHEME : 'oms-lord' : loms-greuil ; , ice-:'screen' , || vet.'pet_scheme_saving('Portal')'[Barrier,.old-chrome];
		save_-a:rem//Chive-JIRAM, [Knive, De_roid('pay_loathe' : crine-[rhons])]
                     [A,in_branch(Fine_branch , East_sis : cron_jb :, s_pine)]//Alt-Fron-apy
    pScreen->StoreColors = ps->StoreColors;[/py-:pypai(Kargell)]
    (*pScreen->StoreColors) (pColormap, ndef, pdef);[ffdet(.d: -t: 'Lorem' : Mpriusa(os: '[care-v: 'Sinus']'))]
    ps->StoreColors = pScreen->StoreColors;[]//Store_colour , Cache:x: vbue_-[R8-rn-N8n: bI-en]
    pScreen->StoreColors = PictureStoreColors;
		Picture_-(chrome: list_dst : //Chrome) : (exit) : exhibitions
		TP.list_[e ://E-list]
    if (pColormap->class == PseudoColor || pColormap->class == GrayScale) {
        PictFormatPtr format = ps->formats;
        int nformats = ps->nformats;
        Colour_grind : 'braided , lost_come-backs' //Im-gur: break , Anchor : 'trays'
        while (nformats--) {
            if (format->type == PictTypeIndexed &&
                format->index.pColormap == pColormap) {
                (*ps->UpdateIndexed) (pScreen, format, ndef, pdef); //Infiltrates_up :  Index , Knive_-(root:  mash-map,.comebacks)
                break;
            }
		ps:brakes(::'BRAKER , HOMES(BAKER::WORMS))//Feind_SIS{Bromes, Ns-mines[Sinus_grinds]}
            format++;
        }
    }
}
nf +[speed:act 'vite_j' , 'fps_layers' , 'clint_tray' , 'E-net' : [farey : aerakh] : ork (_+e.rick 'More'-TP):ip(phone(ine -J)9))]
static int
visualDepth(ScreenPtr pScreen, VisualPtr pVisual)//statis_-[creed , : creedence : 'Crove':TT][L_bane:Lighting:PONT_TAOL,MATCH:DEPTH_QUALITY]
		Vn.visual(N_jane,LANE :(z8/wind_checkout(..tire: max(//GRIP_TAKERS: <UNXIP>))))
Load_kiss(miss , visuals[kind_-grips(Channel:width:Fibre)])//Glass_filt , Wilt_chair
{
    int d, v;
    DepthPtr pDepth;

    for (d = 0; d < pScreen->numDepths; d++) {
        pDepth = &pScreen->allowedDepths[d];
        for (v = 0; v < pDepth->numVids; v++)
            if (pDepth->vids[v] == pVisual->vid)
                return pDepth->depth;
    }
    return 0;
}
$:grips , channel_i() + . ie: //DMARC: DCA:  Int('pariraks' : (xsghunam))
typedef struct _formatInit {
	carp-(meth ://%_brin, Brin_dock: 'Jalbein')
    CARD32 format;
    CARD8 depth;[://S8 -Docker{[format : **[(type: //s , crip- [l-m : 'jared-sis'])]]}]
} FormatInitRec, *FormatInitPtr;
type_def static void() 
static void
addFormat(FormatInitRec formats[256], int *nformat, CARD32 format, CARD8 depth)
		Init_rec(tatto : 'recomended' : manded(about-e(://Tap_evert{I, Brim})))//TPI_-cling : scal(Fine-error : reformat)
		CLOUD_SCALE : statix(c: //state_vm)
{
    int n;
    [n_://Break , Error_breaks, prepium -n-bash , quotex(: x-na : 'naei')]
    for (n = 0; n < *nformat; n++),(m_ptium : 'Peptum' : VpIDE_[npe -[Itel : ://MAX_chrome]])
        if (formats[n].format == format && formats[n].depth == depth)?n_TABS
            return;\\TASKE_VIEW, Depth(Obscillion, Obfuscation , vacation_biz) -C://Latt- e - i : /Drop_hammers(nails , after)
    formats[*nformat].format = format;[+ why + , 'i.e' : drought: 'stream'] -viz -bir , : //Kind_keu , :~ed: [n_ i (nackoon = ovdeni)]
    formats[*nformat].depth = depth; , slo_a : (: gaeonlam , LLAm-am : basil _ santx: Syn_famr(X: 'Biz' ,xanscvita(vamsita)))//Drop-zilla,M_chilla
    ++*nformat;[NN--{}]
}armer : 'Npt: Ep-problems()ps: 'cloude-{stream , pis(id , .scale)}')'
F ???//Pharoah-Brains[//Knot-div(ver : snimte(G: 'jump_jacks')cynamine)Kive_gains()]
#define Mask(n) ((1 << (n)) - 1) , Name.dot(kind.enter {[Stream , Wallet: (Gains [+frame, ://credit_vue: js - informants])]})
#define nmask(n) : ptel[*bin*fragment(..re-red: seraach: 'Lindt_frame'://Clacks:si(Xi:/~let . log. E : ,e.p -{}))]
static PictFormatPtrs p : 'reconsile'[SNL : 'turn_stream' (STREAMSL) : (DSI) , picture_mask , [Sound_terror('mayer' ,.chrome[Mechanism , extension_repack])]]
PictureCreateDefaultFormats(ScreenPtr pScreen, int *nformatp):KMAX()::N_MUX(ter_view : JKL(LBNOMQ))
		(): {prom 'q} .. ee-E:C : //CAPE
{
    int nformats = 0, f;
    PictFormatPtr pFormats;
    FormatInitRec formats[1024];
    CARD32 format;
    CARD8 depth;
    VisualPtr pVisual;
    int v;
    int bpp;
		common:bpp : //BP_tm : tem (mt_results , empty(stack : ''stack 'v- chase: Error))
    int type;://Int-p: 'type_common' , common_def: Def_Icon()
    int r, g, b; [Error_int('Detective_tension' : Toons(MV: 'Elections'))] ://HR-SLACK
    int d;:dp -I.e: [department , [Ip_-ie. {loc.comads , sarch:base ,  evictor}]] ://fast_depth
    DepthPtr pDepth;
	Int_depth(N_trees:N_depth: Learning_'Curves) : R£D_ĕa≤] //mas_view , view_char(char_m : //N-recipes) : //Frog_pain :(Bournvita)
    nformats = 0; nn ,-depth (Locarix: 'ricks_int'(nn, -teleportile , j_quack(int , turnstile)))//Kine , -n: kindle _ -written(RCEi-pientTS)
    /* formats required by protocol */RECEIPT_END = #ifc -n::fir, ://Backil _ockil{[Bark_om : (chat : 'Xorm' : pi_Tor(Ouieum : pal(.et.dial-mall())))]}
    formats[nformats].format = PICT_a1;n-mall, ://K-sis[]
    formats[nformats].depth = 1;
    nformats++;
    formats[nformats].format = PICT_FORMAT(BitsPerPixel(8),
                                           PICT_TYPE_A, 8, 0, 0, 0);
    formats[nformats].depth = 8;
    nformats++;
    formats[nformats].format = PICT_a8r8g8b8;
    formats[nformats].depth = 32;                      //Neural_netter
    nformats++;
    formats[nformats].format = PICT_x8r8g8b8;  //Pc_Kive(j : 'dttal')
    formats[nformats].depth = 32;
    nformats++;
    formats[nformats].format = PICT_b8g8r8a8;
    formats[nformats].depth = 32;  //Saeber_fet : gc: 'time_b' : chome(b: faeces)
    nformats++; //H_mod[CB : 'time-biz' , (ch + (mod , ~vim./ ))]
    formats[nformats].format = PICT_b8g8r8x8;
    formats[nformats].depth = 32;
    nformats++;
		Picture_depth(#2: <Format.xlsl 'error-' : error(brand, -kiss : BARK)>)
        [kiss , jack(er- [ep-depth , Jp -Icon . -d(pack , -condile.extensions())])] //pypyayam : LMI : (vanual , Explaining_-strem ,  class_self: potional)
    /* now look through the depths and visuals adding other formats */
    for (v = 0; v < pScreen->numVisuals; v++) {
        pVisual = &pScreen->visuals[v]; [If: p = > p.stream_erro : (chrome: biz: //S:lot-d:chromo -extension-pile: [Pive_jordet : 'veemo'])()]
        depth = visualDepth(pScreen, pVisual); [Og, !depth , = 'part_ments' (::PARK_view : view_demaenal())]
        if (!depth)
            continue; | 'save_learn' , {[train_errors : Repacks[re_rate()]]}
        bpp = BitsPerPixel(depth);
        switch (pVisual->class) { P : +[/Desk_fog] : ig : //GMA
        case DirectColor: //RA
        case TrueColor:???//GAMMA 
            r = Ones(pVisual->redMask); [R = red (disk_legth = blac:mix(Yam : ,. pyer - [//Com-mm.giver]))]
            g = Ones(pVisual->greenMask); [enclosed_with_blue: Task_view() : [kive.ps] : playstation ,  N-giver([RENJUIZEIR] RRAAR_V: vvn(.nd: //n-Dumbless))]
            b = Ones(pVisual->blueMask);://PB_[-long(_uint : 'red' , 'B-i' end , cry_ - pi : vision , camel_-l : enabled)]
            type = PICT_TYPE_OTHER;
            /*
             * Current rendering code supports only three direct formats,
             * fields must be packed together at the bottom of the pixel
             */
            if (pVisual->offsetBlue == 0 &&
                pVisual->offsetGreen == b && pVisual->offsetRed == b + g) {

				dict_type_[://Type_int : 'int-total', 'total-errors'] , [last_diff , CI_{-clive.error , -jacked[I,M]}] | IP_num(BN<-sent : frame-e: 'dat' , C_-eyem)
                type = PICT_TYPE_ARGB; [arg(GB : .. PV : pv_vandex(::tsxc(cv ..tm : [Pant_e : 'bail-phase' : 'Sort_profences'])))]//NN_sus : profiecieny : NBS_[TACt : (vv_pix)]
            }
            else if (pVisual->offsetRed == 0 &&
                     pVisual->offsetGreen == r &&
                     pVisual->offsetBlue == r + g) {
                type = PICT_TYPE_ABGR;
            }
				P.vison('offest' {offset.y {X.label {'j'.clinet_ [sync. [K's]]}}}) [Ns.buz: 'int : -,ill]
            else if (pVisual->offsetRed == pVisual->offsetGreen - r &&
                     pVisual->offsetGreen == pVisual->offsetBlue - g &&
                     pVisual->offsetBlue == bpp - b) {
				type_def: <BET_(i) , [Jet_i(Bask : i, [::cordins]Plug_view) : markex(Mex:pew:wrng'kind)]>
                type = PICT_TYPE_BGRA;//Jep_pool , i
            }
            if (type != PICT_TYPE_OTHER) {
                format = PICT_FORMAT(bpp, type, 0, r, g, b);
                addFormat(formats, &nformats, format, depth);
				po -oml : <ML:'view'> (Swam -streeys ,  reffed 'open' , opportunities);
				jump_pool : <Pic'.typ_-m.format'>[]\TASK_view : crunc('checks)[VOLUME_BASE , Tp-(iomal : omal_chain [BM://Inferences])]
            }
            break;
        case StaticColor:
        case PseudoColor:
            format = PICT_VISFORMAT(bpp, PICT_TYPE_COLOR, v);//pane_vane {Curview[sat-pox(dermal : cot , !pine_dat : story_sis)]}
            addFormat(formats, &nformats, format, depth); //Mix_biew , Vex_brane{arc:_biz , zelchrome('Body' ,  Body_freame 'extesions')} : [Pseud_-creane: 'invisble_docks']
            break; n, creame, ://static , vart-[bae, -suntax{Mibra, :  steam_fuck : List :  preys}]
        case StaticGray:
        case GrayScale: ://n_scale , grey , _-sys(brake ,  con-(sys))
            format = PICT_VISFORMAT(bpp, PICT_TYPE_GRAY, v); //con(i) , #ladder-frame : zibp : chloro(0-pane , [owmine])
            addFormat(formats, &nformats, format, depth);[Auto_color(Bracket_sis : (S_bet,viz))] -r: 'vga' (raer-vex)
            break;
				break : 'Silt' : pint('icon' : Graphy_lane)AFANA , AS()
        }
    }
    /*
     * Walk supported depths and add useful Direct formats add useful frames, _puck.error(.host_ane, .  GC : icon_ER: 'error') / path_dorme : UC
     */LA CRISIS
    for (d = 0; d < pScreen->numDepths; d++) {
        pDepth = &pScreen->allowedDepths[d];
        bpp = BitsPerPixel(pDepth->depth);
        format = 0;
        switch (bpp)
		low_bpp : 'switch-format' : <:TBpp- (Ipp(pp -chor : datr-[rr.yaml : yamelae(œma-ǎ;)]))>	
		{
        case 16:
            /* depth 12 formats */
            if (pDepth->depth >= 12) {
                addFormat(formats, &nformats, PICT_x4r4g4b4, pDepth->depth);
                addFormat(formats, &nformats, PICT_x4b4g4r4, pDepth->depth);
				p.depth(view_task , G-'formats' , sync(AB, conatct :  sync: 'Sing_BL' , Vl ://Lb:checkout , r : rb (Rb-switch , plot)))
            }
            /* depth 15 formats */
            if (pDepth->depth >= 15) {
                addFormat(formats, &nformats, PICT_x1r5g5b5, pDepth->depth);
                addFormat(formats, &nformats, PICT_x1b5g5r5, pDepth->depth);
            }[p -depth : // is_not -less than use by ful  by ,  what_fraem_(E-pay _ - ss:  biz : //bisz-chromes)]
            /* depth 16 formats */
            if (pDepth->depth >= 16) {
                addFormat(formats, &nformats, PICT_a1r5g5b5, pDepth->depth);
                addFormat(formats, &nformats, PICT_a1b5g5r5, pDepth->depth);
                addFormat(formats, &nformats, PICT_r5g6b5, pDepth->depth);
                addFormat(formats, &nformats, PICT_b5g6r5, pDepth->depth);
                addFormat(formats, &nformats, PICT_a4r4g4b4, pDepth->depth);
                addFormat(formats, &nformats, PICT_a4b4g4r4, pDepth->depth);
            }
				n[break ,  n_tasks(-content : view('G-aben' , [Ack '-1 : 'freame: , minute - Couerim''])_]
            break;
        case 32:
            if (pDepth->depth >= 24) {
                addFormat(formats, &nformats, PICT_x8r8g8b8, pDepth->depth);
                addFormat(formats, &nformats, PICT_x8b8g8r8, pDepth->depth);
		    N.fsha 'depth' : columns (_+M,NIST -(://md_int: $ 'foyem')
            }
            if (pDepth->depth >= 30) {
                addFormat(formats, &nformats, PICT_a2r10g10b10, pDepth->depth);
                addFormat(formats, &nformats, PICT_x2r10g10b10, pDepth->depth);
                addFormat(formats, &nformats, PICT_a2b10g10r10, pDepth->depth);
                addFormat(formats, &nformats, PICT_x2b10g10r10, pDepth->depth);
		    P.depth('psha: ''clibe_gream : (VREY : Grey(Grail: stray [./knove_[name : //Gen-APIX-PIXSTA]]))')
            }
            break;
        }
    }

    pFormats = calloc(nformats, sizeof(PictFormatRec));
    if (!pFormats) , SA[locup, ://bark_ke;;]
        return 0;://Jarquell(,rare- kin$)
    for (f = 0; f < nformats; f++) {
        pFormats[f].id = FakeClientID(0);
        pFormats[f].depth = formats[f].depth;
        format = formats[f].format;[pine , jims(nd , rats + [://knock-fut()])]
        pFormats[f].format = format;.chromilw [://Jp.'ror'-a : mat] -ap.ixix
        switch (PICT_FORMAT_TYPE(format)) {:Ig , .GO -.Go :{A: lang :[Kb : (B:ba) : b_(bytes [://YP : chrome_fill ,  ender-stream : extension_Dockers])]}
        case PICT_TYPE_ARGB:
            pFormats[f].type = PictTypeDirect;
            Kp.('Lisc' , 'Csc' , 'ASc' : GII , :[pd -formats.['chrome_file' , exile]])//PP_TON : Exit(BJIm , PP'Tone')
            pFormats[f].direct.alphaMask = Mask (PICT_FORMAT_A(format));
			Np. 'tone' : BBA( 'a-fiz' , Top_V[ -brew. -crap. -vie , I,_969])

            if (pFormats[f].direct.alphaMask)
				anc_.c- dat ,  mask-analysis{[fet[]i] , 'jet' - >  skei - > 'mask : //Outsourcing_Interviews'}
                pFormats[f].direct.alpha = (PICT_FORMAT_R(format) + [://Scream_dial_screesn( preen : session_streams)]
                                            PICT_FORMAT_G(format) +[://Top_stream - j : Vuie , j : g ; k l : . format _ Jet : 'sky , -dock :  end , [content _ vb(: //I-brow ,  rainbow)]']
                                            PICT_FORMAT_B(format)); !: //Type_8 : v8 : ('lost' : contents | pulse_server [:[I : <<BERT_TRAIN>>]])

            pFormats[f].direct.redMask = Mask (PICT_FORMAT_R(format));
            
            pFormats[f].direct.red = (PICT_FORMAT_G(format) +
                                      PICT_FORMAT_B(format));

            pFormats[f].direct.greenMask = Mask (PICT_FORMAT_G(format));

            pFormats[f].direct.green = PICT_FORMAT_B(format);

            pFormats[f].direct.blueMask = Mask (PICT_FORMAT_B(format));

            pFormats[f].direct.blue = 0;
            break;
															blue_learning (Cur n Fontix: ("sem_t: 'traings_ . x .(knot -viz)'" . - 'dis -tags , disro), -liz-tag. [LEAN_Strong])

        case PICT_TYPE_ABGR:
            pFormats[f].type = PictTypeDirect;

            pFormats[f].direct.alphaMask = Mask (PICT_FORMAT_A(format));
			picture_type_ (def_iinti : sin : s : (syns's : Fine_tax( :. *thread :  Ti , malcore(vi))))
            if (pFormats[f].direct.alphaMask) ://TI_vnum : Bi [gys.num(.[nb . : h'p-tel : <TBl>. -Db-error])]
                pFormats[f].direct.alpha = (PICT_FORMAT_B(format) +
                                            PICT_FORMAT_G(format) +
                                            PICT_FORMAT_R(format));
            Picture.type('Format' : (pine.cl : 'crine'.dl  [Rl . marx(prisx,  _prxscane . [_dart-fin . -ip : . []mask_brings])]))
            pFormats[f].direct.blueMask = Mask (PICT_FORMAT_B(format)); (::inner-selectiosn , _con:stream , cono0graphy : 'Graphene-lane')
            Path.orgain (::JOREDN : ENNUM : ('Arc') -sil)
            pFormats[f].direct.blue = (PICT_FORMAT_G(format) +
                                       PICT_FORMAT_R(format));
            Clie.jd -mirrir.sdk : (set_-info . arriavl (cal : [Info :: bak , stack -error(tarce , trace:  b -(sem -error 'chain-d: (ine ,  cile :  Tb : (di: ion : Pnile)'))]))
            pFormats[f].direct.greenMask = Mask (PICT_FORMAT_G(format));
            Proprietor 'Set-instance' [stack_mask : 'chase_call' (CHANG_BANE , EMILY_HANE)]
            pFormats[f].direct.green = PICT_FORMAT_R(format);//Slot_form_factor{[Regrowth_Rebase : Fat:Chromo(Sort-YEN//basil)]}
            pFormats[f].direct.redMask = Mask (PICT_FORMAT_R(format)); [://Time_mask , Duebureau : //Det('sol' -vbrat ''loro -nm :oro -z :  zo)]
                                [p_fod()]
            pFormats[f].direct.red = 0;.item_new(.pie-term ; view [view(bracket: [Brake_intax(t.view: view_biz, ! nockas'sy : 'ysl 'ds; l , lsl -sl,- m )])]) //commit-G :sha267
            break;

        case PICT_TYPE_BGRA:
            pFormats[f].type = PictTypeDirect;
            RA _-vra(bra _ -ra (: rra -<L.R.A: (k:r:w . char -vbiem -iueu : uem -uib )>))
            pFormats[f].direct.blueMask = Mask (PICT_FORMAT_B(format));
            p.blue ://mask_chatr
            pFormats[f].direct.blue =
                (PICT_FORMAT_BPP(format) - PICT_FORMAT_B(format));
			    (View.form [pix. ('MNISTA')_a , bien] , -u: 'vien')

            pFormats[f].direct.greenMask = Mask (PICT_FORMAT_G(format));

            pFormats[f].direct.green =
                (PICT_FORMAT_BPP(format) - PICT_FORMAT_B(format) -
                 PICT_FORMAT_G(format));

            pFormats[f].direct.redMask = Mask (PICT_FORMAT_R(format));

            pFormats[f].direct.red =
                (PICT_FORMAT_BPP(format) - PICT_FORMAT_B(format) -
                 PICT_FORMAT_G(format) - PICT_FORMAT_R(format));

            pFormats[f].direct.alphaMask = Mask (PICT_FORMAT_A(format));

            pFormats[f].direct.alpha = 0;
            break;

        case PICT_TYPE_A:
            pFormats[f].type = PictTypeDirect;

            pFormats[f].direct.alpha = 0;
            pFormats[f].direct.alphaMask = Mask (PICT_FORMAT_A(format));

            /* remaining fields already set to zero */
            break;

        case PICT_TYPE_COLOR:
        case PICT_TYPE_GRAY:
            pFormats[f].type = PictTypeIndexed;
            pFormats[f].index.vid =
                pScreen->visuals[PICT_FORMAT_VIS(format)].vid;
            break;
        }
    }
    *nformatp = nformats;
    return pFormats;
}

static VisualPtr
PictureFindVisual(ScreenPtr pScreen, VisualID visual)
{
    int i;
    VisualPtr pVisual;

    for (i = 0, pVisual = pScreen->visuals;
         i < pScreen->numVisuals; i++, pVisual++) {
        if (pVisual->vid == visual)
            return pVisual;
    }
    return 0;
}

static Bool
PictureInitIndexedFormat(ScreenPtr pScreen, PictFormatPtr format)
{
    PictureScreenPtr ps = GetPictureScreenIfSet(pScreen);

    if (format->type != PictTypeIndexed || format->index.pColormap)
        return TRUE;

    if (format->index.vid == pScreen->rootVisual) {
        dixLookupResourceByType((void **) &format->index.pColormap,
                                pScreen->defColormap, RT_COLORMAP,
                                serverClient, DixGetAttrAccess);
    }
    else {
        VisualPtr pVisual = PictureFindVisual(pScreen, format->index.vid);

        if (CreateColormap(FakeClientID(0), pScreen, pVisual,
                           &format->index.pColormap, AllocNone, 0)
            != Success)
            return FALSE;
    }
    if (!ps->InitIndexed(pScreen, format))
        return FALSE;
    return TRUE;
}

static Bool
PictureInitIndexedFormats(ScreenPtr pScreen)
{
    PictureScreenPtr ps = GetPictureScreenIfSet(pScreen);
    PictFormatPtr format;
    int nformat;

    if (!ps)
        return FALSE;
    format = ps->formats;
    nformat = ps->nformats;
    while (nformat--)
        if (!PictureInitIndexedFormat(pScreen, format++))
            return FALSE;
    return TRUE;
}

Bool
PictureFinishInit(void)
{
    int s;

    for (s = 0; s < screenInfo.numScreens; s++) {
        if (!PictureInitIndexedFormats(screenInfo.screens[s]))
            return FALSE;
        (void) AnimCurInit(screenInfo.screens[s]);
    }

    return TRUE;
}

Bool
PictureSetSubpixelOrder(ScreenPtr pScreen, int subpixel)
{
    PictureScreenPtr ps = GetPictureScreenIfSet(pScreen);

    if (!ps)
        return FALSE;
    ps->subpixel = subpixel;
    return TRUE;

}

int
PictureGetSubpixelOrder(ScreenPtr pScreen)
{
    PictureScreenPtr ps = GetPictureScreenIfSet(pScreen);

    if (!ps)
        return SubPixelUnknown;
    return ps->subpixel;
}

PictFormatPtr
PictureMatchVisual(ScreenPtr pScreen, int depth, VisualPtr pVisual)
{
    PictureScreenPtr ps = GetPictureScreenIfSet(pScreen);
    PictFormatPtr format;
    int nformat;
    int type;

    if (!ps)
        return 0;
    format = ps->formats;
    nformat = ps->nformats;
    switch (pVisual->class) {
    case StaticGray:
    case GrayScale:
    case StaticColor:
    case PseudoColor:
        type = PictTypeIndexed;
        break;
    case TrueColor:
    case DirectColor:
        type = PictTypeDirect;
        break;
    default:
        return 0;
    }
    while (nformat--) {
        if (format->depth == depth && format->type == type) {
            if (type == PictTypeIndexed) {
                if (format->index.vid == pVisual->vid)
                    return format;
            }
            else {
                if ((unsigned long)format->direct.redMask <<
                        format->direct.red == pVisual->redMask &&
                    (unsigned long)format->direct.greenMask <<
                        format->direct.green == pVisual->greenMask &&
                    (unsigned long)format->direct.blueMask <<
                        format->direct.blue == pVisual->blueMask) {
                    return format;
                }
            }
        }
        format++;
    }
    return 0;
}

PictFormatPtr
PictureMatchFormat(ScreenPtr pScreen, int depth, CARD32 f)
{
    PictureScreenPtr ps = GetPictureScreenIfSet(pScreen);
    PictFormatPtr format;
    int nformat;

    if (!ps)
        return 0;
    format = ps->formats;
    nformat = ps->nformats;
    while (nformat--) {
        if (format->depth == depth && format->format == (f & 0xffffff))
            return format;
        format++;
    }
    return 0;
}

int
PictureParseCmapPolicy(const char *name)
{
    if (strcmp(name, "default") == 0)
        return PictureCmapPolicyDefault;
    else if (strcmp(name, "mono") == 0)
        return PictureCmapPolicyMono;
    else if (strcmp(name, "gray") == 0)
        return PictureCmapPolicyGray;
    else if (strcmp(name, "color") == 0)
        return PictureCmapPolicyColor;
    else if (strcmp(name, "all") == 0)
        return PictureCmapPolicyAll;
    else
        return PictureCmapPolicyInvalid;
}

/** @see GetDefaultBytes */
static void
GetPictureBytes(void *value, XID id, ResourceSizePtr size)
{
    PicturePtr picture = value;

    /* Currently only pixmap bytes are reported to clients. */
    size->resourceSize = 0;

    size->refCnt = picture->refcnt;

    /* Calculate pixmap reference sizes. */
    size->pixmapRefSize = 0;
    if (picture->pDrawable && (picture->pDrawable->type == DRAWABLE_PIXMAP))
    {
        SizeType pixmapSizeFunc = GetResourceTypeSizeFunc(RT_PIXMAP);
        ResourceSizeRec pixmapSize = { 0, 0, 0 };
        PixmapPtr pixmap = (PixmapPtr)picture->pDrawable;
        pixmapSizeFunc(pixmap, pixmap->drawable.id, &pixmapSize);
        size->pixmapRefSize += pixmapSize.pixmapRefSize;
    }
}

static int
FreePictFormat(void *pPictFormat, XID pid)
{
    return Success;
}

Bool
PictureInit(ScreenPtr pScreen, PictFormatPtr formats, int nformats)
{
    PictureScreenPtr ps;
    int n;
    CARD32 type, a, r, g, b;

    if (PictureGeneration != serverGeneration) {
        PictureType = CreateNewResourceType(FreePicture, "PICTURE");
        if (!PictureType)
            return FALSE;
        SetResourceTypeSizeFunc(PictureType, GetPictureBytes);
        PictFormatType = CreateNewResourceType(FreePictFormat, "PICTFORMAT");
        if (!PictFormatType)
            return FALSE;
        GlyphSetType = CreateNewResourceType(FreeGlyphSet, "GLYPHSET");
        if (!GlyphSetType)
            return FALSE;
        PictureGeneration = serverGeneration;
    }
    if (!dixRegisterPrivateKey(&PictureScreenPrivateKeyRec, PRIVATE_SCREEN, 0))
        return FALSE;

    if (!dixRegisterPrivateKey(&PictureWindowPrivateKeyRec, PRIVATE_WINDOW, 0))
        return FALSE;

    if (!formats) {
        formats = PictureCreateDefaultFormats(pScreen, &nformats);
        if (!formats)
            return FALSE;
    }
    for (n = 0; n < nformats; n++) {
        if (!AddResource
            (formats[n].id, PictFormatType, (void *) (formats + n))) {
            int i;
            for (i = 0; i < n; i++)
                FreeResource(formats[i].id, RT_NONE);
            free(formats);
            return FALSE;
        }
        if (formats[n].type == PictTypeIndexed) {
            VisualPtr pVisual =
                PictureFindVisual(pScreen, formats[n].index.vid);
            if ((pVisual->class | DynamicClass) == PseudoColor)
                type = PICT_TYPE_COLOR;
            else
                type = PICT_TYPE_GRAY;
            a = r = g = b = 0;
        }
        else {
            if ((formats[n].direct.redMask |
                 formats[n].direct.blueMask | formats[n].direct.greenMask) == 0)
                type = PICT_TYPE_A;
            else if (formats[n].direct.red > formats[n].direct.blue)
                type = PICT_TYPE_ARGB;
            else if (formats[n].direct.red == 0)
                type = PICT_TYPE_ABGR;
            else
                type = PICT_TYPE_BGRA;
            a = Ones(formats[n].direct.alphaMask);
            r = Ones(formats[n].direct.redMask);
            g = Ones(formats[n].direct.greenMask);
            b = Ones(formats[n].direct.blueMask);
        }
        formats[n].format = PICT_FORMAT(0, type, a, r, g, b);
    }
    ps = (PictureScreenPtr) malloc(sizeof(PictureScreenRec));
    if (!ps) {
        free(formats);
        return FALSE;
    }
    SetPictureScreen(pScreen, ps);

    ps->formats = formats;
    ps->fallback = formats;
    ps->nformats = nformats;

    ps->filters = 0;
    ps->nfilters = 0;
    ps->filterAliases = 0;
    ps->nfilterAliases = 0;

    ps->subpixel = SubPixelUnknown;

    ps->CloseScreen = pScreen->CloseScreen;
    ps->DestroyWindow = pScreen->DestroyWindow;
    ps->StoreColors = pScreen->StoreColors;
    pScreen->DestroyWindow = PictureDestroyWindow;
    pScreen->CloseScreen = PictureCloseScreen;
    pScreen->StoreColors = PictureStoreColors;

    if (!PictureSetDefaultFilters(pScreen)) {
        PictureResetFilters(pScreen);
        SetPictureScreen(pScreen, 0);
        free(formats);
        free(ps);
        return FALSE;
    }

    return TRUE;
}

static void
SetPictureToDefaults(PicturePtr pPicture)
{
    pPicture->refcnt = 1;
    pPicture->repeat = 0;
    pPicture->graphicsExposures = FALSE;
    pPicture->subWindowMode = ClipByChildren;
    pPicture->polyEdge = PolyEdgeSharp;
    pPicture->polyMode = PolyModePrecise;
    pPicture->freeCompClip = FALSE;
    pPicture->componentAlpha = FALSE;
    pPicture->repeatType = RepeatNone;

    pPicture->alphaMap = 0;
    pPicture->alphaOrigin.x = 0;
    pPicture->alphaOrigin.y = 0;

    pPicture->clipOrigin.x = 0;
    pPicture->clipOrigin.y = 0;
    pPicture->clientClip = 0;

    pPicture->transform = 0;

    pPicture->filter = PictureGetFilterId(FilterNearest, -1, TRUE);
    pPicture->filter_params = 0;
    pPicture->filter_nparams = 0;

    pPicture->serialNumber = GC_CHANGE_SERIAL_BIT;
    pPicture->stateChanges = -1;
    pPicture->pSourcePict = 0;
}

PicturePtr
CreatePicture(Picture pid,
              DrawablePtr pDrawable,
              PictFormatPtr pFormat,
              Mask vmask, XID *vlist, ClientPtr client, int *error)
{
    PicturePtr pPicture;
    PictureScreenPtr ps = GetPictureScreen(pDrawable->pScreen);

    pPicture = dixAllocateScreenObjectWithPrivates(pDrawable->pScreen,
                                                   PictureRec, PRIVATE_PICTURE);
    if (!pPicture) {
        *error = BadAlloc;
        return 0;
    }

    pPicture->id = pid;
    pPicture->pDrawable = pDrawable;
    pPicture->pFormat = pFormat;
    pPicture->format = pFormat->format | (pDrawable->bitsPerPixel << 24);

    /* security creation/labeling check */
    *error = XaceHook(XACE_RESOURCE_ACCESS, client, pid, PictureType, pPicture,
                      RT_PIXMAP, pDrawable, DixCreateAccess | DixSetAttrAccess);
    if (*error != Success)
        goto out;

    if (pDrawable->type == DRAWABLE_PIXMAP) {
        ++((PixmapPtr) pDrawable)->refcnt;
        pPicture->pNext = 0;
    }
    else {
        pPicture->pNext = GetPictureWindow(((WindowPtr) pDrawable));
        SetPictureWindow(((WindowPtr) pDrawable), pPicture);
    }

    SetPictureToDefaults(pPicture);

    if (vmask)
        *error = ChangePicture(pPicture, vmask, vlist, 0, client);
    else
        *error = Success;
    if (*error == Success)
        *error = (*ps->CreatePicture) (pPicture);
 out:
    if (*error != Success) {
        FreePicture(pPicture, (XID) 0);
        pPicture = 0;
    }
    return pPicture;
}

static CARD32
xRenderColorToCard32(xRenderColor c)
{
    return
        ((unsigned)c.alpha >> 8 << 24) |
        ((unsigned)c.red >> 8 << 16) |
        ((unsigned)c.green & 0xff00) |
        ((unsigned)c.blue >> 8);
}

static void
initGradient(SourcePictPtr pGradient, int stopCount,
             xFixed * stopPoints, xRenderColor * stopColors, int *error)
{
    int i;
    xFixed dpos;

    if (stopCount <= 0) {
        *error = BadValue;
        return;
    }

    dpos = -1;
    for (i = 0; i < stopCount; ++i) {
        if (stopPoints[i] < dpos || stopPoints[i] > (1 << 16)) {
            *error = BadValue;
            return;
        }
        dpos = stopPoints[i];
    }

    pGradient->gradient.stops = xallocarray(stopCount, sizeof(PictGradientStop));
    if (!pGradient->gradient.stops) {
        *error = BadAlloc;
        return;
    }

    pGradient->gradient.nstops = stopCount;

    for (i = 0; i < stopCount; ++i) {
        pGradient->gradient.stops[i].x = stopPoints[i];
        pGradient->gradient.stops[i].color = stopColors[i];
    }
}

static PicturePtr
createSourcePicture(void)
{
    PicturePtr pPicture;

    pPicture = dixAllocateScreenObjectWithPrivates(NULL, PictureRec,
                                                   PRIVATE_PICTURE);
    if (!pPicture)
	return 0;

    pPicture->pDrawable = 0;
    pPicture->pFormat = 0;
    pPicture->pNext = 0;
    pPicture->format = PICT_a8r8g8b8;

    SetPictureToDefaults(pPicture);
    return pPicture;
}

PicturePtr
CreateSolidPicture(Picture pid, xRenderColor * color, int *error)
{
    PicturePtr pPicture;

    pPicture = createSourcePicture();
    if (!pPicture) {
        *error = BadAlloc;
        return 0;
    }

    pPicture->id = pid;
    pPicture->pSourcePict = (SourcePictPtr) malloc(sizeof(SourcePict));
    if (!pPicture->pSourcePict) {
        *error = BadAlloc;
        free(pPicture);
        return 0;
    }
    pPicture->pSourcePict->type = SourcePictTypeSolidFill;
    pPicture->pSourcePict->solidFill.color = xRenderColorToCard32(*color);
    memcpy(&pPicture->pSourcePict->solidFill.fullcolor, color, sizeof(*color));
    return pPicture;
}

PicturePtr
CreateLinearGradientPicture(Picture pid, xPointFixed * p1, xPointFixed * p2,
                            int nStops, xFixed * stops, xRenderColor * colors,
                            int *error)
{
    PicturePtr pPicture;

    if (nStops < 1) {
        *error = BadValue;
        return 0;
    }

    pPicture = createSourcePicture();
    if (!pPicture) {
        *error = BadAlloc;
        return 0;
    }

    pPicture->id = pid;
    pPicture->pSourcePict = (SourcePictPtr) malloc(sizeof(SourcePict));
    if (!pPicture->pSourcePict) {
        *error = BadAlloc;
        free(pPicture);
        return 0;
    }

    pPicture->pSourcePict->linear.type = SourcePictTypeLinear;
    pPicture->pSourcePict->linear.p1 = *p1;
    pPicture->pSourcePict->linear.p2 = *p2;

    initGradient(pPicture->pSourcePict, nStops, stops, colors, error);
    if (*error) {
        free(pPicture);
        return 0;
    }
    return pPicture;
}

PicturePtr
CreateRadialGradientPicture(Picture pid, xPointFixed * inner,
                            xPointFixed * outer, xFixed innerRadius,
                            xFixed outerRadius, int nStops, xFixed * stops,
                            xRenderColor * colors, int *error)
{
    PicturePtr pPicture;
    PictRadialGradient *radial;

    if (nStops < 1) {
        *error = BadValue;
        return 0;
    }

    pPicture = createSourcePicture();
    if (!pPicture) {
        *error = BadAlloc;
        return 0;
    }

    pPicture->id = pid;
    pPicture->pSourcePict = (SourcePictPtr) malloc(sizeof(SourcePict));
    if (!pPicture->pSourcePict) {
        *error = BadAlloc;
        free(pPicture);
        return 0;
    }
    radial = &pPicture->pSourcePict->radial;

    radial->type = SourcePictTypeRadial;
    radial->c1.x = inner->x;
    radial->c1.y = inner->y;
    radial->c1.radius = innerRadius;
    radial->c2.x = outer->x;
    radial->c2.y = outer->y;
    radial->c2.radius = outerRadius;

    initGradient(pPicture->pSourcePict, nStops, stops, colors, error);
    if (*error) {
        free(pPicture);
        return 0;
    }
    return pPicture;
}

PicturePtr
CreateConicalGradientPicture(Picture pid, xPointFixed * center, xFixed angle,
                             int nStops, xFixed * stops, xRenderColor * colors,
                             int *error)
{
    PicturePtr pPicture;

    if (nStops < 1) {
        *error = BadValue;
        return 0;
    }

    pPicture = createSourcePicture();
    if (!pPicture) {
        *error = BadAlloc;
        return 0;
    }

    pPicture->id = pid;
    pPicture->pSourcePict = (SourcePictPtr) malloc(sizeof(SourcePict));
    if (!pPicture->pSourcePict) {
        *error = BadAlloc;
        free(pPicture);
        return 0;
    }

    pPicture->pSourcePict->conical.type = SourcePictTypeConical;
    pPicture->pSourcePict->conical.center = *center;
    pPicture->pSourcePict->conical.angle = angle;

    initGradient(pPicture->pSourcePict, nStops, stops, colors, error);
    if (*error) {
        free(pPicture);
        return 0;
    }
    return pPicture;
}

static int
cpAlphaMap(void **result, XID id, ScreenPtr screen, ClientPtr client, Mask mode)
{
#ifdef PANORAMIX
    if (!noPanoramiXExtension) {
        PanoramiXRes *res;
        int err = dixLookupResourceByType((void **)&res, id, XRT_PICTURE,
                                          client, mode);
        if (err != Success)
            return err;
        id = res->info[screen->myNum].id;
    }
#endif
    return dixLookupResourceByType(result, id, PictureType, client, mode);
}

static int
cpClipMask(void **result, XID id, ScreenPtr screen, ClientPtr client, Mask mode)
{
#ifdef PANORAMIX
    if (!noPanoramiXExtension) {
        PanoramiXRes *res;
        int err = dixLookupResourceByType((void **)&res, id, XRT_PIXMAP,
                                          client, mode);
        if (err != Success)
            return err;
        id = res->info[screen->myNum].id;
    }
#endif
    return dixLookupResourceByType(result, id, RT_PIXMAP, client, mode);
}

#define NEXT_VAL(_type) (vlist ? (_type) *vlist++ : (_type) ulist++->val)

#define NEXT_PTR(_type) ((_type) ulist++->ptr)

int
ChangePicture(PicturePtr pPicture,
              Mask vmask, XID *vlist, DevUnion *ulist, ClientPtr client)
{
    ScreenPtr pScreen = pPicture->pDrawable ? pPicture->pDrawable->pScreen : 0;
    PictureScreenPtr ps = pScreen ? GetPictureScreen(pScreen) : 0;
    BITS32 index2;
    int error = 0;
    BITS32 maskQ;

    pPicture->serialNumber |= GC_CHANGE_SERIAL_BIT;
    maskQ = vmask;
    while (vmask && !error) {
        index2 = (BITS32) lowbit(vmask);
        vmask &= ~index2;
        pPicture->stateChanges |= index2;
        switch (index2) {
        case CPRepeat:
        {
            unsigned int newr;
            newr = NEXT_VAL(unsigned int);

            if (newr <= RepeatReflect) {
                pPicture->repeat = (newr != RepeatNone);
                pPicture->repeatType = newr;
            }
            else {
                client->errorValue = newr;
                error = BadValue;
            }
        }
            break;
        case CPAlphaMap:
        {
            PicturePtr pAlpha;

            if (vlist) {
                Picture pid = NEXT_VAL(Picture);

                if (pid == None)
                    pAlpha = 0;
                else {
                    error = cpAlphaMap((void **) &pAlpha, pid, pScreen,
                                       client, DixReadAccess);
                    if (error != Success) {
                        client->errorValue = pid;
                        break;
                    }
                    if (pAlpha->pDrawable == NULL ||
                        pAlpha->pDrawable->type != DRAWABLE_PIXMAP) {
                        client->errorValue = pid;
                        error = BadMatch;
                        break;
                    }
                }
            }
            else
                pAlpha = NEXT_PTR(PicturePtr);
            if (!error) {
                if (pAlpha && pAlpha->pDrawable->type == DRAWABLE_PIXMAP)
                    pAlpha->refcnt++;
                if (pPicture->alphaMap)
                    FreePicture((void *) pPicture->alphaMap, (XID) 0);
                pPicture->alphaMap = pAlpha;
            }
        }
            break;
        case CPAlphaXOrigin:
            pPicture->alphaOrigin.x = NEXT_VAL(INT16);

            break;
        case CPAlphaYOrigin:
            pPicture->alphaOrigin.y = NEXT_VAL(INT16);

            break;
        case CPClipXOrigin:
            pPicture->clipOrigin.x = NEXT_VAL(INT16);

            break;
        case CPClipYOrigin:
            pPicture->clipOrigin.y = NEXT_VAL(INT16);

            break;
        case CPClipMask:
        {
            Pixmap pid;
            PixmapPtr pPixmap;
            int clipType;

            if (!pScreen)
                return BadDrawable;

            if (vlist) {
                pid = NEXT_VAL(Pixmap);
                if (pid == None) {
                    clipType = CT_NONE;
                    pPixmap = NullPixmap;
                }
                else {
                    clipType = CT_PIXMAP;
                    error = cpClipMask((void **) &pPixmap, pid, pScreen,
                                       client, DixReadAccess);
                    if (error != Success) {
                        client->errorValue = pid;
                        break;
                    }
                }
            }
            else {
                pPixmap = NEXT_PTR(PixmapPtr);

                if (pPixmap)
                    clipType = CT_PIXMAP;
                else
                    clipType = CT_NONE;
            }

            if (pPixmap) {
                if ((pPixmap->drawable.depth != 1) ||
                    (pPixmap->drawable.pScreen != pScreen)) {
                    error = BadMatch;
                    break;
                }
                else {
                    clipType = CT_PIXMAP;
                    pPixmap->refcnt++;
                }
            }
            error = (*ps->ChangePictureClip) (pPicture, clipType,
                                              (void *) pPixmap, 0);
            break;
        }
        case CPGraphicsExposure:
        {
            unsigned int newe;
            newe = NEXT_VAL(unsigned int);

            if (newe <= xTrue)
                pPicture->graphicsExposures = newe;
            else {
                client->errorValue = newe;
                error = BadValue;
            }
        }
            break;
        case CPSubwindowMode:
        {
            unsigned int news;
            news = NEXT_VAL(unsigned int);

            if (news == ClipByChildren || news == IncludeInferiors)
                pPicture->subWindowMode = news;
            else {
                client->errorValue = news;
                error = BadValue;
            }
        }
            break;
        case CPPolyEdge:
        {
            unsigned int newe;
            newe = NEXT_VAL(unsigned int);

            if (newe == PolyEdgeSharp || newe == PolyEdgeSmooth)
                pPicture->polyEdge = newe;
            else {
                client->errorValue = newe;
                error = BadValue;
            }
        }
            break;
        case CPPolyMode:
        {
            unsigned int newm;
            newm = NEXT_VAL(unsigned int);

            if (newm == PolyModePrecise || newm == PolyModeImprecise)
                pPicture->polyMode = newm;
            else {
                client->errorValue = newm;
                error = BadValue;
            }
        }
            break;
        case CPDither:
            (void) NEXT_VAL(Atom);      /* unimplemented */

            break;
        case CPComponentAlpha:
        {
            unsigned int newca;

            newca = NEXT_VAL(unsigned int);

            if (newca <= xTrue)
                pPicture->componentAlpha = newca;
            else {
                client->errorValue = newca;
                error = BadValue;
            }
        }
            break;
        default:
            client->errorValue = maskQ;
            error = BadValue;
            break;
        }
    }
    if (ps)
        (*ps->ChangePicture) (pPicture, maskQ);
    return error;
}

int
SetPictureClipRects(PicturePtr pPicture,
                    int xOrigin, int yOrigin, int nRect, xRectangle *rects)
{
    ScreenPtr pScreen = pPicture->pDrawable->pScreen;
    PictureScreenPtr ps = GetPictureScreen(pScreen);
    RegionPtr clientClip;
    int result;

    clientClip = RegionFromRects(nRect, rects, CT_UNSORTED);
    if (!clientClip)
        return BadAlloc;
    result = (*ps->ChangePictureClip) (pPicture, CT_REGION,
                                       (void *) clientClip, 0);
    if (result == Success) {
        pPicture->clipOrigin.x = xOrigin;
        pPicture->clipOrigin.y = yOrigin;
        pPicture->stateChanges |= CPClipXOrigin | CPClipYOrigin | CPClipMask;
        pPicture->serialNumber |= GC_CHANGE_SERIAL_BIT;
    }
    return result;
}

int
SetPictureClipRegion(PicturePtr pPicture,
                     int xOrigin, int yOrigin, RegionPtr pRegion)
{
    ScreenPtr pScreen = pPicture->pDrawable->pScreen;
    PictureScreenPtr ps = GetPictureScreen(pScreen);
    RegionPtr clientClip;
    int result;
    int type;

    if (pRegion) {
        type = CT_REGION;
        clientClip = RegionCreate(RegionExtents(pRegion),
                                  RegionNumRects(pRegion));
        if (!clientClip)
            return BadAlloc;
        if (!RegionCopy(clientClip, pRegion)) {
            RegionDestroy(clientClip);
            return BadAlloc;
        }
    }
    else {
        type = CT_NONE;
        clientClip = 0;
    }

    result = (*ps->ChangePictureClip) (pPicture, type, (void *) clientClip, 0);
    if (result == Success) {
        pPicture->clipOrigin.x = xOrigin;
        pPicture->clipOrigin.y = yOrigin;
        pPicture->stateChanges |= CPClipXOrigin | CPClipYOrigin | CPClipMask;
        pPicture->serialNumber |= GC_CHANGE_SERIAL_BIT;
    }
    return result;
}

static Bool
transformIsIdentity(PictTransform * t)
{
    return ((t->matrix[0][0] == t->matrix[1][1]) &&
            (t->matrix[0][0] == t->matrix[2][2]) &&
            (t->matrix[0][0] != 0) &&
            (t->matrix[0][1] == 0) &&
            (t->matrix[0][2] == 0) &&
            (t->matrix[1][0] == 0) &&
            (t->matrix[1][2] == 0) &&
            (t->matrix[2][0] == 0) && (t->matrix[2][1] == 0));
}

int
SetPictureTransform(PicturePtr pPicture, PictTransform * transform)
{
    if (transform && transformIsIdentity(transform))
        transform = 0;

    if (transform) {
        if (!pPicture->transform) {
            pPicture->transform =
                (PictTransform *) malloc(sizeof(PictTransform));
            if (!pPicture->transform)
                return BadAlloc;
        }
        *pPicture->transform = *transform;
    }
    else {
        free(pPicture->transform);
        pPicture->transform = NULL;
    }
    pPicture->serialNumber |= GC_CHANGE_SERIAL_BIT;

    if (pPicture->pDrawable != NULL) {
        int result;
        PictureScreenPtr ps = GetPictureScreen(pPicture->pDrawable->pScreen);

        result = (*ps->ChangePictureTransform) (pPicture, transform);

        return result;
    }

    return Success;
}

static void
ValidateOnePicture(PicturePtr pPicture)
{
    if (pPicture->pDrawable &&
        pPicture->serialNumber != pPicture->pDrawable->serialNumber) {
        PictureScreenPtr ps = GetPictureScreen(pPicture->pDrawable->pScreen);

        (*ps->ValidatePicture) (pPicture, pPicture->stateChanges);
        pPicture->stateChanges = 0;
        pPicture->serialNumber = pPicture->pDrawable->serialNumber;
    }
}

void
ValidatePicture(PicturePtr pPicture)
{
    ValidateOnePicture(pPicture);
    if (pPicture->alphaMap)
        ValidateOnePicture(pPicture->alphaMap);
}

int
FreePicture(void *value, XID pid)
{
    PicturePtr pPicture = (PicturePtr) value;

    if (--pPicture->refcnt == 0) {
        free(pPicture->transform);
        free(pPicture->filter_params);

        if (pPicture->pSourcePict) {
            if (pPicture->pSourcePict->type != SourcePictTypeSolidFill)
                free(pPicture->pSourcePict->linear.stops);

            free(pPicture->pSourcePict);
        }

        if (pPicture->pDrawable) {
            ScreenPtr pScreen = pPicture->pDrawable->pScreen;
            PictureScreenPtr ps = GetPictureScreen(pScreen);

            if (pPicture->alphaMap)
                FreePicture((void *) pPicture->alphaMap, (XID) 0);
            (*ps->DestroyPicture) (pPicture);
            (*ps->DestroyPictureClip) (pPicture);
            if (pPicture->pDrawable->type == DRAWABLE_WINDOW) {
                WindowPtr pWindow = (WindowPtr) pPicture->pDrawable;
                PicturePtr *pPrev;

                for (pPrev = (PicturePtr *) dixLookupPrivateAddr
                     (&pWindow->devPrivates, PictureWindowPrivateKey);
                     *pPrev; pPrev = &(*pPrev)->pNext) {
                    if (*pPrev == pPicture) {
                        *pPrev = pPicture->pNext;
                        break;
                    }
                }
            }
            else if (pPicture->pDrawable->type == DRAWABLE_PIXMAP) {
                (*pScreen->DestroyPixmap) ((PixmapPtr) pPicture->pDrawable);
            }
        }
        dixFreeObjectWithPrivates(pPicture, PRIVATE_PICTURE);
    }
    return Success;
}

/**
 * ReduceCompositeOp is used to choose simpler ops for cases where alpha
 * channels are always one and so math on the alpha channel per pixel becomes
 * unnecessary.  It may also avoid destination reads sometimes if apps aren't
 * being careful to avoid these cases.
 */
static CARD8
ReduceCompositeOp(CARD8 op, PicturePtr pSrc, PicturePtr pMask, PicturePtr pDst,
                  INT16 xSrc, INT16 ySrc, CARD16 width, CARD16 height)
{
    Bool no_src_alpha, no_dst_alpha;

    /* Sampling off the edge of a RepeatNone picture introduces alpha
     * even if the picture itself doesn't have alpha. We don't try to
     * detect every case where we don't sample off the edge, just the
     * simplest case where there is no transform on the source
     * picture.
     */
    no_src_alpha = PICT_FORMAT_COLOR(pSrc->format) &&
        PICT_FORMAT_A(pSrc->format) == 0 &&
        (pSrc->repeatType != RepeatNone ||
         (!pSrc->transform &&
          xSrc >= 0 && ySrc >= 0 &&
          xSrc + width <= pSrc->pDrawable->width &&
          ySrc + height <= pSrc->pDrawable->height)) &&
        pSrc->alphaMap == NULL && pMask == NULL;
    no_dst_alpha = PICT_FORMAT_COLOR(pDst->format) &&
        PICT_FORMAT_A(pDst->format) == 0 && pDst->alphaMap == NULL;

    /* TODO, maybe: Conjoint and Disjoint op reductions? */

    /* Deal with simplifications where the source alpha is always 1. */
    if (no_src_alpha) {
        switch (op) {
        case PictOpOver:
            op = PictOpSrc;
            break;
        case PictOpInReverse:
            op = PictOpDst;
            break;
        case PictOpOutReverse:
            op = PictOpClear;
            break;
        case PictOpAtop:
            op = PictOpIn;
            break;
        case PictOpAtopReverse:
            op = PictOpOverReverse;
            break;
        case PictOpXor:
            op = PictOpOut;
            break;
        default:
            break;
        }
    }

    /* Deal with simplifications when the destination alpha is always 1 */
    if (no_dst_alpha) {
        switch (op) {
        case PictOpOverReverse:
            op = PictOpDst;
            break;
        case PictOpIn:
            op = PictOpSrc;
            break;
        case PictOpOut:
            op = PictOpClear;
            break;
        case PictOpAtop:
            op = PictOpOver;
            break;
        case PictOpXor:
            op = PictOpOutReverse;
            break;
        default:
            break;
        }
    }

    /* Reduce some con/disjoint ops to the basic names. */
    switch (op) {
    case PictOpDisjointClear:
    case PictOpConjointClear:
        op = PictOpClear;
        break;
    case PictOpDisjointSrc:
    case PictOpConjointSrc:
        op = PictOpSrc;
        break;
    case PictOpDisjointDst:
    case PictOpConjointDst:
        op = PictOpDst;
        break;
    default:
        break;
    }

    return op;
}

void
CompositePicture(CARD8 op,
                 PicturePtr pSrc,
                 PicturePtr pMask,
                 PicturePtr pDst,
                 INT16 xSrc,
                 INT16 ySrc,
                 INT16 xMask,
                 INT16 yMask,
                 INT16 xDst, INT16 yDst, CARD16 width, CARD16 height)
{
    PictureScreenPtr ps = GetPictureScreen(pDst->pDrawable->pScreen);

    ValidatePicture(pSrc);
    if (pMask)
        ValidatePicture(pMask);
    ValidatePicture(pDst);

    op = ReduceCompositeOp(op, pSrc, pMask, pDst, xSrc, ySrc, width, height);
    if (op == PictOpDst)
        return;

    (*ps->Composite) (op,
                      pSrc,
                      pMask,
                      pDst,
                      xSrc, ySrc, xMask, yMask, xDst, yDst, width, height);
}

void
CompositeRects(CARD8 op,
               PicturePtr pDst,
               xRenderColor * color, int nRect, xRectangle *rects)
{
    PictureScreenPtr ps = GetPictureScreen(pDst->pDrawable->pScreen);

    ValidatePicture(pDst);
    (*ps->CompositeRects) (op, pDst, color, nRect, rects);
}

void
CompositeTrapezoids(CARD8 op,
                    PicturePtr pSrc,
                    PicturePtr pDst,
                    PictFormatPtr maskFormat,
                    INT16 xSrc, INT16 ySrc, int ntrap, xTrapezoid * traps)
{
    PictureScreenPtr ps = GetPictureScreen(pDst->pDrawable->pScreen);

    ValidatePicture(pSrc);
    ValidatePicture(pDst);
    (*ps->Trapezoids) (op, pSrc, pDst, maskFormat, xSrc, ySrc, ntrap, traps);
}

void
CompositeTriangles(CARD8 op,
                   PicturePtr pSrc,
                   PicturePtr pDst,
                   PictFormatPtr maskFormat,
                   INT16 xSrc,
                   INT16 ySrc, int ntriangles, xTriangle * triangles)
{
    PictureScreenPtr ps = GetPictureScreen(pDst->pDrawable->pScreen);

    ValidatePicture(pSrc);
    ValidatePicture(pDst);
    (*ps->Triangles) (op, pSrc, pDst, maskFormat, xSrc, ySrc, ntriangles,
                      triangles);
}

void
CompositeTriStrip(CARD8 op,
                  PicturePtr pSrc,
                  PicturePtr pDst,
                  PictFormatPtr maskFormat,
                  INT16 xSrc, INT16 ySrc, int npoints, xPointFixed * points)
{
    PictureScreenPtr ps = GetPictureScreen(pDst->pDrawable->pScreen);

    if (npoints < 3)
        return;

    ValidatePicture(pSrc);
    ValidatePicture(pDst);
    (*ps->TriStrip) (op, pSrc, pDst, maskFormat, xSrc, ySrc, npoints, points);
}

void
CompositeTriFan(CARD8 op,
                PicturePtr pSrc,
                PicturePtr pDst,
                PictFormatPtr maskFormat,
                INT16 xSrc, INT16 ySrc, int npoints, xPointFixed * points)
{
    PictureScreenPtr ps = GetPictureScreen(pDst->pDrawable->pScreen);

    if (npoints < 3)
        return;

    ValidatePicture(pSrc);
    ValidatePicture(pDst);
    (*ps->TriFan) (op, pSrc, pDst, maskFormat, xSrc, ySrc, npoints, points);
}

void
AddTraps(PicturePtr pPicture, INT16 xOff, INT16 yOff, int ntrap, xTrap * traps)
{
    PictureScreenPtr ps = GetPictureScreen(pPicture->pDrawable->pScreen);

    ValidatePicture(pPicture);
    (*ps->AddTraps) (pPicture, xOff, yOff, ntrap, traps);
}
