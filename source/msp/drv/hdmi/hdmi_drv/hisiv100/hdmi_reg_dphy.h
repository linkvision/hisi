// ****************************************************************************** 
// Copyright     :  Copyright (C) 2016, Hisilicon Technologies Co. Ltd.
// File name     :  hdmi2tx_dphy_reg_c_union_define.h
// Project line  :  Platform And Key Technologies Development
// Department    :  CAD Development Department
// Author        :  xxx
// Version       :  1
// Date          :  2013/3/10
// Description   :  The description of xxx project
// Others        :  Generated automatically by nManager V4.0.2.5 
// History       :  xxx 2016/01/06 21:08:30 Create file
// ******************************************************************************

#ifndef __HDMI2TX_DPHY_REG_C_UNION_DEFINE_H__
#define __HDMI2TX_DPHY_REG_C_UNION_DEFINE_H__

/* Define the union U_HDMITX_INSSC_SET */
/* Define the union U_HDMITX_INSSC_SET,ATTR:RW,ADDR:0,INIT:C0000000,MASK:ffffffff,CMMNT:hdmi tx ssc in  ctrl0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_set               : 24  ; /* [23:0] */
        unsigned int    reg_set_load          : 1  ; /* [24] */
        unsigned int    reg_sscfifo_tune_en   : 1  ; /* [25] */
        unsigned int    reg_sscfifo_depth_clr : 1  ; /* [26] */
        unsigned int    reg_deep_color        : 2  ; /* [28:27] */
        unsigned int    reg_ssc_mode          : 1  ; /* [29] */
        unsigned int    reg_pllfbmash111_en   : 1  ; /* [30] */
        unsigned int    reg_sscin_bypass_en   : 1  ; /* [31] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_INSSC_SET;

/* Define the union U_HDMITX_INSSC_FIFO */
/* Define the union U_HDMITX_INSSC_FIFO,ATTR:RW,ADDR:4,INIT:01C01001,MASK:3fffffff,CMMNT:hdmi tx ssc  ctrl1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_tune_step            : 8  ; /* [7:0] */
        unsigned int    reg_sscfifo_lower_thresh : 10  ; /* [17:8] */
        unsigned int    reg_sscfifo_upper_thresh : 10  ; /* [27:18] */
        unsigned int    reg_tune_reverse         : 1  ; /* [28] */
        unsigned int    reg_ssc_sync             : 1  ; /* [29] */
        unsigned int    rsv_0                    : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_INSSC_FIFO;

/* Define the union U_HDMITX_INSSC_STEP */
/* Define the union U_HDMITX_INSSC_STEP,ATTR:RW,ADDR:8,INIT:00000000,MASK:ffffffff,CMMNT:hdmi tx ssc  ctrl2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_step  : 10  ; /* [9:0] */
        unsigned int    reg_span  : 14  ; /* [23:10] */
        unsigned int    reg_testd : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_INSSC_STEP;

/* Define the union U_HDMITX_INSSC_TUNE */
/* Define the union U_HDMITX_INSSC_TUNE,ATTR:RW,ADDR:C,INIT:00000000,MASK:ffffffff,CMMNT:hdmi tx ssc  ctrl3*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_tune_interval : 32  ; /* [31:0] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_INSSC_TUNE;

/* Define the union U_HDMITX_SSC_HK */
/* Define the union U_HDMITX_SSC_HK,ATTR:RW,ADDR:14,INIT:00000000,MASK:7f,CMMNT:*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_dnum           : 5  ; /* [4:0] */
        unsigned int    reg_hkmash_en      : 1  ; /* [5] */
        unsigned int    reg_mash111_hk_sel : 1  ; /* [6] */
        unsigned int    rsv_1              : 25  ; /* [31:7] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSC_HK;

/* Define the union U_HDMITX_SSCIN_STATUS0 */
/* Define the union U_HDMITX_SSCIN_STATUS0,ATTR:RW,ADDR:20,INIT:00000000,MASK:ffffff,CMMNT:SSC IN related status0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sscin_span_cnt     : 15  ; /* [14:0] */
        unsigned int    sscin_segment      : 2  ; /* [16:15] */
        unsigned int    sscin_stop_flag    : 1  ; /* [17] */
        unsigned int    sscin_reverse_flag : 1  ; /* [18] */
        unsigned int    sscin_div          : 5  ; /* [23:19] */
        unsigned int    rsv_2              : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCIN_STATUS0;

/* Define the union U_HDMITX_SSCIN_STATUS1 */
/* Define the union U_HDMITX_SSCIN_STATUS1,ATTR:RW,ADDR:24,INIT:00000000,MASK:ffffff,CMMNT:SSC IN related status1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sscin_ssc_offset : 24  ; /* [23:0] */
        unsigned int    rsv_3            : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCIN_STATUS1;

/* Define the union U_HDMITX_SSCIN_STATUS2 */
/* Define the union U_HDMITX_SSCIN_STATUS2,ATTR:RW,ADDR:28,INIT:00000000,MASK:fffff,CMMNT:SSC IN related status2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sscin_sscfifo_depth_max : 10  ; /* [9:0] */
        unsigned int    sscin_sscfifo_depth_min : 10  ; /* [19:10] */
        unsigned int    rsv_4                   : 12  ; /* [31:20] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCIN_STATUS2;

/* Define the union U_HDMITX_SSCFB_STATUS0 */
/* Define the union U_HDMITX_SSCFB_STATUS0,ATTR:RW,ADDR:2C,INIT:00000000,MASK:ffffff,CMMNT:SSC PLL FB status0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sscfb_span_cnt     : 15  ; /* [14:0] */
        unsigned int    sscfb_segment      : 2  ; /* [16:15] */
        unsigned int    sscfb_stop_flag    : 1  ; /* [17] */
        unsigned int    sscfb_reverse_flag : 1  ; /* [18] */
        unsigned int    sscfb_div          : 5  ; /* [23:19] */
        unsigned int    rsv_5              : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCFB_STATUS0;

/* Define the union U_HDMITX_SSCFB_STATUS1 */
/* Define the union U_HDMITX_SSCFB_STATUS1,ATTR:RW,ADDR:30,INIT:00000000,MASK:ffffff,CMMNT:SSC PLL FB status1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sscfb_ssc_offset : 24  ; /* [23:0] */
        unsigned int    rsv_6            : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCFB_STATUS1;

/* Define the union U_HDMITX_SSCFB_STATUS2 */
/* Define the union U_HDMITX_SSCFB_STATUS2,ATTR:RW,ADDR:34,INIT:00000000,MASK:fffff,CMMNT:SSC PLL FB status2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sscfb_sscfifo_depth_max : 10  ; /* [9:0] */
        unsigned int    sscfb_sscfifo_depth_min : 10  ; /* [19:10] */
        unsigned int    rsv_7                   : 12  ; /* [31:20] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCFB_STATUS2;

/* Define the union U_HDMITX_SSCFBMASH111_STATUS0 */
/* Define the union U_HDMITX_SSCFBMASH111_STATUS0,ATTR:RW,ADDR:38,INIT:00000000,MASK:ffffff,CMMNT:SSC PLL FB MASH111 status0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    fbmash_span_cnt     : 15  ; /* [14:0] */
        unsigned int    fbmash_segment      : 2  ; /* [16:15] */
        unsigned int    fbmash_stop_flag    : 1  ; /* [17] */
        unsigned int    fbmash_reverse_flag : 1  ; /* [18] */
        unsigned int    fbmash_div          : 5  ; /* [23:19] */
        unsigned int    rsv_8               : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCFBMASH111_STATUS0;

/* Define the union U_HDMITX_SSCFBMASH111_STATUS1 */
/* Define the union U_HDMITX_SSCFBMASH111_STATUS1,ATTR:RW,ADDR:3C,INIT:00000000,MASK:ffffff,CMMNT:SSC PLL FB MASH111 status1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    fbmash_ssc_offset : 24  ; /* [23:0] */
        unsigned int    rsv_9             : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCFBMASH111_STATUS1;

/* Define the union U_HDMITX_SSCFBMASH111_STATUS2 */
/* Define the union U_HDMITX_SSCFBMASH111_STATUS2,ATTR:RW,ADDR:40,INIT:00000000,MASK:fffff,CMMNT:SSC PLL FB MASH111 status2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    fbmash_sscfifo_depth_max : 10  ; /* [9:0] */
        unsigned int    fbmash_sscfifo_depth_min : 10  ; /* [19:10] */
        unsigned int    rsv_10                   : 12  ; /* [31:20] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_SSCFBMASH111_STATUS2;

/* Define the union U_HDMITX_AFIFO_DATA_H */
/* Define the union U_HDMITX_AFIFO_DATA_H,ATTR:RW,ADDR:4C,INIT:00000000,MASK:3fffffff,CMMNT:HDMITX AFIFO ctrl4*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_aphy_data_ch0_h : 10  ; /* [9:0] */
        unsigned int    reg_aphy_data_ch1_h : 10  ; /* [19:10] */
        unsigned int    reg_aphy_data_ch2_h : 10  ; /* [29:20] */
        unsigned int    rsv_11              : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_AFIFO_DATA_H;

/* Define the union U_HDMITX_AFIFO_DATA_SEL */
/* Define the union U_HDMITX_AFIFO_DATA_SEL,ATTR:RW,ADDR:50,INIT:00003E00,MASK:7ffff,CMMNT:HDMITX AFIFO ctrl0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_txafifo_status_rst : 1  ; /* [0] */
        unsigned int    reg_txafifo_rst        : 1  ; /* [1] */
        unsigned int    reg_aphy_data_ch0_sel  : 1  ; /* [2] */
        unsigned int    reg_aphy_data_ch1_sel  : 1  ; /* [3] */
        unsigned int    reg_aphy_data_ch2_sel  : 1  ; /* [4] */
        unsigned int    txafifo_aful_status    : 1  ; /* [5] */
        unsigned int    txafifo_full_status    : 1  ; /* [6] */
        unsigned int    txafifo_aempt_status   : 1  ; /* [7] */
        unsigned int    txafifo_empt_status    : 1  ; /* [8] */
        unsigned int    reg_aphy_data_clk_h    : 10  ; /* [18:9] */
        unsigned int    rsv_12                 : 13  ; /* [31:19] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_AFIFO_DATA_SEL;

/* Define the union U_HDMITX_AFIFO_CLK */
/* Define the union U_HDMITX_AFIFO_CLK,ATTR:RW,ADDR:54,INIT:01F07C1F,MASK:3fffffff,CMMNT:HDMITX AFIFO ctrl1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_aphy_data_clk_l : 30  ; /* [29:0] */
        unsigned int    rsv_13              : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_AFIFO_CLK;

/* Define the union U_HDMITX_AFIFO_DATA_L */
/* Define the union U_HDMITX_AFIFO_DATA_L,ATTR:RW,ADDR:58,INIT:00000000,MASK:3fffffff,CMMNT:HDMITX AFIFO ctrl2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_aphy_data_ch0 : 10  ; /* [9:0] */
        unsigned int    reg_aphy_data_ch1 : 10  ; /* [19:10] */
        unsigned int    reg_aphy_data_ch2 : 10  ; /* [29:20] */
        unsigned int    rsv_14            : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_AFIFO_DATA_L;

/* Define the union U_HDMITX_AFIFO_CHANNEL */
/* Define the union U_HDMITX_AFIFO_CHANNEL,ATTR:RW,ADDR:5C,INIT:00003440,MASK:7fff,CMMNT:HDMITX AFIFO ctrl3*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_prbs7_en        : 1  ; /* [0] */
        unsigned int    reg_prbs7_clr       : 1  ; /* [1] */
        unsigned int    reg_prbs7_errinject : 1  ; /* [2] */
        unsigned int    reg_ck_dataout_sel  : 3  ; /* [5:3] */
        unsigned int    reg_d0_dataout_sel  : 3  ; /* [8:6] */
        unsigned int    reg_d1_dataout_sel  : 3  ; /* [11:9] */
        unsigned int    reg_d2_dataout_sel  : 3  ; /* [14:12] */
        unsigned int    rsv_15              : 17  ; /* [31:15] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_AFIFO_CHANNEL;

/* Define the union U_APHY_STATUS0 */
/* Define the union U_APHY_STATUS0,ATTR:RW,ADDR:60,INIT:00000000,MASK:7,CMMNT:APHY output status signals*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ad_rxsense      : 1  ; /* [0] */
        unsigned int    ad_txpll_hvflag : 1  ; /* [1] */
        unsigned int    ad_txpll_lock   : 1  ; /* [2] */
        unsigned int    rsv_16          : 29  ; /* [31:3] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_STATUS0;

/* Define the union U_APHY_TOP_PD */
/* Define the union U_APHY_TOP_PD,ATTR:RW,ADDR:64,INIT:0017FFFF,MASK:7fffff,CMMNT:APHY top misc control register*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_gc_pd         : 4  ; /* [3:0] */
        unsigned int    reg_gc_pd_bist    : 1  ; /* [4] */
        unsigned int    reg_gc_pd_de      : 4  ; /* [8:5] */
        unsigned int    reg_gc_pd_ldo     : 2  ; /* [10:9] */
        unsigned int    reg_gc_pd_rterm   : 8  ; /* [18:11] */
        unsigned int    reg_gc_pd_rxsense : 1  ; /* [19] */
        unsigned int    reg_gc_txpll_pd   : 1  ; /* [20] */
        unsigned int    reg_divsel        : 2  ; /* [22:21] */
        unsigned int    rsv_17            : 9  ; /* [31:23] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_TOP_PD;

/* Define the union U_APHY_DRIVER_IMAIN */
/* Define the union U_APHY_DRIVER_IMAIN,ATTR:RW,ADDR:68,INIT:00C71C60,MASK:3fffffff,CMMNT:APHY driver related control0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_isel_main_clk    : 6  ; /* [5:0] */
        unsigned int    reg_isel_main_d0     : 6  ; /* [11:6] */
        unsigned int    reg_isel_main_d1     : 6  ; /* [17:12] */
        unsigned int    reg_isel_main_d2     : 6  ; /* [23:18] */
        unsigned int    reg_isel_main_de_clk : 6  ; /* [29:24] */
        unsigned int    rsv_18               : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_DRIVER_IMAIN;

/* Define the union U_APHY_DRIVER_IPRE */
/* Define the union U_APHY_DRIVER_IPRE,ATTR:RW,ADDR:6C,INIT:18180000,MASK:3fffffff,CMMNT:APHY driver related control1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_isel_main_de_d0 : 6  ; /* [5:0] */
        unsigned int    reg_isel_main_de_d1 : 6  ; /* [11:6] */
        unsigned int    reg_isel_main_de_d2 : 6  ; /* [17:12] */
        unsigned int    reg_isel_pre_clk    : 6  ; /* [23:18] */
        unsigned int    reg_isel_pre_d0     : 6  ; /* [29:24] */
        unsigned int    rsv_19              : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_DRIVER_IPRE;

/* Define the union U_APHY_DRIVER_IPREDE */
/* Define the union U_APHY_DRIVER_IPREDE,ATTR:RW,ADDR:70,INIT:00000618,MASK:3fffffff,CMMNT:APHY driver related control2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_isel_pre_d1     : 6  ; /* [5:0] */
        unsigned int    reg_isel_pre_d2     : 6  ; /* [11:6] */
        unsigned int    reg_isel_pre_de_clk : 6  ; /* [17:12] */
        unsigned int    reg_isel_pre_de_d0  : 6  ; /* [23:18] */
        unsigned int    reg_isel_pre_de_d1  : 6  ; /* [29:24] */
        unsigned int    rsv_20              : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_DRIVER_IPREDE;

/* Define the union U_APHY_DRIVER_RPRE */
/* Define the union U_APHY_DRIVER_RPRE,ATTR:RW,ADDR:74,INIT:0001B780,MASK:3fffffff,CMMNT:APHY driver related control3*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_isel_pre_de_d2  : 6  ; /* [5:0] */
        unsigned int    reg_rsel_pre_clk    : 3  ; /* [8:6] */
        unsigned int    reg_rsel_pre_d0     : 3  ; /* [11:9] */
        unsigned int    reg_rsel_pre_d1     : 3  ; /* [14:12] */
        unsigned int    reg_rsel_pre_d2     : 3  ; /* [17:15] */
        unsigned int    reg_rsel_pre_de_clk : 3  ; /* [20:18] */
        unsigned int    reg_rsel_pre_de_d0  : 3  ; /* [23:21] */
        unsigned int    reg_rsel_pre_de_d1  : 3  ; /* [26:24] */
        unsigned int    reg_rsel_pre_de_d2  : 3  ; /* [29:27] */
        unsigned int    rsv_21              : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_DRIVER_RPRE;

/* Define the union U_APHY_RTERM_CTRL */
/* Define the union U_APHY_RTERM_CTRL,ATTR:RW,ADDR:78,INIT:60606060,MASK:ffffffff,CMMNT:APHY R term related control*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_rt_clk : 8  ; /* [7:0] */
        unsigned int    reg_rt_d0  : 8  ; /* [15:8] */
        unsigned int    reg_rt_d1  : 8  ; /* [23:16] */
        unsigned int    reg_rt_d2  : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_RTERM_CTRL;

/* Define the union U_APHY_MISC_CTRL */
/* Define the union U_APHY_MISC_CTRL,ATTR:RW,ADDR:7C,INIT:00000000,MASK:7ff,CMMNT:APHY misc control*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_sel_ldo     : 6  ; /* [5:0] */
        unsigned int    reg_sel_rxsense : 3  ; /* [8:6] */
        unsigned int    reg_sr_clk      : 2  ; /* [10:9] */
        unsigned int    rsv_22          : 21  ; /* [31:11] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_MISC_CTRL;

/* Define the union U_APHY_TEST_CTRL */
/* Define the union U_APHY_TEST_CTRL,ATTR:RW,ADDR:80,INIT:00000000,MASK:ffffffff,CMMNT:APHY test related control*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_test    : 16  ; /* [15:0] */
        unsigned int    reg_test_dc : 16  ; /* [31:16] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_TEST_CTRL;

/* Define the union U_APHY_TXPLL_CTRL */
/* Define the union U_APHY_TXPLL_CTRL,ATTR:RW,ADDR:8C,INIT:0000C400,MASK:fffff,CMMNT:APHY TXPLL related control*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_txpll_clkin_sel         : 2  ; /* [1:0] */
        unsigned int    reg_txpll_divsel_in         : 3  ; /* [4:2] */
        unsigned int    reg_txpll_divsel_loop       : 7  ; /* [11:5] */
        unsigned int    reg_txpll_divsel_post       : 2  ; /* [13:12] */
        unsigned int    reg_txpll_icp_ictrl         : 4  ; /* [17:14] */
        unsigned int    reg_gc_txpll_en_ref_fb_div2 : 1  ; /* [18] */
        unsigned int    reg_gc_txpll_en_sscdiv      : 1  ; /* [19] */
        unsigned int    rsv_23                      : 12  ; /* [31:20] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_TXPLL_CTRL;

/* Define the union U_APHY_TXPLL_TEST */
/* Define the union U_APHY_TXPLL_TEST,ATTR:RW,ADDR:90,INIT:00000000,MASK:fffff,CMMNT:APHY TXPLL TEST related control*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_txpll_test : 20  ; /* [19:0] */
        unsigned int    rsv_24         : 12  ; /* [31:20] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_APHY_TXPLL_TEST;

/* Define the union U_PLL_LOCK_CTRL */
/* Define the union U_PLL_LOCK_CTRL,ATTR:RW,ADDR:94,INIT:0288080F,MASK:7ffffff,CMMNT:PLL_LOCK_CTRL*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_fb_div_sel       : 2  ; /* [1:0] */
        unsigned int    reg_fb_prd_sel       : 2  ; /* [3:2] */
        unsigned int    reg_ref_lock_timer   : 8  ; /* [11:4] */
        unsigned int    reg_ref_unlock_timer : 8  ; /* [19:12] */
        unsigned int    reg_pll_lock_sel     : 2  ; /* [21:20] */
        unsigned int    reg_pll_unlock_sel   : 1  ; /* [22] */
        unsigned int    reg_pll_lockext_sel  : 3  ; /* [25:23] */
        unsigned int    reg_pll_lock_times   : 1  ; /* [26] */
        unsigned int    rsv_25               : 5  ; /* [31:27] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_PLL_LOCK_CTRL;

/* Define the union U_PLL_LOCK_STATUS */
/* Define the union U_PLL_LOCK_STATUS,ATTR:RW,ADDR:98,INIT:00000000,MASK:1fffff,CMMNT:PLL_LOCK_STATUS*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_fb_exist     : 1  ; /* [0] */
        unsigned int    pll_ena_edge     : 1  ; /* [1] */
        unsigned int    test_pll_cnt     : 17  ; /* [18:2] */
        unsigned int    pll_lock_oneshot : 1  ; /* [19] */
        unsigned int    hdmi_clk_lock    : 1  ; /* [20] */
        unsigned int    rsv_26           : 11  ; /* [31:21] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_PLL_LOCK_STATUS;

/* Define the union U_REG_TXDPHY_DUMMY_CTRL */
/* Define the union U_REG_TXDPHY_DUMMY_CTRL,ATTR:RW,ADDR:9C,INIT:00000000,MASK:ffffffff,CMMNT:�����Ĵ���*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_txdphy_dummy_ctrl : 32  ; /* [31:0] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_REG_TXDPHY_DUMMY_CTRL;

/* Define the union U_HDMITX_FBSSC_SET */
/* Define the union U_HDMITX_FBSSC_SET,ATTR:RW,ADDR:B0,INIT:01640000,MASK:fffffff,CMMNT:hdmi tx ssc fb  ctrl0*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_set_fb               : 24  ; /* [23:0] */
        unsigned int    reg_set_load_fb          : 1  ; /* [24] */
        unsigned int    reg_sscfifo_tune_en_fb   : 1  ; /* [25] */
        unsigned int    reg_sscfifo_depth_clr_fb : 1  ; /* [26] */
        unsigned int    reg_ssc_mode_fb          : 1  ; /* [27] */
        unsigned int    rsv_27                   : 4  ; /* [31:28] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_FBSSC_SET;

/* Define the union U_HDMITX_FBSSC_FIFO */
/* Define the union U_HDMITX_FBSSC_FIFO,ATTR:RW,ADDR:B4,INIT:01C01001,MASK:3fffffff,CMMNT:hdmi tx ssc fb  ctrl1*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_tune_step_fb            : 8  ; /* [7:0] */
        unsigned int    reg_sscfifo_lower_thresh_fb : 10  ; /* [17:8] */
        unsigned int    reg_sscfifo_upper_thresh_fb : 10  ; /* [27:18] */
        unsigned int    reg_tune_reverse_fb         : 1  ; /* [28] */
        unsigned int    reg_ssc_sync_fb             : 1  ; /* [29] */
        unsigned int    rsv_28                      : 2  ; /* [31:30] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_FBSSC_FIFO;

/* Define the union U_HDMITX_FBSSC_STEP */
/* Define the union U_HDMITX_FBSSC_STEP,ATTR:RW,ADDR:B8,INIT:00074046,MASK:ffffffff,CMMNT:hdmi tx ssc fb  ctrl2*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_step_fb  : 10  ; /* [9:0] */
        unsigned int    reg_span_fb  : 14  ; /* [23:10] */
        unsigned int    reg_testd_fb : 8  ; /* [31:24] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_FBSSC_STEP;

/* Define the union U_HDMITX_FBSSC_TUNE */
/* Define the union U_HDMITX_FBSSC_TUNE,ATTR:RW,ADDR:BC,INIT:00000000,MASK:ffffffff,CMMNT:hdmi tx ssc fb  ctrl3*/
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reg_tune_interval_fb : 32  ; /* [31:0] */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} U_HDMITX_FBSSC_TUNE;


//==============================================================================
/* Define the global struct */
typedef struct
{
    volatile U_HDMITX_INSSC_SET            HDMITX_INSSC_SET            ; /* 0 */
    volatile U_HDMITX_INSSC_FIFO           HDMITX_INSSC_FIFO           ; /* 4 */
    volatile U_HDMITX_INSSC_STEP           HDMITX_INSSC_STEP           ; /* 8 */
    volatile U_HDMITX_INSSC_TUNE           HDMITX_INSSC_TUNE           ; /* C */
    volatile unsigned int           reserved_0                     ; /* 0x10 */
    volatile U_HDMITX_SSC_HK               HDMITX_SSC_HK               ; /* 14 */
    volatile unsigned int           reserved_1[2]                     ; /* 0x18~0x1c */
    volatile U_HDMITX_SSCIN_STATUS0        HDMITX_SSCIN_STATUS0        ; /* 20 */
    volatile U_HDMITX_SSCIN_STATUS1        HDMITX_SSCIN_STATUS1        ; /* 24 */
    volatile U_HDMITX_SSCIN_STATUS2        HDMITX_SSCIN_STATUS2        ; /* 28 */
    volatile U_HDMITX_SSCFB_STATUS0        HDMITX_SSCFB_STATUS0        ; /* 2C */
    volatile U_HDMITX_SSCFB_STATUS1        HDMITX_SSCFB_STATUS1        ; /* 30 */
    volatile U_HDMITX_SSCFB_STATUS2        HDMITX_SSCFB_STATUS2        ; /* 34 */
    volatile U_HDMITX_SSCFBMASH111_STATUS0 HDMITX_SSCFBMASH111_STATUS0 ; /* 38 */
    volatile U_HDMITX_SSCFBMASH111_STATUS1 HDMITX_SSCFBMASH111_STATUS1 ; /* 3C */
    volatile U_HDMITX_SSCFBMASH111_STATUS2 HDMITX_SSCFBMASH111_STATUS2 ; /* 40 */
    volatile unsigned int           reserved_2[2]                     ; /* 0x44~0x48 */
    volatile U_HDMITX_AFIFO_DATA_H         HDMITX_AFIFO_DATA_H         ; /* 4C */
    volatile U_HDMITX_AFIFO_DATA_SEL       HDMITX_AFIFO_DATA_SEL       ; /* 50 */
    volatile U_HDMITX_AFIFO_CLK            HDMITX_AFIFO_CLK            ; /* 54 */
    volatile U_HDMITX_AFIFO_DATA_L         HDMITX_AFIFO_DATA_L         ; /* 58 */
    volatile U_HDMITX_AFIFO_CHANNEL        HDMITX_AFIFO_CHANNEL        ; /* 5C */
    volatile U_APHY_STATUS0                APHY_STATUS0                ; /* 60 */
    volatile U_APHY_TOP_PD                 APHY_TOP_PD                 ; /* 64 */
    volatile U_APHY_DRIVER_IMAIN           APHY_DRIVER_IMAIN           ; /* 68 */
    volatile U_APHY_DRIVER_IPRE            APHY_DRIVER_IPRE            ; /* 6C */
    volatile U_APHY_DRIVER_IPREDE          APHY_DRIVER_IPREDE          ; /* 70 */
    volatile U_APHY_DRIVER_RPRE            APHY_DRIVER_RPRE            ; /* 74 */
    volatile U_APHY_RTERM_CTRL             APHY_RTERM_CTRL             ; /* 78 */
    volatile U_APHY_MISC_CTRL              APHY_MISC_CTRL              ; /* 7C */
    volatile U_APHY_TEST_CTRL              APHY_TEST_CTRL              ; /* 80 */
    volatile unsigned int           reserved_3[2]                     ; /* 0x84~0x88 */
    volatile U_APHY_TXPLL_CTRL             APHY_TXPLL_CTRL             ; /* 8C */
    volatile U_APHY_TXPLL_TEST             APHY_TXPLL_TEST             ; /* 90 */
    volatile U_PLL_LOCK_CTRL               PLL_LOCK_CTRL               ; /* 94 */
    volatile U_PLL_LOCK_STATUS             PLL_LOCK_STATUS             ; /* 98 */
    volatile U_REG_TXDPHY_DUMMY_CTRL       REG_TXDPHY_DUMMY_CTRL       ; /* 9C */
    volatile unsigned int           reserved_4[4]                     ; /* 0xa0~0xac */
    volatile U_HDMITX_FBSSC_SET            HDMITX_FBSSC_SET            ; /* B0 */
    volatile U_HDMITX_FBSSC_FIFO           HDMITX_FBSSC_FIFO           ; /* B4 */
    volatile U_HDMITX_FBSSC_STEP           HDMITX_FBSSC_STEP           ; /* B8 */
    volatile U_HDMITX_FBSSC_TUNE           HDMITX_FBSSC_TUNE        ; /* 0xbc */

} S_hdmi2tx_dphy_reg_REGS_TYPE;

/* Declare the struct pointor of the module hdmi2tx_dphy_reg */
extern volatile S_hdmi2tx_dphy_reg_REGS_TYPE *gophdmi2tx_dphy_regAllReg;

int HDMI_HDMITX_INSSC_reg_Init(void);
int HDMI_HDMITX_INSSC_reg_DeInit(void);
/* Declare the functions that set the member value */
int HDMI_HDMITX_INSSC_SET_reg_setSet(unsigned int ureg_set);
int HDMI_HDMITX_INSSC_SET_reg_setGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_set_loadSet(unsigned int ureg_set_load);
int HDMI_HDMITX_INSSC_SET_reg_set_loadGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_sscfifo_tune_enSet(unsigned int ureg_sscfifo_tune_en);
int HDMI_HDMITX_INSSC_SET_reg_sscfifo_tune_enGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_sscfifo_depth_clrSet(unsigned int ureg_sscfifo_depth_clr);
int HDMI_HDMITX_INSSC_SET_reg_sscfifo_depth_clrGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_deep_colorSet(unsigned int ureg_deep_color);
int HDMI_HDMITX_INSSC_SET_reg_deep_colorGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_ssc_modeSet(unsigned int ureg_ssc_mode);
int HDMI_HDMITX_INSSC_SET_reg_ssc_modeGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_pllfbmash111_enSet(unsigned int ureg_pllfbmash111_en);
int HDMI_HDMITX_INSSC_SET_reg_pllfbmash111_enGet(HI_VOID);
int HDMI_HDMITX_INSSC_SET_reg_sscin_bypass_enSet(unsigned int ureg_sscin_bypass_en);
int HDMI_HDMITX_INSSC_SET_reg_sscin_bypass_enGet(HI_VOID);
int HDMI_HDMITX_INSSC_FIFO_reg_tune_stepSet(unsigned int ureg_tune_step);
int HDMI_HDMITX_INSSC_FIFO_reg_tune_stepGet(HI_VOID);
int HDMI_HDMITX_INSSC_FIFO_reg_sscfifo_lower_threshSet(unsigned int ureg_sscfifo_lower_thresh);
int HDMI_HDMITX_INSSC_FIFO_reg_sscfifo_lower_threshGet(HI_VOID);
int HDMI_HDMITX_INSSC_FIFO_reg_sscfifo_upper_threshSet(unsigned int ureg_sscfifo_upper_thresh);
int HDMI_HDMITX_INSSC_FIFO_reg_sscfifo_upper_threshGet(HI_VOID);
int HDMI_HDMITX_INSSC_FIFO_reg_tune_reverseSet(unsigned int ureg_tune_reverse);
int HDMI_HDMITX_INSSC_FIFO_reg_tune_reverseGet(HI_VOID);
int HDMI_HDMITX_INSSC_FIFO_reg_ssc_syncSet(unsigned int ureg_ssc_sync);
int HDMI_HDMITX_INSSC_FIFO_reg_ssc_syncGet(HI_VOID);
int HDMI_HDMITX_INSSC_STEP_reg_stepSet(unsigned int ureg_step);
int HDMI_HDMITX_INSSC_STEP_reg_stepGet(HI_VOID);
int HDMI_HDMITX_INSSC_STEP_reg_spanSet(unsigned int ureg_span);
int HDMI_HDMITX_INSSC_STEP_reg_spanGet(HI_VOID);
int HDMI_HDMITX_INSSC_STEP_reg_testdSet(unsigned int ureg_testd);
int HDMI_HDMITX_INSSC_STEP_reg_testdGet(HI_VOID);
int HDMI_HDMITX_INSSC_TUNE_reg_tune_intervalSet(unsigned int ureg_tune_interval);
int HDMI_HDMITX_INSSC_TUNE_reg_tune_intervalGet(HI_VOID);
int HDMI_HDMITX_SSC_HK_reg_dnumSet(unsigned int ureg_dnum);
int HDMI_HDMITX_SSC_HK_reg_dnumGet(HI_VOID);
int HDMI_HDMITX_SSC_HK_reg_hkmash_enSet(unsigned int ureg_hkmash_en);
int HDMI_HDMITX_SSC_HK_reg_hkmash_enGet(HI_VOID);
int HDMI_HDMITX_SSC_HK_reg_mash111_hk_selSet(unsigned int ureg_mash111_hk_sel);
int HDMI_HDMITX_SSC_HK_reg_mash111_hk_selGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_span_cntSet(unsigned int usscin_span_cnt);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_span_cntGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_segmentSet(unsigned int usscin_segment);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_segmentGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_stop_flagSet(unsigned int usscin_stop_flag);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_stop_flagGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_reverse_flagSet(unsigned int usscin_reverse_flag);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_reverse_flagGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_divSet(unsigned int usscin_div);
int HDMI_HDMITX_SSCIN_STATUS0_sscin_divGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS1_sscin_ssc_offsetSet(unsigned int usscin_ssc_offset);
int HDMI_HDMITX_SSCIN_STATUS1_sscin_ssc_offsetGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS2_sscin_sscfifo_depth_maxSet(unsigned int usscin_sscfifo_depth_max);
int HDMI_HDMITX_SSCIN_STATUS2_sscin_sscfifo_depth_maxGet(HI_VOID);
int HDMI_HDMITX_SSCIN_STATUS2_sscin_sscfifo_depth_minSet(unsigned int usscin_sscfifo_depth_min);
int HDMI_HDMITX_SSCIN_STATUS2_sscin_sscfifo_depth_minGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_span_cntSet(unsigned int usscfb_span_cnt);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_span_cntGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_segmentSet(unsigned int usscfb_segment);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_segmentGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_stop_flagSet(unsigned int usscfb_stop_flag);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_stop_flagGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_reverse_flagSet(unsigned int usscfb_reverse_flag);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_reverse_flagGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_divSet(unsigned int usscfb_div);
int HDMI_HDMITX_SSCFB_STATUS0_sscfb_divGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS1_sscfb_ssc_offsetSet(unsigned int usscfb_ssc_offset);
int HDMI_HDMITX_SSCFB_STATUS1_sscfb_ssc_offsetGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS2_sscfb_sscfifo_depth_maxSet(unsigned int usscfb_sscfifo_depth_max);
int HDMI_HDMITX_SSCFB_STATUS2_sscfb_sscfifo_depth_maxGet(HI_VOID);
int HDMI_HDMITX_SSCFB_STATUS2_sscfb_sscfifo_depth_minSet(unsigned int usscfb_sscfifo_depth_min);
int HDMI_HDMITX_SSCFB_STATUS2_sscfb_sscfifo_depth_minGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_span_cntSet(unsigned int ufbmash_span_cnt);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_span_cntGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_segmentSet(unsigned int ufbmash_segment);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_segmentGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_stop_flagSet(unsigned int ufbmash_stop_flag);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_stop_flagGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_reverse_flagSet(unsigned int ufbmash_reverse_flag);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_reverse_flagGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_divSet(unsigned int ufbmash_div);
int HDMI_HDMITX_SSCFBMASH111_STATUS0_fbmash_divGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS1_fbmash_ssc_offsetSet(unsigned int ufbmash_ssc_offset);
int HDMI_HDMITX_SSCFBMASH111_STATUS1_fbmash_ssc_offsetGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS2_fbmash_sscfifo_depth_maxSet(unsigned int ufbmash_sscfifo_depth_max);
int HDMI_HDMITX_SSCFBMASH111_STATUS2_fbmash_sscfifo_depth_maxGet(HI_VOID);
int HDMI_HDMITX_SSCFBMASH111_STATUS2_fbmash_sscfifo_depth_minSet(unsigned int ufbmash_sscfifo_depth_min);
int HDMI_HDMITX_SSCFBMASH111_STATUS2_fbmash_sscfifo_depth_minGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_H_reg_aphy_data_ch0_hSet(unsigned int ureg_aphy_data_ch0_h);
int HDMI_HDMITX_AFIFO_DATA_H_reg_aphy_data_ch0_hGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_H_reg_aphy_data_ch1_hSet(unsigned int ureg_aphy_data_ch1_h);
int HDMI_HDMITX_AFIFO_DATA_H_reg_aphy_data_ch1_hGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_H_reg_aphy_data_ch2_hSet(unsigned int ureg_aphy_data_ch2_h);
int HDMI_HDMITX_AFIFO_DATA_H_reg_aphy_data_ch2_hGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_txafifo_status_rstSet(unsigned int ureg_txafifo_status_rst);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_txafifo_status_rstGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_txafifo_rstSet(unsigned int ureg_txafifo_rst);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_txafifo_rstGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_ch0_selSet(unsigned int ureg_aphy_data_ch0_sel);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_ch0_selGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_ch1_selSet(unsigned int ureg_aphy_data_ch1_sel);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_ch1_selGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_ch2_selSet(unsigned int ureg_aphy_data_ch2_sel);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_ch2_selGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_aful_statusSet(unsigned int utxafifo_aful_status);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_aful_statusGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_full_statusSet(unsigned int utxafifo_full_status);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_full_statusGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_aempt_statusSet(unsigned int utxafifo_aempt_status);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_aempt_statusGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_empt_statusSet(unsigned int utxafifo_empt_status);
int HDMI_HDMITX_AFIFO_DATA_SEL_txafifo_empt_statusGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_clk_hSet(unsigned int ureg_aphy_data_clk_h);
int HDMI_HDMITX_AFIFO_DATA_SEL_reg_aphy_data_clk_hGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CLK_reg_aphy_data_clk_lSet(unsigned int ureg_aphy_data_clk_l);
int HDMI_HDMITX_AFIFO_CLK_reg_aphy_data_clk_lGet(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_L_reg_aphy_data_ch0Set(unsigned int ureg_aphy_data_ch0);
int HDMI_HDMITX_AFIFO_DATA_L_reg_aphy_data_ch0Get(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_L_reg_aphy_data_ch1Set(unsigned int ureg_aphy_data_ch1);
int HDMI_HDMITX_AFIFO_DATA_L_reg_aphy_data_ch1Get(HI_VOID);
int HDMI_HDMITX_AFIFO_DATA_L_reg_aphy_data_ch2Set(unsigned int ureg_aphy_data_ch2);
int HDMI_HDMITX_AFIFO_DATA_L_reg_aphy_data_ch2Get(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_prbs7_enSet(unsigned int ureg_prbs7_en);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_prbs7_enGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_prbs7_clrSet(unsigned int ureg_prbs7_clr);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_prbs7_clrGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_prbs7_errinjectSet(unsigned int ureg_prbs7_errinject);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_prbs7_errinjectGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_ck_dataout_selSet(unsigned int ureg_ck_dataout_sel);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_ck_dataout_selGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_d0_dataout_selSet(unsigned int ureg_d0_dataout_sel);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_d0_dataout_selGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_d1_dataout_selSet(unsigned int ureg_d1_dataout_sel);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_d1_dataout_selGet(HI_VOID);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_d2_dataout_selSet(unsigned int ureg_d2_dataout_sel);
int HDMI_HDMITX_AFIFO_CHANNEL_reg_d2_dataout_selGet(HI_VOID);
int HDMI_APHY_STATUS0_ad_rxsenseSet(unsigned int uad_rxsense);
int HDMI_APHY_STATUS0_ad_rxsenseGet(HI_VOID);
int HDMI_APHY_STATUS0_ad_txpll_hvflagSet(unsigned int uad_txpll_hvflag);
int HDMI_APHY_STATUS0_ad_txpll_hvflagGet(HI_VOID);
int HDMI_APHY_STATUS0_ad_txpll_lockSet(unsigned int uad_txpll_lock);
int HDMI_APHY_STATUS0_ad_txpll_lockGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_pdSet(unsigned int ureg_gc_pd);
int HDMI_APHY_TOP_PD_reg_gc_pdGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_pd_bistSet(unsigned int ureg_gc_pd_bist);
int HDMI_APHY_TOP_PD_reg_gc_pd_bistGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_pd_deSet(unsigned int ureg_gc_pd_de);
int HDMI_APHY_TOP_PD_reg_gc_pd_deGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_pd_ldoSet(unsigned int ureg_gc_pd_ldo);
int HDMI_APHY_TOP_PD_reg_gc_pd_ldoGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_pd_rtermSet(unsigned int ureg_gc_pd_rterm);
int HDMI_APHY_TOP_PD_reg_gc_pd_rtermGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_pd_rxsenseSet(unsigned int ureg_gc_pd_rxsense);
int HDMI_APHY_TOP_PD_reg_gc_pd_rxsenseGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_gc_txpll_pdSet(unsigned int ureg_gc_txpll_pd);
int HDMI_APHY_TOP_PD_reg_gc_txpll_pdGet(HI_VOID);
int HDMI_APHY_TOP_PD_reg_divselSet(unsigned int ureg_divsel);
int HDMI_APHY_TOP_PD_reg_divselGet(HI_VOID);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_clkSet(unsigned int ureg_isel_main_clk);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_clkGet(HI_VOID);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_d0Set(unsigned int ureg_isel_main_d0);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_d0Get(HI_VOID);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_d1Set(unsigned int ureg_isel_main_d1);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_d1Get(HI_VOID);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_d2Set(unsigned int ureg_isel_main_d2);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_d2Get(HI_VOID);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_de_clkSet(unsigned int ureg_isel_main_de_clk);
int HDMI_APHY_DRIVER_IMAIN_reg_isel_main_de_clkGet(HI_VOID);
int HDMI_APHY_DRIVER_IPRE_reg_isel_main_de_d0Set(unsigned int ureg_isel_main_de_d0);
int HDMI_APHY_DRIVER_IPRE_reg_isel_main_de_d0Get(HI_VOID);
int HDMI_APHY_DRIVER_IPRE_reg_isel_main_de_d1Set(unsigned int ureg_isel_main_de_d1);
int HDMI_APHY_DRIVER_IPRE_reg_isel_main_de_d1Get(HI_VOID);
int HDMI_APHY_DRIVER_IPRE_reg_isel_main_de_d2Set(unsigned int ureg_isel_main_de_d2);
int HDMI_APHY_DRIVER_IPRE_reg_isel_main_de_d2Get(HI_VOID);
int HDMI_APHY_DRIVER_IPRE_reg_isel_pre_clkSet(unsigned int ureg_isel_pre_clk);
int HDMI_APHY_DRIVER_IPRE_reg_isel_pre_clkGet(HI_VOID);
int HDMI_APHY_DRIVER_IPRE_reg_isel_pre_d0Set(unsigned int ureg_isel_pre_d0);
int HDMI_APHY_DRIVER_IPRE_reg_isel_pre_d0Get(HI_VOID);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_d1Set(unsigned int ureg_isel_pre_d1);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_d1Get(HI_VOID);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_d2Set(unsigned int ureg_isel_pre_d2);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_d2Get(HI_VOID);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_de_clkSet(unsigned int ureg_isel_pre_de_clk);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_de_clkGet(HI_VOID);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_de_d0Set(unsigned int ureg_isel_pre_de_d0);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_de_d0Get(HI_VOID);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_de_d1Set(unsigned int ureg_isel_pre_de_d1);
int HDMI_APHY_DRIVER_IPREDE_reg_isel_pre_de_d1Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_isel_pre_de_d2Set(unsigned int ureg_isel_pre_de_d2);
int HDMI_APHY_DRIVER_RPRE_reg_isel_pre_de_d2Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_clkSet(unsigned int ureg_rsel_pre_clk);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_clkGet(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_d0Set(unsigned int ureg_rsel_pre_d0);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_d0Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_d1Set(unsigned int ureg_rsel_pre_d1);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_d1Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_d2Set(unsigned int ureg_rsel_pre_d2);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_d2Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_clkSet(unsigned int ureg_rsel_pre_de_clk);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_clkGet(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_d0Set(unsigned int ureg_rsel_pre_de_d0);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_d0Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_d1Set(unsigned int ureg_rsel_pre_de_d1);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_d1Get(HI_VOID);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_d2Set(unsigned int ureg_rsel_pre_de_d2);
int HDMI_APHY_DRIVER_RPRE_reg_rsel_pre_de_d2Get(HI_VOID);
int HDMI_APHY_RTERM_CTRL_reg_rt_clkSet(unsigned int ureg_rt_clk);
int HDMI_APHY_RTERM_CTRL_reg_rt_clkGet(HI_VOID);
int HDMI_APHY_RTERM_CTRL_reg_rt_d0Set(unsigned int ureg_rt_d0);
int HDMI_APHY_RTERM_CTRL_reg_rt_d0Get(HI_VOID);
int HDMI_APHY_RTERM_CTRL_reg_rt_d1Set(unsigned int ureg_rt_d1);
int HDMI_APHY_RTERM_CTRL_reg_rt_d1Get(HI_VOID);
int HDMI_APHY_RTERM_CTRL_reg_rt_d2Set(unsigned int ureg_rt_d2);
int HDMI_APHY_RTERM_CTRL_reg_rt_d2Get(HI_VOID);
int HDMI_APHY_MISC_CTRL_reg_sel_ldoSet(unsigned int ureg_sel_ldo);
int HDMI_APHY_MISC_CTRL_reg_sel_ldoGet(HI_VOID);
int HDMI_APHY_MISC_CTRL_reg_sel_rxsenseSet(unsigned int ureg_sel_rxsense);
int HDMI_APHY_MISC_CTRL_reg_sel_rxsenseGet(HI_VOID);
int HDMI_APHY_MISC_CTRL_reg_sr_clkSet(unsigned int ureg_sr_clk);
int HDMI_APHY_MISC_CTRL_reg_sr_clkGet(HI_VOID);
int HDMI_APHY_TEST_CTRL_reg_testSet(unsigned int ureg_test);
int HDMI_APHY_TEST_CTRL_reg_testGet(HI_VOID);
int HDMI_APHY_TEST_CTRL_reg_test_dcSet(unsigned int ureg_test_dc);
int HDMI_APHY_TEST_CTRL_reg_test_dcGet(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_clkin_selSet(unsigned int ureg_txpll_clkin_sel);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_clkin_selGet(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_divsel_inSet(unsigned int ureg_txpll_divsel_in);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_divsel_inGet(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_divsel_loopSet(unsigned int ureg_txpll_divsel_loop);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_divsel_loopGet(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_divsel_postSet(unsigned int ureg_txpll_divsel_post);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_divsel_postGet(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_icp_ictrlSet(unsigned int ureg_txpll_icp_ictrl);
int HDMI_APHY_TXPLL_CTRL_reg_txpll_icp_ictrlGet(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_gc_txpll_en_ref_fb_div2Set(unsigned int ureg_gc_txpll_en_ref_fb_div2);
int HDMI_APHY_TXPLL_CTRL_reg_gc_txpll_en_ref_fb_div2Get(HI_VOID);
int HDMI_APHY_TXPLL_CTRL_reg_gc_txpll_en_sscdivSet(unsigned int ureg_gc_txpll_en_sscdiv);
int HDMI_APHY_TXPLL_CTRL_reg_gc_txpll_en_sscdivGet(HI_VOID);
int HDMI_APHY_TXPLL_TEST_reg_txpll_testSet(unsigned int ureg_txpll_test);
int HDMI_APHY_TXPLL_TEST_reg_txpll_testGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_fb_div_selSet(unsigned int ureg_fb_div_sel);
int HDMI_PLL_LOCK_CTRL_reg_fb_div_selGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_fb_prd_selSet(unsigned int ureg_fb_prd_sel);
int HDMI_PLL_LOCK_CTRL_reg_fb_prd_selGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_ref_lock_timerSet(unsigned int ureg_ref_lock_timer);
int HDMI_PLL_LOCK_CTRL_reg_ref_lock_timerGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_ref_unlock_timerSet(unsigned int ureg_ref_unlock_timer);
int HDMI_PLL_LOCK_CTRL_reg_ref_unlock_timerGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_pll_lock_selSet(unsigned int ureg_pll_lock_sel);
int HDMI_PLL_LOCK_CTRL_reg_pll_lock_selGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_pll_unlock_selSet(unsigned int ureg_pll_unlock_sel);
int HDMI_PLL_LOCK_CTRL_reg_pll_unlock_selGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_pll_lockext_selSet(unsigned int ureg_pll_lockext_sel);
int HDMI_PLL_LOCK_CTRL_reg_pll_lockext_selGet(HI_VOID);
int HDMI_PLL_LOCK_CTRL_reg_pll_lock_timesSet(unsigned int ureg_pll_lock_times);
int HDMI_PLL_LOCK_CTRL_reg_pll_lock_timesGet(HI_VOID);
int HDMI_PLL_LOCK_STATUS_clk_fb_existSet(unsigned int uclk_fb_exist);
int HDMI_PLL_LOCK_STATUS_clk_fb_existGet(HI_VOID);
int HDMI_PLL_LOCK_STATUS_pll_ena_edgeSet(unsigned int upll_ena_edge);
int HDMI_PLL_LOCK_STATUS_pll_ena_edgeGet(HI_VOID);
int HDMI_PLL_LOCK_STATUS_test_pll_cntSet(unsigned int utest_pll_cnt);
int HDMI_PLL_LOCK_STATUS_test_pll_cntGet(HI_VOID);
int HDMI_PLL_LOCK_STATUS_pll_lock_oneshotSet(unsigned int upll_lock_oneshot);
int HDMI_PLL_LOCK_STATUS_pll_lock_oneshotGet(HI_VOID);
int HDMI_PLL_LOCK_STATUS_hdmi_clk_lockSet(unsigned int uhdmi_clk_lock);
int HDMI_PLL_LOCK_STATUS_hdmi_clk_lockGet(HI_VOID);
int HDMI_REG_TXDPHY_DUMMY_CTRL_reg_txdphy_dummy_ctrlSet(unsigned int ureg_txdphy_dummy_ctrl);
int HDMI_REG_TXDPHY_DUMMY_CTRL_reg_txdphy_dummy_ctrlGet(HI_VOID);
int HDMI_HDMITX_FBSSC_SET_reg_set_fbSet(unsigned int ureg_set_fb);
int HDMI_HDMITX_FBSSC_SET_reg_set_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_SET_reg_set_load_fbSet(unsigned int ureg_set_load_fb);
int HDMI_HDMITX_FBSSC_SET_reg_set_load_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_SET_reg_sscfifo_tune_en_fbSet(unsigned int ureg_sscfifo_tune_en_fb);
int HDMI_HDMITX_FBSSC_SET_reg_sscfifo_tune_en_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_SET_reg_sscfifo_depth_clr_fbSet(unsigned int ureg_sscfifo_depth_clr_fb);
int HDMI_HDMITX_FBSSC_SET_reg_sscfifo_depth_clr_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_SET_reg_ssc_mode_fbSet(unsigned int ureg_ssc_mode_fb);
int HDMI_HDMITX_FBSSC_SET_reg_ssc_mode_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_FIFO_reg_tune_step_fbSet(unsigned int ureg_tune_step_fb);
int HDMI_HDMITX_FBSSC_FIFO_reg_tune_step_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_FIFO_reg_sscfifo_lower_thresh_fbSet(unsigned int ureg_sscfifo_lower_thresh_fb);
int HDMI_HDMITX_FBSSC_FIFO_reg_sscfifo_lower_thresh_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_FIFO_reg_sscfifo_upper_thresh_fbSet(unsigned int ureg_sscfifo_upper_thresh_fb);
int HDMI_HDMITX_FBSSC_FIFO_reg_sscfifo_upper_thresh_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_FIFO_reg_tune_reverse_fbSet(unsigned int ureg_tune_reverse_fb);
int HDMI_HDMITX_FBSSC_FIFO_reg_tune_reverse_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_FIFO_reg_ssc_sync_fbSet(unsigned int ureg_ssc_sync_fb);
int HDMI_HDMITX_FBSSC_FIFO_reg_ssc_sync_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_STEP_reg_step_fbSet(unsigned int ureg_step_fb);
int HDMI_HDMITX_FBSSC_STEP_reg_step_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_STEP_reg_span_fbSet(unsigned int ureg_span_fb);
int HDMI_HDMITX_FBSSC_STEP_reg_span_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_STEP_reg_testd_fbSet(unsigned int ureg_testd_fb);
int HDMI_HDMITX_FBSSC_STEP_reg_testd_fbGet(HI_VOID);
int HDMI_HDMITX_FBSSC_TUNE_reg_tune_interval_fbSet(unsigned int ureg_tune_interval_fb);
int HDMI_HDMITX_FBSSC_TUNE_reg_tune_interval_fbGet(HI_VOID);

#endif // __HDMI2TX_DPHY_REG_C_UNION_DEFINE_H__
