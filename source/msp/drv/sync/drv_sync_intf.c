/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : avplay_intf.c
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/21
  Description   :
  History       :
  1.Date        : 2009/12/21
    Author      : w58735
    Modification: Created file

*******************************************************************************/
#include <linux/vmalloc.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/fcntl.h>
#include <linux/mm.h>
#include <linux/miscdevice.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 18, 0))
#include <asm/system.h>
#endif
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/string.h>

#include "drv_dev_ext.h"
#include "hi_drv_proc.h"
#include "hi_drv_mmz.h"
#include "drv_sync.h"
#include "drv_sync_intf.h"
#include "drv_sync_ext.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

extern HI_S32       SYNC_DRV_Init(HI_VOID);
extern HI_VOID      SYNC_DRV_Exit(HI_VOID);

static UMAP_DEVICE_S g_SyncRegisterData;

#ifdef HI_SYNC_PROC_SUPPORT
HI_U8 *g_pSyncStatusString[4] = {
    "STOP",    
    "PLAY",    
    "TPLAY",   
    "PAUSE",   
};

HI_U8 *g_pSyncRefString[5] = {
    "NONE",    
    "AUDIO",    
    "VIDEO",   
    "PCR",
    "SCR",
};

HI_U8 *g_pSyncChnString[4] = {
    "AUD",    
    "VID",    
    "PCR",
    "SCR",
};


static HI_S32 SYNC_ProcRead(struct seq_file *p, HI_VOID *v)
{
    DRV_PROC_ITEM_S  *pProcItem;
    HI_U32            SyncId;
    SYNC_S            *pSync;
    HI_U32             PcrLocalTime;
    HI_U32             AudLocalTime;
    HI_U32             VidLocalTime;
#ifdef HI_AVPLAY_SCR_SUPPORT
    HI_U32             ScrLocalTime;
#endif

    pProcItem = p->private;
   
    SyncId = (pProcItem->entry_name[4] - '0')*10 + (pProcItem->entry_name[5] - '0');

    pSync = SYNC_getInfoPtr(SyncId);
    if(pSync == NULL){
        PROC_PRINT(p,"inst %d not exist \n", SyncId);
        return HI_SUCCESS;
    }

    PcrLocalTime = SYNC_GetLocalTime(pSync, SYNC_CHAN_PCR);
    AudLocalTime = SYNC_GetLocalTime(pSync, SYNC_CHAN_AUD);
    VidLocalTime = SYNC_GetLocalTime(pSync, SYNC_CHAN_VID);
#ifdef HI_AVPLAY_SCR_SUPPORT
    ScrLocalTime = SYNC_GetLocalTime(pSync, SYNC_CHAN_SCR);
#endif
    PROC_PRINT(p,"------------------------Hisilicon SYNC%2d Out Info--------------------------\n", SyncId);
    PROC_PRINT(p,"__________Hisilicon SYNC ATTR__________|__________Hisilicon PCR____________\n");
    PROC_PRINT(p,"SyncPrint                   :%-10d|CrtStatus             :%s\n"
                      "SyncRef                     :%-10s|PreSyncStartSysTime   :%d\n"
                      "SyncStart.VidPlusTime       :%-10d|PreSyncEndSysTime     :%d\n"
                      "SyncStart.VidNegativeTime   :%-10d|PreSyncFinish         :%d\n"
                      "SyncStart.bSmoothPlay       :%-10d|BufFundEndSysTime     :%d\n"
                      "SyncNovel.VidPlusTime       :%-10d|BufFundFinish         :%d\n"
                      "SyncNovel.VidNegativeTime   :%-10d|PreSyncTarget         :%s\n"
                      "SyncNovel.bSmoothPlay       :%-10d|PreSyncTargetTime     :%d\n"
                      "VidPtsAdjust                :%-10d|PcrFirstCome          :%d\n"
                      "AudPtsAdjust                :%-10d|PcrFirstSysTime       :%d\n"
                      "PreSyncTimeoutMs            :%-10d|PcrFirst              :%d\n"
                      "bQuickOutput                :%-10d|PcrLast               :%d\n"
                      "VidFirstDecPts              :%-10d|PcrLocalTime          :%d\n"
                      "VidSecondDecPts             :%-10d|PcrAdjustMode         :%d\n"
                      "VidFirstValidPts            :%-10d|PcrAudSyncOK          :%d\n"
                      "AudFirstValidPts            :%-10d|PcrVidSyncOK          :%d\n",
                      
                      
        pSync->bPrint,                                         g_pSyncStatusString[pSync->CrtStatus],                
        g_pSyncRefString[pSync->SyncAttr.enSyncRef],         pSync->PreSyncStartSysTime,    
        pSync->SyncAttr.stSyncStartRegion.s32VidPlusTime,     pSync->PreSyncEndSysTime,    
        pSync->SyncAttr.stSyncStartRegion.s32VidNegativeTime,pSync->PreSyncFinish,        
        pSync->SyncAttr.stSyncStartRegion.bSmoothPlay,         pSync->BufFundEndSysTime,
        pSync->SyncAttr.stSyncNovelRegion.s32VidPlusTime,     pSync->BufFundFinish,    
        pSync->SyncAttr.stSyncNovelRegion.s32VidNegativeTime,g_pSyncChnString[pSync->PreSyncTarget],        
        pSync->SyncAttr.stSyncNovelRegion.bSmoothPlay,         pSync->PreSyncTargetTime,    
        pSync->SyncAttr.s32VidPtsAdjust,                     pSync->PcrSyncInfo.PcrFirstCome,    
        pSync->SyncAttr.s32AudPtsAdjust,                     pSync->PcrSyncInfo.PcrFirstSysTime,    
        pSync->SyncAttr.u32PreSyncTimeoutMs,                 pSync->PcrSyncInfo.PcrFirst,    
        pSync->SyncAttr.bQuickOutput,                         pSync->PcrSyncInfo.PcrLast,    
        pSync->VidFirstDecPts,                               PcrLocalTime,
        pSync->VidSecondDecPts,                              pSync->PcrSyncInfo.enPcrAdjust,
        pSync->VidFirstValidPts,                             pSync->PcrSyncInfo.PcrAudSyncOK,
        pSync->AudFirstValidPts,                             pSync->PcrSyncInfo.PcrVidSyncOK
        );

    PROC_PRINT(p,"__________Hisilicon VID________________|__________Hisilicon AUD____________\n");
    PROC_PRINT(p,"VidFirstCome                :%-10d|AudFirstCome          :%d\n"
                      "VidFirstSysTime             :%-10d|AudFirstSysTime       :%d\n"
                      "VidFirstPts                 :%-10d|AudFirstPts           :%d\n"
                      "VidLastPts                  :%-10d|AudLastPts            :%d\n"
                      "VidPreSyncTargetInit        :%-10d|AudPreSyncTargetInit  :%d\n"
                      "VidPreSyncTargetTime        :%-10d|AudPreSyncTargetTime  :%d\n"
                      "VidFirstPlay                :%-10d|AudFirstPlay          :%d\n"
                      "VidFirstPlayTime            :%-10d|AudFirstPlayTime      :%d\n"
                      "VidBlockFlag                :%-10d|AudBlockFlag          :%d\n"
                      "VidBufPercent               :%-10d|AudBufPercent         :%d\n"
                      "VidLocalTime                :%-10d|AudLocalTime          :%d\n"
                      "VidPcrDiff                  :%-10d|AudPcrDiff            :%d\n"
                      "VidAudDiff                  :%-10d|AudBufTime            :%d\n"
                      "VidDiscard                  :%-10d|AudLastBufTime        :%d\n"
                      "VidSyndAdjust               :%-10d|AudDiscardCnt         :%d\n"
                      "VidDiscardCnt               :%-10d|AudRepeatCnt          :%d\n"
                      "VidRepeatCnt                :%-10d|\n",

                    pSync->VidFirstCome,        pSync->AudFirstCome,                                    
                    pSync->VidFirstSysTime,     pSync->AudFirstSysTime,                                             
                    pSync->VidFirstPts,         pSync->AudFirstPts,                                               
                    pSync->VidLastPts,          pSync->AudLastPts,                                           
                    pSync->VidPreSyncTargetInit,pSync->AudPreSyncTargetInit,                                    
                    pSync->VidPreSyncTargetTime,pSync->AudPreSyncTargetTime,                                           
                    pSync->VidFirstPlay,        pSync->AudFirstPlay,                              
                    pSync->VidFirstPlayTime,    pSync->AudFirstPlayTime,                                              
                    pSync->CrtBufStatus.VidBlockFlag,        pSync->CrtBufStatus.AudBlockFlag,                                            
                    pSync->CrtBufStatus.VidBufPercent,       pSync->CrtBufStatus.AudBufPercent,                                        
                    VidLocalTime,               AudLocalTime,  
                    pSync->PcrSyncInfo.VidPcrDiff,          pSync->PcrSyncInfo.AudPcrDiff,      
                    pSync->VidAudDiff,            pSync->AudInfo.BufTime,      
                    pSync->VidDiscard,          pSync->AudLastBufTime,                                            
                    pSync->VidSyndAdjust,       pSync->AudDiscardCnt,
                    pSync->VidDiscardCnt,       pSync->AudRepeatCnt,
                    pSync->VidRepeatCnt                                                           
                    );

#ifdef HI_AVPLAY_SCR_SUPPORT
    PROC_PRINT(p,"__________Hisilicon SCR________________\n");
    PROC_PRINT(p,"ScrInitFlag                 :%-10d\n"
                      "ScrFirstSysTime             :%-10d\n"
                      "ScrFirstLocalTime           :%-10d\n"
                      "ScrLocalTime                :%-10d\n"
                      "AudScrDiff                  :%-10d\n"
                      "VidScrDiff                  :%-10d\n",

                    pSync->ScrInitFlag,
                    pSync->ScrFirstSysTime,
                    pSync->ScrFirstLocalTime,
                    ScrLocalTime,
                    pSync->AudScrDiff,
                    pSync->VidScrDiff
                    );
#endif

    return HI_SUCCESS;
}

HI_S32 SYNC_ProcParsePara(HI_CHAR *pProcPara,HI_CHAR **ppItem,HI_CHAR **ppValue)
{
    HI_CHAR *pChar = HI_NULL;
    HI_CHAR *pItem,*pValue;

    pChar = strchr(pProcPara,'=');
    if (HI_NULL == pChar)
    {
        return HI_FAILURE; /* Not Found '=' */
    }

    pItem = pProcPara;
    pValue = pChar + 1;
    *pChar = '\0';

    /* remove blank bytes from item tail */
    pChar = pItem;
    while(*pChar != ' ' && *pChar != '\0')
    {
        pChar++;
    }
    *pChar = '\0';
    
    /* remove blank bytes from value head */
    while(*pValue == ' ')
    {
        pValue++;
    }

    *ppItem = pItem;
    *ppValue = pValue;
    return HI_SUCCESS;
}

HI_VOID SYNC_ProcPrintHelp(HI_VOID)
{
    HI_PRINT("echo SyncPrint = 1|0 > /proc/msp/syncxx\n"
           "echo SyncRef   = audio|pcr|scr|none > proc/msp/syncxx\n"
           "echo SyncStart.VidPlusTime = xxx > /proc/msp/syncxx\n"
           "echo SyncStart.VidNegativeTime = xxx > /proc/msp/syncxx\n"
           "echo SyncStart.bSmoothPlay = true|false > /proc/msp/syncxx\n"
           "echo SyncNovel.VidPlusTime = xxx > /proc/msp/syncxx\n"
           "echo SyncNovel.VidNegativeTime = xxx > /proc/msp/syncxx\n"
           "echo SyncNovel.bSmoothPlay = true|false > /proc/msp/syncxx\n"
           "echo PreSyncTimeoutMs = xxx > /proc/msp/syncxx\n"
           "echo bQuickOutput = true|false > /proc/msp/syncxx\n");
}

static HI_S32 SYNC_ProcWrite(struct file * file,
    const char __user * buf, size_t count, loff_t *ppos)

{
    SYNC_S            *pSync;
    struct seq_file   *s = file->private_data;
    DRV_PROC_ITEM_S  *pProcItem = s->private;
    HI_U32            SyncId;
    HI_CHAR           ProcPara[64]={0};
    HI_CHAR           *pItem,*pValue;
    HI_S32            Ret;

    if (copy_from_user(ProcPara, buf, count))
    {
        return -EFAULT;
    }

	ProcPara[63] = '\0';

    Ret = SYNC_ProcParsePara(ProcPara,&pItem,&pValue);
    if (HI_SUCCESS != Ret)
    {
        SYNC_ProcPrintHelp();
        return -EFAULT;
    }

    SyncId = (pProcItem->entry_name[4] - '0')*10 + (pProcItem->entry_name[5] - '0');

    pSync = SYNC_getInfoPtr(SyncId);
    if(pSync == NULL){
        HI_PRINT("inst %d not exist \n",SyncId);
        return HI_SUCCESS;
    }
    if (!strncmp(pItem,"SyncPrint", sizeof("SyncPrint") ))
    {
        pSync->bPrint = simple_strtol(pValue, NULL, 10);
    }
	else if (!strncmp(pItem,"SyncRef", sizeof("SyncRef") ))
    {
	    if (!strncmp(pValue,"none\n", sizeof("none\n")))
        {
            pSync->SyncAttr.enSyncRef = HI_UNF_SYNC_REF_NONE;
        }
	    else if (!strncmp(pValue,"audio\n", sizeof("audio\n")))
        {
            pSync->SyncAttr.enSyncRef = HI_UNF_SYNC_REF_AUDIO;
        }
	    else if (!strncmp(pValue,"pcr\n", sizeof("pcr\n")))
        {
            pSync->SyncAttr.enSyncRef = HI_UNF_SYNC_REF_PCR;
        }
        else if (!strncmp(pValue,"scr\n", sizeof("scr\n")))
        {
            pSync->SyncAttr.enSyncRef = HI_UNF_SYNC_REF_SCR;
        }
        else
        {
            SYNC_ProcPrintHelp();
        }
    }
    else if (!strncmp(pItem,"SyncStart.VidPlusTime", sizeof("SyncStart.VidPlusTime")))
    {
        pSync->SyncAttr.stSyncStartRegion.s32VidPlusTime = simple_strtol(pValue, NULL, 10);
    }
	else if (!strncmp(pItem,"SyncStart.VidNegativeTime", sizeof("SyncStart.VidNegativeTime")))
    {
        pSync->SyncAttr.stSyncStartRegion.s32VidNegativeTime = simple_strtol(pValue, NULL, 10);
    }
    else if (!strncmp(pItem, "SyncStart.bSmoothPlay", sizeof("SyncStart.bSmoothPlay")))
    {
        if (!strncmp(pValue,"true\n", sizeof("true\n")))
        {
            pSync->SyncAttr.stSyncStartRegion.bSmoothPlay = HI_TRUE;
        }
        else if(!strncmp(pValue,"false\n", sizeof("false\n")))
        {
            pSync->SyncAttr.stSyncStartRegion.bSmoothPlay = HI_FALSE;
        }
    }
    else if (!strncmp(pItem, "SyncNovel.VidPlusTime", sizeof("SyncNovel.VidPlusTime")))
    {
        pSync->SyncAttr.stSyncNovelRegion.s32VidPlusTime = simple_strtol(pValue, NULL, 10);
    }
    else if (!strncmp(pItem, "SyncNovel.VidNegativeTime", sizeof("SyncNovel.VidNegativeTime")))
    {
        pSync->SyncAttr.stSyncNovelRegion.s32VidNegativeTime = simple_strtol(pValue, NULL, 10);
    }
    else if (!strncmp(pItem, "SyncNovel.bSmoothPlay", sizeof("SyncNovel.bSmoothPlay")))
    {
        if (!strncmp(pValue,"true\n", sizeof("true\n")))
        {
            pSync->SyncAttr.stSyncNovelRegion.bSmoothPlay = HI_TRUE;
        }
        else if(!strncmp(pValue,"false\n", sizeof("false\n")))
        {
            pSync->SyncAttr.stSyncNovelRegion.bSmoothPlay = HI_FALSE;
        }
    }
    else if (!strncmp(pItem, "PreSyncTimeoutMs", sizeof("PreSyncTimeoutMs")))
    {
        pSync->SyncAttr.u32PreSyncTimeoutMs = simple_strtol(pValue, NULL, 10);
    }
    else if (!strncmp(pItem, "bQuickOutput", sizeof("bQuickOutput")))
    {
        if (!strncmp(pValue,"true\n", sizeof("true\n")))
        {
            pSync->SyncAttr.bQuickOutput = HI_TRUE;
        }
        else if(!strncmp(pValue,"false\n", sizeof("false\n")))
        {
            pSync->SyncAttr.bQuickOutput = HI_FALSE;
        }
    }
    else
    {
        SYNC_ProcPrintHelp();
        return -EFAULT;
    }

    return count;
}
#endif

static long SYNC_DRV_Ioctl(struct file *ffile, unsigned int cmd, unsigned long arg)
{
    HI_S32 Ret;

    Ret = HI_DRV_UserCopy(ffile->f_path.dentry->d_inode, ffile, cmd, arg, SYNC_Ioctl);

    return Ret;
}

static struct file_operations SYNC_FOPS =
{
    .owner          = THIS_MODULE,
    .open           = SYNC_DRV_Open,
    .unlocked_ioctl = SYNC_DRV_Ioctl,
    .release        = SYNC_DRV_Close,
};


static PM_BASEOPS_S SYNC_DRVOPS = {
    .probe        = NULL,
    .remove       = NULL,
    .shutdown     = NULL,
    .prepare      = NULL,
    .complete     = NULL,
    .suspend      = SYNC_Suspend,
    .suspend_late = NULL,
    .resume_early = NULL,
    .resume       = SYNC_Resume,
};

#ifdef HI_SYNC_PROC_SUPPORT
static SYNC_REGISTER_PARAM_S SYNC_ProcPara = {
    .rdproc = SYNC_ProcRead,
    .wtproc = SYNC_ProcWrite,
};
#endif	

HI_S32 SYNC_DRV_ModInit(HI_VOID)
{
    HI_S32  Ret;

#ifndef HI_MCE_SUPPORT
    Ret = SYNC_DRV_Init();
    if(HI_SUCCESS != Ret)
    {
        HI_FATAL_SYNC("register SYNC Intf failed.\n");
        return HI_FAILURE;
    }
#endif

#ifdef HI_SYNC_PROC_SUPPORT
    Ret = SYNC_IntfRegister(&SYNC_ProcPara);
    if (Ret != HI_SUCCESS)
    {
        HI_FATAL_SYNC("register SYNC Intf failed.\n");
        return HI_FAILURE;
    }
#endif	
    snprintf(g_SyncRegisterData.devfs_name, sizeof(g_SyncRegisterData.devfs_name),UMAP_DEVNAME_SYNC);
    g_SyncRegisterData.fops = &SYNC_FOPS;
    g_SyncRegisterData.minor = UMAP_MIN_MINOR_SYNC;
    g_SyncRegisterData.owner  = THIS_MODULE;
    g_SyncRegisterData.drvops = &SYNC_DRVOPS;
    if (HI_DRV_DEV_Register(&g_SyncRegisterData) < 0)
    {
        HI_FATAL_SYNC("register SYNC failed.\n");
        return HI_FAILURE;
    }
   
    return  0;
}

HI_VOID SYNC_DRV_ModExit(HI_VOID)
{
    HI_DRV_DEV_UnRegister(&g_SyncRegisterData);

    SYNC_IntfUnRegister();

#ifndef HI_MCE_SUPPORT
    SYNC_DRV_Exit();
#endif

}

#ifdef MODULE
module_init(SYNC_DRV_ModInit);
module_exit(SYNC_DRV_ModExit);
#endif

MODULE_AUTHOR("HISILICON");
MODULE_LICENSE("GPL");


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif