/*$$$!!Warning: Huawei key information asset. No spread without permission.$$$*/
/*CODEMARK:HuE1v2Elv7J9C1aMkGmdiUQZoS/R2sDdIoxXqdBKL9eiPHH/FdSvQYZfBQZKkVdipTcRXX+G
kqk+/W4lTjU7wod1fiGpDLWinyw9avjJNtVJXlCqEH8vbMgn4565yduiKY1IaIpzuduWKvns
ccIC0qCxay5CDpGKWVc1b7cddnIOc4I/R8pIy+gzjG0sPoJATF6Xi6pnMUxHdyZFcT6B8OgS
GBu40NYDy4UeBA1w7rYQjA6nljAl9TGXYZr2x/Dpx5VlsgP3eXYLcr1ScESYtg==#*/
/*$$$!!Warning: Deleting or modifying the preceding information is prohibited.$$$*/
#include    "syntax.h"
#include    "real8.h"
#include    "public.h"
#include    "bitstream.h"
#include    "vfmw.h"

#include    "vdm_hal.h"
#include    "postprocess.h"
#include    "vfmw_ctrl.h"
#include    "fsp.h"


#ifdef REAL8_ENABLE



SINT32 REAL8DEC_Init(RV8_CTX_S *pCtx, SYNTAX_EXTRA_DATA_S *pstExtraData)
{

    return 0;
}


VOID REAL8DEC_Destroy(RV8_CTX_S *pCtx)
{
    return;
}


SINT32 REAL8DEC_Decode(RV8_CTX_S *pCtx, DEC_STREAM_PACKET_S *pPacket)
{
    return RV8_VFMW_FALSE;
}


SINT32 REAL8DEC_RecycleImage(RV8_CTX_S *pCtx, UINT32 ImgID)
{
    return RV8_VFMW_FALSE;
}


SINT32 REAL8DEC_GetRemainImg(RV8_CTX_S *pCtx)
{
    return -1;
}


UINT32 REAL8DEC_VDMPostProc(RV8_CTX_S *pCtx, SINT32 ErrRatio, UINT32 Mb0QpInCurrPic)
{
    return RV8_VFMW_FALSE;
}


SINT32 REAL8DEC_GetImageBuffer( RV8_CTX_S *pCtx )
{
    return 0;
}
VOID REAL8DEC_Support(SINT32 *flag)
{
    *flag = 0;
    return;
}


#endif //REAL8_VFMW_ENABLE
