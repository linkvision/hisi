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
#include "sample_fsdebug.h"

#ifndef  _SAMPLE_FSMANGER_H_
 #define  _SAMPLE_FSMANGER_H_

 #ifdef __cplusplus
extern "C" {
 #endif

 #define MAX_PATH_LENGTH 300
 #define MAX_NAME_LENGTH 300

typedef struct
{
    HI_CHAR uFileName[MAX_NAME_LENGTH];
} USB_FILE_NAME;

typedef struct
{
    HI_CHAR uFolderPath[MAX_PATH_LENGTH];
} USB_FOLDER_PATH;

typedef struct
{
    USB_FOLDER_PATH sFileFolderPath;
    USB_FILE_NAME   sFileName;
} USB_FILE_COMPLETE_INFO;

typedef struct
{
    HI_S32   u32TotalSizeKB;
    HI_S32   u32FreeSizeKB;
    HI_CHAR  *pu8MountPoint;
} USB_DISK_INFO_S;

HI_S32 FS_Init(void);

HI_S32 FS_GetFilesNumByPath(HI_CHAR* pPath, HI_U32* puFolderNum, HI_U32* puMp3Num, HI_U32* puJpegNum);

HI_S32 FS_GetFilesContentByPath(HI_CHAR* pPath,
                                   USB_FILE_NAME** pFolder,
                                   USB_FILE_NAME** pMp3,
                                   USB_FILE_NAME** pJpeg);

HI_BOOL FS_IsDiskOk(void);
HI_S32 FS_GetDiskInfo(HI_CHAR *pu8DiskName, USB_DISK_INFO_S *pstDiskInfo);

HI_S32 test_diskManage_list(void);

 #ifdef __cplusplus
}
 #endif

#endif
