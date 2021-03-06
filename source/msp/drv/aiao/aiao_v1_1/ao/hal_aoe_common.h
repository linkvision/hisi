/*********************************************************************************
*
*  Copyright (C) 2014 Hisilicon Technologies Co., Ltd.  All rights reserved. 
*
*  This program is confidential and proprietary to Hisilicon Technologies Co., Ltd.
*  (Hisilicon), and may not be copied, reproduced, modified, disclosed to
*  others, published or used, in whole or in part, without the express prior
*  written permission of Hisilicon.
*
***********************************************************************************
File Name     : hal_aoe_common.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2012/09/22
Last Modified :
Description   : hal_aoe
Function List :
History       :
* main\1    2013-03-11   zgjie     init.
******************************************************************************/
#ifndef __HI_HAL_AOE_COMMON_H__
#define __HI_HAL_AOE_COMMON_H__

#include "hi_type.h"
#include "hi_audsp_aoe.h"



/* AOE AIP Definition */
typedef enum
{
    AOE_AIP0  = 0x00,
    AOE_AIP1  = 0x01,
    AOE_AIP2  = 0x02,
    AOE_AIP3  = 0x03,
    AOE_AIP4  = 0x04,
    AOE_AIP5  = 0x05,
    AOE_AIP6  = 0x06,
    AOE_AIP7  = 0x07,

    AOE_AIP_BUTT = AOE_MAX_AIP_NUM,
} AOE_AIP_ID_E;

/* AOE AOP Definition */
typedef enum
{
    AOE_AOP0 = 0x00,
    AOE_AOP1 = 0x01,
    AOE_AOP2 = 0x02,
    AOE_AOP3 = 0x03,
    AOE_AOP4 = 0x04,
    AOE_AOP5 = 0x05,
    AOE_AOP6 = 0x06,
    AOE_AOP7 = 0x07,

    AOE_AOP_BUTT = AOE_MAX_AOP_NUM,
} AOE_AOP_ID_E;

/* AOE ENGINE Definition */
typedef enum
{
    AOE_ENGINE0 = 0x00,
    AOE_ENGINE1 = 0x01,
    AOE_ENGINE2 = 0x02,
    AOE_ENGINE3 = 0x03,
    AOE_ENGINE4 = 0x04,
    AOE_ENGINE5 = 0x05,

    AOE_ENGINE_BUTT = AOE_MAX_ENGINE_NUM,
} AOE_ENGINE_ID_E;

/**Defines the  status of an AIP.*/
typedef enum
{
    AOE_AIP_STATUS_STOP = 0, /**<Stop*//**<CNcomment: 停止 */
    AOE_AIP_STATUS_START, /**<Start*//**<CNcomment: 运行 */
    AOE_AIP_STATUS_PAUSE,

    AIP_STATUS_BUTT
} AOE_AIP_STATUS_E;

/**Defines the  status of an AOP.*/
typedef enum
{
    AOE_AOP_STATUS_STOP = 0, /**<Stop*//**<CNcomment: 停止 */
    AOE_AOP_STATUS_START, /**<Start*//**<CNcomment: 运行 */

    AOE_AOP_STATUS_BUTT
} AOE_AOP_STATUS_E;

/**Defines the  status of an Engine.*/
typedef enum
{
    AOE_ENGINE_STATUS_STOP = 0, /**<Stop*//**<CNcomment: 停止 */
    AOE_ENGINE_STATUS_START, /**<Start*//**<CNcomment: 运行 */

    AOE_ENGINE_STATUS_BUTT
} AOE_ENGINE_STATUS_E;

typedef struct
{
    HI_U32  u32BufPhyAddr;  // hw aoe
    HI_U32  u32BufPhyWptr;  // hw aoe
    HI_U32  u32BufPhyRptr;  // hw aoe 
    HI_U32  u32BufVirAddr;  // sw aoe
    HI_U32  u32BufVirWptr;  // sw aoe
    HI_U32  u32BufVirRptr;  // sw aoe
    HI_U32  u32BufWptrRptrFlag;  /* 0: u32BufWptr & u32BufRptr located at AIP Reg, else: */
    HI_U32  u32BufSize;
} AOE_RBUF_ATTR_S;

typedef struct
{
    AOE_RBUF_ATTR_S stRbfAttr;
    HI_U32 u32BufBitPerSample; /**<I/O, bit per sampling*//**<CNcomment:OUT. Bit per sample */
    HI_U32 u32BufChannels; /**<I/O, number of channels*//**<CNcomment:OUT. 输出声道数  */
    HI_U32 u32BufSampleRate; /**<I/O, sampling rate*//**<CNcomment:OUT. 输出采样频率 */
    HI_U32 u32BufDataFormat;          /**<I/O, 0, linear pcm, 1, iec61937 */
    HI_U32 u32BufLatencyThdMs;   /* 40 ~ 1000 ms */
    HI_U32  u32FadeinMs;
    HI_U32  u32FadeoutMs;
    HI_BOOL bFadeEnable;
    HI_BOOL bAlsaEnable;  
    HI_BOOL bMixPriority;  /* TRUE: high priority */

} AOE_AIP_INBUF_ATTR_S;

typedef struct
{
    HI_U32 u32FifoBitPerSample; /**<I/O, bit per sampling*/ /**<CNcomment:OUT. Bit per sample */
    HI_U32 u32FifoChannels; /**<I/O, number of channels*/ /**<CNcomment:OUT. 输出声道数  */
    HI_U32 u32FifoSampleRate; /**<I/O, sampling rate*/ /**<CNcomment:OUT. 输出采样频率 */
    HI_U32 u32FifoDataFormat;               /**<I/O, 0, linear pcm, 1, iec61937 */
    HI_U32 u32FiFoLatencyThdMs; /* 10 ~ 40 ms */
} AOE_AIP_OUTFIFO_ATTR_S;

typedef struct
{
    AOE_AIP_INBUF_ATTR_S   stBufInAttr;   
    AOE_AIP_OUTFIFO_ATTR_S stFifoOutAttr;
} AOE_AIP_CHN_ATTR_S;

typedef struct
{
    AOE_RBUF_ATTR_S stRbfAttr;
    HI_U32  u32BufBitPerSample; /**<I/O, bit per sampling*//**<CNcomment:OUT. Bit per sample */
    HI_U32  u32BufChannels; /**<I/O, number of channels*//**<CNcomment:OUT. 输出声道数  */
    HI_U32  u32BufSampleRate; /**<I/O, sampling rate*//**<CNcomment:OUT. 输出采样频率 */
    HI_U32  u32BufDataFormat;          /**<I/O, 0, linear pcm, 1, iec61937 */
    HI_U32  u32BufLatencyThdMs;        /* 10 ~ 40 ms */
    HI_BOOL bRbfHwPriority; /* TRUE: high priority */
} AOE_AOP_OUTBUF_ATTR_S;


typedef struct
{
    AOE_AOP_OUTBUF_ATTR_S stRbfOutAttr;
} AOE_AOP_CHN_ATTR_S;

typedef struct
{
    HI_U32 u32BitPerSample; /**<I/O, bit per sampling*/ /**<CNcomment:OUT. Bit per sample */
    HI_U32 u32Channels; /**<I/O, number of channels*/ /**<CNcomment:OUT. 输出声道数  */
    HI_U32 u32SampleRate; /**<I/O, sampling rate*/ /**<CNcomment:OUT. 输出采样频率 */
    HI_U32 u32DataFormat;               /**<I/O, 0, linear pcm, 1, iec61937 */
} AOE_ENGINE_CHN_ATTR_S;

typedef struct
{
    HI_BOOL bPreGainEn;
    HI_U32 u32PreGainInt;  /**< prescale integer part, ranging from 0x28 to 0x8B, 0x28 is mute, 0x78 is -1dB, 0x79 is 0dB, 0x8B is 18dB*/
    HI_S32 s32PreGainDec;  /**< prescale decimal part, step 0.125dB, 1 is 0.125dB, 2 is 0.250dB, -1 is -0.125dB*/
} SND_ENGINE_PREGAIN_S;
#endif  // __HI_HAL_AOE_COMMON_H__
