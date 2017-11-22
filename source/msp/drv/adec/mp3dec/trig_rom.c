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
/**************************************************************************************
 * Hisilicon MP3 decoder
 * trigtabs.c - global ROM tables for pre-calculated trig coefficients
 **************************************************************************************/

#include "coder.h"
#include "assembly.h"
#include "arm_opt.h"

/* post-IMDCT window, win[blockType][i]
 * format = Q31
 * Fused sin window with final stage of IMDCT
 * includes 1/sqrt(2) scaling, since we scale by sqrt(2) in dequant in order
 *   for fast IMDCT36 to be usable
 * 
 * 	for(i=0;i<9;i++)   win[0][i] = sin(pi/36 *(i+0.5));
 * 	for(i=9;i<36;i++)  win[0][i] = -sin(pi/36 *(i+0.5));
 * 
 * 	for(i=0;i<9;i++)   win[1][i] = sin(pi/36 *(i+0.5));
 * 	for(i=9;i<18;i++)  win[1][i] = -sin(pi/36 *(i+0.5));
 * 	for(i=18;i<24;i++) win[1][i] = -1;
 * 	for(i=24;i<30;i++) win[1][i] = -sin(pi/12 *(i+0.5-18));
 * 	for(i=30;i<36;i++) win[1][i] = 0;
 * 
 * 	for(i=0;i<6;i++)   win[3][i] = 0;
 * 	for(i=6;i<9;i++)   win[3][i] = sin(pi/12 *(i+0.5-6));
 * 	for(i=9;i<12;i++)  win[3][i] = -sin(pi/12 *(i+0.5-6));
 * 	for(i=12;i<18;i++) win[3][i] = -1;
 * 	for(i=18;i<36;i++) win[3][i] = -sin(pi/36*(i+0.5));
 * 
 * 	for(i=0;i<3;i++)   win[2][i] = sin(pi/12*(i+0.5));
 * 	for(i=3;i<12;i++)  win[2][i] = -sin(pi/12*(i+0.5));
 * 	for(i=12;i<36;i++) win[2][i] = 0;
 * 
 * 	for (i = 0; i < 4; i++) {
 * 		if (i == 2) {
 * 			win[i][8]  *= cos(pi/12 * (0+0.5));
 * 			win[i][9]  *= cos(pi/12 * (0+0.5));
 * 			win[i][7]  *= cos(pi/12 * (1+0.5));
 * 			win[i][10] *= cos(pi/12 * (1+0.5));
 * 			win[i][6]  *= cos(pi/12 * (2+0.5));
 * 			win[i][11] *= cos(pi/12 * (2+0.5));
 * 			win[i][0]  *= cos(pi/12 * (3+0.5));
 * 			win[i][5]  *= cos(pi/12 * (3+0.5));
 * 			win[i][1]  *= cos(pi/12 * (4+0.5));
 * 			win[i][4]  *= cos(pi/12 * (4+0.5));
 * 			win[i][2]  *= cos(pi/12 * (5+0.5));
 * 			win[i][3]  *= cos(pi/12 * (5+0.5));
 * 		} else {
 * 			for (j = 0; j < 9; j++) {
 * 				win[i][8-j] *= cos(pi/36 * (17-j+0.5));
 * 				win[i][9+j] *= cos(pi/36 * (17-j+0.5));
 * 			}
 * 			for (j = 0; j < 9; j++) {
 * 				win[i][18+8-j] *= cos(pi/36 * (j+0.5));
 * 				win[i][18+9+j] *= cos(pi/36 * (j+0.5));
 * 			}
 * 		}
 * 	}
 *	for (i = 0; i < 4; i++)
 *		for (j = 0; j < 36; j++)
 * 			win[i][j] *= 1.0 / sqrt(2);
 */
const int imdctWin[4][36] = {
	{
	0x02aace8b, 0x07311c28, 0x0a868fec, 0x0c913b52, 0x0d413ccd, 0x0c913b52, 0x0a868fec, 0x07311c28, 
	0x02aace8b, 0xfd16d8dd, 0xf6a09e66, 0xef7a6275, 0xe7dbc161, 0xe0000000, 0xd8243e9f, 0xd0859d8b, 
	0xc95f619a, 0xc2e92723, 0xbd553175, 0xb8cee3d8, 0xb5797014, 0xb36ec4ae, 0xb2bec333, 0xb36ec4ae, 
	0xb5797014, 0xb8cee3d8, 0xbd553175, 0xc2e92723, 0xc95f619a, 0xd0859d8b, 0xd8243e9f, 0xe0000000, 
	0xe7dbc161, 0xef7a6275, 0xf6a09e66, 0xfd16d8dd, 
	},
	{
	0x02aace8b, 0x07311c28, 0x0a868fec, 0x0c913b52, 0x0d413ccd, 0x0c913b52, 0x0a868fec, 0x07311c28, 
	0x02aace8b, 0xfd16d8dd, 0xf6a09e66, 0xef7a6275, 0xe7dbc161, 0xe0000000, 0xd8243e9f, 0xd0859d8b, 
	0xc95f619a, 0xc2e92723, 0xbd44ef14, 0xb831a052, 0xb3aa3837, 0xafb789a4, 0xac6145bb, 0xa9adecdc, 
	0xa864491f, 0xad1868f0, 0xb8431f49, 0xc8f42236, 0xdda8e6b1, 0xf47755dc, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	},
	{
	0x07311c28, 0x0d413ccd, 0x07311c28, 0xf6a09e66, 0xe0000000, 0xc95f619a, 0xb8cee3d8, 0xb2bec333, 
	0xb8cee3d8, 0xc95f619a, 0xe0000000, 0xf6a09e66, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	},
	{
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x028e9709, 0x04855ec0, 
	0x026743a1, 0xfcde2c10, 0xf515dc82, 0xec93e53b, 0xe4c880f8, 0xdd5d0b08, 0xd63510b7, 0xcf5e834a, 
	0xc8e6b562, 0xc2da4105, 0xbd553175, 0xb8cee3d8, 0xb5797014, 0xb36ec4ae, 0xb2bec333, 0xb36ec4ae, 
	0xb5797014, 0xb8cee3d8, 0xbd553175, 0xc2e92723, 0xc95f619a, 0xd0859d8b, 0xd8243e9f, 0xe0000000, 
	0xe7dbc161, 0xef7a6275, 0xf6a09e66, 0xfd16d8dd, 
	},
};

/* indexing = [mid-side off/on][intensity scale factor]
 * format = Q30, range = [0.0, 1.414]
 *
 * mid-side off: 
 *   ISFMpeg1[0][i] = tan(i*pi/12) / [1 + tan(i*pi/12)]  (left scalefactor)
 *                  =      1       / [1 + tan(i*pi/12)]  (right scalefactor)
 *
 * mid-side on: 
 *   ISFMpeg1[1][i] = sqrt(2) * ISFMpeg1[0][i]
 *
 * output L = ISFMpeg1[midSide][isf][0] * input L
 * output R = ISFMpeg1[midSide][isf][1] * input L
 *
 * obviously left scalefactor + right scalefactor = 1 (m-s off) or sqrt(2) (m-s on)
 *   so just store left and calculate right as 1 - left 
 *  (can derive as right = ISFMpeg1[x][6] - left)
 *
 * if mid-side enabled, multiply joint stereo scale factors by sqrt(2)
 *   - we scaled whole spectrum by 1/sqrt(2) in Dequant for the M+S/sqrt(2) in MidSideProc
 *   - but the joint stereo part of the spectrum doesn't need this, so we have to undo it
 *
 * if scale factor is and illegal intensity position, this becomes a passthrough
 *   - gain = [1, 0] if mid-side off, since L is coded directly and R = 0 in this region
 *   - gain = [1, 1] if mid-side on, since L = (M+S)/sqrt(2), R = (M-S)/sqrt(2)
 *     - and since S = 0 in the joint stereo region (above NZB right) then L = R = M * 1.0
 */
const int ISFMpeg1[2][7] = {
	{0x00000000, 0x0d8658ba, 0x176cf5d0, 0x20000000, 0x28930a2f, 0x3279a745, 0x40000000},
	{0x00000000, 0x13207f5c, 0x2120fb83, 0x2d413ccc, 0x39617e16, 0x4761fa3d, 0x5a827999}
};

/* indexing = [intensity scale on/off][mid-side off/on][intensity scale factor]
 * format = Q30, range = [0.0, 1.414]
 *
 * if (isf == 0)                 kl = 1.0             kr = 1.0
 * else if (isf & 0x01 == 0x01)  kl = i0^((isf+1)/2), kr = 1.0
 * else if (isf & 0x01 == 0x00)  kl = 1.0,            kr = i0^(isf/2)
 *
 * if (intensityScale == 1)      i0 = 1/sqrt(2)       = 0x2d413ccc (Q30)
 * else                          i0 = 1/sqrt(sqrt(2)) = 0x35d13f32 (Q30)
 *
 * see comments for ISFMpeg1 (just above) regarding scaling, sqrt(2), etc.
 *
 * compress the MPEG2 table using the obvious identities above...
 * for isf = [0, 1, 2, ... 30], let sf = table[(isf+1) >> 1] 
 *   - if isf odd,  L = sf*L,     R = tab[0]*R
 *   - if isf even, L = tab[0]*L, R = sf*R
 */
const int ISFMpeg2[2][2][16] = {
{
	{
		/* intensityScale off, mid-side off */
		0x40000000, 0x35d13f32, 0x2d413ccc, 0x260dfc14, 0x1fffffff, 0x1ae89f99, 0x16a09e66, 0x1306fe0a, 
		0x0fffffff, 0x0d744fcc, 0x0b504f33, 0x09837f05, 0x07ffffff, 0x06ba27e6, 0x05a82799, 0x04c1bf82,
	},
	{
		/* intensityScale off, mid-side on */
		0x5a827999, 0x4c1bf827, 0x3fffffff, 0x35d13f32, 0x2d413ccc, 0x260dfc13, 0x1fffffff, 0x1ae89f99, 
		0x16a09e66, 0x1306fe09, 0x0fffffff, 0x0d744fcc, 0x0b504f33, 0x09837f04, 0x07ffffff, 0x06ba27e6, 
	},
},
{
	{
		/* intensityScale on, mid-side off */
		0x40000000, 0x2d413ccc, 0x20000000, 0x16a09e66, 0x10000000, 0x0b504f33, 0x08000000, 0x05a82799, 
		0x04000000, 0x02d413cc, 0x02000000, 0x016a09e6, 0x01000000, 0x00b504f3, 0x00800000, 0x005a8279, 
	},
		/* intensityScale on, mid-side on */
	{
		0x5a827999, 0x3fffffff, 0x2d413ccc, 0x1fffffff, 0x16a09e66, 0x0fffffff, 0x0b504f33, 0x07ffffff, 
		0x05a82799, 0x03ffffff, 0x02d413cc, 0x01ffffff, 0x016a09e6, 0x00ffffff, 0x00b504f3, 0x007fffff, 
	}
}
};

/* indexing = [intensity scale on/off][left/right]
 * format = Q30, range = [0.0, 1.414]
 *
 * illegal intensity position scalefactors (see comments on ISFMpeg1)
 */
const int ISFIIP[2][2] = {
	{0x40000000, 0x00000000}, /* mid-side off */
	{0x40000000, 0x40000000}, /* mid-side on */
};

const unsigned char uniqueIDTab[8] = {0x5f, 0x4b, 0x43, 0x5f, 0x5f, 0x4a, 0x52, 0x5f};

/* anti-alias coefficients - see spec Annex B, table 3-B.9 
 *   csa[0][i] = CSi, csa[1][i] = CAi
 * format = Q31
 */
const int csa[8][2] = {
	{0x6dc253f0, 0xbe2500aa}, 
	{0x70dcebe4, 0xc39e4949},
	{0x798d6e73, 0xd7e33f4a},
	{0x7ddd40a7, 0xe8b71176},
	{0x7f6d20b7, 0xf3e4fe2f},
	{0x7fe47e40, 0xfac1a3c7}, 
	{0x7ffcb263, 0xfe2ebdc6}, 
	{0x7fffc694, 0xff86c25d}, 
};

/* format = Q30, range = [0.0981, 1.9976]
 *
 * n = 16;
 * k = 0;
 * for(i=0; i<5; i++, n=n/2) {
 *   for(p=0; p<n; p++, k++) {
 *     t = (PI / (4*n)) * (2*p + 1);
 *     coef32[k] = 2.0 * cos(t);
 *   }
 * }
 * coef32[30] *= 0.5;	/ *** for initial back butterfly (i.e. two-point DCT) *** /
 */
const int coef32[31] = {
	0x7fd8878d, 0x7e9d55fc, 0x7c29fbee, 0x78848413, 0x73b5ebd0, 0x6dca0d14, 0x66cf811f, 0x5ed77c89, 
	0x55f5a4d2, 0x4c3fdff3, 0x41ce1e64, 0x36ba2013, 0x2b1f34eb, 0x1f19f97b, 0x12c8106e, 0x0647d97c, 
	0x7f62368f, 0x7a7d055b, 0x70e2cbc6, 0x62f201ac, 0x5133cc94, 0x3c56ba70, 0x25280c5d, 0x0c8bd35e, 
	0x7d8a5f3f, 0x6a6d98a4, 0x471cece6, 0x18f8b83c, 0x7641af3c, 0x30fbc54d, 0x2d413ccc, 
};

/* format = Q30, right shifted by 12 (sign bits only in top 12 - undo this when rounding to short)
 *   this is to enable early-terminating multiplies on ARM
 * range = [-1.144287109, 1.144989014]
 * max gain of filter (per output sample) ~= 2.731
 *
 * new (properly sign-flipped) values 
 *  - these actually are correct to 32 bits, (floating-pt coefficients in spec
 *      chosen such that only ~20 bits are required)
 *
 * Reordering - see table 3-B.3 in spec (appendix B)
 *
 * polyCoef[i] = 
 *   D[ 0, 32, 64, ... 480],   i = [  0, 15]
 *   D[ 1, 33, 65, ... 481],   i = [ 16, 31]
 *   D[ 2, 34, 66, ... 482],   i = [ 32, 47]
 *     ...
 *   D[15, 47, 79, ... 495],   i = [240,255]
 *
 * also exploits symmetry: D[i] = -D[512 - i], for i = [1, 255]
 * 
 * polyCoef[256, 257, ... 263] are for special case of sample 16 (out of 0)
 *   see PolyphaseStereo() and PolyphaseMono()
 */

#ifdef ENA_SUBBAND_COEF_OPT

const int polyCoef[264]={
            (signed int)0x00000000>>4, (signed int)0x00000074>>4, (signed int)0x00000354>>4, (signed int)0x0000072c>>4, (signed int)0x00001fd4>>4, (signed int)0x00005084>>4, (signed int)0x000066b8>>4, (signed int)0x000249c4>>4,       
	(signed int)0x00049478>>4, (signed int)0xfffdb63c>>4, (signed int)0x000066b8>>4, (signed int)0xffffaf7c>>4, (signed int)0x00001fd4>>4, (signed int)0xfffff8d4>>4, (signed int)0x00000354>>4, (signed int)0xffffff8c>>4,
	(signed int)0xfffffffc>>4, (signed int)0x00000068>>4, (signed int)0x00000368>>4, (signed int)0x00000644>>4, (signed int)0x00001f40>>4, (signed int)0x00004ad0>>4, (signed int)0x00005d1c>>4, (signed int)0x00022ce0>>4,
	(signed int)0x000493c0>>4, (signed int)0xfffd9960>>4, (signed int)0x00006f78>>4, (signed int)0xffffa9cc>>4, (signed int)0x0000203c>>4, (signed int)0xfffff7e4>>4, (signed int)0x00000340>>4, (signed int)0xffffff84>>4,
	(signed int)0xfffffffc>>4, (signed int)0x00000060>>4, (signed int)0x00000378>>4, (signed int)0x0000056c>>4, (signed int)0x00001e80>>4, (signed int)0x00004524>>4, (signed int)0x000052a0>>4, (signed int)0x00020ffc>>4,
	(signed int)0x000491a0>>4, (signed int)0xfffd7ca0>>4, (signed int)0x00007760>>4, (signed int)0xffffa424>>4, (signed int)0x00002080>>4, (signed int)0xfffff6ec>>4, (signed int)0x00000328>>4, (signed int)0xffffff74>>4,
	(signed int)0xfffffffc>>4, (signed int)0x00000054>>4, (signed int)0x00000384>>4, (signed int)0x00000498>>4, (signed int)0x00001d94>>4, (signed int)0x00003f7c>>4, (signed int)0x00004744>>4, (signed int)0x0001f32c>>4,
	(signed int)0x00048e18>>4, (signed int)0xfffd6008>>4, (signed int)0x00007e70>>4, (signed int)0xffff9e8c>>4, (signed int)0x0000209c>>4, (signed int)0xfffff5ec>>4, (signed int)0x00000310>>4, (signed int)0xffffff68>>4,
	(signed int)0xfffffffc>>4, (signed int)0x0000004c>>4, (signed int)0x0000038c>>4, (signed int)0x000003d0>>4, (signed int)0x00001c78>>4, (signed int)0x000039e4>>4, (signed int)0x00003b00>>4, (signed int)0x0001d680>>4,
	(signed int)0x00048924>>4, (signed int)0xfffd43ac>>4, (signed int)0x000084b0>>4, (signed int)0xffff990c>>4, (signed int)0x00002094>>4, (signed int)0xfffff4e4>>4, (signed int)0x000002f8>>4, (signed int)0xffffff5c>>4,
	(signed int)0xfffffffc>>4, (signed int)0x00000044>>4, (signed int)0x00000390>>4, (signed int)0x00000314>>4, (signed int)0x00001b2c>>4, (signed int)0x0000345c>>4, (signed int)0x00002ddc>>4, (signed int)0x0001ba04>>4,
	(signed int)0x000482d0>>4, (signed int)0xfffd279c>>4, (signed int)0x00008a20>>4, (signed int)0xffff93a4>>4, (signed int)0x0000206c>>4, (signed int)0xfffff3d4>>4, (signed int)0x000002dc>>4, (signed int)0xffffff4c>>4,
	(signed int)0xfffffffc>>4, (signed int)0x00000040>>4, (signed int)0x00000390>>4, (signed int)0x00000264>>4, (signed int)0x000019b0>>4, (signed int)0x00002ef0>>4, (signed int)0x00001fd4>>4, (signed int)0x00019dc8>>4,
	(signed int)0x00047b1c>>4, (signed int)0xfffd0be8>>4, (signed int)0x00008ecc>>4, (signed int)0xffff8e64>>4, (signed int)0x00002024>>4, (signed int)0xfffff2c0>>4, (signed int)0x000002c0>>4, (signed int)0xffffff3c>>4,
	(signed int)0xfffffff8>>4, (signed int)0x00000038>>4, (signed int)0x0000038c>>4, (signed int)0x000001bc>>4, (signed int)0x000017fc>>4, (signed int)0x0000299c>>4, (signed int)0x000010e8>>4, (signed int)0x000181d8>>4,
	(signed int)0x0004720c>>4, (signed int)0xfffcf09c>>4, (signed int)0x000092b4>>4, (signed int)0xffff894c>>4, (signed int)0x00001fc0>>4, (signed int)0xfffff1a4>>4, (signed int)0x000002a4>>4, (signed int)0xffffff2c>>4,
	(signed int)0xfffffff8>>4, (signed int)0x00000034>>4, (signed int)0x00000380>>4, (signed int)0x00000120>>4, (signed int)0x00001618>>4, (signed int)0x00002468>>4, (signed int)0x00000118>>4, (signed int)0x00016644>>4,
	(signed int)0x000467a4>>4, (signed int)0xfffcd5cc>>4, (signed int)0x000095e0>>4, (signed int)0xffff8468>>4, (signed int)0x00001f44>>4, (signed int)0xfffff084>>4, (signed int)0x00000284>>4, (signed int)0xffffff18>>4,
	(signed int)0xfffffff8>>4, (signed int)0x0000002c>>4, (signed int)0x00000374>>4, (signed int)0x00000090>>4, (signed int)0x00001400>>4, (signed int)0x00001f58>>4, (signed int)0xfffff068>>4, (signed int)0x00014b14>>4,
	(signed int)0x00045bf0>>4, (signed int)0xfffcbb88>>4, (signed int)0x00009858>>4, (signed int)0xffff7fbc>>4, (signed int)0x00001ea8>>4, (signed int)0xffffef60>>4, (signed int)0x00000268>>4, (signed int)0xffffff04>>4,
	(signed int)0xfffffff8>>4, (signed int)0x00000028>>4, (signed int)0x0000035c>>4, (signed int)0x00000008>>4, (signed int)0x000011ac>>4, (signed int)0x00001a70>>4, (signed int)0xffffded8>>4, (signed int)0x00013058>>4,
	(signed int)0x00044ef8>>4, (signed int)0xfffca1d8>>4, (signed int)0x00009a1c>>4, (signed int)0xffff7b54>>4, (signed int)0x00001dfc>>4, (signed int)0xffffee3c>>4, (signed int)0x0000024c>>4, (signed int)0xfffffef0>>4,
	(signed int)0xfffffff4>>4, (signed int)0x00000024>>4, (signed int)0x00000340>>4, (signed int)0xffffff8c>>4, (signed int)0x00000f28>>4, (signed int)0x000015b0>>4, (signed int)0xffffcc70>>4, (signed int)0x0001161c>>4,
	(signed int)0x000440bc>>4, (signed int)0xfffc88d8>>4, (signed int)0x00009b3c>>4, (signed int)0xffff7734>>4, (signed int)0x00001d38>>4, (signed int)0xffffed18>>4, (signed int)0x0000022c>>4, (signed int)0xfffffedc>>4,
	(signed int)0xfffffff4>>4, (signed int)0x00000020>>4, (signed int)0x00000320>>4, (signed int)0xffffff1c>>4, (signed int)0x00000c68>>4, (signed int)0x0000111c>>4, (signed int)0xffffb92c>>4, (signed int)0x0000fc6c>>4,
	(signed int)0x00043150>>4, (signed int)0xfffc708c>>4, (signed int)0x00009bb8>>4, (signed int)0xffff7368>>4, (signed int)0x00001c64>>4, (signed int)0xffffebf4>>4, (signed int)0x00000210>>4, (signed int)0xfffffec4>>4,
	(signed int)0xfffffff0>>4, (signed int)0x0000001c>>4, (signed int)0x000002f4>>4, (signed int)0xfffffeb4>>4, (signed int)0x00000974>>4, (signed int)0x00000cb8>>4, (signed int)0xffffa518>>4, (signed int)0x0000e350>>4,
	(signed int)0x000420b4>>4, (signed int)0xfffc5908>>4, (signed int)0x00009b9c>>4, (signed int)0xffff6ff4>>4, (signed int)0x00001b7c>>4, (signed int)0xffffead0>>4, (signed int)0x000001f4>>4, (signed int)0xfffffeac>>4,
	(signed int)0xfffffff0>>4, (signed int)0x0000001c>>4, (signed int)0x000002c4>>4, (signed int)0xfffffe58>>4, (signed int)0x00000648>>4, (signed int)0x00000884>>4, (signed int)0xffff9038>>4, (signed int)0x0000cad0>>4,
	(signed int)0x00040ef8>>4, (signed int)0xfffc425c>>4, (signed int)0x00009af0>>4, (signed int)0xffff6ce0>>4, (signed int)0x00001a88>>4, (signed int)0xffffe9b0>>4, (signed int)0x000001d4>>4, (signed int)0xfffffe94>>4,
	(signed int)0xffffffec>>4, (signed int)0x00000018>>4, (signed int)0x0000028c>>4, (signed int)0xfffffe04>>4, (signed int)0x000002e4>>4, (signed int)0x00000480>>4, (signed int)0xffff7a90>>4, (signed int)0x0000b2fc>>4,
	(signed int)0x0003fc28>>4, (signed int)0xfffc2c90>>4, (signed int)0x000099b8>>4, (signed int)0xffff6a3c>>4, (signed int)0x00001988>>4, (signed int)0xffffe898>>4, (signed int)0x000001bc>>4, (signed int)0xfffffe7c>>4,
	(signed int)0x000001a0>>4, (signed int)0x0000187c>>4, (signed int)0x000097fc>>4, (signed int)0x0003e84c>>4, (signed int)0xffff6424>>4, (signed int)0xffffff4c>>4, (signed int)0x00000248>>4, (signed int)0xffffffec>>4,
};
#else

const int polyCoef[264] = {
	/* shuffled vs. original from 0, 1, ... 15 to 0, 15, 2, 13, ... 14, 1 */
	0x00000000, 0x00000074, 0x00000354, 0x0000072c, 0x00001fd4, 0x00005084, 0x000066b8, 0x000249c4,
	0x00049478, 0xfffdb63c, 0x000066b8, 0xffffaf7c, 0x00001fd4, 0xfffff8d4, 0x00000354, 0xffffff8c,
	0xfffffffc, 0x00000068, 0x00000368, 0x00000644, 0x00001f40, 0x00004ad0, 0x00005d1c, 0x00022ce0,
	0x000493c0, 0xfffd9960, 0x00006f78, 0xffffa9cc, 0x0000203c, 0xfffff7e4, 0x00000340, 0xffffff84,
	0xfffffffc, 0x00000060, 0x00000378, 0x0000056c, 0x00001e80, 0x00004524, 0x000052a0, 0x00020ffc,
	0x000491a0, 0xfffd7ca0, 0x00007760, 0xffffa424, 0x00002080, 0xfffff6ec, 0x00000328, 0xffffff74,
	0xfffffffc, 0x00000054, 0x00000384, 0x00000498, 0x00001d94, 0x00003f7c, 0x00004744, 0x0001f32c,
	0x00048e18, 0xfffd6008, 0x00007e70, 0xffff9e8c, 0x0000209c, 0xfffff5ec, 0x00000310, 0xffffff68,
	0xfffffffc, 0x0000004c, 0x0000038c, 0x000003d0, 0x00001c78, 0x000039e4, 0x00003b00, 0x0001d680,
	0x00048924, 0xfffd43ac, 0x000084b0, 0xffff990c, 0x00002094, 0xfffff4e4, 0x000002f8, 0xffffff5c,
	0xfffffffc, 0x00000044, 0x00000390, 0x00000314, 0x00001b2c, 0x0000345c, 0x00002ddc, 0x0001ba04,
	0x000482d0, 0xfffd279c, 0x00008a20, 0xffff93a4, 0x0000206c, 0xfffff3d4, 0x000002dc, 0xffffff4c,
	0xfffffffc, 0x00000040, 0x00000390, 0x00000264, 0x000019b0, 0x00002ef0, 0x00001fd4, 0x00019dc8,
	0x00047b1c, 0xfffd0be8, 0x00008ecc, 0xffff8e64, 0x00002024, 0xfffff2c0, 0x000002c0, 0xffffff3c,
	0xfffffff8, 0x00000038, 0x0000038c, 0x000001bc, 0x000017fc, 0x0000299c, 0x000010e8, 0x000181d8,
	0x0004720c, 0xfffcf09c, 0x000092b4, 0xffff894c, 0x00001fc0, 0xfffff1a4, 0x000002a4, 0xffffff2c,
	0xfffffff8, 0x00000034, 0x00000380, 0x00000120, 0x00001618, 0x00002468, 0x00000118, 0x00016644,
	0x000467a4, 0xfffcd5cc, 0x000095e0, 0xffff8468, 0x00001f44, 0xfffff084, 0x00000284, 0xffffff18,
	0xfffffff8, 0x0000002c, 0x00000374, 0x00000090, 0x00001400, 0x00001f58, 0xfffff068, 0x00014b14,
	0x00045bf0, 0xfffcbb88, 0x00009858, 0xffff7fbc, 0x00001ea8, 0xffffef60, 0x00000268, 0xffffff04,
	0xfffffff8, 0x00000028, 0x0000035c, 0x00000008, 0x000011ac, 0x00001a70, 0xffffded8, 0x00013058,
	0x00044ef8, 0xfffca1d8, 0x00009a1c, 0xffff7b54, 0x00001dfc, 0xffffee3c, 0x0000024c, 0xfffffef0,
	0xfffffff4, 0x00000024, 0x00000340, 0xffffff8c, 0x00000f28, 0x000015b0, 0xffffcc70, 0x0001161c,
	0x000440bc, 0xfffc88d8, 0x00009b3c, 0xffff7734, 0x00001d38, 0xffffed18, 0x0000022c, 0xfffffedc,
	0xfffffff4, 0x00000020, 0x00000320, 0xffffff1c, 0x00000c68, 0x0000111c, 0xffffb92c, 0x0000fc6c,
	0x00043150, 0xfffc708c, 0x00009bb8, 0xffff7368, 0x00001c64, 0xffffebf4, 0x00000210, 0xfffffec4,
	0xfffffff0, 0x0000001c, 0x000002f4, 0xfffffeb4, 0x00000974, 0x00000cb8, 0xffffa518, 0x0000e350,
	0x000420b4, 0xfffc5908, 0x00009b9c, 0xffff6ff4, 0x00001b7c, 0xffffead0, 0x000001f4, 0xfffffeac,
	0xfffffff0, 0x0000001c, 0x000002c4, 0xfffffe58, 0x00000648, 0x00000884, 0xffff9038, 0x0000cad0,
	0x00040ef8, 0xfffc425c, 0x00009af0, 0xffff6ce0, 0x00001a88, 0xffffe9b0, 0x000001d4, 0xfffffe94,
	0xffffffec, 0x00000018, 0x0000028c, 0xfffffe04, 0x000002e4, 0x00000480, 0xffff7a90, 0x0000b2fc,
	0x0003fc28, 0xfffc2c90, 0x000099b8, 0xffff6a3c, 0x00001988, 0xffffe898, 0x000001bc, 0xfffffe7c,
	0x000001a0, 0x0000187c, 0x000097fc, 0x0003e84c, 0xffff6424, 0xffffff4c, 0x00000248, 0xffffffec, 
};

#endif

