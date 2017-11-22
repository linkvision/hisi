#ifndef __HI_CHIP_REGS_H__
#define __HI_CHIP_REGS_H__

#include <mach/io.h>

#define REG_BASE_DDRC		0x10100000
#define REG_BASE_VOU		0x10110000
#define REG_BASE_TDE		0x10120000
#define REG_BASE_VDH		0x10130000
#define REG_BASE_PGD		0x10150000
#define REG_BASE_AO		0x10160000
#define REG_BASE_HDMI		0x10170000
#define REG_BASE_OTP		0x10180000

#define REG_BASE_SCTL		0x101E0000
#define REG_BASE_IR		0x101E1000
#define REG_BASE_TIMER01	0x101E2000
#define REG_BASE_LEDC		0x101E3000
#define REG_BASE_GPIO5		0x101E4000
//#define REG_BASE_TIMER67	0x101E5000
#define REG_BASE_GPIO0		0x101E6000
#define REG_BASE_GPIO1		0x101E7000
#define REG_BASE_GPIO2		0x101E8000
#define REG_BASE_GPIO3		0x101E9000
#define REG_BASE_GPIO4		0x101EA000
#define REG_BASE_TIMER45	0x101EB000
#define REG_BASE_GPIO6		0x101EC000
#define REG_BASE_GPIO7		0x101ED000
#define REG_BASE_GPIO8		0x101EE000
#define REG_BASE_GPIO9		0x101EF000
#define REG_BASE_GPIO10		0x101F0000
#define REG_BASE_GPIO11		0x101F1000
#define REG_BASE_GPIO12		0x101F2000

#define REG_BASE_SCI0		0x101F3000
#define REG_BASE_SCI1		0x101F4000
#define REG_BASE_CRG		0x101F5000
#define REG_BASE_I2C_QAM	0x101F6000
#define REG_BASE_I2C0		0x101F7000
#define REG_BASE_I2C1		0x101F8000
#define REG_BASE_I2C2		0x101F9000
#define REG_BASE_I2C3		0x101FA000
#define REG_BASE_UART0		0x101E5000
#define REG_BASE_UART1		0x101FC000
#define REG_BASE_UART3		0x101FE000
#define REG_BASE_SSP		0x101FF000

#define REG_BASE_PERI_CTRL	0x10200000
#define REG_START_MODE		0
#define REG_BASE_PERI_CTRL_START_MODE	(REG_BASE_PERI_CTRL)
#define CA_BOOTMODE_OFFSET	2
#define CA_BOOTMODE_MASK	3
#define NORMAL_BOOTMODE_OFFSET	9
#define NORMAL_BOOTMODE_MASK	3
#define OTP_BOOTMODE_OFFSET	2
#define OTP_BOOTMODE_MASK	1
#define PIN_BOOTMODE_OFFSET	11
#define PIN_BOOTMODE_MASK	1
#define CA_SCS_MASK		2

#define REG_BASE_WDG		0x10201000
#define REG_BASE_TIMER23	0x10202000
#define REG_BASE_IO_CONFIG	0x10203000
#define REG_BASE_PWM		0x10204000

#define REG_BASE_A9_PERI	0x10220000
#define REG_BASE_CSSYS		0x10330000
#define REG_BASE_DNR		0x10450000

#define REG_BASE_L2CACHE	0x16800000

#define REG_BASE_SMI		0x60000000
#define REG_BASE_NANDC		0x60010000
#define REG_BASE_SFC		0x60020000
#define REG_BASE_DMAC		0x60030000
#define REG_BASE_SATA		0x60040000
#define REG_BASE_PCIE0		0x60050000
#define REG_BASE_OHCI		0x60070000
#define REG_BASE_EHCI		0x60080000
#define REG_BASE_MCU_SLAVE	0x600B0000
#define REG_BASE_PVR		0x600C0000
#define REG_BASE_SF		0x600D0000
#define REG_BASE_CIPHER		0x600E0000
#define REG_BASE_SCD		0x600F0000
#define REG_BASE_JPEG		0x60100000
#define REG_BASE_VEDU		0x60110000
#define REG_BASE_VIU		0x60130000
#define REG_BASE_GMAC		0x60140000

#define REG_BASE_SIO0		0x60150000
#define REG_BASE_GPU		0x60180000
#define REG_BASE_MMC_SD_SDIO	0x601C0000

/*CORTTX-A9 MPCORE MEMORY REGION*/
#define REG_A9_PERI_SCU 	0x0000
#define REG_A9_PERI_GIC_CPU 0x0100
#define REG_A9_PERI_GLOBAL_TIMER    0x0200
#define REG_A9_PERI_PRI_TIMER_WDT   0x0600
#define REG_A9_PERI_GIC_DIST  0x1000 

#define REG_BASE_CA                    0x10000000
#define REG_END_CA                     0x1000ffff

/* CA clock and reset register */
#define REG_PERI_CRG29                0x00B4

#define CA_CTRL_PROC                   0x78
#define CA_VENDOR_OFFSET               28
#define CA_VENDOR_MASK                 0x0f
#define CA_TYPE_NO_CA                  0
#define CA_TYPE_NAGRA                  1

#define REG_PERI_CRG94                0x178

#define HI3716MV310_PERI_SOC_FUSE_0    (0x840)
#define HI3716MV310_PERI_SOC_FUSE_MASK (0x1f << 16)

/* SYSTEM CONTROL REG */
#define REG_SC_CTRL                         0x0000
#define REG_SC_SYSRES                       0x0004
#define REG_SC_XTALCTRL                     0x0010
#define REG_SC_APLLCTRL                     0x0014
#define REG_SC_APLLFREQCTRL0                0x0018
#define REG_SC_APLLFREQCTRL1                0x001C
#define REG_SC_VPLL0FREQCTRL0               0x0020
#define REG_SC_VPLL0FREQCTRL1               0x0024
#define REG_SC_VPLL1FREQCTRL0               0x0028
#define REG_SC_VPLL1FREQCTRL1               0x002C
#define REG_SC_EPLLFREQCTRL0                0x0030
#define REG_SC_EPLLFREQCTRL1                0x0034
#define REG_SC_QPLLFREQCTRL0                0x0038
#define REG_SC_QPLLFREQCTRL1                0x003C
#define REG_SC_LOW_POWER_CTRL               0x0040
#define REG_SC_IO_REUSE_SEL                 0x0044
#define REG_SC_SRST_REQ_CTRL                0x0048
#define REG_SC_CA_RST_CTRL                  0x004C
#define REG_SC_WDG_RST_CTRL                 0x0050
#define REG_SC_DDRC_DFI_RST_CTRL            0x0054
#define REG_SC_PLLLOCK_STAT                 0x0070
#define REG_SC_GEN0                         0x0080
#define REG_SC_GEN1                         0x0084
#define REG_SC_GEN2                         0x0088
#define REG_SC_GEN3                         0x008C
#define REG_SC_GEN4                         0x0090
#define REG_SC_GEN5                         0x0094
#define REG_SC_GEN6                         0x0098
#define REG_SC_GEN7                         0x009C
#define REG_SC_GEN8                         0x00A0
#define REG_SC_GEN9                         0x00A4
#define REG_SC_GEN10                        0x00A8
#define REG_SC_GEN11                        0x00AC
#define REG_SC_GEN12                        0x00B0
#define REG_SC_GEN13                        0x00B4
#define REG_SC_GEN14                        0x00B8
#define REG_SC_GEN15                        0x00BC
#define REG_SC_GEN16                        0x00C0
#define REG_SC_GEN17                        0x00C4
#define REG_SC_GEN18                        0x00C8
#define REG_SC_GEN19                        0x00CC
#define REG_SC_GEN20                        0x00D0
#define REG_SC_GEN21                        0x00D4
#define REG_SC_GEN22                        0x00D8
#define REG_SC_GEN23                        0x00DC
#define REG_SC_GEN24                        0x00E0
#define REG_SC_GEN25                        0x00E4
#define REG_SC_GEN26                        0x00E8
#define REG_SC_GEN27                        0x00EC
#define REG_SC_GEN28                        0x00F0
#define REG_SC_GEN29                        0x00F4
#define REG_SC_GEN30                        0x00F8
#define REG_SC_GEN31                        0x00FC
#define REG_SC_LOCKEN                       0x020C
#define REG_SC_SYSID0                       0x0EE0
#define REG_SC_SYSID1                       0x0EE4
#define REG_SC_SYSID2                       0x0EE8
#define REG_SC_SYSID3                       0x0EEC

#define HI3716MV310_CA_BASE                 0x10180000
#define HI3716MV310_BOOT_MODE_SEL           0x80
#define HI3716MV310_BOOT_MODE_SEL_MASK      0x03

#define HI3716MV310_CA_BOOTSEL_CTRL         0x84
#define HI3716MV310_CA_BOOTSEL_CTRL_MASK    0x04

#define REG_BASE_WDG0                       0x10201000

#define REG_TIMER_RELOAD	0x000
#define REG_TIMER_VALUE		0x004
#define REG_TIMER_CONTROL	0x008
#define REG_TIMER_INTCLR	0x00C
#define REG_TIMER_RIS		0x010
#define REG_TIMER_MIS		0x014
#define REG_TIMER_BGLOAD	0x018

#define REG_TIMER1_RELOAD        0x020
#define REG_TIMER1_VALUE         0x024
#define REG_TIMER1_CONTROL       0x028
#define REG_TIMER1_INTCLR        0x02C
#define REG_TIMER1_RIS           0x030
#define REG_TIMER1_MIS           0x034
#define REG_TIMER1_BGLOAD        0x038

#define CFG_GIC_CPU_BASE    (IO_ADDRESS(REG_BASE_A9_PERI) + REG_A9_PERI_GIC_CPU)
#define CFG_GIC_DIST_BASE   (IO_ADDRESS(REG_BASE_A9_PERI) + REG_A9_PERI_GIC_DIST)

#define DDR_SUSPEND_SIZE        0x1000       /* size 1KB */

/* timer source */
#define HI3712_OSC_FREQ         24000000

/*********************************************************************/
/*
 * 0x1-> init item1
 * 0x2-> init item2
 * 0x3->init item1 & item2
 */
#define INIT_REG_ITEM1               1
#define INIT_REG_ITEM2               2
#define INIT_REG_ITEM1_ITEM2         (INIT_REG_ITEM1 | INIT_REG_ITEM2)

#endif /*End of __HI_CHIP_REGS_H__ */
