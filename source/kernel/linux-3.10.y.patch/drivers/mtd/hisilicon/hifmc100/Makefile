
obj-y	+= hifmc100_host.o
obj-y	+= hifmc100_spinor.o
obj-$(CONFIG_MTD_NAND)		+= hifmc100_xnand.o
obj-$(CONFIG_ARCH_HI3716MV310)	+= hifmc100_clock_hi3716mv330.o
obj-$(CONFIG_ARCH_S40)		+= hifmc100_clock_hi3716mv410.o
obj-$(CONFIG_ARCH_HI3798CV2X)	+= hifmc100_clock_hi3798cv2x.o

ccflags-y += -I./drivers/mtd/hisilicon
