/******************************************************************************
*
* Copyright (C) 2016 Hisilicon Technologies Co., Ltd.  All rights reserved. 
*
* This program is confidential and proprietary to Hisilicon  Technologies Co., Ltd. (Hisilicon), 
* and may not be copied, reproduced, modified, disclosed to others, published or used, in
* whole or in part, without the express prior written permission of Hisilicon.
*
******************************************************************************
File Name           : tde_api.h
Version             : Initial Draft
Author              : 
Created             : 2014/06/20
Description         : 
Function List       :                    
History             :
Date                        Author                  Modification
2014/06/20                  y00181162               Created file        
******************************************************************************/
#ifndef _TDE_ADP_H_
#define _TDE_ADP_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#ifndef HI_BUILD_IN_BOOT
	#if defined(CONFIG_GFX_STB_SDK)
	#include "hi_drv_mmz.h"
    #include "drv_dev_ext.h"
	#elif defined(CONFIG_GFX_BVT_SDK)
	#include <linux/sched.h>
	#endif
	#include "drv_tde_ext.h"
#endif

#if defined(CONFIG_GFX_STB_SDK) || defined(HI_BUILD_IN_BOOT)
	#define TDE_INTNUM            (36+32)
	#define TDE_REG_BASEADDR     (0x10120000)
	#define TDE_REG_CLOCK         (0x101f5094)
	
	#define CONFIG_TDE_USE_SDK_CRG_ENABLE
	#define CONFIG_TDE_TDE_EXPORT_FUNC
	#define CONFIG_TDE_PM_ENABLE
	#define MPP_LICENSE "GPL"
	#define DESCRIPTION "Hisilicon TDE Device driver"
	#define AUTHOR "Digital Media Team, Hisilicon crop."
	#define TDE_VERSION "V1.0.0.0" /** revise by y00181162 in compile miniboot **/
#elif defined(CONFIG_GFX_BVT_SDK)
	#if (HICHIP==0x35360100)
		#define TDE_INTNUM  80
		#define TDE_REG_BASEADDR 0x13130000//0x10120000
	#else
		#error "chip type error."
	#endif
	#define TDE_REG_CLOCK 0x12040058
	#define DESCRIPTION "Digital Media Chipset and Sulution Development Dept, HS"
	#define AUTHOR "Digital Media Team, Hisilicon crop."
	#define TDE_VERSION "V1.0.0.0"
	typedef unsigned long      HI_SIZE_T;
#elif defined(CONFIG_GFX_TV_SDK)
	#define TDE_INTNUM  123
	#define TDE_REG_BASEADDR 0xff380000
	#define CONFIG_TDE_USE_SDK_CRG_ENABLE
	#define CONFIG_TDE_TDE_EXPORT_FUNC
	#define CONFIG_TDE_PM_ENABLE
	#define MPP_LICENSE "GPL"
	#define DESCRIPTION "Hisilicon TDE Device driver"
	#define AUTHOR "Digital Media Team, Hisilicon crop."
	#define TDE_VERSION "V1.0.0.0"
#endif



#define TDE_NO_SCALE_STEP 0x1000
#define TDE_FLOAT_BITLEN 12
#define TDE_MAX_SLICE_WIDTH 256
#define TDE_MAX_SLICE_NUM 20
#define TDE_MAX_RECT_WIDTH 0xfff
#define TDE_MAX_RECT_HEIGHT 0xfff
#define TDE_MAX_SURFACE_PITCH 0xffff
#define TDE_MAX_ZOOM_OUT_STEP 8
#define TDE_MAX_RECT_WIDTH_EX 0x2000
#define TDE_MAX_RECT_HEIGHT_EX 0x2000


#define TDE_MAX_MINIFICATION_H  255
#define TDE_MAX_MINIFICATION_V  255



#define   ROP        (0x1)/*Rop*/
#define   ALPHABLEND     (0x1<<1) /* AlphaBlend */
#define   COLORIZE    (0x1<<2)/* Colorize */
#define   CLUT   (0x1<<3) /* Clut */
#define   COLORKEY  (0x1<<4) /* ColorKey */
#define   CLIP  (0x1<<5) /* Clip */
#define   DEFLICKER  (0x1<<6) /* Deflicker */
#define   RESIZE  (0x1<<7) /* Resize */
#define   MIRROR  (0x1<<8) /* Mirror */
#define   CSCCOVERT  (0x1<<9) /* CSC */
#define   QUICKCOPY  (0x1<<10)/*快速拷贝*/
#define   QUICKFILL  (0x1<<11)/*快速填充*/
#define   PATTERFILL  (0x1<<12)/*模式填充*/
#define   MASKROP  (0x1<<13)/*MaskRop*/
#define   MASKBLEND  (0x1<<14)/*MaskBlend*/

/*******************************************************************************
* Function:      TdeHalGetCapability
* Description:   Get the capability of TDE
* Input:         the pointer of the capability
* Output:        none
* Return:        success
* Others:        none
*******************************************************************************/
HI_S32 TdeHalGetCapability(HI_U32 *pstCapability);

#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif  /*_TDE_ADP_H_*/


