#ifndef _L0_API_H_
#define _L0_API_H_
/*
****************************************************************************************
 Change log:
 As from V3.3.9:
  Changing comment related to using #define SiTRACES_FEATURES     SiTRACES_MINIMAL
    WARNING : the minimal features mode disables tracing functions in the extern file

****************************************************************************************/

/* Un-comment the line below to compile for non-windows platforms (such as Linux) */
/*#define NO_WIN32*/

//#include <linux/file.h>
#include <linux/list.h>
//#include <linux/wait.h>
//#include <linux/param.h>
//#include <linux/kthread.h>
//#include <linux/sched.h>

//#include <linux/delay.h>
//#include <linux/semaphore.h>

//#include "linux/kernel.h"

//#include <hi_debug.h>
#include "hi_type.h"
//#include "drv_i2c_ext.h"
#include "hi_unf_frontend.h"
#include "hi_drv_tuner.h"
#include "drv_demod.h"

#include <common.h>



#ifdef    NO_WIN32
  #include <stdlib.h>
  #include <stdio.h>
  #include <time.h>
  #include <string.h>
  #include <stdarg.h>
#ifndef   NO_MATH_H_APPLICATION
  #include <math.h>
#endif /* NO_MATH_H_APPLICATION */
#else  /* NO_WIN32 not defined: the plaform is Windows-based */
  //#include <windows.h>
  //#include <time.h>
  //#include <stdio.h>
/* <porting> Comment the line below to avoid using the Cypress chip for USB communication */
  #define USB_Capability
#endif /* NO_WIN32 */

/* Uncomment the following line to activate all traces in the code */
#define  SiTRACES

/* <porting> Replace  CUSTOM_PRINTF with your print-out function.*/
#define CUSTOM_PRINTF printf

#define ERROR_MESSAGE_MAX_LENGH 1000
//#define SiERROR               L0_StoreError
#define CHECK_FOR_ERRORS  if (L0_ErrorMessage()) printf("\n\n**************\n%s**************\n\n\n", L0_error_message);

#define  SiTRACE HI_INFO_TUNER

#define SiERROR               SiTRACE

#define TRACES_PRINTF                SiTRACE
#define ALLOCATION_ERROR_MESSAGE     SiTRACE
#define TREAT_ERROR_MESSAGE          SiTRACE
#define TRACES_ERR                   SiTRACE
#define TRACES_TRACE                 SiTRACE
#define TRACES_SHOW                  SiTRACE
#define TRACES_USE                   SiTRACE


typedef enum CONNECTION_TYPE
{
    SIMU = 0,
    USB,
    CUSTOMER,
    none
}  CONNECTION_TYPE;

typedef struct L0_Context
{
    unsigned char   address;
    int             indexSize;
    CONNECTION_TYPE connectionType;
    int             trackWrite;
    int             trackRead;
    int             mustReadWithoutStop;
#ifdef    NO_WIN32


#endif /* NO_WIN32 */
} L0_Context;

/* Layer 1 core types definitions */
typedef enum ErrorCode
{
    Error_CODE_BASE                 = 2000,
    Error_INCORRECT_NB_READ,       /* 2001 */
    Error_INCORRECT_NB_WRITTEN,    /* 2002 */
    Error_DLL_LOAD,                /* 2003 */
    Error_ENUM_VAL_UNKNOWN,        /* 2004 */
    Error_COULD_NOT_WRITE_ITEM,    /* 2005 */
    Error_REGISTER_TYPE_UNKNOWN,   /* 2006 */
    Error_ENUM_OUT_OF_RANGE,       /* 2007 */
    Error_TYPE_IS_NOT_ENUMERATE,   /* 2008 */
    Error_VALUE_NOT_IN_ENUM_LIST,  /* 2009 */
    Error_COULD_NOT_UPDATE_ITEM,   /* 2010 */
    Error_VALUE_OUT_OF_RANGE,      /* 2011 */
    Error_UNKNOW_REGISTER,         /* 2012 */
    Error_READ_TRACES_ERROR,       /* 2013 */
    Error_WRITE_TRACES_ERROR,      /* 2014 */
    Error_UNKNOWN_COMMAND,         /* 2015 */
    Error_BUFFER_DOES_NOT_CONTAIN_REQUIRED_DATA         /* 2016 */
} ErrorCode;

typedef struct L1_Context {
  L0_Context *i2c;
  void       *specific;
} L1_Context;

#ifdef __cplusplus
extern "C" {
#endif

    #ifdef    SiTRACES
    void   SiTraceDefaultConfiguration(void);
    void   SiTraceFunction     (const char *name, int trace_linenumber, const char *func, const char *fmt, ...);
    char * SiTraceConfiguration(const char *config);
    #else
    #define SiTraceDefaultConfiguration(...) /* empty */
    #endif /* SiTRACES */

extern    char   *L0_error_message;

    int     system_wait    (int time_ms);
    int     system_time    (void);

    int     strcmp_nocase  (const char* str1, const char* str2);
    int     strcmp_nocase_n(const char* str1, const char* str2, unsigned int n);
    int     L0_StoreError  (const char *message);
    int     L0_ErrorMessage(void);

    void    L0_Init              (L0_Context* i2c); /* initialize the Layer 0 DLL. It sets the layer 0 context parameters to startup values. It must be called first. It is automatically called by the Layer 1 init function.*/
    int     L0_Connect           (L0_Context* i2c, CONNECTION_TYPE connType); /* Select the connection mode */
    char*   L0_InterfaceType     (L0_Context* i2c);
    int     L0_SetAddress        (L0_Context* i2c, unsigned int add, int addSize); /* set the IP's i2c address. It must be called only once at startup, as the IP's address is not expected to change over time.*/
    int     L0_ReadBytes         (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pbtDataBuffer) ;/* read  iNbBytes bytes from the IP. A buffer large enough to hold the values needs to be reserved by the upper layer.*/
    int     L0_WriteBytes        (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pbtDataBuffer); /* write iNbBytes bytes in the IP. The referenced buffer contains the bytes to be written.*/
    void    L0_TrackRead         (L0_Context* i2c, unsigned int track); /* toggle the read traces. Useful for debug purposes, mostly to control that data read in the IP is properly translated to the above layers.*/
    void    L0_TrackWrite        (L0_Context* i2c, unsigned int track); /* toggle the write traces at the lower possible layer. Useful for debug purposes, to check the i2C bus data sent to the IP.*/

    int     L0_ReadRawBytes      (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pbtDataBuffer);
    int     L0_WriteRawBytes     (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pbtDataBuffer);

    int     L0_ReadCommandBytes  (L0_Context* i2c, int iNbBytes, unsigned char *pucDataBuffer);
    int     L0_WriteCommandBytes (L0_Context* i2c, int iNbBytes, unsigned char *pucDataBuffer);

    long    L0_ReadRegister      (L0_Context *i2c,                           unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned int isSigned);
    long    L0_ReadRegisterTrace (L0_Context *i2c, char* name,               unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned int isSigned);
    long    L0_WriteRegister     (L0_Context *i2c,                           unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned char alone, long Value);
    long    L0_WriteRegisterTrace(L0_Context *i2c, char* name, char* valtxt, unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned char alone, long Value);

    int     L0_ReadString        (L0_Context* i2c, char *readString, unsigned char *pbtDataBuffer);
    int     L0_WriteString       (L0_Context* i2c, char *writeString);
    char*   Si_I2C_TAG_TEXT      (void);

    int     L0_FastI2C           (void);
    int     L0_SlowI2C           (void);

#ifdef    USB_Capability
    int     L0_Cypress_Process   (const char *cmd, const char *text, double dval, double *retdval, char **rettxt);
    int     L0_Cypress_Configure (const char *cmd, const char *text, double dval, double *retdval, char **rettxt);
    int     L0_Cypress_Cget      (const char *cmd, const char *text, double dval, double *retdval, char **rettxt);
#endif /* USB_Capability*/

#ifdef __cplusplus
}
#endif

#endif /* _L0_API_H_*/

