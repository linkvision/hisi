#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "hi_type.h"
#include "hi_common.h"

#include "hi_unf_disp.h"
#include "hi_go.h"
#include "hi_go_text.h"
#include "hi_go_bliter.h"

#include "sample_cc_out.h"
#include "hi_unf_cc.h"

//#define CC_DEBUG

#ifdef CC_DEBUG
#define DBG_PRINT(fmt,args...)  printf(fmt,##args)
#else
#define DBG_PRINT(fmt,args...)
#endif

#define CC_FONT_FILE "DroidSansMono.ttf"
//#define CC_FONT_FILE "malgunbd.ttf"

#define COLOR2ARGB(a, c) (a) = ((c).u8Alpha << 24) | ((c).u8Red << 16) | ((c).u8Green << 8) | (c).u8Blue

#define INTERLINE_HEIGTH 5
#define MAX_CC_COLUMNS_4B3       32
#define MAX_CC_COLUMNS_16B9      42

static HI_HANDLE s_hccLayer = HIGO_INVALID_HANDLE;
static HI_HANDLE s_LayerSurface = HIGO_INVALID_HANDLE;
static HI_HANDLE s_hFontOutStardard= HIGO_INVALID_HANDLE;
static HI_HANDLE s_hFontOutLarge= HIGO_INVALID_HANDLE;
static HI_HANDLE s_hFontOutSmall= HIGO_INVALID_HANDLE;
static HI_HANDLE s_hCCSurface = HIGO_INVALID_HANDLE;

static HI_RECT PstRect = {0};

static HI_S32 GetUnicode_Len(HI_U32 c)
{
    HI_S32 len = 0;
    if (c < 0x80) {len = 1;}
    else if (c < 0x800) {len = 2;}
    else if (c < 0x10000) {len = 3;}
    else if (c < 0x200000) {len = 4;}
    else if (c < 0x4000000) {len = 5;}
    else {len = 6;}
    return len;
}

static HI_S32 ConvUNICODEToUTF8code( HI_U32 c, HI_U8 *outbuf)
{
    HI_U32 len ;
    HI_S32 first;
    HI_S32 i;

    if (c < 0x80) {first = 0; len = 1;}
    else if (c < 0x800) {first = 0xc0;len = 2;}
    else if (c < 0x10000) {first = 0xe0;len = 3;}
    else if (c < 0x200000) {first = 0xf0;len = 4;}
    else if (c < 0x4000000) {first = 0xf8;len = 5;}
    else {first = 0xfc;len = 6;}

    for (i = len - 1; i > 0; --i)
    {
        outbuf[i] = (c & 0x3f) | 0x80;
        c >>= 6;
    }
    outbuf[0] = c | first;

    return len;
}


static HI_S32 UTF16LE_to_UTF8(const HI_U8 *pInbuf, HI_S32 InLen,HI_U8 *pOutbuf, HI_S32 *pOutLen )
{
    const HI_U8 *in = (const HI_U8*)pInbuf;
    HI_U8 *p = pOutbuf;
    HI_U32 unicode = 0;
    HI_S32 s32Outsize = *pOutLen;
    HI_S32 s32len = 0;
    HI_S32 i = 0;
    HI_U32 tmp = 0;

    for(i = 0; i < InLen;i += 2)
    {
        if((i+1) < InLen)
        {
            unicode = in[i];
            tmp = in[i+1];
            unicode |= tmp << 8;
        }
        else
        {
            break;
        }

        s32len =  GetUnicode_Len(unicode);
        if( s32Outsize < s32len )
        {
            break;
        }
        s32Outsize -= s32len;

        p += ConvUNICODEToUTF8code(unicode,p);

    }

    *p = 0;
    *pOutLen = p - pOutbuf;

    return HI_SUCCESS;
}

static HI_U8 JustifyTranscode(HI_U8 u8justify)
{
    switch(u8justify)
    {
        case HI_UNF_CC_JUSTIFY_LEFT:
            u8justify = HIGO_LAYOUT_LEFT;
            break;
        case HI_UNF_CC_JUSTIFY_RIGHT:
            u8justify = HIGO_LAYOUT_RIGHT;
            break;
        case HI_UNF_CC_JUSTIFY_CENTER:
            u8justify = HIGO_LAYOUT_HCENTER;
            break;
        case HI_UNF_CC_JUSTIFY_FULL:
            u8justify = HIGO_LAYOUT_HCENTER;
            break;
        default:
            u8justify = HIGO_LAYOUT_LEFT;
            break;
    }
    return u8justify;
}

static HI_U8 ReverseChar(HI_U8 Data)
{
    HI_U8 b0,b1,b2,b3,b4,b5,b6,b7;
    HI_U8  Reversed;

    b0 = (Data >> 0) & 0x1 ;
    b1 = (Data >> 1) & 0x1 ;
    b2 = (Data >> 2) & 0x1 ;
    b3 = (Data >> 3) & 0x1 ;
    b4 = (Data >> 4) & 0x1 ;
    b5 = (Data >> 5) & 0x1 ;
    b6 = (Data >> 6) & 0x1 ;
    b7 = (Data >> 7) & 0x1 ;
    Reversed = (b7 << 0)
             | (b6 << 1)
             | (b5 << 2)
             | (b4 << 3)
             | (b3 << 4)
             | (b2 << 5)
             | (b1 << 6)
             | (b0 << 7);
    return(Reversed);
}


static HI_S32 HigoInit()
{
    HI_S32 s32Ret = 0;
    HIGO_LAYER_INFO_S stLayerInfo = {0};
    HIGO_TEXT_INFO_S stFontInfo;

    s32Ret = HI_GO_Init();
    if (HI_SUCCESS != s32Ret)
    {
        printf("failed to init higo! ret = 0x%x !\n", s32Ret);
        return HI_FAILURE;
    }
#ifdef CHIP_TYPE_hi3110ev500
    HI_GO_GetLayerDefaultParam(HIGO_LAYER_SD_0, &stLayerInfo);
#else
    HI_GO_GetLayerDefaultParam(HIGO_LAYER_HD_0, &stLayerInfo);
#endif
    stLayerInfo.LayerFlushType = HIGO_LAYER_FLUSH_NORMAL;
    stLayerInfo.PixelFormat = HIGO_PF_1555;//HIGO_PF_8888;
    s32Ret = HI_GO_CreateLayer(&stLayerInfo, &s_hccLayer);

    if (HI_SUCCESS != s32Ret)
    {
        printf( "failed to create the layer hd 0, ret = 0x%x !\n", s32Ret);
        goto RET;
    }

    s32Ret =  HI_GO_GetLayerSurface(s_hccLayer, &s_LayerSurface);

    if (HI_SUCCESS != s32Ret)
    {
        printf( "failed to get layer surface! s32Ret = 0x%x !\n", s32Ret);
        goto RET;
    }


    (HI_VOID)HI_GO_FillRect(s_LayerSurface, NULL, 0x00000000, HIGO_COMPOPT_NONE);

    stFontInfo.pMbcFontFile = HI_NULL;
    stFontInfo.pSbcFontFile = CC_FONT_FILE;
    stFontInfo.u32Size = 20;

    if(HI_SUCCESS != HI_GO_CreateTextEx(&stFontInfo, &s_hFontOutStardard))
    {
        printf( "failed to create the stardard font:%s !ret =0x%x\n",CC_FONT_FILE,s32Ret);
        goto RET;
    }
    HI_GO_SetInputCharSet(s_hFontOutStardard,HIGO_CHARSET_UTF8);

    stFontInfo.u32Size = 24;
    if(HI_SUCCESS != HI_GO_CreateTextEx(&stFontInfo, &s_hFontOutLarge))
    {
        printf( "failed to create the large font:%s !ret =0x%x\n",CC_FONT_FILE,s32Ret);
        goto RET;
    }
    HI_GO_SetInputCharSet(s_hFontOutLarge,HIGO_CHARSET_UTF8);

    stFontInfo.u32Size = 14;
    if(HI_SUCCESS != HI_GO_CreateTextEx(&stFontInfo, &s_hFontOutSmall))
    {
        printf( "failed to create the small font:%s !ret =0x%x\n",CC_FONT_FILE,s32Ret);
        goto RET;
    }
    HI_GO_SetInputCharSet(s_hFontOutSmall,HIGO_CHARSET_UTF8);

    return HI_SUCCESS;

RET:
    if (HIGO_INVALID_HANDLE != s_hccLayer)
    {
        (HI_VOID)HI_GO_DestroyLayer(s_hccLayer);
        s_hccLayer = HIGO_INVALID_HANDLE;
    }

    if (HIGO_INVALID_HANDLE != s_hFontOutStardard)
    {
        (HI_VOID)HI_GO_DestroyText(s_hFontOutStardard);
        s_hFontOutStardard = HIGO_INVALID_HANDLE;
    }

    if (HIGO_INVALID_HANDLE != s_hFontOutLarge)
    {
        (HI_VOID)HI_GO_DestroyText(s_hFontOutLarge);
        s_hFontOutLarge = HIGO_INVALID_HANDLE;
    }

    if (HIGO_INVALID_HANDLE != s_hFontOutSmall)
    {
        (HI_VOID)HI_GO_DestroyText(s_hFontOutSmall);
        s_hFontOutSmall = HIGO_INVALID_HANDLE;
    }

    s_LayerSurface = HIGO_INVALID_HANDLE;

    (HI_VOID)HI_GO_Deinit();

    return HI_FAILURE;
}


static HI_S32 HigoDeInit()
{
    if (HIGO_INVALID_HANDLE != s_hCCSurface)
    {
        (HI_VOID)HI_GO_FreeSurface(s_hCCSurface);
        s_hCCSurface = HIGO_INVALID_HANDLE;
    }

    if (HIGO_INVALID_HANDLE != s_hccLayer)
    {
        (HI_VOID)HI_GO_DestroyLayer(s_hccLayer);
        s_hccLayer = HIGO_INVALID_HANDLE;
    }
    if (HIGO_INVALID_HANDLE != s_hFontOutStardard)
    {
        (HI_VOID)HI_GO_DestroyText(s_hFontOutStardard);
        s_hFontOutStardard = HIGO_INVALID_HANDLE;
    }
    if (HIGO_INVALID_HANDLE != s_hFontOutLarge)
    {
        (HI_VOID)HI_GO_DestroyText(s_hFontOutLarge);
        s_hFontOutLarge = HIGO_INVALID_HANDLE;
    }
    if (HIGO_INVALID_HANDLE != s_hFontOutSmall)
    {
        (HI_VOID)HI_GO_DestroyText(s_hFontOutSmall);
        s_hFontOutSmall = HIGO_INVALID_HANDLE;
    }
    s_LayerSurface = HIGO_INVALID_HANDLE;

    (HI_VOID)HI_GO_Deinit();

    return HI_SUCCESS;
}

HI_S32 CC_Output_Init(HI_HANDLE* phOut)
{
    HI_S32 s32Ret = HI_SUCCESS;

    if (HIGO_INVALID_HANDLE == s_LayerSurface)
    {
        s32Ret = HigoInit();
    }

    *phOut = 0xFE00;

    return s32Ret;
}

HI_S32 CC_Output_DeInit(HI_HANDLE hOut)
{
    HI_S32 s32Ret = HI_SUCCESS;
    if (HIGO_INVALID_HANDLE != s_LayerSurface)
    {
        s32Ret = HigoDeInit();
    }

    return s32Ret;
}

HI_S32 CC_Output_OnDraw(HI_U32 u32UserData, HI_UNF_CC_DISPLAY_PARAM_S *pstDisplayParam)
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_S32 s32SurfaceWidth = 0, s32SurfaceHeight = 0;
    HI_RECT SrcRect = {0};
    HIGO_BLTOPT_S stBlitOpt;

    if(NULL == pstDisplayParam)
    {
        return HI_FAILURE;
    }

    SrcRect.x = pstDisplayParam->stRect.x;
    SrcRect.y = pstDisplayParam->stRect.y;
    SrcRect.w = pstDisplayParam->stRect.width;
    SrcRect.h = pstDisplayParam->stRect.height;

    if (HIGO_INVALID_HANDLE == s_hCCSurface)
    {
        DBG_PRINT("DisplayWidth : %d, DisplayHeight : %d\n", pstDisplayParam->u32DisplayWidth, pstDisplayParam->u32DisplayHeight);
        (HI_VOID)HI_GO_CreateSurface(pstDisplayParam->u32DisplayWidth,pstDisplayParam->u32DisplayHeight,
                                     HIGO_PF_1555/*HIGO_PF_8888*/,&s_hCCSurface);
        (HI_VOID)HI_GO_FillRect(s_hCCSurface, HI_NULL, 0x00000000, HIGO_COMPOPT_NONE);
    }
    else
    {
        (HI_VOID)HI_GO_GetSurfaceSize(s_hCCSurface, &s32SurfaceWidth, &s32SurfaceHeight);
        if(s32SurfaceWidth != pstDisplayParam->u32DisplayWidth
            || s32SurfaceHeight != pstDisplayParam->u32DisplayHeight)
        {
            DBG_PRINT("DisplayWidth : %d, DisplayHeight : %d\n", pstDisplayParam->u32DisplayWidth, pstDisplayParam->u32DisplayHeight);
            (HI_VOID)HI_GO_FreeSurface(s_hCCSurface);
            (HI_VOID)HI_GO_CreateSurface(pstDisplayParam->u32DisplayWidth,pstDisplayParam->u32DisplayHeight,
                                         HIGO_PF_1555/*HIGO_PF_8888*/,&s_hCCSurface);
            (HI_VOID)HI_GO_FillRect(s_hCCSurface, HI_NULL, 0x00000000, HIGO_COMPOPT_NONE);
        }
    }

    switch (pstDisplayParam->enOpt)
    {

    case HI_UNF_CC_OPT_DRAWTEXT:
    {
        HI_U8 *pu8InBuf = (HI_U8 *)pstDisplayParam->unDispParam.stText.pu16Text;
        HI_S32 s32InLen = pstDisplayParam->unDispParam.stText.u8TextLen * 2;
        HI_U8  pu8OutBuf[128];
        HI_S32 s32OutLen = sizeof(pu8OutBuf);
        HI_U32 u32bgColor,u32fgColor;
        HI_U8  u8justify = pstDisplayParam->unDispParam.stText.u8Justify;
        HI_U8  u8WordWrap = pstDisplayParam->unDispParam.stText.u8WordWrap;
        HI_U8  u8fontstyle = pstDisplayParam->unDispParam.stText.enFontStyle;
        HIGO_LAYOUT_E enlayout;

        s32Ret = UTF16LE_to_UTF8(pu8InBuf,s32InLen,pu8OutBuf,&s32OutLen);
        if (HI_SUCCESS != s32Ret)
        {
            printf("failed to UTF16LE_to_UTF8,ret = %x\n",s32Ret);
        }

        //u32BufLen = (HI_U32)s32OutLen;
        DBG_PRINT("\ns32InLen: [%d]\n",s32InLen);
        DBG_PRINT("\nOnDraw : [%d,%s]\n",s32OutLen,pu8OutBuf);

        HI_HANDLE hFontOut;
        if(pstDisplayParam->unDispParam.stText.enFontSize == HI_UNF_CC_FONTSIZE_LARGE)
        {
            hFontOut = s_hFontOutLarge;
         }
        else if(pstDisplayParam->unDispParam.stText.enFontSize == HI_UNF_CC_FONTSIZE_SMALL)
        {
            hFontOut = s_hFontOutSmall;
        }
        else
        {
            hFontOut = s_hFontOutStardard;
        }
        COLOR2ARGB(u32bgColor, pstDisplayParam->unDispParam.stText.stBgColor);
        COLOR2ARGB(u32fgColor, pstDisplayParam->unDispParam.stText.stFgColor);
		
		#if 1
        {
            HI_U32 i = 0;
            for(i = 0; i < s32OutLen; i++)
            {
                if(*(pu8OutBuf + i) != 0x20)
                {
                    break;
                }
            }
            if(i >= s32OutLen)
            {
			     SrcRect.y -=1;
                 SrcRect.h +=1;
                (HI_VOID)HI_GO_FillRect(s_hCCSurface, &SrcRect, u32bgColor, HIGO_COMPOPT_NONE);

                memset(&stBlitOpt, 0, sizeof(HIGO_BLTOPT_S));
                stBlitOpt.EnableScale = HI_TRUE;
                (HI_VOID)HI_GO_Blit (s_hCCSurface, HI_NULL,
                                     s_LayerSurface, HI_NULL,
                                     &stBlitOpt);
                (HI_VOID)HI_GO_RefreshLayer(s_hccLayer, NULL);
				 break;
            }
        }
		#endif
		
        HI_GO_SetTextColor(hFontOut, u32fgColor);
        HI_GO_SetTextBGColor(hFontOut, u32bgColor);

        if(0 == pstDisplayParam->unDispParam.stText.stBgColor.u8Alpha)
        {
            (HI_VOID)HI_GO_SetTextBGTransparent(hFontOut, HI_TRUE);
        }
        else
        {
            (HI_VOID)HI_GO_SetTextBGTransparent(hFontOut, HI_FALSE);
        }

        DBG_PRINT("u32bgColor:%#x\n",u32bgColor);
        DBG_PRINT("u32fgColor:%#x\n",u32fgColor);

        enlayout = JustifyTranscode(u8justify);

        if(u8WordWrap)
        {
            enlayout = enlayout | HIGO_LAYOUT_WRAP;
        }

        if((u8fontstyle ==  HI_UNF_CC_FONTSTYLE_ITALIC)||(u8fontstyle == HI_UNF_CC_FONTSTYLE_ITALIC_UNDERLINE))
        {
            HI_GO_SetTextStyle(hFontOut,HIGO_TEXT_STYLE_ITALIC);
        }
        else
        {
            HI_GO_SetTextStyle(hFontOut,HIGO_TEXT_STYLE_NORMAL);
        }

        DBG_PRINT("Text Rect[%d %d %d %d]\n\n",SrcRect.x,SrcRect.y,SrcRect.w,SrcRect.h);

        s32Ret = HI_GO_TextOutEx(hFontOut, s_hCCSurface, (HI_CHAR *)pu8OutBuf, &SrcRect, enlayout);
        if (HI_SUCCESS != s32Ret)
        {
            printf("failed to text out char!,ret = %x\n",s32Ret);
        }

        memset(&stBlitOpt, 0, sizeof(HIGO_BLTOPT_S));
        stBlitOpt.EnableScale = HI_TRUE;
        (HI_VOID)HI_GO_Blit (s_hCCSurface, HI_NULL,
                   s_LayerSurface, HI_NULL,
                   &stBlitOpt);
        (HI_VOID)HI_GO_RefreshLayer(s_hccLayer, HI_NULL);

        break;
    }
    case HI_UNF_CC_OPT_FILLRECT:
    {
        HI_U32 u32Color;

        COLOR2ARGB(u32Color, pstDisplayParam->unDispParam.stFillRect.stColor);

        DBG_PRINT("\nFillRect, u32Color:%#x, Rect[%d %d %d %d]\n\n",u32Color, SrcRect.x,SrcRect.y,SrcRect.w,SrcRect.h);

        PstRect.x = SrcRect.x ;
        PstRect.y = SrcRect.y ;
        PstRect.w = SrcRect.w ;
        PstRect.h = SrcRect.h ;

        (HI_VOID)HI_GO_FillRect(s_hCCSurface, &SrcRect, u32Color,HIGO_COMPOPT_NONE);

        memset(&stBlitOpt, 0, sizeof(HIGO_BLTOPT_S));
        stBlitOpt.EnableScale = HI_TRUE;
        (HI_VOID)HI_GO_Blit (s_hCCSurface, HI_NULL,
                   s_LayerSurface, HI_NULL,
                   &stBlitOpt);
        (HI_VOID)HI_GO_RefreshLayer(s_hccLayer, NULL);

         break;
    }
    case HI_UNF_CC_OPT_DRAWBITMAP:
    default:
        printf("Not implement\n");
        break;

    }

    return s32Ret;
}

HI_S32 CC_Output_GetTextSize(HI_U32 u32Userdata, HI_U16 *u16Str,HI_S32 s32StrNum, HI_S32 *ps32Width, HI_S32 *ps32Heigth)
{
    HI_S32 s32Ret = HI_SUCCESS;

    HI_U8 *pu8InBuf = (HI_U8 *)u16Str;
    HI_S32 s32InLen = s32StrNum * 2;
    HI_U8 pu8OutBuf[128];
    HI_S32 s32OutLen = sizeof(pu8OutBuf);
    if((NULL == u16Str) || (0 == s32StrNum) || (NULL == ps32Width) || (NULL == ps32Heigth))
    {
        return HI_FAILURE;
    }

    *ps32Width = *ps32Heigth = 0;
    s32Ret = UTF16LE_to_UTF8(pu8InBuf,s32InLen,pu8OutBuf,&s32OutLen);
    if (HI_SUCCESS != s32Ret)
    {
        printf("failed to UTF16LE_to_UTF8,ret = %x\n",s32Ret);
    }
    s32Ret = HI_GO_GetTextExtent(s_hFontOutStardard, (const HI_CHAR*)pu8OutBuf, ps32Width, ps32Heigth);
    if (HI_SUCCESS != s32Ret)
    {
        printf("failed to HI_GO_GetTextExtent,ret = %x\n",s32Ret);
    }
    return  HI_SUCCESS;
}

HI_S32 CC_Output_Blit(HI_U32 u32UserPrivatData, HI_UNF_CC_RECT_S *pstSrcRect, HI_UNF_CC_RECT_S *pstDestRect)
{
    HIGO_BLTOPT_S stBlitOpt;
    HI_RECT stSrcRect = {0, 0, 0, 0};
    HI_RECT stDstRect = {0, 0, 0, 0};

    if(NULL == pstSrcRect || NULL == pstDestRect)
    {
        return HI_FAILURE;
    }
    if (HIGO_INVALID_HANDLE == s_hCCSurface)
    {
        //printf("Surface has not create!\n");
        return HI_SUCCESS;
    }
    stSrcRect.x = pstSrcRect->x;
    stSrcRect.y = pstSrcRect->y;
    stSrcRect.w = pstSrcRect->width;
    stSrcRect.h = pstSrcRect->height;

    stDstRect.x = pstDestRect->x;
    stDstRect.y = pstDestRect->y;
    stDstRect.w = pstDestRect->width;
    stDstRect.h = pstDestRect->height;

    DBG_PRINT("Blit:[%d,%d,%d,%d]->[%d,%d,%d,%d]\n",stSrcRect.x,stSrcRect.y,stSrcRect.w,stSrcRect.h,stDstRect.x,stDstRect.y,stDstRect.w,stDstRect.h);
    (HI_VOID)HI_GO_Blit (s_hCCSurface, &stSrcRect,s_hCCSurface, &stDstRect, HI_NULL);

    memset(&stBlitOpt, 0, sizeof(HIGO_BLTOPT_S));
    stBlitOpt.EnableScale = HI_TRUE;
    (HI_VOID)HI_GO_Blit (s_hCCSurface, HI_NULL, s_LayerSurface, HI_NULL ,&stBlitOpt);
    (HI_VOID)HI_GO_RefreshLayer(s_hccLayer, HI_NULL);
    return HI_SUCCESS;
}

HI_S32 CC_Output_VBIOutput(HI_U32 u32UserData, HI_UNF_CC_VBI_DADA_S *pstVBIDataField1, HI_UNF_CC_VBI_DADA_S *pstVBIDataField2)
{
    HI_S32 Ret = HI_SUCCESS;
    HI_U8 buf[25] = {0x00,0x00,0x01,0xbd,0x00,0x13,0x8f,0x80,0x05,0x21,0x25,0xb5,0xf1,0x27,0x99,0xc5,
                                      0x03,0x00,0x00,0x00,0xc5,0x03,0x00,0x00,0x00};
    
    HI_UNF_DISP_VBI_DATA_S stVBIData = {0};

    buf[17] = 0xf5;
    buf[18] = ReverseChar(pstVBIDataField1->u8Data1);
    buf[19] = ReverseChar(pstVBIDataField1->u8Data2);

    buf[22] = 0xd5;
    buf[23] = ReverseChar(pstVBIDataField2->u8Data1);
    buf[24] = ReverseChar(pstVBIDataField2->u8Data2);

    if ((buf[18] == 0) && (buf[19] == 0)) //顶场数据为0
    {
        if ((buf[23] != 0) || (buf[24] != 0)) //底场数据不为0，只传底场
        {
            buf[17] = buf[22];
            buf[18] = buf[23];
            buf[19] = buf[24];

            buf[20] = 0xff; //0xc5->0xff
            buf[21] = 0x0; //0x03->0x0
        }
    }
    else if ((buf[23] == 0) && (buf[24] == 0)) //顶场数据不为0，底场数据为0，只传顶场
    {
        buf[20] = 0xff; //0xc5->0xff
        buf[21] = 0x0; //0x03->0x0
    }

    stVBIData.pu8DataAddr = buf;
    stVBIData.u32DataLen = sizeof(buf);

    Ret = HI_UNF_DISP_SendVbiData(HI_UNF_DISP_SD0,&stVBIData);

    return Ret;

}
