#include "hieth.h"
#include "mdio.h"
#include "mac.h"
#include "ctrl.h"
#include "glb.h"
#include "sys.h"
#include <config.h>
#include <miiphy.h>
#include <net.h>

#include "phy_fix.h"

#define CONFIG_FEPHY_TRIM 1

static const u32 phy_fix_param[] = {
0x33f9,0xbd,
0x33fa,0x34,
0x33fb,0x00,
0x33fc,0x39,
0x3400,0x39,
0x3401,0xCC,
0x3402,0x40,
0x3403,0x03,
0x3404,0xFD,
0x3405,0xFF,
0x3406,0xF0,
0x3407,0xF6,
0x3408,0x36,
0x3409,0xF2,
0x340A,0x26,
0x340B,0x1A,
0x340C,0xC6,
0x340D,0x01,
0x340E,0xF7,
0x340F,0x36,
0x3410,0xF2,
0x3411,0xC6,
0x3412,0x14,
0x3413,0xF7,
0x3414,0x31,
0x3415,0x63,
0x3416,0xF7,
0x3417,0x31,
0x3418,0x64,
0x3419,0x7F,
0x341A,0x31,
0x341B,0x65,
0x341C,0xC6,
0x341D,0x20,
0x341E,0xF7,
0x341F,0x31,
0x3420,0x66,
0x3421,0xC6,
0x3422,0x80,
0x3423,0xF7,
0x3424,0x00,
0x3425,0xEC,
0x3426,0xCC,
0x3427,0x35,
0x3428,0xB2,
0x3429,0x1A,
0x342A,0xB3,
0x342B,0x00,
0x342C,0xB5,
0x342D,0x27,
0x342E,0x26,
0x342F,0xFD,
0x3430,0x00,
0x3431,0xB5,
0x3432,0x7F,
0x3433,0x01,
0x3434,0xC1,
0x3435,0xC6,
0x3436,0xE0,
0x3437,0xF7,
0x3438,0x00,
0x3439,0x79,
0x343A,0xC6,
0x343B,0x54,
0x343C,0xF7,
0x343D,0x01,
0x343E,0xE9,
0x343F,0xC6,
0x3440,0x01,
0x3441,0xF7,
0x3442,0x20,
0x3443,0x08,
0x3444,0xCC,
0x3445,0x36,
0x3446,0xE6,
0x3447,0xFD,
0x3448,0x30,
0x3449,0x08,
0x344A,0xC6,
0x344B,0xB4,
0x344C,0xF7,
0x344D,0x30,
0x344E,0x64,
0x344F,0xCC,
0x3450,0x36,
0x3451,0x35,
0x3452,0xFD,
0x3453,0x01,
0x3454,0x01,
0x3455,0x39,
0x3456,0x7F,
0x3457,0x20,
0x3458,0x0F,
0x3459,0xC6,
0x345A,0x07,
0x345B,0xF7,
0x345C,0x20,
0x345D,0x11,
0x345E,0xC6,
0x345F,0xB0,
0x3460,0xF7,
0x3461,0x20,
0x3462,0x12,
0x3463,0xC6,
0x3464,0x80,
0x3465,0xF7,
0x3466,0x20,
0x3467,0x13,
0x3468,0x7F,
0x3469,0x20,
0x346A,0x15,
0x346B,0x7F,
0x346C,0x20,
0x346D,0x16,
0x346E,0x39,
0x346F,0xC6,
0x3470,0x02,
0x3471,0xF7,
0x3472,0x20,
0x3473,0x06,
0x3474,0xF6,
0x3475,0x20,
0x3476,0x06,
0x3477,0xC4,
0x3478,0xCF,
0x3479,0xFA,
0x347A,0x31,
0x347B,0x66,
0x347C,0xF7,
0x347D,0x20,
0x347E,0x06,
0x347F,0xC6,
0x3480,0x90,
0x3481,0xF7,
0x3482,0x20,
0x3483,0x05,
0x3484,0xF6,
0x3485,0x20,
0x3486,0x05,
0x3487,0xC4,
0x3488,0xC0,
0x3489,0xFA,
0x348A,0x31,
0x348B,0x63,
0x348C,0xF7,
0x348D,0x20,
0x348E,0x05,
0x348F,0xC6,
0x3490,0xB0,
0x3491,0xF7,
0x3492,0x20,
0x3493,0x09,
0x3494,0xC6,
0x3495,0x80,
0x3496,0xF7,
0x3497,0x20,
0x3498,0x0D,
0x3499,0xF7,
0x349A,0x20,
0x349B,0x0E,
0x349C,0xC6,
0x349D,0xE9,
0x349E,0xF7,
0x349F,0x20,
0x34A0,0x14,
0x34A1,0x39,
0x34A2,0xC6,
0x34A3,0x02,
0x34A4,0xF7,
0x34A5,0x20,
0x34A6,0x06,
0x34A7,0xC6,
0x34A8,0x94,
0x34A9,0xF7,
0x34AA,0x20,
0x34AB,0x05,
0x34AC,0xF6,
0x34AD,0x20,
0x34AE,0x05,
0x34AF,0xC4,
0x34B0,0xC0,
0x34B1,0xFA,
0x34B2,0x31,
0x34B3,0x64,
0x34B4,0xF7,
0x34B5,0x20,
0x34B6,0x05,
0x34B7,0xC6,
0x34B8,0x88,
0x34B9,0xF7,
0x34BA,0x20,
0x34BB,0x09,
0x34BC,0xC6,
0x34BD,0x40,
0x34BE,0xF7,
0x34BF,0x20,
0x34C0,0x0D,
0x34C1,0xC6,
0x34C2,0xC0,
0x34C3,0xF7,
0x34C4,0x20,
0x34C5,0x0E,
0x34C6,0x39,
0x34C7,0x3C,
0x34C8,0x34,
0x34C9,0x30,
0x34CA,0xBD,
0x34CB,0x87,
0x34CC,0x8D,
0x34CD,0xE7,
0x34CE,0x00,
0x34CF,0xC0,
0x34D0,0x02,
0x34D1,0x27,
0x34D2,0x12,
0x34D3,0x5A,
0x34D4,0x27,
0x34D5,0x31,
0x34D6,0x5A,
0x34D7,0x27,
0x34D8,0x56,
0x34D9,0x5A,
0x34DA,0x27,
0x34DB,0x76,
0x34DC,0x5A,
0x34DD,0x27,
0x34DE,0x50,
0x34DF,0x5A,
0x34E0,0x27,
0x34E1,0x70,
0x34E2,0x7E,
0x34E3,0x35,
0x34E4,0x7C,
0x34E5,0xF6,
0x34E6,0x1E,
0x34E7,0x0F,
0x34E8,0xC4,
0x34E9,0xFC,
0x34EA,0xF7,
0x34EB,0x1E,
0x34EC,0x0F,
0x34ED,0xBD,
0x34EE,0x86,
0x34EF,0x38,
0x34F0,0xC6,
0x34F1,0xC8,
0x34F2,0xF7,
0x34F3,0x20,
0x34F4,0x10,
0x34F5,0xF6,
0x34F6,0x20,
0x34F7,0x10,
0x34F8,0xC4,
0x34F9,0xE7,
0x34FA,0xFA,
0x34FB,0x31,
0x34FC,0x65,
0x34FD,0xF7,
0x34FE,0x20,
0x34FF,0x10,
0x3500,0xF6,
0x3501,0x1E,
0x3502,0x0F,
0x3503,0xCA,
0x3504,0x01,
0x3505,0x20,
0x3506,0x20,
0x3507,0xF6,
0x3508,0x1E,
0x3509,0x0F,
0x350A,0xC4,
0x350B,0xFC,
0x350C,0xF7,
0x350D,0x1E,
0x350E,0x0F,
0x350F,0xBD,
0x3510,0x86,
0x3511,0x38,
0x3512,0xC6,
0x3513,0xE8,
0x3514,0xF7,
0x3515,0x20,
0x3516,0x10,
0x3517,0xF6,
0x3518,0x20,
0x3519,0x10,
0x351A,0xC4,
0x351B,0xE7,
0x351C,0xFA,
0x351D,0x31,
0x351E,0x65,
0x351F,0xF7,
0x3520,0x20,
0x3521,0x10,
0x3522,0xF6,
0x3523,0x1E,
0x3524,0x0F,
0x3525,0xCA,
0x3526,0x02,
0x3527,0xF7,
0x3528,0x1E,
0x3529,0x0F,
0x352A,0xBD,
0x352B,0x34,
0x352C,0x6F,
0x352D,0x20,
0x352E,0x4D,
0x352F,0xF6,
0x3530,0x1E,
0x3531,0x0F,
0x3532,0xC4,
0x3533,0xFC,
0x3534,0xF7,
0x3535,0x1E,
0x3536,0x0F,
0x3537,0xBD,
0x3538,0x86,
0x3539,0x38,
0x353A,0xC6,
0x353B,0x90,
0x353C,0xF7,
0x353D,0x20,
0x353E,0x10,
0x353F,0xF6,
0x3540,0x1E,
0x3541,0x0F,
0x3542,0xCA,
0x3543,0x01,
0x3544,0xF7,
0x3545,0x1E,
0x3546,0x0F,
0x3547,0xBD,
0x3548,0x34,
0x3549,0xA2,
0x354A,0xE6,
0x354B,0x00,
0x354C,0xC1,
0x354D,0x06,
0x354E,0x26,
0x354F,0x27,
0x3550,0x20,
0x3551,0x21,
0x3552,0xF6,
0x3553,0x1E,
0x3554,0x0F,
0x3555,0xC4,
0x3556,0xFC,
0x3557,0xF7,
0x3558,0x1E,
0x3559,0x0F,
0x355A,0xBD,
0x355B,0x86,
0x355C,0x38,
0x355D,0xC6,
0x355E,0xB0,
0x355F,0xF7,
0x3560,0x20,
0x3561,0x10,
0x3562,0xF6,
0x3563,0x1E,
0x3564,0x0F,
0x3565,0xCA,
0x3566,0x02,
0x3567,0xF7,
0x3568,0x1E,
0x3569,0x0F,
0x356A,0xBD,
0x356B,0x34,
0x356C,0xA2,
0x356D,0xE6,
0x356E,0x00,
0x356F,0xC1,
0x3570,0x07,
0x3571,0x26,
0x3572,0x04,
0x3573,0xC6,
0x3574,0xE9,
0x3575,0x20,
0x3576,0x02,
0x3577,0xC6,
0x3578,0xEB,
0x3579,0xF7,
0x357A,0x20,
0x357B,0x14,
0x357C,0xBD,
0x357D,0x34,
0x357E,0x56,
0x357F,0x18,
0x3580,0xFE,
0x3581,0x30,
0x3582,0x00,
0x3583,0xF6,
0x3584,0x30,
0x3585,0x54,
0x3586,0x86,
0x3587,0x03,
0x3588,0x3D,
0x3589,0x18,
0x358A,0x3A,
0x358B,0xF6,
0x358C,0x20,
0x358D,0x11,
0x358E,0xC4,
0x358F,0xF0,
0x3590,0x18,
0x3591,0xEA,
0x3592,0x00,
0x3593,0xF7,
0x3594,0x20,
0x3595,0x11,
0x3596,0x18,
0x3597,0xFE,
0x3598,0x30,
0x3599,0x00,
0x359A,0xF6,
0x359B,0x30,
0x359C,0x54,
0x359D,0x86,
0x359E,0x03,
0x359F,0x3D,
0x35A0,0xCB,
0x35A1,0x02,
0x35A2,0x18,
0x35A3,0x3A,
0x35A4,0xF6,
0x35A5,0x20,
0x35A6,0x12,
0x35A7,0xC4,
0x35A8,0xF8,
0x35A9,0x18,
0x35AA,0xEA,
0x35AB,0x00,
0x35AC,0xF7,
0x35AD,0x20,
0x35AE,0x12,
0x35AF,0x31,
0x35B0,0x38,
0x35B1,0x39,
0x35B2,0xD6,
0x35B3,0x25,
0x35B4,0xC4,
0x35B5,0x02,
0x35B6,0xF7,
0x35B7,0x00,
0x35B8,0xFE,
0x35B9,0x8D,
0x35BA,0x7A,
0x35BB,0xBD,
0x35BC,0x86,
0x35BD,0x38,
0x35BE,0xBD,
0x35BF,0x86,
0x35C0,0x38,
0x35C1,0xF6,
0x35C2,0x1E,
0x35C3,0x08,
0x35C4,0xCA,
0x35C5,0x01,
0x35C6,0xF7,
0x35C7,0x1E,
0x35C8,0x08,
0x35C9,0xBD,
0x35CA,0x96,
0x35CB,0xB6,
0x35CC,0xBD,
0x35CD,0x96,
0x35CE,0xCF,
0x35CF,0xBD,
0x35D0,0xE0,
0x35D1,0x37,
0x35D2,0xBD,
0x35D3,0x86,
0x35D4,0x38,
0x35D5,0xBD,
0x35D6,0x86,
0x35D7,0xF2,
0x35D8,0xF6,
0x35D9,0x00,
0x35DA,0x41,
0x35DB,0xC5,
0x35DC,0x01,
0x35DD,0x26,
0x35DE,0x03,
0x35DF,0xBD,
0x35E0,0x34,
0x35E1,0xC7,
0x35E2,0xF6,
0x35E3,0x1E,
0x35E4,0x08,
0x35E5,0xCA,
0x35E6,0x03,
0x35E7,0xF7,
0x35E8,0x1E,
0x35E9,0x08,
0x35EA,0xBD,
0x35EB,0xD4,
0x35EC,0xE8,
0x35ED,0xBD,
0x35EE,0x89,
0x35EF,0xD1,
0x35F0,0xBD,
0x35F1,0x8D,
0x35F2,0x35,
0x35F3,0xBD,
0x35F4,0x8B,
0x35F5,0xB1,
0x35F6,0xFC,
0x35F7,0x00,
0x35F8,0x42,
0x35F9,0xBD,
0x35FA,0x8A,
0x35FB,0xD4,
0x35FC,0xFC,
0x35FD,0x00,
0x35FE,0x42,
0x35FF,0xBD,
0x3600,0x8C,
0x3601,0x95,
0x3602,0xBD,
0x3603,0x8D,
0x3604,0x01,
0x3605,0xF6,
0x3606,0x20,
0x3607,0x0E,
0x3608,0xC4,
0x3609,0xED,
0x360A,0xF7,
0x360B,0x20,
0x360C,0x0E,
0x360D,0xBD,
0x360E,0x89,
0x360F,0x5A,
0x3610,0xBD,
0x3611,0xE0,
0x3612,0xCD,
0x3613,0xF6,
0x3614,0x00,
0x3615,0x41,
0x3616,0xC5,
0x3617,0x20,
0x3618,0x27,
0x3619,0x10,
0x361A,0xF6,
0x361B,0x12,
0x361C,0x31,
0x361D,0xCA,
0x361E,0x20,
0x361F,0xF7,
0x3620,0x12,
0x3621,0x31,
0x3622,0xF6,
0x3623,0x12,
0x3624,0x22,
0x3625,0xCA,
0x3626,0x20,
0x3627,0xF7,
0x3628,0x12,
0x3629,0x22,
0x362A,0xBD,
0x362B,0x87,
0x362C,0x2B,
0x362D,0x13,
0x362E,0x23,
0x362F,0x80,
0x3630,0x03,
0x3631,0xBD,
0x3632,0x96,
0x3633,0x30,
0x3634,0x39,
0x3635,0x3C,
0x3636,0x34,
0x3637,0x30,
0x3638,0xF6,
0x3639,0x00,
0x363A,0xFE,
0x363B,0x26,
0x363C,0x08,
0x363D,0xF6,
0x363E,0x1E,
0x363F,0x0C,
0x3640,0xC4,
0x3641,0xFD,
0x3642,0xF7,
0x3643,0x1E,
0x3644,0x0C,
0x3645,0x7F,
0x3646,0x10,
0x3647,0xF1,
0x3648,0x7F,
0x3649,0x10,
0x364A,0xF3,
0x364B,0x7F,
0x364C,0x1C,
0x364D,0xF1,
0x364E,0x7F,
0x364F,0x1C,
0x3650,0xF2,
0x3651,0x7F,
0x3652,0x12,
0x3653,0xF2,
0x3654,0x7F,
0x3655,0x12,
0x3656,0xF3,
0x3657,0x7F,
0x3658,0x10,
0x3659,0xF0,
0x365A,0x7F,
0x365B,0x10,
0x365C,0xF2,
0x365D,0x7F,
0x365E,0x1C,
0x365F,0xF0,
0x3660,0x7F,
0x3661,0x1C,
0x3662,0xF3,
0x3663,0x7F,
0x3664,0x12,
0x3665,0xF0,
0x3666,0x7F,
0x3667,0x12,
0x3668,0xF1,
0x3669,0xF6,
0x366A,0x00,
0x366B,0xFE,
0x366C,0x26,
0x366D,0x2C,
0x366E,0x7F,
0x366F,0x1D,
0x3670,0xF1,
0x3671,0x7F,
0x3672,0x1D,
0x3673,0xF0,
0x3674,0x7F,
0x3675,0x1D,
0x3676,0xF4,
0x3677,0x7F,
0x3678,0x11,
0x3679,0xF1,
0x367A,0x7F,
0x367B,0x11,
0x367C,0xF0,
0x367D,0xF6,
0x367E,0x1E,
0x367F,0x0B,
0x3680,0xC4,
0x3681,0xFC,
0x3682,0xE7,
0x3683,0x00,
0x3684,0xF7,
0x3685,0x1E,
0x3686,0x0B,
0x3687,0xC5,
0x3688,0x01,
0x3689,0x27,
0x368A,0x05,
0x368B,0xF7,
0x368C,0x1E,
0x368D,0x08,
0x368E,0x20,
0x368F,0x0A,
0x3690,0x1C,
0x3691,0x00,
0x3692,0x01,
0x3693,0xE6,
0x3694,0x00,
0x3695,0xF7,
0x3696,0x1E,
0x3697,0x08,
0x3698,0x8D,
0x3699,0x0D,
0x369A,0xF6,
0x369B,0x1E,
0x369C,0x08,
0x369D,0xC4,
0x369E,0xFD,
0x369F,0xF7,
0x36A0,0x1E,
0x36A1,0x08,
0x36A2,0x8D,
0x36A3,0x03,
0x36A4,0x31,
0x36A5,0x38,
0x36A6,0x39,
0x36A7,0x7F,
0x36A8,0x20,
0x36A9,0x01,
0x36AA,0x7F,
0x36AB,0x20,
0x36AC,0x02,
0x36AD,0x7F,
0x36AE,0x20,
0x36AF,0x03,
0x36B0,0x7F,
0x36B1,0x20,
0x36B2,0x05,
0x36B3,0xC6,
0x36B4,0x01,
0x36B5,0xF7,
0x36B6,0x20,
0x36B7,0x08,
0x36B8,0x7F,
0x36B9,0x20,
0x36BA,0x09,
0x36BB,0x7F,
0x36BC,0x20,
0x36BD,0x0A,
0x36BE,0x7F,
0x36BF,0x20,
0x36C0,0x0B,
0x36C1,0x7F,
0x36C2,0x20,
0x36C3,0x0C,
0x36C4,0x7F,
0x36C5,0x20,
0x36C6,0x0D,
0x36C7,0x7F,
0x36C8,0x20,
0x36C9,0x0E,
0x36CA,0x7F,
0x36CB,0x20,
0x36CC,0x0F,
0x36CD,0x7F,
0x36CE,0x20,
0x36CF,0x10,
0x36D0,0x7F,
0x36D1,0x20,
0x36D2,0x11,
0x36D3,0x7F,
0x36D4,0x20,
0x36D5,0x12,
0x36D6,0x7F,
0x36D7,0x20,
0x36D8,0x13,
0x36D9,0x7F,
0x36DA,0x20,
0x36DB,0x14,
0x36DC,0x7F,
0x36DD,0x20,
0x36DE,0x15,
0x36DF,0x7F,
0x36E0,0x20,
0x36E1,0x16,
0x36E2,0x7F,
0x36E3,0x20,
0x36E4,0x18,
0x36E5,0x39,
0x36E6,0x00,
0x36E7,0x00,
0x36E8,0x10,
0x36E9,0x00,
0x36EA,0x00,
0x36EB,0x41,
0x36EC,0x10,
0x36ED,0x0E,
0x36EE,0xCD,
0x36EF,0x01,
0x36F0,0x01,
0x36F1,0x00,
0x36F2,0x00,
0x3400,0x01,
0x33f8,0x01
};

static const u32 phy_fix_param_mv300[] = {
0x33f9,0xbd,
0x33fa,0x34,
0x33fb,0x00,
0x33fc,0x39,
0x3400,0x39,
0x3401,0xCC,
0x3402,0x23,
0x3403,0x02,
0x3404,0xFD,
0x3405,0xFF,
0x3406,0xF2,
0x3407,0x4F,
0x3408,0x5F,
0x3409,0xFD,
0x340A,0xFF,
0x340B,0xF0,
0x340C,0xB6,
0x340D,0x37,
0x340E,0x0D,
0x340F,0x26,
0x3410,0x04,
0x3411,0x5C,
0x3412,0xF7,
0x3413,0x37,
0x3414,0x0D,
0x3415,0xCC,
0x3416,0x36,
0x3417,0x70,
0x3418,0x1A,
0x3419,0xB3,
0x341A,0x00,
0x341B,0xD2,
0x341C,0x27,
0x341D,0x12,
0x341E,0xFD,
0x341F,0x00,
0x3420,0xD2,
0x3421,0x7F,
0x3422,0x01,
0x3423,0xBF,
0x3424,0xCC,
0x3425,0x36,
0x3426,0xCD,
0x3427,0xFD,
0x3428,0x30,
0x3429,0x4A,
0x342A,0xCC,
0x342B,0x36,
0x342C,0xE1,
0x342D,0xFD,
0x342E,0x30,
0x342F,0x4C,
0x3430,0x20,
0x3431,0x00,
0x3432,0xF6,
0x3433,0x01,
0x3434,0xC6,
0x3435,0xC1,
0x3436,0x06,
0x3437,0x26,
0x3438,0x05,
0x3439,0xCC,
0x343A,0x34,
0x343B,0x45,
0x343C,0x20,
0x343D,0x03,
0x343E,0xCC,
0x343F,0xCD,
0x3440,0x14,
0x3441,0xFD,
0x3442,0x00,
0x3443,0xCC,
0x3444,0x39,
0x3445,0x3C,
0x3446,0x34,
0x3447,0x30,
0x3448,0xF6,
0x3449,0x00,
0x344A,0xEB,
0x344B,0x26,
0x344C,0x0E,
0x344D,0xC6,
0x344E,0x52,
0x344F,0xBD,
0x3450,0xDB,
0x3451,0x47,
0x3452,0x5D,
0x3453,0x26,
0x3454,0x03,
0x3455,0x7E,
0x3456,0x35,
0x3457,0x03,
0x3458,0x7C,
0x3459,0x00,
0x345A,0xEB,
0x345B,0xC6,
0x345C,0x56,
0x345D,0xBD,
0x345E,0xDB,
0x345F,0x47,
0x3460,0x5D,
0x3461,0x27,
0x3462,0x5C,
0x3463,0xF6,
0x3464,0x00,
0x3465,0x7D,
0x3466,0xC5,
0x3467,0x10,
0x3468,0x27,
0x3469,0x55,
0x346A,0xC5,
0x346B,0x80,
0x346C,0x26,
0x346D,0x51,
0x346E,0xF6,
0x346F,0x01,
0x3470,0xFD,
0x3471,0x5A,
0x3472,0x26,
0x3473,0x10,
0x3474,0xF6,
0x3475,0x31,
0x3476,0x1B,
0x3477,0xF7,
0x3478,0x00,
0x3479,0x79,
0x347A,0xF6,
0x347B,0x31,
0x347C,0x1C,
0x347D,0xF7,
0x347E,0x00,
0x347F,0x7A,
0x3480,0xC6,
0x3481,0x02,
0x3482,0x20,
0x3483,0x0E,
0x3484,0xF6,
0x3485,0x31,
0x3486,0x19,
0x3487,0xF7,
0x3488,0x00,
0x3489,0x79,
0x348A,0xF6,
0x348B,0x31,
0x348C,0x1A,
0x348D,0xF7,
0x348E,0x00,
0x348F,0x7A,
0x3490,0xC6,
0x3491,0x01,
0x3492,0xF7,
0x3493,0x01,
0x3494,0xFD,
0x3495,0xF6,
0x3496,0x00,
0x3497,0x79,
0x3498,0xF7,
0x3499,0x1C,
0x349A,0xC2,
0x349B,0xBD,
0x349C,0x9E,
0x349D,0x83,
0x349E,0xF6,
0x349F,0x20,
0x34A0,0x07,
0x34A1,0xC4,
0x34A2,0xFC,
0x34A3,0xFA,
0x34A4,0x00,
0x34A5,0x7A,
0x34A6,0xF7,
0x34A7,0x20,
0x34A8,0x07,
0x34A9,0xF6,
0x34AA,0x31,
0x34AB,0x1D,
0x34AC,0x37,
0x34AD,0xC6,
0x34AE,0x56,
0x34AF,0xBD,
0x34B0,0xDA,
0x34B1,0xA7,
0x34B2,0x31,
0x34B3,0x7C,
0x34B4,0x01,
0x34B5,0xFC,
0x34B6,0xF6,
0x34B7,0x01,
0x34B8,0xFC,
0x34B9,0x5C,
0x34BA,0x26,
0x34BB,0x03,
0x34BC,0x7F,
0x34BD,0x01,
0x34BE,0xFC,
0x34BF,0xBD,
0x34C0,0xD4,
0x34C1,0x61,
0x34C2,0x5D,
0x34C3,0x27,
0x34C4,0x13,
0x34C5,0xF6,
0x34C6,0x00,
0x34C7,0x5C,
0x34C8,0xC5,
0x34C9,0x01,
0x34CA,0x26,
0x34CB,0x03,
0x34CC,0x7E,
0x34CD,0x35,
0x34CE,0x76,
0x34CF,0xCC,
0x34D0,0x37,
0x34D1,0x07,
0x34D2,0xBD,
0x34D3,0xEE,
0x34D4,0xD3,
0x34D5,0x7E,
0x34D6,0x35,
0x34D7,0x76,
0x34D8,0xF6,
0x34D9,0x00,
0x34DA,0x7E,
0x34DB,0xF1,
0x34DC,0x00,
0x34DD,0x7C,
0x34DE,0x25,
0x34DF,0x23,
0x34E0,0xC6,
0x34E1,0xC8,
0x34E2,0x37,
0x34E3,0xC6,
0x34E4,0x53,
0x34E5,0xBD,
0x34E6,0xDA,
0x34E7,0xA7,
0x34E8,0x31,
0x34E9,0xBD,
0x34EA,0xCA,
0x34EB,0xE4,
0x34EC,0xF6,
0x34ED,0x10,
0x34EE,0x51,
0x34EF,0xCA,
0x34F0,0x08,
0x34F1,0xF7,
0x34F2,0x10,
0x34F3,0x51,
0x34F4,0xF6,
0x34F5,0x10,
0x34F6,0x52,
0x34F7,0xCA,
0x34F8,0x40,
0x34F9,0xF7,
0x34FA,0x10,
0x34FB,0x52,
0x34FC,0x14,
0x34FD,0x0D,
0x34FE,0x01,
0x34FF,0xC6,
0x3500,0x09,
0x3501,0x20,
0x3502,0x26,
0x3503,0xC6,
0x3504,0x54,
0x3505,0xBD,
0x3506,0xDB,
0x3507,0x47,
0x3508,0x5D,
0x3509,0x27,
0x350A,0x24,
0x350B,0xF6,
0x350C,0x00,
0x350D,0x7D,
0x350E,0xC5,
0x350F,0x10,
0x3510,0x27,
0x3511,0x1D,
0x3512,0x13,
0x3513,0x24,
0x3514,0x80,
0x3515,0x19,
0x3516,0xC5,
0x3517,0x80,
0x3518,0x26,
0x3519,0x15,
0x351A,0xF6,
0x351B,0x30,
0x351C,0x5C,
0x351D,0x37,
0x351E,0xC6,
0x351F,0x54,
0x3520,0xBD,
0x3521,0xDA,
0x3522,0xA7,
0x3523,0x31,
0x3524,0x14,
0x3525,0x22,
0x3526,0x04,
0x3527,0xC6,
0x3528,0x04,
0x3529,0xF7,
0x352A,0x01,
0x352B,0xC6,
0x352C,0x31,
0x352D,0x38,
0x352E,0x39,
0x352F,0xF6,
0x3530,0x10,
0x3531,0xE1,
0x3532,0xC5,
0x3533,0x08,
0x3534,0x27,
0x3535,0xF6,
0x3536,0xBD,
0x3537,0xDC,
0x3538,0x6A,
0x3539,0xBD,
0x353A,0x9E,
0x353B,0x8C,
0x353C,0xE7,
0x353D,0x00,
0x353E,0xF6,
0x353F,0x00,
0x3540,0x7D,
0x3541,0xC5,
0x3542,0x10,
0x3543,0x27,
0x3544,0x2C,
0x3545,0x13,
0x3546,0x24,
0x3547,0x80,
0x3548,0x28,
0x3549,0xBD,
0x354A,0xD4,
0x354B,0x61,
0x354C,0x5D,
0x354D,0x26,
0x354E,0x22,
0x354F,0xF6,
0x3550,0x01,
0x3551,0xFA,
0x3552,0xC5,
0x3553,0x80,
0x3554,0x26,
0x3555,0x1B,
0x3556,0xF6,
0x3557,0x10,
0x3558,0x50,
0x3559,0xC5,
0x355A,0xF0,
0x355B,0x26,
0x355C,0x14,
0x355D,0xE6,
0x355E,0x00,
0x355F,0x27,
0x3560,0x04,
0x3561,0x13,
0x3562,0x22,
0x3563,0x04,
0x3564,0x07,
0x3565,0x5D,
0x3566,0x26,
0x3567,0x09,
0x3568,0x13,
0x3569,0x22,
0x356A,0x04,
0x356B,0x05,
0x356C,0xC6,
0x356D,0x04,
0x356E,0xF7,
0x356F,0x01,
0x3570,0xC6,
0x3571,0x7F,
0x3572,0x01,
0x3573,0xFA,
0x3574,0x20,
0x3575,0xB6,
0x3576,0xF6,
0x3577,0x00,
0x3578,0x5C,
0x3579,0xC5,
0x357A,0x01,
0x357B,0x27,
0x357C,0x06,
0x357D,0xCC,
0x357E,0x37,
0x357F,0x01,
0x3580,0xBD,
0x3581,0xEE,
0x3582,0xD3,
0x3583,0xF6,
0x3584,0x10,
0x3585,0x51,
0x3586,0xC4,
0x3587,0xF7,
0x3588,0xF7,
0x3589,0x10,
0x358A,0x51,
0x358B,0xF6,
0x358C,0x30,
0x358D,0x5F,
0x358E,0x37,
0x358F,0xC6,
0x3590,0x56,
0x3591,0xBD,
0x3592,0xDA,
0x3593,0xA7,
0x3594,0x31,
0x3595,0xC6,
0x3596,0x07,
0x3597,0x20,
0x3598,0x90,
0x3599,0x3C,
0x359A,0x37,
0x359B,0x36,
0x359C,0x34,
0x359D,0x30,
0x359E,0x1A,
0x359F,0xEE,
0x35A0,0x01,
0x35A1,0x18,
0x35A2,0xE6,
0x35A3,0x00,
0x35A4,0x26,
0x35A5,0x47,
0x35A6,0xF6,
0x35A7,0x00,
0x35A8,0x5C,
0x35A9,0xC5,
0x35AA,0x04,
0x35AB,0x27,
0x35AC,0x06,
0x35AD,0xCC,
0x35AE,0x36,
0x35AF,0xF5,
0x35B0,0xBD,
0x35B1,0xEE,
0x35B2,0xD3,
0x35B3,0xC6,
0x35B4,0x52,
0x35B5,0xBD,
0x35B6,0xDB,
0x35B7,0x47,
0x35B8,0x5D,
0x35B9,0x27,
0x35BA,0x03,
0x35BB,0xBD,
0x35BC,0xBE,
0x35BD,0x86,
0x35BE,0xF6,
0x35BF,0x00,
0x35C0,0x46,
0x35C1,0xC5,
0x35C2,0x0C,
0x35C3,0x26,
0x35C4,0x0A,
0x35C5,0x1A,
0x35C6,0xEE,
0x35C7,0x01,
0x35C8,0x18,
0x35C9,0x6F,
0x35CA,0x00,
0x35CB,0xC6,
0x35CC,0x07,
0x35CD,0x20,
0x35CE,0x1A,
0x35CF,0xFC,
0x35D0,0x30,
0x35D1,0x0C,
0x35D2,0xBD,
0x35D3,0x92,
0x35D4,0xBD,
0x35D5,0xBD,
0x35D6,0x9E,
0x35D7,0x83,
0x35D8,0xC6,
0x35D9,0x02,
0x35DA,0x37,
0x35DB,0xC6,
0x35DC,0x51,
0x35DD,0xBD,
0x35DE,0xDA,
0x35DF,0xA7,
0x35E0,0x31,
0x35E1,0xC6,
0x35E2,0x02,
0x35E3,0x1A,
0x35E4,0xEE,
0x35E5,0x01,
0x35E6,0x18,
0x35E7,0xE7,
0x35E8,0x00,
0x35E9,0x31,
0x35EA,0x38,
0x35EB,0x38,
0x35EC,0x39,
0x35ED,0xC6,
0x35EE,0x52,
0x35EF,0xBD,
0x35F0,0xDB,
0x35F1,0x47,
0x35F2,0x5D,
0x35F3,0x27,
0x35F4,0x03,
0x35F5,0xBD,
0x35F6,0xBE,
0x35F7,0x86,
0x35F8,0xF6,
0x35F9,0x00,
0x35FA,0x46,
0x35FB,0xC5,
0x35FC,0x0C,
0x35FD,0x26,
0x35FE,0x0A,
0x35FF,0x1A,
0x3600,0xEE,
0x3601,0x01,
0x3602,0x18,
0x3603,0x6F,
0x3604,0x00,
0x3605,0xC6,
0x3606,0x07,
0x3607,0x20,
0x3608,0xE0,
0x3609,0xC6,
0x360A,0x51,
0x360B,0xBD,
0x360C,0xDB,
0x360D,0x47,
0x360E,0x5D,
0x360F,0x26,
0x3610,0x04,
0x3611,0xC6,
0x3612,0x02,
0x3613,0x20,
0x3614,0xD4,
0x3615,0xF6,
0x3616,0x1C,
0x3617,0xC2,
0x3618,0xE7,
0x3619,0x00,
0x361A,0xF6,
0x361B,0x00,
0x361C,0x41,
0x361D,0xC5,
0x361E,0x10,
0x361F,0x26,
0x3620,0x44,
0x3621,0xE6,
0x3622,0x00,
0x3623,0xC5,
0x3624,0xF0,
0x3625,0x26,
0x3626,0x1D,
0x3627,0xF6,
0x3628,0x20,
0x3629,0x07,
0x362A,0xC4,
0x362B,0x03,
0x362C,0x5A,
0x362D,0x27,
0x362E,0x15,
0x362F,0xBD,
0x3630,0x9E,
0x3631,0x39,
0x3632,0xC6,
0x3633,0xF0,
0x3634,0xF7,
0x3635,0x1C,
0x3636,0xC2,
0x3637,0xC6,
0x3638,0x02,
0x3639,0x37,
0x363A,0xC6,
0x363B,0x51,
0x363C,0xBD,
0x363D,0xDA,
0x363E,0xA7,
0x363F,0x31,
0x3640,0xC6,
0x3641,0x02,
0x3642,0x20,
0x3643,0xA5,
0x3644,0xE6,
0x3645,0x00,
0x3646,0xC4,
0x3647,0xF0,
0x3648,0xC1,
0x3649,0xF0,
0x364A,0x26,
0x364B,0x19,
0x364C,0xF6,
0x364D,0x20,
0x364E,0x07,
0x364F,0xC4,
0x3650,0x03,
0x3651,0xC1,
0x3652,0x03,
0x3653,0x27,
0x3654,0x10,
0x3655,0xBD,
0x3656,0x9E,
0x3657,0x5E,
0x3658,0xC6,
0x3659,0x02,
0x365A,0x37,
0x365B,0xC6,
0x365C,0x51,
0x365D,0xBD,
0x365E,0xDA,
0x365F,0xA7,
0x3660,0x31,
0x3661,0xC6,
0x3662,0x02,
0x3663,0x20,
0x3664,0x84,
0x3665,0x1A,
0x3666,0xEE,
0x3667,0x01,
0x3668,0x18,
0x3669,0x6F,
0x366A,0x00,
0x366B,0xC6,
0x366C,0x03,
0x366D,0x7E,
0x366E,0x35,
0x366F,0xE9,
0x3670,0xF6,
0x3671,0x01,
0x3672,0xBF,
0x3673,0xC1,
0x3674,0x08,
0x3675,0x24,
0x3676,0x55,
0x3677,0xBD,
0x3678,0xF5,
0x3679,0x01,
0x367A,0x36,
0x367B,0x8B,
0x367C,0x36,
0x367D,0x93,
0x367E,0x36,
0x367F,0x9B,
0x3680,0x36,
0x3681,0xA3,
0x3682,0x36,
0x3683,0xAB,
0x3684,0x36,
0x3685,0xB3,
0x3686,0x36,
0x3687,0xBB,
0x3688,0x36,
0x3689,0xC3,
0x368A,0x39,
0x368B,0xCC,
0x368C,0x01,
0x368D,0xB1,
0x368E,0xBD,
0x368F,0xBF,
0x3690,0x1C,
0x3691,0x20,
0x3692,0x36,
0x3693,0xCC,
0x3694,0x01,
0x3695,0xB1,
0x3696,0xBD,
0x3697,0xBF,
0x3698,0xB6,
0x3699,0x20,
0x369A,0x2E,
0x369B,0xCC,
0x369C,0x01,
0x369D,0xB1,
0x369E,0xBD,
0x369F,0x35,
0x36A0,0x99,
0x36A1,0x20,
0x36A2,0x26,
0x36A3,0xCC,
0x36A4,0x01,
0x36A5,0xB1,
0x36A6,0xBD,
0x36A7,0xC2,
0x36A8,0x27,
0x36A9,0x20,
0x36AA,0x1E,
0x36AB,0xCC,
0x36AC,0x01,
0x36AD,0xB1,
0x36AE,0xBD,
0x36AF,0xC2,
0x36B0,0xC6,
0x36B1,0x20,
0x36B2,0x16,
0x36B3,0xCC,
0x36B4,0x01,
0x36B5,0xB1,
0x36B6,0xBD,
0x36B7,0xC3,
0x36B8,0x98,
0x36B9,0x20,
0x36BA,0x0E,
0x36BB,0xCC,
0x36BC,0x01,
0x36BD,0xB1,
0x36BE,0xBD,
0x36BF,0xC4,
0x36C0,0xC7,
0x36C1,0x20,
0x36C2,0x06,
0x36C3,0xCC,
0x36C4,0x01,
0x36C5,0xB1,
0x36C6,0xBD,
0x36C7,0xC6,
0x36C8,0x1F,
0x36C9,0xF7,
0x36CA,0x01,
0x36CB,0xBF,
0x36CC,0x39,
0x36CD,0x06,
0x36CE,0x06,
0x36CF,0x06,
0x36D0,0x05,
0x36D1,0x05,
0x36D2,0x04,
0x36D3,0x04,
0x36D4,0x04,
0x36D5,0x02,
0x36D6,0x02,
0x36D7,0x02,
0x36D8,0x02,
0x36D9,0x02,
0x36DA,0x01,
0x36DB,0x01,
0x36DC,0x00,
0x36DD,0x00,
0x36DE,0x00,
0x36DF,0x00,
0x36E0,0x00,
0x36E1,0x07,
0x36E2,0x07,
0x36E3,0x07,
0x36E4,0x06,
0x36E5,0x06,
0x36E6,0x05,
0x36E7,0x05,
0x36E8,0x05,
0x36E9,0x04,
0x36EA,0x04,
0x36EB,0x04,
0x36EC,0x04,
0x36ED,0x04,
0x36EE,0x02,
0x36EF,0x02,
0x36F0,0x01,
0x36F1,0x01,
0x36F2,0x01,
0x36F3,0x01,
0x36F4,0x01,
0x36F5,0x43,
0x36F6,0x3A,
0x36F7,0x41,
0x36F8,0x44,
0x36F9,0x54,
0x36FA,0x5F,
0x36FB,0x41,
0x36FC,0x54,
0x36FD,0x4E,
0x36FE,0x0A,
0x36FF,0x0D,
0x3700,0x00,
0x3701,0x41,
0x3702,0x30,
0x3703,0x38,
0x3704,0x0A,
0x3705,0x0D,
0x3706,0x00,
0x3707,0x4C,
0x3708,0x53,
0x3709,0x43,
0x370A,0x0A,
0x370B,0x0D,
0x370C,0x00,
0x370D,0x00,
0x3400,0x01,
0x33f8,0x01
};

int phy_expanded_read(struct eth_device *dev, u32 reg_addr)
{
	int ret = 0;
	struct hieth_netdev_local *ld = (struct hieth_netdev_local *)dev->priv;

	if (miiphy_write(dev->name, UD_REG_NAME(PHY_ADDR), MII_EXPMA, 
		      (unsigned short)reg_addr) != 0)
		return -1;

	if (miiphy_read(dev->name, UD_REG_NAME(PHY_ADDR), MII_EXPMD,
			(unsigned short *)&ret) != 0)
		return -1;

	return ret;
}

int phy_expanded_write(struct eth_device *dev, u32 reg_addr, u16 val)
{
	struct hieth_netdev_local *ld = (struct hieth_netdev_local *)dev->priv;

	if (miiphy_write(dev->name, UD_REG_NAME(PHY_ADDR), MII_EXPMA, 
		      (unsigned short)reg_addr) != 0)
		return -1;

	if (miiphy_write(dev->name, UD_REG_NAME(PHY_ADDR), MII_EXPMD, val) != 0)
		return -1;

	return 0;
}

int phy_expanded_write_bulk(struct eth_device *dev, const u32 reg_and_val[], 
			    int count)
{
	unsigned short v = 0;
	int i;
	u32 reg_addr;
	u16 val;
	struct hieth_netdev_local *ld = (struct hieth_netdev_local *)dev->priv;

	if (miiphy_read(dev->name, UD_REG_NAME(PHY_ADDR), PHY_BMCR, &v))
		return -1;

	v |= PHY_BMCR_POWD;
	if (miiphy_write (dev->name, UD_REG_NAME(PHY_ADDR), PHY_BMCR, v) != 0)
		return -1;

	for (i = 0; i < (2 * count); i += 2) {	
		reg_addr = reg_and_val[i];
		val = (u16) reg_and_val[i + 1];
		if (miiphy_write (dev->name, UD_REG_NAME(PHY_ADDR), 
			      MII_EXPMA, (unsigned short)reg_addr) != 0)
			return -1;

		if (miiphy_write(dev->name, UD_REG_NAME(PHY_ADDR), 
				   MII_EXPMD, val) != 0)
			return -1;
	}

	if (miiphy_read(dev->name, UD_REG_NAME(PHY_ADDR), PHY_BMCR, &v) != 0)
		return -1;

	v &= (~PHY_BMCR_POWD);
	if (miiphy_write (dev->name, UD_REG_NAME(PHY_ADDR), PHY_BMCR, v) != 0)
		return -1;

	return 0;
}

/* fix FEPHY for better eye diagram */
int hisilicon_fephy_fix(struct eth_device *dev)
{
	int count;

	count = sizeof(phy_fix_param) / sizeof(phy_fix_param[0]);
	if (count % 2)
		printf("internal FEPHY fix register count is not right.\n");
	count /= 2;

	phy_expanded_write_bulk(dev, phy_fix_param, count);

	return 0;
}

/* fix FEPHY for better eye diagram */
int hisilicon_fephy_fix_mv330(struct eth_device *dev)
{
	int count;

	count = sizeof(phy_fix_param_mv300) / sizeof(phy_fix_param_mv300[0]);
	if (count % 2)
		printf("internal FEPHY fix register count is not right.\n");
	count /= 2;

	phy_expanded_write_bulk(dev, phy_fix_param_mv300, count);

	return 0;
}
/*
 * Create a contiguous bitmask starting at bit position @l and ending at
 * position @h. For example
 * GENMASK_ULL(39, 21) gives us the 64bit vector 0x000000ffffe00000.
 */
#define GENMASK(h, l) \
	(((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

#define REG_LD_AM		0x3050
#define LD_AM_MASK		GENMASK(4, 0)
#define REG_LDO_AM		0x3051
#define LDO_AM_MASK		GENMASK(2, 0)
#define REG_R_TUNING		0x3052
#define R_TUNING_MASK		GENMASK(5, 0)
#define REG_WR_DONE		0x3053
#define REG_DEF_ATE		0x3057

#define REG_BASE_OTP		HI3716MV310_CA_BASE
#define OTP_FEPHY_ATE		0x1AC
#define DEF_LD_AM		0x12
#define DEF_LDO_AM		0x4
#define DEF_R_TUNING		0x1f

static int hieth_use_default_ate(struct eth_device *dev)
{
	struct hieth_netdev_local *ld = (struct hieth_netdev_local *)dev->priv;
	unsigned short v = 0;
	int timeout = 3;

	do {
		udelay(250 * 1000);
		v = phy_expanded_read(dev, REG_DEF_ATE);
		v &= (1 << 0);
	} while (!v && --timeout);
	if (!timeout)
		printf("festav271 0x3057 wait bit0 timeout!\n");

	return 0;
}

static int hieth_config_festa_phy_ate(struct eth_device *dev)
{
	struct hieth_netdev_local *ld = (struct hieth_netdev_local *)dev->priv;
	void *otp_base;
	u32 ate_params;
	unsigned short ld_amptlitude;
	unsigned short ldo_amptlitude;
	unsigned short r_tuning_val;
	unsigned short v = 0;
	int timeout = 3000;

	ld_amptlitude = DEF_LD_AM;
	ldo_amptlitude = DEF_LDO_AM;
	r_tuning_val = DEF_R_TUNING;

	otp_base = (void *)REG_BASE_OTP;
	ate_params = readl(otp_base + OTP_FEPHY_ATE);

	printf("fephy otp value %08x\n", ate_params);

	if (!ate_params)
		return hieth_use_default_ate(dev);

	ld_amptlitude = ate_params & LD_AM_MASK;
	ldo_amptlitude = (ate_params >> 8) & LDO_AM_MASK;
	r_tuning_val = (ate_params >> 16) & R_TUNING_MASK;

	v = phy_expanded_read(dev, REG_LD_AM);
	v = (v & ~LD_AM_MASK) | (ld_amptlitude & LD_AM_MASK);
	phy_expanded_write(dev, REG_LD_AM, v);

	v = phy_expanded_read(dev, REG_LDO_AM);
	v = (v & ~LDO_AM_MASK) | (ldo_amptlitude & LDO_AM_MASK);
	phy_expanded_write(dev, REG_LDO_AM, v);

	v = phy_expanded_read(dev, REG_R_TUNING);
	v = (v & ~R_TUNING_MASK) | (r_tuning_val & R_TUNING_MASK);
	phy_expanded_write(dev, REG_R_TUNING, v);

	v = phy_expanded_read(dev, REG_WR_DONE);
	if (v & (1 << 1))
		printf("festav271 0x3053 bit1 CFG_ACK value: 1\n");
	v = v | (1 << 0);
	phy_expanded_write(dev, REG_WR_DONE, v);

	do {
		udelay(100);
		v = phy_expanded_read(dev, REG_WR_DONE);
		v &= (1 << 1);
	} while (!v && --timeout);
	if (!timeout)
		printf("festav271 0x3053 wait bit1 CFG_ACK timeout!\n");

	return 0;
}

#ifdef CONFIG_FEPHY_TRIM
int hieth_fix_festa_phy_ate(struct eth_device *dev)
{
	if (_HI3716M_V330 == get_chipid()) {
		hieth_config_festa_phy_ate(dev);
		mdelay(5);
	}

	return 0;
}
#else
int hieth_fix_festa_phy_ate(struct eth_device *dev)
{
	mdelay(300);
	return 0;
}
#endif