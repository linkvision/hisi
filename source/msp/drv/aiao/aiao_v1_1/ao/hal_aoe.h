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
File Name     : hal_aoe.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2013/03/09
Last Modified :
Description   : hal_aoe
Function List :
History       :
* main\1    2012-03-09  zgjie     init.
******************************************************************************/
#ifndef __HI_HAL_AOE_H__
#define __HI_HAL_AOE_H__

#include "hi_type.h"
#include "hi_audsp_common.h"
#include "hal_aoe_common.h"
#include "hi_unf_sound.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/***************************** Macro Definition ******************************/
#define AOE_AIP_BUFF_LATENCYMS_MIN 10
#define AOE_AIP_FIFO_LATENCYMS_MIN 10
#define AOE_AOP_BUFF_LATENCYMS_MIN 10

#define AOE_AOP_BUFF_LATENCYMS_DF  (AOE_AOP_BUFF_LATENCYMS_MIN*10)
#define AOE_AOP_BUFF_LATENCYMS_MAX (AOE_AOP_BUFF_LATENCYMS_MIN*12)
#define AOE_CAST_BUFF_LATENCYMS_MAX (512)

#define AO_DAC_MMZSIZE_MAX    ((48000*2*sizeof(HI_U16)/1000)*AOE_AOP_BUFF_LATENCYMS_MAX)
#define AO_I2S_MMZSIZE_MAX    ((48000*2*sizeof(HI_U16)/1000)*AOE_AOP_BUFF_LATENCYMS_MAX)
#define AO_SPDIF_MMZSIZE_MAX  ((48000*2*sizeof(HI_U16)/1000)*AOE_AOP_BUFF_LATENCYMS_MAX)
#define AO_HDMI_SPDIF_MMZSIZE_MAX  ((192000*2*sizeof(HI_U16)/1000)*AOE_AOP_BUFF_LATENCYMS_MAX)
#define AO_HDMI_MMZSIZE_MAX   ((192000*8*sizeof(HI_U32)/1000)*AOE_AOP_BUFF_LATENCYMS_MAX)
#define AO_CAST_MMZSIZE_MAX   ((48000*2*sizeof(HI_U16)/1000)*AOE_CAST_BUFF_LATENCYMS_MAX)

static inline HI_U32 CALC_LATENCY_MS(HI_U32 Rate, HI_U32 FrameSize, HI_U32 Byte)
{
    if (Rate && FrameSize)
    {
        return (1000 * Byte) / (Rate * FrameSize);
    }
    else
    {
        return 0;
    }
}

/* global function */
HI_S32                  HAL_AOE_Init(HI_BOOL bSwAoeFlag);
HI_VOID                 HAL_AOE_DeInit(HI_VOID);

/* AIP function */
HI_S32                  HAL_AOE_AIP_Create(AOE_AIP_ID_E* penAIP, AOE_AIP_CHN_ATTR_S* pstAttr);
HI_VOID                 HAL_AOE_AIP_Destroy(AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_AIP_SetAttr(AOE_AIP_ID_E enAIP, AOE_AIP_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_AIP_GetAttr(AOE_AIP_ID_E enAIP, AOE_AIP_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_AIP_Start(AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_AIP_Stop(AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_AIP_Group_Stop(HI_U32 u32StopMask);                     //only used for master track type
HI_S32                  HAL_AOE_AIP_Pause(AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_AIP_Flush(AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_AIP_SetSpeed(AOE_AIP_ID_E enAIP, HI_S32 s32AdjSpeed);
HI_U32                  HAL_AOE_AIP_WriteBufData(AOE_AIP_ID_E enAIP, HI_U8* pu32Src, HI_U32 u32SrcBytes);
HI_U32                  HAL_AOE_AIP_QueryBufData(AOE_AIP_ID_E enAIP);
HI_U32                  HAL_AOE_AIP_QueryBufFree(AOE_AIP_ID_E enAIP);
HI_VOID                 HAL_AOE_AIP_GetBufDelayMs(AOE_AIP_ID_E enAIP, HI_U32* pDelayms);  // for aip buf delay
HI_VOID                 HAL_AOE_AIP_GetFiFoDelayMs(AOE_AIP_ID_E enAIP, HI_U32* pDelayms); // for aip fifo delay
HI_VOID                 HAL_AOE_AIP_GetStatus(AOE_AIP_ID_E enAIP, AOE_AIP_STATUS_E* peStatus);
HI_S32                  HAL_AOE_AIP_SetLRVolume(AOE_AIP_ID_E enAIP, HI_U32 u32VolumeLdB, HI_U32 u32RVolumeRdB);
HI_S32                  HAL_AOE_AIP_SetMute(AOE_AIP_ID_E enAIP, HI_BOOL bMute);
HI_S32                  HAL_AOE_AIP_SetChannelMode(AOE_AIP_ID_E enAIP, HI_U32 u32ChannelMode);
HI_VOID                 HAL_AOE_AIP_SetDataSource(AOE_AIP_ID_E enAIP, HI_BOOL bDataFromKernel);

/* AOP function */
HI_S32                  HAL_AOE_AOP_SetMute(AOE_AOP_ID_E enAOP, HI_BOOL bMute);
HI_S32                  HAL_AOE_AOP_SetLRVolume(AOE_AOP_ID_E enAOP, HI_U32 u32VolumeLdB, HI_U32 u32VolumeRdB);
HI_S32                  HAL_AOE_AOP_Create(AOE_AOP_ID_E* penAOP, AOE_AOP_CHN_ATTR_S* pstAttr);
HI_VOID                 HAL_AOE_AOP_Destroy(AOE_AOP_ID_E enAOP);
HI_S32                  HAL_AOE_AOP_SetAttr(AOE_AOP_ID_E enAOP, AOE_AOP_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_AOP_GetAttr(AOE_AOP_ID_E enAOP, AOE_AOP_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_AOP_Start(AOE_AOP_ID_E enAOP);
HI_S32                  HAL_AOE_AOP_Stop(AOE_AOP_ID_E enAOP);

/* ENGINE function */
HI_S32                  HAL_AOE_ENGINE_Create(AOE_ENGINE_ID_E* penENGINE, AOE_ENGINE_CHN_ATTR_S* pstAttr);
HI_VOID                 HAL_AOE_ENGINE_Destroy(AOE_ENGINE_ID_E enENGINE);
HI_S32                  HAL_AOE_ENGINE_SetAttr(AOE_ENGINE_ID_E enENGINE, AOE_ENGINE_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_ENGINE_GetAttr(AOE_ENGINE_ID_E enENGINE, AOE_ENGINE_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_ENGINE_Start(AOE_ENGINE_ID_E enENGINE);
HI_S32                  HAL_AOE_ENGINE_Stop(AOE_ENGINE_ID_E enENGINE);
HI_S32                  HAL_AOE_ENGINE_GetAttr(AOE_ENGINE_ID_E enENGINE, AOE_ENGINE_CHN_ATTR_S* pstAttr);
HI_S32                  HAL_AOE_ENGINE_SetAvcAttr(AOE_ENGINE_ID_E enENGINE, HI_UNF_SND_AVC_ATTR_S* pstAvcAttr);
HI_S32                  HAL_AOE_ENGINE_AttachAip(AOE_ENGINE_ID_E enENGINE, AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_ENGINE_DetachAip(AOE_ENGINE_ID_E enENGINE, AOE_AIP_ID_E enAIP);
HI_S32                  HAL_AOE_ENGINE_AttachAop(AOE_ENGINE_ID_E enENGINE, AOE_AOP_ID_E enAOP);
HI_S32                  HAL_AOE_ENGINE_DetachAop(AOE_ENGINE_ID_E enENGINE, AOE_AOP_ID_E enAOP);
HI_S32                  HAL_AOE_ENGINE_SetAvcEnable(AOE_ENGINE_ID_E enENGINE, HI_BOOL bEnable);
HI_S32                  HAL_AOE_ENGINE_SetPreGainEnable(AOE_ENGINE_ID_E enENGINE, SND_ENGINE_PREGAIN_S* pstPreGain);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif  // __HI_HAL_AOE_H__
