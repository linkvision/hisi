#
# Automatically generated make config: don't edit
# SDK version: KERNELVERSION
# Thu Aug 18 15:05:52 2016
#

#
# Base
#
CFG_HI3716MV310=y
# CFG_HI3110EV500 is not set
# CFG_HI3716MV330 is not set
CFG_HI_CHIP_TYPE=hi3716mv310
CFG_ARM_HISIV200_LINUX=y
# CFG_ARM_HISTBV310_LINUX is not set
CFG_HI_TOOLCHAINS_NAME=arm-hisiv200-linux
CFG_HI_LOADER_SUPPORT=y
# CFG_HI_BOOTLOADER_SUPPORT is not set
CFG_HI_APPLOADER_SUPPORT=y
CFG_HI_OPTM_SIZE_SUPPORT=y

#
# Board
#

#
# Ethernet Config
#
CFG_HI_ETH_SUPPORT=y
CFG_HI_ETH_UP_PHYADDR=2
CFG_HI_ETH_DOWN_PHYADDR=1

#
# Flash Config
#
# CFG_HI_NAND_SUPPORT is not set
CFG_HI_SPI_SUPPORT=y
CFG_HI_SPI_BLOCK_SIZE=0x40000

#
# Tuner Config
#
CFG_HI_TUNER_NUMBER=1

#
# First Tuner Config
#
CFG_HI_TUNER_SIGNAL_CAB=y
# CFG_HI_TUNER_SIGNAL_SAT is not set
# CFG_HI_TUNER_SIGNAL_DVB_T is not set
# CFG_HI_TUNER_SIGNAL_DVB_T2 is not set
# CFG_HI_TUNER_SIGNAL_ISDB_T is not set
# CFG_HI_TUNER_SIGNAL_ATSC_T is not set
# CFG_HI_TUNER_SIGNAL_DTMB is not set
# CFG_HI_TUNER_SIGNAL_J83B is not set
# CFG_HI_TUNER_DEV_TYPE_XG_3BL is not set
# CFG_HI_TUNER_DEV_TYPE_CD1616 is not set
# CFG_HI_TUNER_DEV_TYPE_ALPS_TDAE is not set
# CFG_HI_TUNER_DEV_TYPE_TDCC is not set
# CFG_HI_TUNER_DEV_TYPE_TDA18250 is not set
# CFG_HI_TUNER_DEV_TYPE_CD1616_DOUBLE is not set
# CFG_HI_TUNER_DEV_TYPE_MT2081 is not set
# CFG_HI_TUNER_DEV_TYPE_TMX7070X is not set
# CFG_HI_TUNER_DEV_TYPE_R820C is not set
# CFG_HI_TUNER_DEV_TYPE_R836 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL203 is not set
# CFG_HI_TUNER_DEV_TYPE_AV2011 is not set
# CFG_HI_TUNER_DEV_TYPE_SHARP7903 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL101 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL603 is not set
# CFG_HI_TUNER_DEV_TYPE_IT9170 is not set
# CFG_HI_TUNER_DEV_TYPE_IT9133 is not set
# CFG_HI_TUNER_DEV_TYPE_TDA6651 is not set
CFG_HI_TUNER_DEV_TYPE_TDA18250B=y
# CFG_HI_TUNER_DEV_TYPE_M88TS2022 is not set
# CFG_HI_TUNER_DEV_TYPE_RDA5815 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL608 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL214 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL254 is not set
# CFG_HI_TUNER_DEV_TYPE_TDA18280 is not set
# CFG_HI_TUNER_DEV_TYPE_TDA18215 is not set
# CFG_HI_TUNER_DEV_TYPE_M88TC3800 is not set
# CFG_HI_TUNER_DEV_TYPE_SI2144 is not set
# CFG_HI_TUNER_DEV_TYPE_TDA18275A is not set
# CFG_HI_TUNER_DEV_TYPE_MXL661 is not set
# CFG_HI_TUNER_DEV_TYPE_SI2150 is not set
# CFG_HI_TUNER_DEV_TYPE_AV2018 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL601 is not set
# CFG_HI_TUNER_DEV_TYPE_R850 is not set
CFG_HI_TUNER_DEV_ADDR=0xc0
# CFG_HI_DEMOD_DEV_TYPE_NONE is not set
CFG_HI_DEMOD_DEV_TYPE_3130I=y
# CFG_HI_DEMOD_DEV_TYPE_3130E is not set
# CFG_HI_DEMOD_DEV_TYPE_J83B is not set
# CFG_HI_DEMOD_DEV_TYPE_AVL6211 is not set
# CFG_HI_DEMOD_DEV_TYPE_MXL101 is not set
# CFG_HI_DEMOD_DEV_TYPE_MN88472 is not set
# CFG_HI_DEMOD_DEV_TYPE_IT9170 is not set
# CFG_HI_DEMOD_DEV_TYPE_IT9133 is not set
# CFG_HI_DEMOD_DEV_TYPE_3136 is not set
# CFG_HI_DEMOD_DEV_TYPE_3136I is not set
# CFG_HI_DEMOD_DEV_TYPE_3137 is not set
# CFG_HI_DEMOD_DEV_TYPE_MXL254 is not set
# CFG_HI_DEMOD_DEV_TYPE_MXL214 is not set
# CFG_HI_DEMOD_DEV_TYPE_3138 is not set
# CFG_HI_DEMOD_DEV_TYPE_ATBM8869 is not set
CFG_HI_DEMOD_DEV_ADDR=0xa0
# CFG_HI_DEMOD_TS_DEFAULT is not set
CFG_HI_DEMOD_TS_PARALLEL_MODE_A=y
# CFG_HI_DEMOD_TS_PARALLEL_MODE_B is not set
# CFG_HI_DEMOD_TS_SERIAL is not set
# CFG_HI_DEMOD_TS_SERIAL_50 is not set
# CFG_HI_DEMOD_TS_SERIAL_2BIT is not set
CFG_HI_DEMOD_I2C_CHANNEL=3
CFG_HI_DEMOD_RESET_GPIO=0x0
CFG_HI_DEMUX_PORT=0

#
# Cable Attribute Config
#
CFG_HI_DEMOD_CAB_REF_CLOCK=24000
CFG_HI_TUNER_CAB_TS_SERIAL_PIN_0=y
# CFG_HI_TUNER_CAB_TS_SERIAL_PIN_7 is not set
# CFG_HI_TUNER_TSOUT is not set

#
# Second Tuner Config
#
CFG_HI_TUNER1_SIGNAL_CAB=y
# CFG_HI_TUNER1_SIGNAL_SAT is not set
# CFG_HI_TUNER1_SIGNAL_DVB_T is not set
# CFG_HI_TUNER1_SIGNAL_DVB_T2 is not set
# CFG_HI_TUNER1_SIGNAL_ISDB_T is not set
# CFG_HI_TUNER1_SIGNAL_ATSC_T is not set
# CFG_HI_TUNER1_SIGNAL_DTMB is not set
# CFG_HI_TUNER1_SIGNAL_J83B is not set
# CFG_HI_TUNER1_DEV_TYPE_XG_3BL is not set
# CFG_HI_TUNER1_DEV_TYPE_CD1616 is not set
# CFG_HI_TUNER1_DEV_TYPE_ALPS_TDAE is not set
# CFG_HI_TUNER1_DEV_TYPE_TDCC is not set
CFG_HI_TUNER1_DEV_TYPE_TDA18250=y
# CFG_HI_TUNER1_DEV_TYPE_CD1616_DOUBLE is not set
# CFG_HI_TUNER1_DEV_TYPE_MT2081 is not set
# CFG_HI_TUNER1_DEV_TYPE_TMX7070X is not set
# CFG_HI_TUNER1_DEV_TYPE_R820C is not set
# CFG_HI_TUNER1_DEV_TYPE_R836 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL203 is not set
# CFG_HI_TUNER1_DEV_TYPE_AV2011 is not set
# CFG_HI_TUNER1_DEV_TYPE_SHARP7903 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL101 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL603 is not set
# CFG_HI_TUNER1_DEV_TYPE_IT9170 is not set
# CFG_HI_TUNER1_DEV_TYPE_IT9133 is not set
# CFG_HI_TUNER1_DEV_TYPE_TDA6651 is not set
# CFG_HI_TUNER1_DEV_TYPE_TDA18250B is not set
# CFG_HI_TUNER1_DEV_TYPE_M88TS2022 is not set
# CFG_HI_TUNER1_DEV_TYPE_RDA5815 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL608 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL214 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL254 is not set
# CFG_HI_TUNER1_DEV_TYPE_TDA18280 is not set
# CFG_HI_TUNER1_DEV_TYPE_TDA18215 is not set
# CFG_HI_TUNER1_DEV_TYPE_M88TC3800 is not set
# CFG_HI_TUNER1_DEV_TYPE_SI2144 is not set
# CFG_HI_TUNER1_DEV_TYPE_TDA18275A is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL661 is not set
# CFG_HI_TUNER1_DEV_TYPE_SI2150 is not set
# CFG_HI_TUNER1_DEV_TYPE_AV2018 is not set
# CFG_HI_TUNER1_DEV_TYPE_MXL601 is not set
# CFG_HI_TUNER1_DEV_TYPE_R850 is not set
CFG_HI_TUNER1_DEV_ADDR=0xc6
# CFG_HI_DEMOD1_DEV_TYPE_NONE is not set
CFG_HI_DEMOD1_DEV_TYPE_3130I=y
# CFG_HI_DEMOD1_DEV_TYPE_3130E is not set
# CFG_HI_DEMOD1_DEV_TYPE_J83B is not set
# CFG_HI_DEMOD1_DEV_TYPE_AVL6211 is not set
# CFG_HI_DEMOD1_DEV_TYPE_MXL101 is not set
# CFG_HI_DEMOD1_DEV_TYPE_MN88472 is not set
# CFG_HI_DEMOD1_DEV_TYPE_IT9170 is not set
# CFG_HI_DEMOD1_DEV_TYPE_IT9133 is not set
# CFG_HI_DEMOD1_DEV_TYPE_3136 is not set
# CFG_HI_DEMOD1_DEV_TYPE_3136I is not set
# CFG_HI_DEMOD1_DEV_TYPE_3137 is not set
# CFG_HI_DEMOD1_DEV_TYPE_MXL254 is not set
# CFG_HI_DEMOD1_DEV_TYPE_MXL214 is not set
# CFG_HI_DEMOD1_DEV_TYPE_3138 is not set
# CFG_HI_DEMOD1_DEV_TYPE_ATBM8869 is not set
CFG_HI_DEMOD1_DEV_ADDR=0xb6
# CFG_HI_DEMOD1_TS_DEFAULT is not set
CFG_HI_DEMOD1_TS_PARALLEL_MODE_A=y
# CFG_HI_DEMOD1_TS_PARALLEL_MODE_B is not set
# CFG_HI_DEMOD1_TS_SERIAL is not set
# CFG_HI_DEMOD1_TS_SERIAL_50 is not set
# CFG_HI_DEMOD1_TS_SERIAL_2BIT is not set
CFG_HI_DEMOD1_I2C_CHANNEL=4
CFG_HI_DEMOD1_RESET_GPIO=0x0
CFG_HI_DEMUX1_PORT=0

#
# Cable Attribute Config
#
CFG_HI_DEMOD1_CAB_REF_CLOCK=24000
CFG_HI_TUNER1_CAB_TS_SERIAL_PIN_0=y
# CFG_HI_TUNER1_CAB_TS_SERIAL_PIN_7 is not set
# CFG_HI_TUNER1_TSOUT is not set

#
# Video DAC Config
#
CFG_HI_DAC_CVBS=3
CFG_HI_DAC_YPBPR_Y=1
CFG_HI_DAC_YPBPR_PB=2
CFG_HI_DAC_YPBPR_PR=0

#
# Keyled Config
#
CFG_HI_KEYLED_SUPPORT=y
# CFG_HI_KEYLED_GPIOKEY_SUPPORT is not set
CFG_HI_KEYLED_CT1642_SUPPORT=y
# CFG_HI_KEYLED_CT1642_GPIO_MODE is not set
# CFG_HI_KEYLED_PT6961_SUPPORT is not set
# CFG_HI_KEYLED_PT6964_SUPPORT is not set
# CFG_HI_KEYLED_FD650_SUPPORT is not set
# CFG_HI_SND_MUTECTL_SUPPORT is not set

#
# SCI Config
#
CFG_HI_SCI_NUMBER=1

#
# First Sci Config
#
CFG_HI_SCI0_CLK_MODE_CMOS=y
# CFG_HI_SCI0_CLK_MODE_OD is not set
CFG_HI_SCI0_VCCEN_LOW=y
# CFG_HI_SCI0_VCCEN_HIGH is not set
CFG_HI_SCI0_DETECT_LOW=y
# CFG_HI_SCI0_DETECT_HIGH is not set
CFG_HI_BOOT_REG_NAME=hi3716m31dma_hi3716mv310_ddr3_512Mbyte_16bit_2layers.reg
CFG_HI_BOOT_CFG_NAME=hi3716m31dma_hi3716mv310_ddr3_512Mbyte_16bit_2layers_spi.cfg

#
# Uboot
#
# CFG_HI_UBOOT_SUPPORT is not set
CFG_HI_MINIBOOT_SUPPORT=y
CFG_HI_BOOT_ENV_STARTADDR=0x80000
CFG_HI_BOOT_ENV_SIZE=0x10000
CFG_HI_BOOT_ENV_RANGE=0x20000
# CFG_HI_BOOT_ENV_BAK_SUPPORT is not set
CFG_HI_BOOT_COMPRESSED=y
# CFG_HI_BOOT_USB_SUPPORT is not set

#
# Build Product Code in Fastboot
#
CFG_HI_BUILD_WITH_PRODUCT=y
# CFG_HI_BOOTLOADER_OSD_LANG_EN is not set
# CFG_HI_BOOTLOADER_OSD_LANG_CN is not set
# CFG_HI_BOOTLOADER_USB_PROTOCOL_HISI_FILE is not set
# CFG_HI_BOOTLOADER_TUNER_CAB is not set
# CFG_HI_BOOTLOADER_TUNER_TER is not set
# CFG_HI_BOOTLOADER_TUNER_SAT is not set
# CFG_HI_BOOTLOADER_TUNER_DVB_T is not set
# CFG_HI_BOOTLOADER_TUNER_DVB_T2 is not set
# CFG_HI_BOOTLOADER_PROTOCOL_SSU_OTA is not set
# CFG_HI_BOOTLOADER_PROTOCOL_HISI_OTA is not set
CFG_HI_BUILD_WITH_FRONTEND=y
# CFG_HI_BOOT_TUNER_TYPE_ALPS_TDAE is not set
# CFG_HI_BOOT_TUNER_TYPE_TDCC is not set
# CFG_HI_BOOT_TUNER_TYPE_TDA18250 is not set
CFG_HI_BOOT_TUNER_TYPE_TDA18250B=y
# CFG_HI_BOOT_TUNER_TYPE_TMX7070X is not set
# CFG_HI_BOOT_TUNER_TYPE_R820C is not set
# CFG_HI_BOOT_TUNER_TYPE_R836 is not set
# CFG_HI_BOOT_TUNER_TYPE_MXL203 is not set
# CFG_HI_BOOT_TUNER_TYPE_AV2011 is not set
# CFG_HI_BOOT_TUNER_TYPE_SHARP7903 is not set
# CFG_HI_BOOT_TUNER_TYPE_M88TS2022 is not set
# CFG_HI_BOOT_TUNER_TYPE_RDA5815 is not set
# CFG_HI_BOOT_TUNER_TYPE_MXL603 is not set
# CFG_HI_BOOT_TUNER_TYPE_MXL608 is not set
# CFG_HI_BOOT_TUNER_TYPE_TDA18215 is not set
# CFG_HI_BOOT_TUNER_TYPE_M88TC3800 is not set
# CFG_HI_BOOT_TUNER_TYPE_SI2144 is not set
# CFG_HI_BOOT_TUNER_TYPE_TDA18275A is not set
# CFG_HI_BOOT_TUNER_TYPE_MXL661 is not set
# CFG_HI_BOOT_TUNER_TYPE_SI2150 is not set
# CFG_HI_BOOT_TUNER_TYPE_R850 is not set
CFG_HI_BOOT_DEMOD_TYPE_HI3130I=y
# CFG_HI_BOOT_DEMOD_TYPE_J83B is not set
# CFG_HI_BOOT_DEMOD_TYPE_HI3136 is not set
CFG_HI_BUILD_WITH_IR=y
CFG_HI_BUILD_WITH_KEYLED=y
# CFG_HI_BOOT_KEYLED_GPIOKEY is not set
# CFG_HI_BOOT_KEYLED_74HC164 is not set
CFG_HI_BOOT_KEYLED_CT1642=y
# CFG_HI_BOOT_KEYLED_PT6961 is not set
# CFG_HI_BOOT_KEYLED_PT6964 is not set
# CFG_HI_BOOT_KEYLED_FD650 is not set

#
# Kernel
#
# CFG_LINUX-2.6.35 is not set
CFG_LINUX-3.10.y=y
# CFG_LINUX-3.18.y is not set
CFG_HI_KERNEL_VERSION=linux-3.10.y
CFG_HI_KERNEL_CFG=hi3716mv310_vmx_mini_defconfig
# CFG_HI_FS_BUILDIN is not set
CFG_HI_MSP_BUILDIN=y

#
# Rootfs
#

#
# Board Tools Config
#
CFG_HI_TOOL_UDEV_SUPPORT=y
# CFG_HI_TOOL_MDEV_SUPPORT is not set
CFG_HI_TOOL_DOSFS_SUPPORT=y
CFG_HI_MKDOSFS_TOOLS_SUPPORT=y
# CFG_HI_DOSFSCK_TOOLS_SUPPORT is not set
# CFG_HI_TOOL_FILECAP_SUPPORT is not set
# CFG_HI_TOOL_GDB_SUPPORT is not set
# CFG_HI_TOOL_IPTABLES_SUPPORT is not set
# CFG_HI_TOOL_MTDUTILS_SUPPORT is not set
CFG_HI_TOOL_REG_SUPPORT=y
CFG_HI_TOOL_SANDBOX_SUPPORT=y
# CFG_HI_TOOL_TOP_SUPPORT is not set
CFG_HI_TOOL_PPPD_SUPPORT=y
# CFG_HI_TOOL_IPERF_SUPPORT is not set
# CFG_HI_TOOL_MSP_DEBUG_SUPPORT is not set
# CFG_HI_TOOL_SOC_SERVER is not set
# CFG_HI_LXC_CONTAINER_SUPPORT is not set
# CFG_HI_TOOL_MEMTESTER_SUPPORT is not set

#
# Busybox Config
#
CFG_BUSYBOX_1.16.1=y
# CFG_BUSYBOX_1.24.1 is not set
CFG_HI_BUSYBOX_CFG_NAME=glibc_mini_debug.config
# CFG_HI_LIBC_FULL_SUPPORT is not set
CFG_HI_LIBC_LITE_SUPPORT=y
# CFG_HI_LIBCPP_SUPPORT is not set

#
# File System Config
#
# CFG_HI_ROOTFS_RULEFILE is not set
CFG_HI_ROOTFS_STRIP=y
# CFG_HI_ROOTFS_INSTALL_SHARED_LIBS is not set
# CFG_HI_ROOTFS_CRAMFS is not set
# CFG_HI_ROOTFS_JFFS2 is not set
CFG_HI_ROOTFS_SQUASHFS=y

#
# Common
#
CFG_HI_LOG_SUPPORT=y
CFG_HI_LOG_LEVEL=1
CFG_HI_LOG_NETWORK_SUPPORT=y
CFG_HI_LOG_UDISK_SUPPORT=y
# CFG_HI_MEMMGR_SUPPORT is not set
CFG_HI_PROC_SUPPORT=y
# CFG_HI_MOD_POSTPID is not set

#
# Component
#
CFG_HI_ADVCA_SUPPORT=y
# CFG_ADVCA_CONAX is not set
# CFG_ADVCA_NOVEL is not set
# CFG_ADVCA_NAGRA is not set
# CFG_ADVCA_SUMA is not set
# CFG_ADVCA_CTI is not set
CFG_ADVCA_VERIMATRIX=y
# CFG_ADVCA_IRDETO is not set
# CFG_ADVCA_PANACCESS is not set
# CFG_ADVCA_DCAS is not set
# CFG_ADVCA_OTHER is not set
CFG_HI_ADVCA_TYPE=VERIMATRIX
# CFG_ADVCA_FUNCTION is not set
# CFG_HI_ADVCA_VERIFY_ENABLE is not set
CFG_HI_ADVCA_SANDBOX_SUPPORT=y
CFG_SANDBOX_CHROOT=y
# CFG_SANDBOX_LXC is not set
CFG_HI_ADVCA_SANDBOX_TYPE=CHROOT
CFG_HI_WIFI_SUPPORT=y

#
# WiFi Device Type
#
CFG_HI_WIFI_DEVICE_RTL8188EUS=y
# CFG_HI_WIFI_DEVICE_RTL8192EU is not set
# CFG_HI_WIFI_DEVICE_RTL8723BU is not set
# CFG_HI_WIFI_DEVICE_RT5370 is not set
# CFG_HI_WIFI_DEVICE_MT7601U is not set
# CFG_HI_WIFI_DEVICE_RT5572 is not set

#
# WiFi Working Mode
#
CFG_HI_WIFI_MODE_STA=y
# CFG_HI_WIFI_MODE_AP is not set
# CFG_HI_FAT_SUPPORT is not set
CFG_HI_NTFS_SUPPORT=y
CFG_HI_NTFS_MODULE_SUPPORT=y
CFG_HI_NTFS_TOOLS_SUPPORT=y
# CFG_HI_NTFS_CHECK_TOOLS_SUPPORT is not set
CFG_HI_NTFS_FORMAT_TOOLS_SUPPORT=y
CFG_HI_3G_SUPPORT=y
# CFG_HI_ALSA_SUPPORT is not set
# CFG_HI_BLUETOOTH_SUPPORT is not set

#
# HACODEC Config
#
CFG_HI_HACODEC_MP3DECODE_SUPPORT=y
CFG_HI_HACODEC_AACDECODE_SUPPORT=y
CFG_HI_HACODEC_AC3PASSTHROUGH_SUPPORT=y
# CFG_HI_HACODEC_AMRNBCODEC_SUPPORT is not set
# CFG_HI_HACODEC_AMRWBCODEC_SUPPORT is not set
# CFG_HI_HACODEC_BLURAYLPCMDECODE_SUPPORT is not set
CFG_HI_HACODEC_COOKDECODE_SUPPORT=y
# CFG_HI_HACODEC_DRADECODE_SUPPORT is not set
# CFG_HI_HACODEC_DTSPASSTHROUGH_SUPPORT is not set
# CFG_HI_HACODEC_G711CODEC_SUPPORT is not set
# CFG_HI_HACODEC_G722CODEC_SUPPORT is not set
# CFG_HI_HACODEC_MP2DECODE_SUPPORT is not set
CFG_HI_HACODEC_PCMDECODE_SUPPORT=y
CFG_HI_HACODEC_WMADECODE_SUPPORT=y
# CFG_HI_PES_SUPPORT is not set

#
# Caption Config
#
CFG_HI_CAPTION_SUBT_SUPPORT=y
# CFG_HI_CAPTION_TTX_SUPPORT is not set
CFG_HI_CAPTION_SO_SUPPORT=y
CFG_HI_CAPTION_CC_SUPPORT=y
CFG_HI_PLAYER_SUPPORT=y
# CFG_HI_PLAYER_FULL_SUPPORT is not set
CFG_HI_PLAYER_NORMAL_SUPPORT=y
# CFG_HI_LOADER_APPLOADER is not set

#
# Msp
#

#
# Frontend Config
#
# CFG_HI_DISEQC_SUPPORT is not set

#
# Tuner Config
#
# CFG_HI_TUNER_TYPE_XG_3BL is not set
# CFG_HI_TUNER_TYPE_CD1616 is not set
# CFG_HI_TUNER_TYPE_ALPS_TDAE is not set
# CFG_HI_TUNER_TYPE_TDCC is not set
# CFG_HI_TUNER_TYPE_TDA18250 is not set
CFG_HI_TUNER_TYPE_TDA18250B=y
# CFG_HI_TUNER_TYPE_CD1616_LF_GIH_4 is not set
# CFG_HI_TUNER_TYPE_MT2081 is not set
# CFG_HI_TUNER_TYPE_TMX7070X is not set
# CFG_HI_TUNER_TYPE_R820C is not set
# CFG_HI_TUNER_TYPE_R836 is not set
# CFG_HI_TUNER_TYPE_MXL203 is not set
# CFG_HI_TUNER_TYPE_AV2011 is not set
# CFG_HI_TUNER_TYPE_SHARP7903 is not set
# CFG_HI_TUNER_TYPE_M88TS2022 is not set
# CFG_HI_TUNER_TYPE_RDA5815 is not set
# CFG_HI_TUNER_TYPE_MXL603 is not set
# CFG_HI_TUNER_TYPE_MXL608 is not set
# CFG_HI_TUNER_TYPE_TDA6651 is not set
# CFG_HI_TUNER_TYPE_MXL214 is not set
# CFG_HI_TUNER_TYPE_MXL254 is not set
# CFG_HI_TUNER_TYPE_TDA18280 is not set
# CFG_HI_TUNER_TYPE_TDA18215 is not set
# CFG_HI_TUNER_TYPE_M88TC3800 is not set
# CFG_HI_TUNER_TYPE_SI2144 is not set
# CFG_HI_TUNER_TYPE_TDA18275A is not set
# CFG_HI_TUNER_TYPE_MXL661 is not set
# CFG_HI_TUNER_TYPE_SI2150 is not set
# CFG_HI_TUNER_TYPE_R850 is not set

#
# Demod Config
#
CFG_HI_DEMOD_TYPE_HI3130I=y
# CFG_HI_DEMOD_TYPE_HI3130E is not set
# CFG_HI_DEMOD_TYPE_J83B is not set
# CFG_HI_DEMOD_TYPE_AVL6211 is not set
# CFG_HI_DEMOD_TYPE_MXL101 is not set
# CFG_HI_DEMOD_TYPE_MN88472 is not set
# CFG_HI_DEMOD_TYPE_IT9133 is not set
# CFG_HI_DEMOD_TYPE_IT9170 is not set
# CFG_HI_DEMOD_TYPE_HI3136 is not set
# CFG_HI_DEMOD_TYPE_HI3137 is not set
# CFG_HI_DEMOD_TYPE_MXL214 is not set
# CFG_HI_DEMOD_TYPE_MXL254 is not set
# CFG_HI_DEMOD_TYPE_TDA18280 is not set
# CFG_HI_DEMOD_TYPE_HI3138 is not set
# CFG_HI_DEMOD_TYPE_ATBM8869 is not set

#
# LNB Chip Config
#
# CFG_HI_LNB_CTRL_ISL9492 is not set
# CFG_HI_LNB_CTRL_MPS8125 is not set

#
# DEMUX Config
#
CFG_HI_DEMUX_SUPPORT_PROC=y
CFG_HI_DEMUX_SUPPORT_REC=y
CFG_HI_DEMUX_SUPPORT_SCD=y
CFG_HI_DEMUX_SUPPORT_TSO=y
CFG_HI_DEMUX_SUPPORT_DESC=y
CFG_HI_DEMUX_POOLBUF_SIZE=0x100000

#
# Audio Config
#
# CFG_HI_SND_ALSA_AO_SUPPORT is not set
CFG_HI_SND_ADAC_SUPPORT=y
CFG_HI_SND_SPDIF_SUPPORT=y
CFG_HI_SND_HDMI_SUPPORT=y
CFG_HI_ADEC_MAX_INSTANCE=2
CFG_HI_ADEC_AUDSPECTRUM_SUPPORT=y
# CFG_HI_SND_AVC_SUPPORT is not set
CFG_HI_RESAMPLER_QUALITY_LINEAR=y
# CFG_HI_SUPPORT_INTERNAL_OP is not set

#
# Video Decoder Config
#
CFG_HD_FULL=y
# CFG_HD_SIMPLE is not set
# CFG_HD_BASIC is not set
CFG_HI_VFMW_DECODE_CAPABILITY=HD_FULL
CFG_FHD=y
# CFG_D1 is not set
CFG_HI_VFMW_DECODE_PREALLOC_MMZ=FHD
CFG_HI_VDEC_MAX_INSTANCE=2
CFG_HI_VDEC_MAX_REF_FRAME=5
CFG_HI_VDEC_MAX_DISP_FRAME=6
CFG_HI_VDEC_SCD_BUFFER_SIZE=0x200000
CFG_HI_VDEC_DEINTERLACE_SUPPORT=y
# CFG_HI_VDEC_SVDEC_SUPPORT is not set
# CFG_HI_VDEC_REG_CODEC_SUPPORT is not set
# CFG_HI_VDEC_MJPEG_SUPPORT is not set
CFG_HI_VDEC_USERDATA_CC_SUPPORT=y
CFG_HI_VDEC_USERDATA_CC_BUFSIZE=0x4000
CFG_HI_VDEC_DSD_SUPPORT=y

#
# VO Config
#
CFG_HI_DISP_CVBS_VIDEO_BUFF=y
# CFG_HI_DISP_CVBS_LC is not set
# CFG_HI_DISP_YPBPR_VIDEO_BUFF is not set
CFG_HI_DISP_YPBPR_LC=y
CFG_HI_DISP_TTX_SUPPORT=y
CFG_HI_DISP_TTX_INBUFFERSIZE=0x4000
CFG_HI_DISP_CC_SUPPORT=y
CFG_HI_DISP_CC_INBUFFERSIZE=0x4000
CFG_HI_VO_DUMPFRAME_SUPPORT=y

#
# HDMI Config
#
CFG_HI_HDMI_SUPPORT_HDCP=y
# CFG_HI_HDMI_SUPPORT_CEC is not set
# CFG_HI_HDMI_SUPPORT_DEBUG is not set

#
# I2C Config
#

#
# Avplay Config
#
# CFG_HI_AVPLAY_FCC_SUPPORT is not set

#
# Graphic Config
#
CFG_LIB_JPEG_VERSION_6B=y
# CFG_LIB_JPEG_VERSION_9A is not set
# CFG_LIB_PNG_VERSION_1_6_16 is not set
CFG_LIB_PNG_VERSION_1_4_16=y
# CFG_HI_JPEG_SOFT_ENCODE_SUPPORT is not set
# CFG_HI_DIRECTFB_SUPPORT is not set
# CFG_HIFB_CURSOR_SUPPORT is not set
# CFG_HIFB_SCROLLTEXT_SUPPORT is not set
CFG_HI_PNG_DECODER_SUPPORT=y
CFG_HI_FREETYPE_FONT_SUPPORT=y
CFG_HI_FREETYPE_MINI_LIB_SUPPORT=y
CFG_HI_TDE_CSCTMPBUFFER_SIZE=0x0
CFG_HI_JPEG6B_STREAMBUFFER_SIZE=0x80000
CFG_HI_HD_FB_VRAM_SIZE=3600

#
# IR Config
#
CFG_HI_IR_TYPE_S2=y
# CFG_HI_IR_TYPE_STD is not set
# CFG_HI_IR_TYPE_LIRC is not set
CFG_HI_IR_NEC_SUPPORT=y
# CFG_HI_IR_RC6_SUPPORT is not set
# CFG_HI_IR_RC5_SUPPORT is not set
# CFG_HI_IR_SONY_SUPPORT is not set
# CFG_HI_IR_TC9012_SUPPORT is not set
# CFG_HI_IR_CREDIT_SUPPORT is not set

#
# Cipher Config
#
CFG_HI_CIPHER_MULTICIPHER_SUPPORT=y
# CFG_HI_CIPHER_MULTI_PACKGET is not set
CFG_HI_CIPHER_HASH_SUPPORT=y
# CFG_HI_CIPHER_AES_CBCMAC is not set
# CFG_HI_CIPHER_HASH_IRDETO_CBCMAC is not set
# CFG_HI_CIPHER_HASH_HMAC is not set
CFG_HI_CIPHER_HDCP_SUPPORT=y
CFG_HI_CIPHER_RNG_SUPPORT=y

#
# CI/CI+ Config
#
# CFG_HI_CIPLUS_SUPPORT is not set
# CFG_HI_MCE_SUPPORT is not set
CFG_HI_SCI_SUPPORT=y
CFG_HI_GPIOI2C_SUPPORT=y

#
# PVR Config
#
CFG_HI_PVR_SUPPORT=y
# CFG_HI_PVR_L2_CACHE_SUPPORT is not set
