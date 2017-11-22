/*********************************************************************************
*
*  Copyright (C) 2014 Hisilicon Technologies Co., Ltd.  All rights reserved. 
*
*  This program is confidential and proprietary to Hisilicon Technologies Co., Ltd.
*  (Hisilicon), and may not be copied, reproduced, modified, disclosed to
*  others, published or used, in whole or in part, without the express prior
*  written permission of Hisilicon.
*
***********************************************************************************/
#include <linux/proc_fs.h>
#include <linux/ioport.h>
#include <linux/ioctl.h>

/* Unf headers */
#include "hi_error_mpi.h"
#include "hi_drv_mmz.h"
#include "hi_drv_stat.h"
#include "hi_drv_sys.h"
#include "hi_drv_proc.h"

/* Drv headers */
#include "hi_drv_ao.h"
#include "drv_ao_ioctl.h"
#include "drv_ao_ext.h"
#include "drv_ao_private.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* End of #ifdef __cplusplus */


static struct file_operations s_stAoDevFileOpts =
{
    .owner = THIS_MODULE,
    .unlocked_ioctl   = AO_DRV_Ioctl,
    .open             = AO_DRV_Open,
    .release          = AO_DRV_Release,
};

static PM_BASEOPS_S s_stAoDrvOps = {
    .probe        = NULL,
    .remove       = NULL,
    .shutdown     = NULL,
    .prepare      = NULL,
    .complete     = NULL,
    .suspend      = AO_DRV_Suspend,
    .suspend_late = NULL,
    .resume_early = NULL,
    .resume       = AO_DRV_Resume,
};

#ifndef HI_ADVCA_FUNCTION_RELEASE

static AO_REGISTER_PARAM_S s_stProcParam = {
    .pfnReadProc  = AO_DRV_ReadProc,
    .pfnWriteProc = AO_DRV_WriteProc,
};
#endif
/* the attribute struct of audio decode engine device */
static UMAP_DEVICE_S s_stAdeUmapDev;

static __inline__ int  AO_DRV_RegisterDev(void)
{
    /*register aenc chn device*/
    snprintf(s_stAdeUmapDev.devfs_name, sizeof(s_stAdeUmapDev.devfs_name), UMAP_DEVNAME_AO);
    s_stAdeUmapDev.fops   = &s_stAoDevFileOpts;
    s_stAdeUmapDev.minor  = UMAP_MIN_MINOR_AO;
    s_stAdeUmapDev.owner  = THIS_MODULE;
    s_stAdeUmapDev.drvops = &s_stAoDrvOps;
    if (HI_DRV_DEV_Register(&s_stAdeUmapDev) < 0)
    {
        HI_FATAL_AO("FATAL: vdec register device failed\n");
        return HI_FAILURE;
    }

    return HI_SUCCESS;
}

static __inline__ void AO_DRV_UnregisterDev(void)
{
    /*unregister aenc chn device*/
    HI_DRV_DEV_UnRegister(&s_stAdeUmapDev);
}


HI_S32 AO_DRV_ModInit(HI_VOID)
{
    int ret;

#ifndef HI_MCE_SUPPORT
    ret = AO_DRV_Init();
    if (HI_SUCCESS != ret)
    {
        HI_FATAL_AO("Init ao drv fail!\n");
        return HI_FAILURE;
    }
#endif
#ifndef HI_ADVCA_FUNCTION_RELEASE
    ret = AO_DRV_RegisterProc(&s_stProcParam);
    if (HI_SUCCESS != ret)
    {
        HI_FATAL_AO("Reg proc fail!\n");
        return HI_FAILURE;
    }
#endif
    ret = AO_DRV_RegisterDev();
    if (HI_SUCCESS != ret)
    {
 #ifndef HI_ADVCA_FUNCTION_RELEASE
        AO_DRV_UnregisterProc();
 #endif
        HI_FATAL_AO("Reg dev fail!\n");
        return HI_FAILURE;
    }

    return HI_SUCCESS;
}

HI_VOID AO_DRV_ModExit(HI_VOID)
{
    AO_DRV_UnregisterDev();
    
#ifndef HI_ADVCA_FUNCTION_RELEASE
    AO_DRV_UnregisterProc();
#endif

#ifndef HI_MCE_SUPPORT
    AO_DRV_Exit();
#endif
    return;
}

#ifdef MODULE
//module_init(AO_DRV_ModInit);
//module_exit(AO_DRV_ModExit);
#endif

MODULE_AUTHOR("HISILICON");
MODULE_LICENSE("GPL");

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* End of #ifdef __cplusplus */
