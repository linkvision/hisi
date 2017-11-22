/******************************************************************************
*
* Copyright (C) 2016 Hisilicon Technologies Co., Ltd.  All rights reserved. 
*
* This program is confidential and proprietary to Hisilicon  Technologies Co., Ltd. (Hisilicon), 
* and may not be copied, reproduced, modified, disclosed to others, published or used, in
* whole or in part, without the express prior written permission of Hisilicon.
*
******************************************************************************
File Name           : hi_boot_logo.h
Version             : Initial Draft
Author              : 
Created             : 2016/01/12
Description         : 
                       CNcomment: logoͷ�ļ� CNend\n
Function List   : 
History         :
Date                        Author                  Modification
2016/01/12                                          modiy by y00181162     
******************************************************************************/
#ifndef __HI_BOOT_LOGO_H__
#define __HI_BOOT_LOGO_H__


/*********************************add include here******************************/
#include "hi_boot_common.h"
#include "hi_flash.h"
#include "hi_unf_disp.h"

#ifdef HI_LOADER_APPLOADER
#include "hi_go_gdev.h"
#include "hi_go_decoder.h"
#include "hi_go_bliter.h"
#endif

#include "hi_boot_pdm.h"


/***************************** Macro Definition ******************************/

#define HI_ERR_MCE(format...)     HI_ERR_BOOT(0, format)
#define HI_INFO_MCE(format...)    HI_INFO_BOOT(0, format)

/*************************** Structure Definition ****************************/

/********************** Global Variable declaration **************************/


/******************************* API declaration *****************************/

/***************************************************************************************
* func          : HI_LOGO_DecImg
* description   : CNcomment: ͼƬ���� CNend\n
* param[in]     : HI_VOID
* retval        : NA
* others:       : NA
***************************************************************************************/
HI_S32 HI_LOGO_DecImg(HI_PDM_LOGO_INFO_S stLogoParam, HI_U32 u32LogoDataAddr, HI_HANDLE *hSurface);

#endif /*__HI_BOOT_LOGO_H__ */
