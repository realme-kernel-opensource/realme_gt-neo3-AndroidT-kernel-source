# SPDX-License-Identifier: GPL-2.0

# MENU Governor Predict(low power) include path
ifeq ($(CONFIG_MTK_ACAO_SUPPORT),y)
ccflags-y += -I$(srctree)/drivers/misc/mediatek/base/power/mcdi/include/
endif

# adsp include path
ccflags-y += -I$(srctree)/drivers/misc/mediatek/audio_ipi/include
ccflags-y += -I$(srctree)/sound/soc/mediatek/audio_dsp

# spm include path
ccflags-y += -I$(srctree)/drivers/misc/mediatek/base/power/include
ccflags-y += -I$(srctree)/drivers/misc/mediatek/include/mt-plat/$(MTK_PLATFORM)/include

# platform driver
obj-$(CONFIG_SND_SOC_MT6855) += snd-soc-mt6855-afe.o
snd-soc-mt6855-afe-objs += \
	mt6855-afe-pcm.o \
	mt6855-afe-clk.o \
	mt6855-afe-gpio.o \
	mt6855-dai-adda.o \
	mt6855-afe-control.o \
	mt6855-dai-i2s.o \
	mt6855-dai-hw-gain.o \
	mt6855-dai-src.o \
	mt6855-dai-pcm.o \
	mt6855-dai-hostless.o \
	mt6855-misc-control.o

	#	mt6855-dai-tdm.o \

# machine driver
obj-$(CONFIG_SND_SOC_MT6855_MT6369) += mt6855-mt6369.o
