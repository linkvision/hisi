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

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>

#include "drv_i2c_ioctl.h"
#include "drv_struct_ext.h"

static HI_S32 g_I2cDevFd = -1;

static pthread_mutex_t g_I2cMutex = PTHREAD_MUTEX_INITIALIZER;

#define HI_I2C_LOCK() (void)pthread_mutex_lock(&g_I2cMutex);
#define HI_I2C_UNLOCK() (void)pthread_mutex_unlock(&g_I2cMutex);

#define CHECK_I2C_OPEN() \
    do {\
        HI_I2C_LOCK(); \
        if (g_I2cDevFd < 0)\
        {\
            HI_ERR_I2C("I2C is not open.\n"); \
            HI_I2C_UNLOCK(); \
            return HI_ERR_I2C_NOT_INIT; \
        } \
        HI_I2C_UNLOCK(); \
    } while (0)

/*******************************************
Function:              HI_UNF_I2C_Init
Description:  init i2c device
Calls:        HI_DRV_I2C_Open
Data Accessed:      NA
Data Updated:        NA
Input:                  NA
Output:                NA
Return:         ErrorCode(reference to document)
Others:                  NA
*******************************************/
HI_S32 HI_UNF_I2C_Init (HI_VOID)
{
    HI_I2C_LOCK();

    /* reopen will direct return success*/
    if (g_I2cDevFd > 0)
    {
        HI_I2C_UNLOCK();
        return HI_SUCCESS;
    }

    g_I2cDevFd = open("/dev/" UMAP_DEVNAME_I2C, O_RDWR, 0);
    if (g_I2cDevFd < 0)
    {
        HI_FATAL_I2C("open I2C err.\n");
        HI_I2C_UNLOCK();
        return HI_ERR_I2C_OPEN_ERR;
    }

    HI_I2C_UNLOCK();

    return HI_SUCCESS;
}

/*******************************************
Function:              HI_UNF_I2C_DeInit
Description:  deinit i2c device
Calls:        HI_DRV_I2C_Close
Data Accessed:      NA
Data Updated:        NA
Input:                  NA
Output:                NA
Return:         ErrorCode(reference to document)
Others:                  NA
*******************************************/
HI_S32 HI_UNF_I2C_DeInit (HI_VOID)
{
    HI_S32 Ret;

    HI_I2C_LOCK();

    if (g_I2cDevFd < 0)
    {
        HI_I2C_UNLOCK();
        return HI_SUCCESS;
    }

    Ret = close(g_I2cDevFd);

    if (HI_SUCCESS != Ret)
    {
        HI_FATAL_I2C("Close I2C err.\n");
        HI_I2C_UNLOCK();
        return HI_ERR_I2C_CLOSE_ERR;
    }

    g_I2cDevFd = -1;

    HI_I2C_UNLOCK();

    return HI_SUCCESS;
}

/*******************************************
Function:              HI_UNF_I2C_Read
Description:  read data via i2c
Calls:        HI_DRV_I2C_Read
Data Accessed:      NA
Data Updated:        NA
Input:                  NA
Output:                NA
Return:         ErrorCode(reference to document)
Others:                  NA
*******************************************/
HI_S32 HI_UNF_I2C_Read(HI_U32 u32I2cNum, HI_U8 u8DevAddress, HI_U32 u32RegAddr,
                       HI_U32 u32RegAddrCount, HI_U8 *pu8Buf, HI_U32 u32Length)
{
    HI_S32 Ret = 0;
    I2C_DATA_S I2cData;

    if (u32I2cNum > HI_I2C_MAX_NUM_USER)
    {
        HI_ERR_I2C("para u32I2cNum is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    if ((u32RegAddrCount != 1)
        && (u32RegAddrCount != 2)
    )
    {
        HI_ERR_I2C("para u32RegAddrCount is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    if (!pu8Buf)
    {
        HI_ERR_I2C("para penPressStatus is null.\n");
        return HI_ERR_I2C_NULL_PTR;
    }

    if ((u32Length > HI_I2C_MAX_LENGTH) || (0 == u32Length))
    {
        HI_ERR_I2C("para u32Length is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    CHECK_I2C_OPEN();

    I2cData.I2cNum = u32I2cNum;
    I2cData.I2cDevAddr  = u8DevAddress;
    I2cData.I2cRegAddr  = u32RegAddr;
    I2cData.I2cRegCount = u32RegAddrCount;
    I2cData.pData   = pu8Buf;
    I2cData.DataLen = u32Length;

    Ret = ioctl(g_I2cDevFd, CMD_I2C_READ, (HI_U32)&I2cData);
    if (Ret != HI_SUCCESS)
    {
        return Ret;
    }

    return HI_SUCCESS;
}

/*******************************************
Function:              HI_UNF_I2C_Write
Description:  write data via i2c
Calls:        HI_DRV_I2C_Write
Data Accessed:      NA
Data Updated:        NA
Input:                  NA
Output:                NA
Return:         ErrorCode(reference to document)
Others:                  NA
*******************************************/
HI_S32 HI_UNF_I2C_Write(HI_U32 u32I2cNum, HI_U8 u8DevAddress, HI_U32 u32RegAddr,
                        HI_U32 u32RegAddrCount, HI_U8 *pu8Buf, HI_U32 u32Length)
{
    HI_S32 Ret = 0;
    I2C_DATA_S I2cData;

    if (u32I2cNum > HI_I2C_MAX_NUM_USER)
    {
        HI_ERR_I2C("para u32I2cNum is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    if ((u32RegAddrCount != 1)
        && (u32RegAddrCount != 2)
    )
    {
        HI_ERR_I2C("para u32RegAddrCount is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    if (!pu8Buf)
    {
        HI_ERR_I2C("para penPressStatus is null.\n");
        return HI_ERR_I2C_NULL_PTR;
    }

    if ((u32Length > HI_I2C_MAX_LENGTH) || (0 == u32Length))
    {
        HI_ERR_I2C("para u32Length is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    CHECK_I2C_OPEN();

    I2cData.I2cNum = u32I2cNum;
    I2cData.I2cDevAddr  = u8DevAddress;
    I2cData.I2cRegAddr  = u32RegAddr;
    I2cData.I2cRegCount = u32RegAddrCount;
    I2cData.pData   = pu8Buf;
    I2cData.DataLen = u32Length;

    Ret = ioctl(g_I2cDevFd, CMD_I2C_WRITE, (HI_U32)&I2cData);
    if (Ret != HI_SUCCESS)
    {
        return Ret;
    }

    return HI_SUCCESS;
}

/*******************************************
Function:       HI_UNF_I2C_CreateGpioI2c
Description:    config param
Calls:          gpio_i2c_config
Data Accessed:  NA
Data Updated:   NA
Input:          NA
Output:
Return:         ErrorCode(reference to document)
Others:         NA
*******************************************/
HI_S32 HI_UNF_I2C_CreateGpioI2c(HI_U32 *pu32I2cNum, HI_U32 whichGpioClock, HI_U32 whichGpioData, HI_U32 clockBit, HI_U32 dataBit)
{
    I2C_GPIO_S I2cGpio;
    HI_S32 Ret = 0;

    CHECK_I2C_OPEN();

    if (HI_NULL == pu32I2cNum)
    {
        HI_ERR_I2C("para u32I2cNum is NULL.\n");
        return HI_ERR_I2C_NULL_PTR;
    }
	if ((whichGpioClock == whichGpioData) && (clockBit == dataBit))
	{
        HI_ERR_I2C("whichGpioClock = whichGpioData and clockBit = dataBit is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
	}

	if (whichGpioClock >6|| whichGpioData > 6)
	{
        HI_ERR_I2C("para whichGpioClock or whichGpioData is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
	}

    if (clockBit > 7 || dataBit > 7)
	{
        HI_ERR_I2C("para clockBit or dataBit is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
	}
  
    I2cGpio.u32SCLGpioNo  = whichGpioClock*8+clockBit;
    I2cGpio.u32SDAGpioNo  = whichGpioData*8+dataBit;
    I2cGpio.bUsed          = HI_TRUE;

    Ret = ioctl(g_I2cDevFd, CMD_I2C_CONFIG, &I2cGpio);
    if (Ret != HI_SUCCESS)
    {
        HI_ERR_I2C("  CreateGpioI2c number failed .\n");
        return Ret;
    }

    *pu32I2cNum = I2cGpio.I2cNum;

    return HI_SUCCESS;
}

/*******************************************
Function:       HI_UNF_I2C_DestroyGpioI2c
Description:    config param
Calls:          gpio_i2c_destroy
Data Accessed:  NA
Data Updated:   NA
Input:          NA
Output:
Return:         ErrorCode(reference to document)
Others:         NA
*******************************************/
HI_S32 HI_UNF_I2C_DestroyGpioI2c(HI_U32 u32I2cNum)
{
    I2C_GPIO_S I2cGpio;
    HI_S32 Ret = 0;

    if ((HI_STD_I2C_NUM > u32I2cNum) || (HI_I2C_MAX_NUM <= u32I2cNum))
    {
        HI_ERR_I2C("para u32I2cNum = %d is invalid.\n", u32I2cNum);
        return HI_ERR_I2C_INVALID_PARA;
    }

    CHECK_I2C_OPEN();

    I2cGpio.I2cNum        = u32I2cNum;

    I2cGpio.u32SCLGpioNo = 0;
    I2cGpio.u32SDAGpioNo  = 0;
    I2cGpio.bUsed          = HI_FALSE;
    

    Ret = ioctl(g_I2cDevFd, CMD_I2C_DESTROY, (HI_U32)&I2cGpio);
    if (Ret != HI_SUCCESS)
    {
        return Ret;
    }

    return HI_SUCCESS;
}

/*******************************************
Function:              HI_UNF_I2C_SetRate
Description:  set the rate
Calls:        HI_I2C_SetRate
Data Accessed:      NA
Data Updated:        NA
Input:                  NA
Output:                NA
Return:         ErrorCode(reference to document)
Others:                  NA
*******************************************/
HI_S32 HI_UNF_I2C_SetRate(HI_U32 u32I2cNum, HI_UNF_I2C_RATE_E enI2cRate)
{
    HI_S32 Ret = 0;
    I2C_RATE_S I2cRate;

    if (u32I2cNum >= HI_STD_I2C_NUM)
    {
        HI_ERR_I2C("para u32I2cNum is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    CHECK_I2C_OPEN();

    I2cRate.I2cNum = u32I2cNum;

    switch (enI2cRate)
    {
    case HI_UNF_I2C_RATE_10K:
        I2cRate.I2cRate = 10000;
        break;
    case HI_UNF_I2C_RATE_50K:
        I2cRate.I2cRate = 50000;
        break;
    case HI_UNF_I2C_RATE_100K:
        I2cRate.I2cRate = 100000;
        break;
    case HI_UNF_I2C_RATE_200K:
        I2cRate.I2cRate = 200000;
        break;
    case HI_UNF_I2C_RATE_300K:
        I2cRate.I2cRate = 300000;
        break;
    case HI_UNF_I2C_RATE_400K:
        I2cRate.I2cRate = 400000;
        break;
    default:
        HI_ERR_I2C("para enI2cRate is invalid.\n");
        return HI_ERR_I2C_INVALID_PARA;
    }

    Ret = ioctl(g_I2cDevFd, CMD_I2C_SET_RATE, (HI_U32)&I2cRate);
    if (Ret != HI_SUCCESS)
    {
        return Ret;
    }

    return HI_SUCCESS;
}


