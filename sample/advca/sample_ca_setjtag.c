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
#include <stdlib.h>
#include "hi_type.h"
#include "hi_unf_advca.h"
#include "sample_ca_common.h"

/***************************** Macro Definition ******************************/



/*************************** Structure Definition ****************************/



/********************** Global Variable declaration **************************/



/******************************* API declaration *****************************/
HI_S32 main(HI_S32 argc,HI_CHAR** argv)
{
    HI_S32 JtagMode;
    HI_S32 Ret;
    HI_UNF_ADVCA_JTAG_MODE_E enJtagMode;
    
    if (argc < 2)
    {
        printf("usage:%s mode\n"
               "      mode 0-Opened 1-Password Protected 2-Closed\n",argv[0]);
        return HI_FAILURE;               
    }

    JtagMode = atoi(argv[1]);
    switch (JtagMode)
    {
        case 0 :
            enJtagMode = HI_UNF_ADVCA_JTAG_MODE_OPEN;
            break;
        case 1 :
            enJtagMode = HI_UNF_ADVCA_JTAG_MODE_PROTECT;
            break;
        case 2 :
            enJtagMode = HI_UNF_ADVCA_JTAG_MODE_CLOSED;
            break;
        default:
            HI_DEBUG_ADVCA("the mode value is invalid\n");
            return HI_FAILURE;
    }

    Ret = HI_UNF_ADVCA_Init();
    if (HI_SUCCESS != Ret)
    {
        HI_DEBUG_ADVCA("HI_UNF_ADVCA_Init failed:%#x\n",Ret);
        return HI_FAILURE;
    }

    Ret = HI_UNF_ADVCA_SetJtagMode(enJtagMode);
    if (HI_SUCCESS != Ret)
    {
        HI_DEBUG_ADVCA("HI_UNF_ADVCA_SetJtagMode failed:%#x\n",Ret);
    }

    (HI_VOID)HI_UNF_ADVCA_DeInit();
    return Ret;
}



