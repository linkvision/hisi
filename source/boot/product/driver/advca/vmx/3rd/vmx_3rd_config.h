/*******************************************************************
                   Copyright 2008 - 2013, Hisilicon Tech. Co., Ltd.
                             ALL RIGHTS RESERVED

Filename      : vmx_config.h
Author        : 
Creation time : 2016/1/16
Description   : 

Version       : 1.0
********************************************************************/
#include "hi_type.h"

#define RSA_N_LEN    (256)
#define RSA_E_LEN    (256)
#define KEY_LEN      (16)
#define HASH_SIZE (20*1024*1024)    //20M per round inside this interface for hash


HI_U8 g_au8VMX3RDRsaN[RSA_N_LEN]=
{
    0xd2, 0xce, 0x43, 0x15, 0xcc, 0xa9, 0xba, 0x8a, 0x43, 0x15, 0xe0, 0x37, 0x7c, 0x0d, 0x09, 0x07, 
    0xa8, 0x93, 0xa6, 0xd4, 0x20, 0x6e, 0x1a, 0x1a, 0x61, 0x5a, 0x08, 0xc2, 0x57, 0x35, 0xdb, 0xd2, 
    0xca, 0x9a, 0x41, 0x4d, 0x5c, 0xe6, 0x0d, 0x65, 0xc0, 0x43, 0xa5, 0xed, 0x7e, 0x91, 0x96, 0xf5, 
    0x41, 0x45, 0x0e, 0x63, 0x39, 0xec, 0x73, 0x59, 0xa8, 0xd3, 0x0e, 0x30, 0x95, 0xa4, 0xb4, 0x1c, 
    0xf4, 0x73, 0x89, 0x96, 0x78, 0x77, 0x7b, 0x8f, 0x7f, 0xe3, 0x4a, 0x6f, 0x8f, 0x3e, 0xdb, 0x8d, 
    0xc0, 0x2d, 0x4a, 0x55, 0x98, 0x37, 0xbe, 0xdd, 0x77, 0x34, 0xea, 0x5c, 0xe7, 0xbc, 0x5c, 0xac, 
    0xe9, 0xf4, 0x45, 0x95, 0xf4, 0x25, 0xad, 0x6f, 0xd7, 0xaa, 0x10, 0xe8, 0xd7, 0xbb, 0x90, 0xd9, 
    0x68, 0x5c, 0x64, 0x42, 0x6f, 0x8d, 0xca, 0x7d, 0x22, 0xdf, 0x0e, 0xe9, 0x84, 0xce, 0xbe, 0xc3, 
    0xb1, 0xa0, 0x90, 0xd6, 0x44, 0x72, 0x52, 0xca, 0xc3, 0x0f, 0xef, 0xd5, 0xe4, 0x38, 0x2c, 0xb2, 
    0x55, 0xcf, 0x87, 0x53, 0x9d, 0x32, 0x73, 0x49, 0x38, 0x3c, 0x71, 0x21, 0x66, 0x58, 0xea, 0x7a, 
    0x41, 0x41, 0x8f, 0x4c, 0x3f, 0x8f, 0x0e, 0x88, 0x57, 0xfa, 0xf6, 0x18, 0x42, 0x0e, 0xd1, 0x92, 
    0x93, 0xa6, 0x7c, 0xb3, 0x5e, 0x0d, 0x2b, 0x27, 0x2b, 0x78, 0x69, 0xc4, 0x81, 0x67, 0x1a, 0xf0, 
    0x8c, 0xec, 0x58, 0xd9, 0x07, 0x8e, 0x2c, 0x90, 0xb5, 0x40, 0xb5, 0x6d, 0xf0, 0x2d, 0xbb, 0x8f, 
    0xc8, 0x15, 0x5a, 0xcd, 0xd6, 0x93, 0xac, 0xf3, 0x8a, 0x8d, 0xb4, 0x0f, 0x75, 0x46, 0x7b, 0x30, 
    0xb9, 0x7c, 0x0f, 0x59, 0xce, 0x03, 0x6e, 0xa0, 0x9e, 0xf9, 0x67, 0xb9, 0xf6, 0x72, 0xfe, 0xfe, 
    0x8e, 0x4c, 0x5c, 0x04, 0x89, 0x0b, 0xb5, 0x7c, 0xdf, 0x27, 0x99, 0xbb, 0x23, 0xec, 0xde, 0xe1, 

};

HI_U8 g_au8VMX3RDRsaE[RSA_E_LEN] = 
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03
};

//Misc input config
HI_U8 g_u8MiscInput1[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
HI_U8 g_u8MiscInput2[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
HI_U8 g_u8MiscInput3[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
HI_U8 g_u8MiscInput4[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
HI_U8 g_u8MiscInput5[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

HI_U8 g_u8MiscInput6[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

//Encrypt SWPK config
//E1A6AB111AD31ECBC4166050472AE534
HI_U8 g_u8EncryptedSWPK[KEY_LEN] = {0xE1, 0xA6, 0xAB, 0x11, 0x1A, 0xD3, 0x1E, 0xCB, 0xC4, 0x16, 0x60, 0x50, 0x47, 0x2A, 0xE5, 0x34};
