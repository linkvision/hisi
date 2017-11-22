
/******************************************************************************

  版权所有 (C), 2001-2011, 华为技术有限公司

******************************************************************************
    文 件 名   : mem_manage.h
    版 本 号   : 初稿
    作    者   :
    生成日期   :
    最近修改   :
    功能描述   : firmware的存储管理模块头文件，与mem_manage.c配套，包括
				 1. 存储空间虚拟地址/物理地址之间的映射
				 2. 通用存储访问函数（比如寄存器读写）
				 3. 存储空间的分配与销毁（屏蔽多种操作系统差异）
				 4. 寄存器地址映射（屏蔽多种操作系统差异）


	修改历史   :
    1.日    期 : 2009-01-07
    作    者   : z56361
    修改内容   :

******************************************************************************/
#ifndef _VFMW_MEM_MANAGE_HEAD_
#define _VFMW_MEM_MANAGE_HEAD_

#ifdef __cplusplus
extern "C" {
#endif


#include "basedef.h"
#include "vfmw.h"


/*######################################################################*/
/*     常数                                                             */
/*######################################################################*/
#define MEM_MAN_ERR  -1
#define MEM_MAN_OK    0


/*###########################################################################################*/
/*     数据结构                                                                              */
/*###########################################################################################*/
typedef struct
{
    SINT8      IsCached;
    SINT8      *VirAddr;
    SINT32     PhyAddr;
    SINT32     Length;
} MEM_RECORD_S;

extern OSAL_IRQ_SPIN_LOCK g_RecordLock;// = {0};

/*###########################################################################################*/
/*     函数声明                                                                              */
/*###########################################################################################*/

/************************************************************************/
/*    初始化                                                            */
/************************************************************************/
VOID MEM_InitMemManager(SINT32 MemBaseAddr, SINT32 MemSize);

/************************************************************************/
/*    指定内存操作                                                      */
/************************************************************************/
VOID MEM_ManagerWithOperation(VDEC_OPERATION_S *pArgs);

/************************************************************************/
/*    清除指定内存操作                                                  */
/************************************************************************/
VOID MEM_ManagerClearOperation(VOID);

/************************************************************************/
/*    添加记录                                                          */
/************************************************************************/
SINT32 MEM_AddMemRecord( SINT32 PhyAddr, VOID *VirAddr, SINT32 Length );


/************************************************************************/
/*    删除记录                                                          */
/************************************************************************/
SINT32 MEM_DelMemRecord( SINT32 PhyAddr, VOID *VirAddr, SINT32 Length );


/************************************************************************/
/*   地址转换： 物理地址 -> 虚拟地址                                    */
/************************************************************************/
VOID *MEM_Phy2Vir( SINT32 PhyAddr );


/************************************************************************/
/*   地址转换： 虚拟地址 -> 物理地址                                    */
/************************************************************************/
SINT32 MEM_Vir2Phy( SINT8 *VirAddr );


/************************************************************************/
/*   mem操作： 向指定的物理地址写入一个word                             */
/************************************************************************/
VOID MEM_WritePhyWord( SINT32 PhyAddr, SINT32 Data32 );


/************************************************************************
mem操作： 向指定的物理地址读入一个word
          不可读时返回默认值0
************************************************************************/
SINT32 MEM_ReadPhyWord(SINT32 PhyAddr);

/************************************************************************/
/*   mem操作： 拷贝一片数据（phy -> phy）                               */
/************************************************************************/
VOID MEM_CopyPhy2Phy( SINT32 DstPhyAddr, SINT32 SrcPhyAddr, SINT32 Length );



/************************************************************************/
/*   mem操作： 拷贝一片数据（phy -> vir）                               */
/************************************************************************/
VOID MEM_CopyPhy2Vir( SINT8 *DstVirAddr, SINT32 SrcPhyAddr, SINT32 Length );



/************************************************************************/
/*   mem操作： 拷贝一片数据（vir -> phy）                               */
/************************************************************************/
VOID MEM_CopyVir2Phy( SINT32 DstPhyAddr, SINT8 *SrcVirAddr, SINT32 Length );



/************************************************************************/
/*   申请内存块                                                         */
/************************************************************************/
SINT32  MEM_AllocMemBlock(SINT8 *MemName, SINT32 ExpectedPhyAddr, SINT32 ExpectedLen, MEM_RECORD_S *pMemRecord, SINT32 IsCached);



/************************************************************************/
/*   映射寄存器                                                         */
/************************************************************************/
SINT32  MEM_MapRegisterAddr( SINT32 RegStartPhyAddr, SINT32 RegByteLen, MEM_RECORD_S *pMemRecord );
VOID MEM_UnmapRegisterAddr( SINT32 PhyAddr, UINT8 *VirAddr );

/************************************************************************/
/*   释放内存块                                                         */
/************************************************************************/
VOID MEM_ReleaseMemBlock( SINT32 PhyAddr, UINT8 *VirAddr );





#ifdef __cplusplus
}
#endif

#endif /* end of '#ifndef _VFMW_MEM_MANAGE_HEAD_' */










