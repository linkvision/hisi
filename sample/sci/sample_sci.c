#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "hi_unf_sci.h"

//lint -save -e14
//lint -save -e785
//lint -save -e133

HI_U8 rcv_buf[512];

/******************t0_irdeto_zeta*************************************/

HI_U8 t0_irdeto_zeta_send[][17] = {
    {0xd2, 0x42, 0x00, 0x00, 0x01},
    {0x1d},
    {0xd2, 0xfe, 0x00, 0x00, 0x19},
    {0xd2, 0x40, 0x00, 0x00, 0x11},
    {0x03, 0x06, 0x14, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x1d},
    {0xd2, 0xfe, 0x00, 0x00, 0x09},
    {0xd2, 0x3c, 0x00, 0x00, 0x01},
    {0x22},
    {0xd2, 0xfe, 0x00, 0x00, 0x15},
    {0xd2, 0x3e, 0x00, 0x00, 0x01},
    {0x23},
    {0xd2, 0xfe, 0x00, 0x00, 0x0b},
    {0xd2, 0x00, 0x00, 0x00, 0x01},
    {0x3c},
    {0xd2, 0xfe, 0x00, 0x00, 0x1d},
};
HI_U8 t0_irdeto_zeta_rcv[][32] = {
    { 0x42},
    {0x90,0x19},
    {0xfe, 0x01, 0x02, 0x00, 0x00,
     0x21, 0x00, 0x00, 0x10, 0x03,
     0x06, 0x14, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00,
     0x1c, 0x90, 0x00},
    { 0x40},
    {0x90,0x09},
    {0xfe, 0x01, 0x02, 0x00, 0x00,
     0x20, 0x00, 0x00, 0x00, 0x1c,
     0x90, 0x00},
    { 0x3c},
    {0x90,0x15},
    {0xfe, 0x01, 0x02, 0x00, 0x00,
     0x1e, 0x00, 0x00, 0x0c, 0x53,
     0x36, 0x01, 0x0e, 0x00, 0x08,
     0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x4c, 0x90, 0x00},
    { 0x3e},
    {0x90,0x0b},
    {0xfe, 0x01, 0x02, 0x00, 0x00,
     0x1f, 0x00, 0x00, 0x02, 0x00,
     0x02, 0x23, 0x90, 0x00},
    { 0x00},
    {0x90,0x1d},
    {0xfe, 0x01, 0x02, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x14, 0x34,
     0x30, 0x32, 0x30, 0x33, 0x32,
     0x35, 0x31, 0x35, 0x32, 0x54,
     0x36, 0x33, 0x38, 0x35, 0x30,
     0x30, 0x30, 0x41, 0x00, 0x01,
     0x90, 0x00},
};

HI_U32 t0_irdeto_zeta_send_len[15] = {5, 1, 5, 5, 17, 5, 5, 1, 5, 5, 1, 5, 5, 1, 5};
HI_U32 t0_irdeto_zeta_rcv_len[15] = {1, 2, 28, 1, 2, 12, 1, 2, 24, 1, 2, 14, 1, 2, 32};

#if 0

/**************************T1 suantong******************************************/
HI_U8 atr_suantong_t1[18] = {0x3b, 0xe9, 0x00, 0x00, 0x81,
                            0x31, 0xc3, 0x45, 0x99, 0x63,
                            0x74, 0x69, 0x19, 0x99, 0x12,
                            0x56, 0x10, 0xec};
HI_U32 atr_suantong_t1_cnt = 18;

HI_U8 t1_suantong_send[][18] = {
    {0x00, 0x00, 0x05, 0x00, 0x25, 0xa0, 0x21, 0x20, 0x81},
    {0x00, 0x00, 0x05, 0x80, 0xb5, 0x30, 0x01, 0x20, 0x21},
    {0x00, 0x00, 0x05, 0x81, 0xdd, 0x00, 0x10, 0x04, 0x4d},
    {0x00, 0x00, 0x05, 0x81, 0xd4, 0x00, 0x01, 0x05, 0x54},
    {0x00, 0x00, 0x05, 0x81, 0xd4, 0x00, 0x01, 0x0b, 0x5a},
    {0x00, 0x00, 0x05, 0x81, 0xd0, 0x00, 0x01, 0x08, 0x5d},
    {0x00, 0x00, 0x05, 0x81, 0xc0, 0x00, 0x01, 0x0a, 0x4f},
    {0x00, 0x00, 0x05, 0x00, 0x31, 0x05, 0x00, 0x08, 0x39},
    {0x00, 0x00, 0x0a, 0x33, 0x2e, 0x30, 0x34, 0x00, 0x00, 0x00,
     0x00, 0x90, 0x00, 0x83},
    {0x00, 0x00, 0x05, 0x81, 0xd1, 0x00, 0x01, 0x10, 0x44},
    {0x00, 0x00, 0x05, 0x81, 0xd2, 0x00, 0x01, 0x10, 0x47},
    {0x00, 0x00, 0x05, 0x81, 0xa3, 0x00, 0x00, 0x05, 0x22},
    {0x00, 0x00, 0x05, 0x81, 0xa3, 0x00, 0x01, 0x05, 0x23},
    {0x00, 0x00, 0x05, 0x00, 0x25, 0x00, 0x02, 0x01, 0x23},
    {0x00, 0x00, 0x0e, 0x02, 0x68, 0x00, 0x00, 0x09, 0x00, 0x00,
     0x00, 0x00, 0x01, 0x82, 0x02, 0x50, 0x03, 0xbf},
};
HI_U8 t1_suantong_rcv[][39] = {
    {0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x01, 0x90, 0x00, 0x9f},
    {0x00, 0x00, 0x23, 0xeb, 0x70, 0x11, 0x27, 0xc7, 0x72, 0xfc,
     0x84, 0xa4, 0x53, 0x39, 0x66, 0xe3, 0xc5, 0x5d, 0xa2, 0x34,
     0x27, 0x2b, 0xac, 0x1b, 0xf6, 0xf6, 0x5f, 0x49, 0xa7, 0x51,
     0x5e, 0x08, 0x00, 0xe5, 0xba, 0x0c, 0x90, 0x00, 0xc8},
    {0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x01, 0x90, 0x00,0x96},
    {0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x90, 0x00,
     0x96},
    {0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x01, 0x86, 0xf1, 0x90, 0x00, 0xeb},
    {0x00, 0x00, 0x0a, 0x28, 0x4b, 0x3c, 0x2a, 0x04, 0x99, 0x71,
     0xcf, 0x90, 0x00, 0xcc},
    {0x00, 0x00, 0x04, 0x30, 0x00, 0x90, 0x00,0xa4},
    {0x00, 0x00, 0x0a, 0x33, 0x2e, 0x30, 0x34, 0x00, 0x00, 0x00,
     0x00, 0x90, 0x00, 0x83},
    {0x00, 0x00, 0x12, 0x00, 0x1c, 0xdc, 0x33, 0x3e, 0x9f, 0xc8,
     0x0a, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x90,
     0x00, 0x12},
    {0x00, 0x00, 0x12, 0x50, 0x61, 0x79, 0x5f, 0x54, 0x56, 0x5f,
     0x43, 0x61, 0x72, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
     0x00, 0xfc},
    {0x00, 0x00, 0x07, 0x1c, 0x21, 0x0e, 0x15, 0x00, 0x90, 0x00,
     0xb1},
    {0x00, 0x00, 0x07, 0x2a, 0x87, 0x0e, 0x15, 0x00, 0x90, 0x00,
     0x21},
    {0x00, 0x00, 0x08, 0x00, 0x25, 0x00, 0x02, 0x01, 0x09, 0x90,
     0x00, 0xb7},
    {0x00, 0x00, 0x20, 0x50, 0x09, 0x1b, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x90, 0x00, 0xc2},
};
HI_U32 t1_suantong_send_len[15] = {9, 9, 9, 9, 9, 9, 9, 9, 14, 9, 9, 9, 9, 9, 18};
HI_U32 t1_suantong_rcv_len[15] = {18, 39, 10, 11, 17, 14, 8, 14, 22, 22, 11, 11, 12, 36};

#else

/***************************T1 suantong*******************************************/
HI_U8 atr_suantong_t1[18] = {0x3b, 0xe9, 0x00, 0x00, 0x81,
                            0x31, 0xc3, 0x45, 0x99, 0x63,
                            0x74, 0x69, 0x19, 0x99, 0x12,
                            0x56, 0x10, 0xec};
HI_U32 atr_suantong_t1_cnt = 18;
HI_U8 t1_suantong_send[][23] = { //[][6]
    {0x00, 0x00, 0x06, 0x00, 0x32, 0x10, 0x01, 0x01, 0x01, 0x25},

    //{0x00, 0x00, 0x05, 0x00, 0x84, 0x00, 0x00, 0x10, 0x91},
    {0x00, 0x00, 0x05, 0x00, 0x25, 0xa0, 0x21, 0x20,0x81},
    {0x00, 0x00, 0x05, 0x81, 0xdd, 0x00, 0x10, 0x04,0x4d},
    {0x00, 0x00, 0x05, 0x81, 0xd4, 0x00, 0x01, 0x05,0x54},
    {0x00, 0x00, 0x05, 0x81, 0xd4, 0x00, 0x01, 0x0b,0x5a},
    {0x00, 0x00, 0x05, 0x81, 0xd0, 0x00, 0x01, 0x08,0x5d},
    {0x00, 0x00, 0x05, 0x81, 0xc0, 0x00, 0x01, 0x0a,0x4f},
    {0x00, 0x00, 0x05, 0x00, 0x31, 0x05, 0x00, 0x08,0x39},
    {0x00, 0x00, 0x05, 0x81, 0xd1, 0x00, 0x01, 0x10,0x44},
    {0x00, 0x00, 0x05, 0x81, 0xd2, 0x00, 0x01, 0x10,0x47},
    {0x00, 0x00, 0x05, 0x81, 0xa3, 0x00, 0x00, 0x05,0x22},
    {0x00, 0x00, 0x05, 0x81, 0xa3, 0x00, 0x01, 0x05,0x23},
    {0x00, 0x00, 0x05, 0x00, 0x25, 0x00, 0x02, 0x01,0x23},
    {0x00, 0x00, 0x0e, 0x02, 0x68, 0x00, 0x00, 0x09, 0x00, 0x00,
     0x00, 0x00, 0x01, 0x82, 0x02, 0x50, 0x03, 0xbf},
    {0x00, 0x00, 0x13, 0x02, 0x68, 0x00, 0x00, 0x0e, 0x00, 0x00,
     0x00, 0x00, 0x01, 0x82, 0x07, 0x90, 0x03, 0x00, 0x00, 0x10,
     0xa7, 0x10, 0xc7},
    {0x00, 0x00, 0x13, 0x02, 0x68, 0x00, 0x00, 0x0e, 0x00, 0x00,
     0x00, 0x00, 0x01, 0x82, 0x07, 0x90, 0x03, 0x00, 0x00, 0x20,
     0xa7, 0x10, 0xf7},
    {0x00, 0x00, 0x13, 0x02, 0x68, 0x00, 0x00, 0x0e, 0x00, 0x00,
     0x00, 0x00, 0x01, 0x82, 0x07, 0x90, 0x03, 0x00, 0x00, 0x30,
     0xa7, 0x10, 0xe7},
    {0x00, 0x00, 0x05, 0x81, 0xd4, 0x00, 0x01, 0x0b,0x5a},
    {0x00, 0x00, 0x05, 0x00, 0x25, 0x80, 0x14, 0x01,0xb5},
};
HI_U8 t1_suantong_rcv[][36] = { //[][13]
    {0x00, 0x00, 0x02, 0x90, 0x00, 0x92},

    //{0x00, 0x00, 0x12, 0xd0, 0x9d, 0x75, 0xb4, 0xcf, 0x06, 0xd4, 0xa9, 0x5c, 0x02, 0x5f, 0x56, 0xb1, 0xa9,
    //0xf1, 0xf3, 0x90, 0x00, 0xf7},
    {0x00, 0x00, 0x02, 0x6a, 0x86, 0xee},
    {0x00, 0x00, 0x06, 0x00, 0x01,0x00,0x01,0x90,0x00,0x96},
    {0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x90, 0x00,
     0x96},
    {0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x01, 0x86, 0xf1, 0x90, 0x00, 0xeb},
    {0x00, 0x00, 0x0a, 0x33, 0xc5, 0xcf, 0xc0, 0x02, 0xed, 0x02,
     0x7b, 0x90, 0x00, 0xf5},
    {0x00, 0x00, 0x04, 0x30, 0x00,0x90,0x00,0xa4},
    {0x00, 0x00, 0x0a, 0x32, 0x2e, 0x35, 0x31, 0x00, 0x00, 0x00,
     0x00, 0x90, 0x00, 0x82},
    {0x00, 0x00, 0x12, 0x00, 0x1c, 0x6b, 0xf6, 0x14, 0x9f, 0x39,
     0xe9, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x90,
     0x00, 0x58},
    {0x00, 0x00, 0x12, 0x43, 0x54, 0x49, 0x5f, 0xd3, 0xc3, 0xbb,
     0xa7, 0xbf, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
     0x00, 0x98},
    {0x00, 0x00, 0x07, 0x1c, 0x29, 0x0b, 0x20, 0x00, 0x90, 0x00,
     0x89},
    {0x00, 0x00, 0x07, 0x20, 0xa9, 0x0b, 0x20, 0x00, 0x90, 0x00,
     0x35},
    {0x00, 0x00, 0x08, 0x00, 0x25, 0x00, 0x02, 0x01, 0x12, 0x90,
     0x00, 0xac},
    {0x00, 0x00, 0x20, 0x50, 0x09, 0x1b, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0x30, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x90, 0x00, 0xf2},
    {0x00, 0x00, 0x14, 0xa7, 0x10, 0x53, 0x54, 0x42, 0x20, 0x54,
     0x65, 0x61, 0x6d, 0x28, 0x43, 0x41, 0x29, 0x00, 0x00, 0x00,
     0x00, 0x90, 0x00, 0x68},
    {0x00, 0x00, 0x14, 0xa7, 0x10, 0x32, 0xb1, 0xb1, 0xbe, 0xa9,
     0xb6, 0xfe, 0xcc, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x90, 0x00, 0x3a},
    {0x00, 0x00, 0x14, 0xa7, 0x10, 0x33, 0xb1, 0xb1, 0xbe, 0xa9,
     0xc8, 0xfd, 0xcc, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x90, 0x00, 0x46},
    {0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x01, 0x86, 0xf1, 0x90, 0x00, 0xeb},
    {0x00, 0x00, 0x02, 0x6a, 0x86, 0xee},
};
HI_U32 t1_suantong_send_len[19] = {10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 18, 23, 23, 23, 9, 9}; //{6,5,5,5};
HI_U32 t1_suantong_rcv_len[19] = {6, 6, 10, 11, 17, 14, 8, 14, 22, 22, 11, 11, 12, 36, 24, 24, 24, 17, 6};

#endif

/******************t14_irdeto_access*************************************/
HI_U8 atr_irdeto_access_t14[20] = {0x3b, 0x9f, 0x21,  0xe, 0x49, 0x52, 0x44, 0x45,
                                  0x54, 0x4f, 0x20, 0x41, 0x43, 0x53, 0x20, 0x56,
                                  0x32, 0x2e, 0x32, 0x98};
HI_U32 atr_irdeto_access_t14_cnt = 20;
HI_U8 t14_irdeto_access_send[][7] = {
    {0x1, 0x2, 0x0, 0x0, 0x0, 0x0, 0x3c},
    {0x1, 0x2, 0x1, 0x0, 0x0, 0x0, 0x3d},
    {0x1, 0x2, 0x2, 0x0, 0x0, 0x0, 0x3e},
    {0x1, 0x2, 0x8, 0x0, 0x0, 0x0, 0x34},
    {0x1, 0x2, 0x3, 0x0, 0x0, 0x0, 0x3f},
};
HI_U8 t14_irdeto_access_rcv[][73] = {
    {0x1, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14,
     0x34, 0x30, 0x30, 0x32, 0x33, 0x33, 0x30, 0x34,
     0x39, 0x34, 0x54, 0x33, 0x32, 0x34, 0x30, 0x31,
     0x41, 0x0, 0x0, 0x0, 0x6},
    {0x1, 0x2, 0x0, 0x0, 0x1, 0x0, 0x0, 0x10,
     0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x4, 0x7, 0x37, 0x94, 0xe6, 0x18,
     0x8c},
    {0x1, 0x2, 0x0, 0x0, 0x2, 0x0, 0x0, 0x10,
     0x4, 0x6, 0x12, 0x6, 0x23, 0x6, 0x24, 0x6,
     0x25, 0x6, 0x26, 0x0, 0x0, 0x43, 0x48, 0x4e,
     0x7f},
    {0x1, 0x2, 0x0, 0x0, 0x8, 0x0, 0x0, 0x40,
     0x0, 0x1, 0x8, 0x20, 0x0, 0x15, 0x60, 0x2,
     0x60, 0x0, 0x0, 0x3, 0x81, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0xc8},
    {0x1, 0x2, 0x0, 0x0, 0x3, 0x0, 0x0, 0x18,
     0x0, 0x3, 0xe9, 0x97, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x2, 0x11, 0x1, 0x1, 0x0, 0x0,
     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x49},
};
HI_U32 t14_irdeto_access_send_len[5] = {7, 7, 7, 7, 7};
HI_U32 t14_irdeto_access_rcv_len[5] = {29, 25, 25, 73, 33};

/********************t0_crypto_send*******************************/
HI_U8 t0_crypto_send[][5] = {
    {0xa4, 0xc0, 0x00, 0x00, 0x11},
    {0xa4, 0xa4, 0x00, 0x00, 0x02},
    {0x3f,0x00},
    {0xa4, 0xa4, 0x00, 0x00, 0x02},
    {0x2f,0x01},
    {0xa4, 0xa2, 0x00, 0x00, 0x01},
    {0xd1},
};
HI_S32 t0_crypto_send_len[7] = {5, 5, 2, 5, 2, 5, 1};

HI_U8 t0_crypto_rcv[][20] = {
    {0xc0, 0xdf, 0x0f, 0x05, 0x04, 0x00, 0x09, 0x3f, 0x00, 0x01,
     0x00, 0xf0, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x90, 0x00},
    {0xa4},
    {0x9f,0x11},
    {0xa4},
    {0x9f,0x11},
    {0xa2},
    {0x9f,0x04},
};
HI_S32 t0_crypto_rcv_len[7] = {20, 1, 2, 1, 2, 1, 2};

/********************************************************************/

static HI_U32 g_u32MaxSndLen;
static HI_U32 g_u32SndTimes;
static HI_U32 *g_pSndLen;
static HI_U8 *g_pSndBuf;

static HI_U32 g_u32MaxRcvLen;
static HI_U32 *g_pRcvLen;
static HI_U8 *g_pRcvBuf;

static HI_BOOL g_bDropWord;
static HI_U8 g_u8SCIPort = 0;

HI_S32 SelectCard(HI_U32 CardNo)
{
    if (0 == CardNo)
    {
        g_pSndBuf = (HI_U8*)t0_irdeto_zeta_send;
        g_pSndLen = t0_irdeto_zeta_send_len;
        g_u32MaxSndLen = sizeof(t0_irdeto_zeta_send[0]);
        g_u32SndTimes = sizeof(t0_irdeto_zeta_send) / sizeof(t0_irdeto_zeta_send[0]);

        g_pRcvBuf = (HI_U8*)t0_irdeto_zeta_rcv;
        g_pRcvLen = t0_irdeto_zeta_rcv_len;
        g_u32MaxRcvLen = sizeof(t0_irdeto_zeta_rcv[0]);
        g_bDropWord = HI_TRUE;
    }
    else if (1 == CardNo)
    {
        g_pSndBuf = (HI_U8*)t1_suantong_send;
        g_pSndLen = t1_suantong_send_len;
        g_u32MaxSndLen = sizeof(t1_suantong_send[0]);
        g_u32SndTimes = sizeof(t1_suantong_send) / sizeof(t1_suantong_send[0]);

        g_pRcvBuf = (HI_U8*)t1_suantong_rcv;
        g_pRcvLen = t1_suantong_rcv_len;
        g_u32MaxRcvLen = sizeof(t1_suantong_rcv[0]);
        g_bDropWord = HI_FALSE;
    }
    else if (14 == CardNo)
    {
        g_pSndBuf = (HI_U8*)t14_irdeto_access_send;
        g_pSndLen = t14_irdeto_access_send_len;
        g_u32MaxSndLen = sizeof(t14_irdeto_access_send[0]);
        g_u32SndTimes = sizeof(t14_irdeto_access_send) / sizeof(t14_irdeto_access_send[0]);

        g_pRcvBuf = (HI_U8*)t14_irdeto_access_rcv;
        g_pRcvLen = t14_irdeto_access_rcv_len;
        g_u32MaxRcvLen = sizeof(t14_irdeto_access_rcv[0]);
        g_bDropWord = HI_FALSE;
    }
    else
    {
        printf("not supported in this sample now\n");
        return HI_FAILURE;
    }

    return HI_SUCCESS;
}

HI_S32 CardOutProcess()
{
    return HI_SUCCESS;
}

HI_S32 CardInProcess()
{
    HI_S32 s32Ret;
    HI_UNF_SCI_STATUS_E u32SCIStatus;
    HI_S32 s32ResetTime;
    HI_U8 u8ATRCount;
    HI_U8 ATRBuf[255];
    HI_U32 u32TotalReadLen, u32ReadLen;
    HI_U32 u32SendLen;
    HI_U32 i, j;
    HI_U8 u8Result = 0;

    s32Ret = HI_UNF_SCI_ResetCard(g_u8SCIPort, 0);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }
    else
    {
        printf("Reset Card\n");
    }

    s32ResetTime = 0;
    while (1)
    {
        /* will exit reset when reseting out of 2S*/
        if (s32ResetTime >= 200)
        {
            printf("Reset Card Failure\n");
            return HI_FAILURE;
        }

        /*get SCI card status */
        s32Ret = HI_UNF_SCI_GetCardStatus(g_u8SCIPort, &u32SCIStatus);
        if (HI_SUCCESS != s32Ret)
        {
            printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
            return s32Ret;
        }
        else
        {
            if (u32SCIStatus >= HI_UNF_SCI_STATUS_READY)
            {
                /*reset Success*/
                printf("Reset Card Success\n");
                break;
            }
            else
            {
                printf("Reset Card Waiting...\n");
                usleep( 50000);
                s32ResetTime += 1;
            }
        }
    }

    /*get and print ATR message*/
    s32Ret = HI_UNF_SCI_GetATR(g_u8SCIPort, ATRBuf, 255, &u8ATRCount);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }

    printf("GetATR Count:%d\n", u8ATRCount);

    for (i = 0; i < u8ATRCount; i++)
    {
        printf("ATRBuf[%d]:%#x\n", i, ATRBuf[i]);
    }

    /* start send and receive data*/
    printf("now begin send and rcv\n");
    printf("we should send %d times\n", g_u32SndTimes);
    for (j = 0; j < g_u32SndTimes; j++)
    {
        printf("this is round %d\n", j);
        printf("send sequence:");
        for (i = 0; i < g_pSndLen[j]; i++)
        {
            printf("%#x ", g_pSndBuf[j * g_u32MaxSndLen + i]);
        }

        printf("\n");

        s32Ret = HI_UNF_SCI_Send(g_u8SCIPort, (HI_U8 *)g_pSndBuf + j * g_u32MaxSndLen, g_pSndLen[j], &u32SendLen, 5000);
        if ((HI_SUCCESS != s32Ret) || (g_pSndLen[j] != u32SendLen))
        {
            printf("%s->%d, HI_UNF_SCI_Send return %d SendLen:%d\n", __func__, __LINE__, s32Ret, u32SendLen);
            return s32Ret;
        }

        u32TotalReadLen = 0;
        while (u32TotalReadLen < g_pRcvLen[j])
        {
            s32Ret = HI_UNF_SCI_Receive(g_u8SCIPort, (HI_U8 *)&rcv_buf[u32TotalReadLen], 1, &u32ReadLen, 10000);
            if (s32Ret != HI_SUCCESS)
            {
                printf("%s->%d HI_UNF_SCI_Receive return %#x ReadLen:%d\n", __func__, __LINE__, s32Ret, u32ReadLen);
                return s32Ret;
            }

            if ((0x60 == rcv_buf[u32TotalReadLen]) && (HI_TRUE == g_bDropWord))
            {
                printf("drop 0x60\n");
                continue;
            }

            u32TotalReadLen++;
        }

        printf("expect rcv sequence:");
        for (i = 0; i < g_pRcvLen[j]; i++)
        {
            printf("%#x ", g_pRcvBuf[j * g_u32MaxRcvLen + i]);
        }

        printf("\nactual rcv sequence:");
        for (i = 0; i < g_pRcvLen[j]; i++)
        {
            if ((0x60 == rcv_buf[i]) && (HI_TRUE == g_bDropWord))
            {
                printf("drop 0x60\n");
                continue;
            }

            printf("%#x ", rcv_buf[i]);
            if ((0 == u8Result) && (rcv_buf[i] != g_pRcvBuf[j * g_u32MaxRcvLen + i]))
            {
                u8Result = 1;
            }
        }

        printf("\n");

        if (1 == u8Result)
        {
            printf("ERROR\n");
        }
        else
        {
            printf("OK\n");
        }

        u8Result = 0;
    }

    return HI_SUCCESS;
}

#define ACTION_CARDIN 0           /* card inset flag*/
#define ACTION_CARDOUT 1      /* card pull out flag*/
#define ACTION_NONE 2         /* card immobile */

HI_BOOL g_bCardStatus = HI_FALSE; /*g_bCardStatus = HI_TRUE indicate card in ;g_bCardStatus = HI_FALSE  indicate no card */
HI_U8 g_CardAction = ACTION_NONE;

HI_S32 CheckCa(HI_U8 *pAction)
{
    HI_S32 s32Ret;
    HI_U8 SciPort = g_u8SCIPort;
    HI_UNF_SCI_STATUS_E enStatus;
    HI_BOOL bStatus;

    s32Ret = HI_UNF_SCI_GetCardStatus(SciPort, &enStatus);
    if (HI_SUCCESS != s32Ret)
    {
        return HI_FAILURE;
    }

    if (enStatus <= HI_UNF_SCI_STATUS_NOCARD)
    {
        bStatus = HI_FALSE;  /*no card  */
    }
    else
    {
        bStatus = HI_TRUE;   /*have card*/
    }

    /* if bStatus is ture indicated the card have been pull out or push in */
    if (g_bCardStatus != bStatus)       
    {
        g_bCardStatus = bStatus;
        if (HI_TRUE == bStatus)
        {
            *pAction = ACTION_CARDIN;       /*card in  */
        }
        else
        {
            *pAction = ACTION_CARDOUT;    /*card out */
        }
    }
    else
    {
        *pAction = ACTION_NONE;        /*no operation*/
    }

    return HI_SUCCESS;
}

static HI_BOOL g_RunFlag1, g_RunFlag2;
static pthread_mutex_t g_SciMutex = PTHREAD_MUTEX_INITIALIZER;

HI_VOID* CheckSci(HI_VOID* args)
{
    HI_S32 Ret;

    while (g_RunFlag1)
    {
        pthread_mutex_lock(&g_SciMutex);
        Ret = CheckCa(&g_CardAction);
        if (HI_SUCCESS != Ret)
        {
            printf("CheckCa failed\n");
        }

        pthread_mutex_unlock(&g_SciMutex);
        usleep(50 * 1000);
    }

    return (HI_VOID*)HI_SUCCESS;
}

HI_VOID* RunSci(HI_VOID *args)
{
    HI_U8 CardAction;

    while (g_RunFlag2)
    {
        pthread_mutex_lock(&g_SciMutex);
        CardAction = g_CardAction;
        pthread_mutex_unlock(&g_SciMutex);
        if (ACTION_CARDIN == CardAction)
        {
            printf("CARD IN\n");
            CardInProcess();
        }
        else if (ACTION_CARDOUT == CardAction)
        {
            printf("CARD OUT\n");
            CardOutProcess();
        }
        else
        {
            //do nothing
        }

        usleep(50 * 1000);
    }

    return (HI_VOID*)HI_SUCCESS;
}

HI_S32 main(HI_S32 argc, HI_CHAR *argv[])
{
    HI_S32 s32Ret = HI_FAILURE;
    HI_U32 u32ClkMode;
    HI_U32 u32Freq;
    HI_U32 u32Level, u32Detect;
    HI_UNF_SCI_MODE_E enClkMode;
    HI_U32 u8ProtocolType;
    HI_UNF_SCI_PROTOCOL_E enProtocolType;
    HI_UNF_SCI_LEVEL_E enSciLevel;
    pthread_t task1, task2;
#if defined(CHIP_TYPE_hi3716mv330)
	HI_U32 u32ResetMode,u32VccEnMode;
	HI_UNF_SCI_MODE_E enResetMode,enVccEnMode;
#endif

#define STR_LEN (10)
    HI_CHAR a[STR_LEN];

    printf("please select protocol type: 0-T0 1-T1 14-T14 others-T0\n");
    printf("for most card, this should be use  0-T0\n");
    scanf("%s", a);
    u8ProtocolType = (HI_U32)strtoul(a, 0, 0);
    if ((0 != u8ProtocolType) && (1 != u8ProtocolType) && (14 != u8ProtocolType))
    {
        u8ProtocolType = 0;
    }

    printf("u8ProtocolType = %d\n", u8ProtocolType);
    s32Ret = SelectCard(u8ProtocolType);
    if (HI_SUCCESS != s32Ret)
    {
        return HI_FAILURE;
    }

    if (14 == u8ProtocolType)
    {
        enProtocolType = HI_UNF_SCI_PROTOCOL_T14;
        u32Freq = 6000;
    }
    else
    {
        enProtocolType = u8ProtocolType;

        u32Freq = 3570;
    }

    HI_UNF_SCI_Init();

    /*open SCI device */
    s32Ret = HI_UNF_SCI_Open(g_u8SCIPort, enProtocolType, u32Freq);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        HI_UNF_SCI_DeInit();
        return s32Ret;
    }

    printf("please config clk mode: 0-OD 1-CMOS\n");
    printf("for hisilicon demo board, this should be 1-CMOS\n");
    scanf("%s", a);
    u32ClkMode = strtoul(a, 0, 0);
    printf("u32ClkMode = %d\n", u32ClkMode);
    if (0 == u32ClkMode)
    {
        enClkMode = HI_UNF_SCI_MODE_OD;
    }
    else
    {
        enClkMode = HI_UNF_SCI_MODE_CMOS;
    }

    /*set SCI clk mode:  0-OD 1-CMOS . it reference the hardware design*/
    s32Ret = HI_UNF_SCI_ConfigClkMode(g_u8SCIPort, enClkMode);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        goto ERR1;
    }
#if defined(CHIP_TYPE_hi3716mv330)
	printf("please config reset mode: 0-OD 1-CMOS\n");
    printf("for hisilicon demo board, this should be 1-CMOS\n");
    scanf("%s", a);
    u32ResetMode = strtoul(a, 0, 0);
    printf("u32ResetMode = %d\n", u32ResetMode);
    if (0 == u32ClkMode)
    {
        enResetMode = HI_UNF_SCI_MODE_OD;
    }
    else
    {
        enResetMode = HI_UNF_SCI_MODE_CMOS;
    }

    /*set SCI reset mode:  0-OD 1-CMOS . it reference the hardware design*/
    s32Ret = HI_UNF_SCI_ConfigResetMode(g_u8SCIPort, enResetMode);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        goto ERR1;
    }

	printf("please config vccen mode: 0-OD 1-CMOS\n");
    printf("for hisilicon demo board, this should be 1-CMOS\n");
    scanf("%s", a);
    u32VccEnMode = strtoul(a, 0, 0);
    printf("u32VccEnMode = %d\n", u32VccEnMode);
    if (0 == u32ClkMode)
    {
        enVccEnMode = HI_UNF_SCI_MODE_OD;
    }
    else
    {
        enVccEnMode = HI_UNF_SCI_MODE_CMOS;
    }

    /*set SCI vccen mode:  0-OD 1-CMOS . it reference the hardware design*/
    s32Ret = HI_UNF_SCI_ConfigVccEnMode(g_u8SCIPort, enVccEnMode);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        goto ERR1;
    }
#endif

    printf("please config VccEn: 0-low level active 1-high level active\n");
    printf("for hisilicon demo board, this should be 0-low level active\n");
    scanf("%s", a);
    u32Level = (HI_U32)strtoul(a, 0, 0);
    if (!u32Level)
    {
        enSciLevel = HI_UNF_SCI_LEVEL_LOW;
    }
    else
    {
        enSciLevel = HI_UNF_SCI_LEVEL_HIGH;
    }

    printf("u32Level = %d\n", enSciLevel);

    /*set sci card power enable level.it reference the hardware design*/
    s32Ret = HI_UNF_SCI_ConfigVccEn(g_u8SCIPort, enSciLevel);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        goto ERR1;
    }

    printf("please config Detect: 0-low level active; 1-high level active\n");
    printf("for hisilicon demo board, this should be 1-high level active\n");
    scanf("%s", a);
    u32Detect = (HI_U32)strtoul(a, 0, 0);
    if (!u32Detect)
    {
        enSciLevel = HI_UNF_SCI_LEVEL_LOW;
    }
    else
    {
        enSciLevel = HI_UNF_SCI_LEVEL_HIGH;
    }

    printf("u32Detect = %d\n", enSciLevel);

    /*set sci card detect level.it reference the hardware design*/
    s32Ret = HI_UNF_SCI_ConfigDetect(g_u8SCIPort, enSciLevel);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%x\n", __FILE__, __LINE__, s32Ret);
        goto ERR1;
    }

    pthread_mutex_init(&g_SciMutex, NULL);

    /** create thread to checkca */
    g_RunFlag1 = 1;
    s32Ret = pthread_create(&task1, NULL, CheckSci, NULL);
    if (HI_SUCCESS != s32Ret)
    {
        goto ERR2;
    }

    /** Create thread to send and rcv data */
    g_RunFlag2 = 1;
    s32Ret = pthread_create(&task2, NULL, RunSci, NULL);
    if (HI_SUCCESS != s32Ret)
    {
        goto ERR3;
    }

    printf("Press any key to finish sci demo\n");
    getchar();
    getchar();

    g_RunFlag1 = 0;
    g_RunFlag2 = 0;

    pthread_join(task1, NULL);
    pthread_join(task2, NULL);

    pthread_mutex_destroy(&g_SciMutex);
    HI_UNF_SCI_DeactiveCard( g_u8SCIPort);
    HI_UNF_SCI_Close(g_u8SCIPort);

    printf("\nrun sci demo finished\n");
    return HI_SUCCESS;

ERR3:
    g_RunFlag1 = 0;
    pthread_join(task1, NULL);
ERR2:
    pthread_mutex_destroy(&g_SciMutex);
ERR1:
    HI_UNF_SCI_DeactiveCard( g_u8SCIPort);
    HI_UNF_SCI_Close(g_u8SCIPort);
    HI_UNF_SCI_DeInit();
    return HI_FAILURE;
}
//lint -restore

