/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */
#ifndef __SOC_MEDIATEK_SCPSYS_H
#define __SOC_MEDIATEK_SCPSYS_H

#define _BUS_PROT(_type, _set_ofs, _clr_ofs,			\
		_en_ofs, _sta_ofs, _mask, _ignore_clr_ack) {	\
		.type = _type,					\
		.set_ofs = _set_ofs,				\
		.clr_ofs = _clr_ofs,				\
		.en_ofs = _en_ofs,				\
		.sta_ofs = _sta_ofs,				\
		.mask = _mask,					\
		.ignore_clr_ack = _ignore_clr_ack,		\
	}

#define BUS_PROT(_type, _set_ofs, _clr_ofs,		\
		_en_ofs, _sta_ofs, _mask)		\
		_BUS_PROT(_type, _set_ofs, _clr_ofs,	\
		_en_ofs, _sta_ofs, _mask, false)

#define BUS_PROT_IGN(_type, _set_ofs, _clr_ofs,	\
		_en_ofs, _sta_ofs, _mask)		\
		_BUS_PROT(_type, _set_ofs, _clr_ofs,	\
		_en_ofs, _sta_ofs, _mask, true)

#define MT2701_TOP_AXI_PROT_EN_MM_M0		BIT(1)
#define MT2701_TOP_AXI_PROT_EN_CONN_M		BIT(2)
#define MT2701_TOP_AXI_PROT_EN_CONN_S		BIT(8)

#define MT6873_TOP_AXI_PROT_EN_MD		BIT(7)
#define MT6873_TOP_AXI_PROT_EN_VDNR_MD		(BIT(2) | BIT(14) | \
						 BIT(22))

#define MT7622_TOP_AXI_PROT_EN_ETHSYS		(BIT(3) | BIT(17))
#define MT7622_TOP_AXI_PROT_EN_HIF0		(BIT(24) | BIT(25))
#define MT7622_TOP_AXI_PROT_EN_HIF1		(BIT(26) | BIT(27) | \
						 BIT(28))
#define MT7622_TOP_AXI_PROT_EN_WB		(BIT(2) | BIT(6) | \
						 BIT(7) | BIT(8))

#define MT6789_TOP_AXI_PROT_EN_MD	(BIT(7))
#define MT6789_TOP_AXI_PROT_EN_INFRA_VDNR_MD	(BIT(0) | BIT(10) |  \
			BIT(15))
#define MT6789_TOP_AXI_PROT_EN_CONN	(BIT(13) | BIT(18))
#define MT6789_TOP_AXI_PROT_EN_CONN_2ND	(BIT(14))
#define MT6789_TOP_AXI_PROT_EN_1_CONN	(BIT(10))
#define MT6789_TOP_AXI_PROT_EN_1_MFG1	(BIT(21))
#define MT6789_TOP_AXI_PROT_EN_2_MFG1	(BIT(5) | BIT(6))
#define MT6789_TOP_AXI_PROT_EN_MFG1	(BIT(21) | BIT(22))
#define MT6789_TOP_AXI_PROT_EN_2_MFG1_2ND	(BIT(7))
#define MT6789_TOP_AXI_PROT_EN_MM_2_ISP	(BIT(8))
#define MT6789_TOP_AXI_PROT_EN_MM_2_ISP_2ND	(BIT(9))
#define MT6789_TOP_AXI_PROT_EN_MM_IPE	(BIT(16))
#define MT6789_TOP_AXI_PROT_EN_MM_IPE_2ND	(BIT(17))
#define MT6789_TOP_AXI_PROT_EN_MM_VDEC	(BIT(24))
#define MT6789_TOP_AXI_PROT_EN_MM_VDEC_2ND	(BIT(25))
#define MT6789_TOP_AXI_PROT_EN_MM_VENC	(BIT(26))
#define MT6789_TOP_AXI_PROT_EN_MM_VENC_2ND	(BIT(27))
#define MT6789_TOP_AXI_PROT_EN_MM_DISP	(BIT(10) | BIT(12))
#define MT6789_TOP_AXI_PROT_EN_DISP	(BIT(6) | BIT(23))
#define MT6789_TOP_AXI_PROT_EN_2_AUDIO	(BIT(4))
#define MT6789_TOP_AXI_PROT_EN_MM_CAM	(BIT(0) | BIT(2))
#define MT6789_TOP_AXI_PROT_EN_MM_CAM_2ND	(BIT(1) | BIT(3))

#define MT6833_TOP_AXI_PROT_EN_INFRA_MD	(BIT(7))
#define MT6833_TOP_AXI_PROT_EN_INFRA_VDNR_MD	(BIT(0) | BIT(10) |  \
			BIT(16))
#define MT6833_TOP_AXI_PROT_EN_INFRA_CONN	(BIT(13) | BIT(18))
#define MT6833_TOP_AXI_PROT_EN_INFRA_CONN_2ND	(BIT(14))
#define MT6833_TOP_AXI_PROT_EN_INFRA_1_CONN	(BIT(10))
#define MT6833_TOP_AXI_PROT_EN_INFRA_1_MFG1	(BIT(21))
#define MT6833_TOP_AXI_PROT_EN_INFRA_2_MFG1	(BIT(5) | BIT(6))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MFG1	(BIT(21) | BIT(22))
#define MT6833_TOP_AXI_PROT_EN_INFRA_2_MFG1_2ND	(BIT(7))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_2_ISP	(BIT(8))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_2_ISP_2ND	(BIT(9))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_IPE	(BIT(16))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_IPE_2ND	(BIT(17))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_VDEC	(BIT(24))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_VDEC_2ND	(BIT(25))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_VENC	(BIT(26))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_VENC_2ND	(BIT(27))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_DISP	(BIT(0) | BIT(2) |  \
			BIT(10) | BIT(12) |  \
			BIT(16) | BIT(24) |  \
			BIT(26))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_2_DISP	(BIT(8))
#define MT6833_TOP_AXI_PROT_EN_INFRA_DISP	(BIT(6) | BIT(23))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_DISP_2ND	(BIT(1) | BIT(3) |  \
			BIT(17) | BIT(25) |  \
			BIT(27))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_2_DISP_2ND	(BIT(9))
#define MT6833_TOP_AXI_PROT_EN_INFRA_2_AUDIO	(BIT(4))
#define MT6833_TOP_AXI_PROT_EN_INFRA_2_CAM	(BIT(0))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_CAM	(BIT(0) | BIT(2))
#define MT6833_TOP_AXI_PROT_EN_INFRA_1_CAM	(BIT(22))
#define MT6833_TOP_AXI_PROT_EN_INFRA_MM_CAM_2ND	(BIT(1) | BIT(3))
#define MT6833_TOP_AXI_PROT_EN_INFRA_VDNR_CAM	(BIT(15))

#define MT6853_TOP_AXI_PROT_EN_MD	(BIT(7))
#define MT6853_TOP_AXI_PROT_EN_VDNR_MD	(BIT(2) | BIT(12) |  \
			BIT(20))
#define MT6853_TOP_AXI_PROT_EN_CONN	(BIT(13) | BIT(18))
#define MT6853_TOP_AXI_PROT_EN_CONN_2ND	(BIT(14))
#define MT6853_TOP_AXI_PROT_EN_1_CONN	(BIT(10))
#define MT6853_TOP_AXI_PROT_EN_1_MFG1	(BIT(21))
#define MT6853_TOP_AXI_PROT_EN_2_MFG1	(BIT(5) | BIT(6))
#define MT6853_TOP_AXI_PROT_EN_MFG1	(BIT(21) | BIT(22))
#define MT6853_TOP_AXI_PROT_EN_2_MFG1_2ND	(BIT(7))
#define MT6853_TOP_AXI_PROT_EN_MM_2_ISP	(BIT(8))
#define MT6853_TOP_AXI_PROT_EN_MM_2_ISP_2ND	(BIT(9))
#define MT6853_TOP_AXI_PROT_EN_MM_IPE	(BIT(16))
#define MT6853_TOP_AXI_PROT_EN_MM_IPE_2ND	(BIT(17))
#define MT6853_TOP_AXI_PROT_EN_MM_VDEC	(BIT(24))
#define MT6853_TOP_AXI_PROT_EN_MM_VDEC_2ND	(BIT(25))
#define MT6853_TOP_AXI_PROT_EN_MM_VENC	(BIT(26))
#define MT6853_TOP_AXI_PROT_EN_MM_VENC_2ND	(BIT(27))
#define MT6853_TOP_AXI_PROT_EN_MM_DISP	(BIT(0) | BIT(2) |  \
			BIT(10) | BIT(12) |  \
			BIT(16) | BIT(24) |  \
			BIT(26))
#define MT6853_TOP_AXI_PROT_EN_MM_2_DISP	(BIT(8))
#define MT6853_TOP_AXI_PROT_EN_DISP	(BIT(6) | BIT(23))
#define MT6853_TOP_AXI_PROT_EN_MM_DISP_2ND	(BIT(1) | BIT(3) |  \
			BIT(17) | BIT(25) |  \
			BIT(27))
#define MT6853_TOP_AXI_PROT_EN_MM_2_DISP_2ND	(BIT(9))
#define MT6853_TOP_AXI_PROT_EN_2_AUDIO	(BIT(4))
#define MT6853_TOP_AXI_PROT_EN_2_ADSP_DORMANT	(BIT(3))
#define MT6853_TOP_AXI_PROT_EN_2_CAM	(BIT(0))
#define MT6853_TOP_AXI_PROT_EN_MM_CAM	(BIT(0) | BIT(2))
#define MT6853_TOP_AXI_PROT_EN_1_CAM	(BIT(22))
#define MT6853_TOP_AXI_PROT_EN_MM_CAM_2ND	(BIT(1) | BIT(3))
#define MT6853_TOP_AXI_PROT_EN_VDNR_CAM	(BIT(19))

#define MT6855_TOP_AXI_PROT_EN_INFRASYS1_MD	(BIT(9))
#define MT6855_TOP_AXI_PROT_EN_EMISYS0_MD	(BIT(16) | BIT(17))
#define MT6855_TOP_AXI_PROT_EN_MCU0_CONN	(BIT(1))
#define MT6855_TOP_AXI_PROT_EN_INFRASYS1_CONN	(BIT(12))
#define MT6855_TOP_AXI_PROT_EN_MCU0_CONN_2ND	(BIT(0))
#define MT6855_TOP_AXI_PROT_EN_INFRASYS0_CONN	(BIT(8))
#define MT6855_VLP_AXI_PROT_EN_UFS0	(BIT(5))
#define MT6855_TOP_AXI_PROT_EN_PERISYS0_UFS0	(BIT(4))
#define MT6855_VLP_AXI_PROT_EN_UFS0_2ND	(BIT(6))
#define MT6855_VLP_AXI_PROT_EN_UFS0	(BIT(5))
#define MT6855_TOP_AXI_PROT_EN_PERISYS0_UFS0	(BIT(4))
#define MT6855_VLP_AXI_PROT_EN_UFS0_2ND	(BIT(6))
#define MT6855_TOP_AXI_PROT_EN_MMSYS0_ISP_DIP1	(BIT(14))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_ISP_DIP1	(BIT(7))
#define MT6855_TOP_AXI_PROT_EN_MMSYS2_ISP_IPE	(BIT(2))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_ISP_IPE	(BIT(8))
#define MT6855_TOP_AXI_PROT_EN_MMSYS0_VDE0	(BIT(20))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_VDE0	(BIT(13))
#define MT6855_TOP_AXI_PROT_EN_MMSYS0_VEN0	(BIT(12))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_VEN0	(BIT(12))
#define MT6855_TOP_AXI_PROT_EN_MMSYS0_CAM_MAIN	(BIT(16) | BIT(26))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_CAM_MAIN	(BIT(9) | BIT(10))
#define MT6855_TOP_AXI_PROT_EN_MMSYS0_DISP	(BIT(0) | BIT(1) |  \
			BIT(18))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_DISP	(BIT(11) | BIT(14) |  \
			BIT(15))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA	(BIT(1) | BIT(2) |  \
			BIT(3) | BIT(6))
#define MT6855_TOP_AXI_PROT_EN_INFRASYS1_MM_INFRA	(BIT(11))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA_2ND	(BIT(0) | BIT(4) |  \
			BIT(5) | BIT(7) |  \
			BIT(8) | BIT(9) |  \
			BIT(10) | BIT(11) |  \
			BIT(12) | BIT(13) |  \
			BIT(14) | BIT(15))
#define MT6855_TOP_AXI_PROT_EN_INFRASYS0_MM_INFRA	(BIT(16))
#define MT6855_TOP_AXI_PROT_EN_EMISYS0_MM_INFRA	(BIT(20) | BIT(21))
#define MT6855_VLP_AXI_PROT_EN_MM_PROC	(BIT(7) | BIT(8))
#define MT6855_VLP_AXI_PROT_EN_MM_PROC_2ND	(BIT(9) | BIT(10))
#define MT6855_TOP_AXI_PROT_EN_MMSYS1_MM_PROC	(BIT(4) | BIT(5))
#define MT6855_TOP_AXI_PROT_EN_MD0_MFG0	(BIT(4))
#define MT6855_TOP_AXI_PROT_EN_INFRASYS0_MFG0	(BIT(9))
#define MT6855_TOP_AXI_PROT_EN_MD0_MFG0	(BIT(4))
#define MT6855_TOP_AXI_PROT_EN_INFRASYS0_MFG0	(BIT(9))
#define MT6855_TOP_AXI_PROT_EN_MD0_MFG1	(BIT(0))
#define MT6855_TOP_AXI_PROT_EN_MD0_MFG1_2ND	(BIT(1))
#define MT6855_TOP_AXI_PROT_EN_EMISYS0_MFG1	(BIT(18) | BIT(19))
#define MT6855_TOP_AXI_PROT_EN_MD0_MFG1_3RD	(BIT(2))
#define MT6855_TOP_AXI_PROT_EN_MD0_MFG1_4RD	(BIT(3))

#define MT6879_TOP_AXI_PROT_EN_MCU0_CONN	(BIT(1))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS1_CONN	(BIT(12))
#define MT6879_TOP_AXI_PROT_EN_MCU0_CONN_2ND	(BIT(0))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS0_CONN	(BIT(8))
#define MT6879_VLP_AXI_PROT_EN_UFS0	(BIT(5))
#define MT6879_TOP_AXI_PROT_EN_PERISYS0_UFS0	(BIT(4))
#define MT6879_VLP_AXI_PROT_EN_UFS0_2ND	(BIT(6))
#define MT6879_VLP_AXI_PROT_EN_AUDIO	(BIT(17))
#define MT6879_VLP_AXI_PROT_EN_AUDIO_2ND	(BIT(19))
#define MT6879_VLP_AXI_PROT_EN_ADSP_TOP	(BIT(11) | BIT(12) |  \
			BIT(13) | BIT(14))
#define MT6879_VLP_AXI_PROT_EN_ADSP_TOP_2ND	(BIT(20) | BIT(21))
#define MT6879_VLP_AXI_PROT_EN_ADSP_INFRA	(BIT(15) | BIT(16) |  \
			BIT(19) | BIT(20) |  \
			BIT(21) | BIT(23) |  \
			BIT(24) | BIT(25) |  \
			BIT(26) | BIT(27))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS1_ADSP_INFRA	(BIT(8))
#define MT6879_VLP_AXI_PROT_EN_ADSP_INFRA_2ND	(BIT(11) | BIT(12) |  \
			BIT(13) | BIT(14) |  \
			BIT(17) | BIT(18) |  \
			BIT(22) | BIT(28))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS0_ADSP_INFRA	(BIT(4) | BIT(5))
#define MT6879_TOP_AXI_PROT_EN_MMSYS2_ISP_MAIN	(BIT(0) | BIT(2))
#define MT6879_TOP_AXI_PROT_EN_MMSYS2_ISP_MAIN_2ND	(BIT(1) | BIT(3))
#define MT6879_TOP_AXI_PROT_EN_MMSYS0_ISP_VCORE	(BIT(14) | BIT(24))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_ISP_VCORE	(BIT(7) | BIT(8))
#define MT6879_TOP_AXI_PROT_EN_MMSYS0_VDE0	(BIT(20))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_VDE0	(BIT(13))
#define MT6879_TOP_AXI_PROT_EN_MMSYS0_VEN0	(BIT(12))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_VEN0	(BIT(12))
#define MT6879_TOP_AXI_PROT_EN_MMSYS0_CAM_MAIN	(BIT(16) | BIT(26))
#define MT6879_TOP_AXI_PROT_EN_DRAMC0_CAM_MAIN	(BIT(10))
#define MT6879_TOP_AXI_PROT_EN_MMSYS2_CAM_MAIN	(BIT(5) | BIT(7))
#define MT6879_TOP_AXI_PROT_EN_DRAMC0_CAM_MAIN_2ND	(BIT(11))
#define MT6879_TOP_AXI_PROT_EN_MMSYS2_CAM_VCORE	(BIT(4) | BIT(6))
#define MT6879_TOP_AXI_PROT_EN_DRAMC0_CAM_VCORE	(BIT(12))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_CAM_VCORE	(BIT(9) | BIT(10))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS0_CAM_VCORE	(BIT(13))
#define MT6879_TOP_AXI_PROT_EN_MMSYS0_DISP	(BIT(0) | BIT(1) |  \
			BIT(18))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_DISP	(BIT(11) | BIT(14) |  \
			BIT(15))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA	(BIT(1) | BIT(2) |  \
			BIT(3) | BIT(6))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS1_MM_INFRA	(BIT(11))
#define MT6879_TOP_AXI_PROT_EN_INFRASYS0_MM_INFRA	(BIT(16))
#define MT6879_TOP_AXI_PROT_EN_EMISYS0_MM_INFRA	(BIT(20) | BIT(21))
#define MT6879_VLP_AXI_PROT_EN_MM_PROC	(BIT(7) | BIT(8))
#define MT6879_VLP_AXI_PROT_EN_MM_PROC_2ND	(BIT(9) | BIT(10))
#define MT6879_TOP_AXI_PROT_EN_MMSYS1_MM_PROC	(BIT(4) | BIT(5))
#define MT6879_TOP_AXI_PROT_EN_MD0_MFG1	(BIT(0))
#define MT6879_TOP_AXI_PROT_EN_MD0_MFG1_2ND	(BIT(1))
#define MT6879_TOP_AXI_PROT_EN_EMISYS0_MFG1	(BIT(18) | BIT(19))
#define MT6879_TOP_AXI_PROT_EN_MD0_MFG1_3RD	(BIT(2))
#define MT6879_TOP_AXI_PROT_EN_MD0_MFG1_4RD	(BIT(3))

#define MT6893_TOP_AXI_PROT_EN_1_MFG1	(BIT(19) | BIT(20) |  \
			BIT(21))
#define MT6893_TOP_AXI_PROT_EN_2_MFG1	(BIT(5) | BIT(6))
#define MT6893_TOP_AXI_PROT_EN_MFG1	(BIT(21) | BIT(22))
#define MT6893_TOP_AXI_PROT_EN_2_MFG1_2ND	(BIT(7))
#define MT6893_TOP_AXI_PROT_EN_SUB_INFRA_VDNR_MFG1	(BIT(17) | BIT(19))
#define MT6893_TOP_AXI_PROT_EN_MM_2_ISP	(BIT(8))
#define MT6893_TOP_AXI_PROT_EN_MM_2_ISP_2ND	(BIT(9))
#define MT6893_TOP_AXI_PROT_EN_MM_ISP2	(BIT(14))
#define MT6893_TOP_AXI_PROT_EN_MM_ISP2_2ND	(BIT(15))
#define MT6893_TOP_AXI_PROT_EN_MM_IPE	(BIT(16))
#define MT6893_TOP_AXI_PROT_EN_MM_IPE_2ND	(BIT(17))
#define MT6893_TOP_AXI_PROT_EN_MM_VDEC	(BIT(24))
#define MT6893_TOP_AXI_PROT_EN_MM_VDEC_2ND	(BIT(25))
#define MT6893_TOP_AXI_PROT_EN_MM_2_VDEC2	(BIT(6))
#define MT6893_TOP_AXI_PROT_EN_MM_2_VDEC2_2ND	(BIT(7))
#define MT6893_TOP_AXI_PROT_EN_MM_VENC	(BIT(26))
#define MT6893_TOP_AXI_PROT_EN_MM_2_VENC	(BIT(0))
#define MT6893_TOP_AXI_PROT_EN_MM_VENC_2ND	(BIT(27))
#define MT6893_TOP_AXI_PROT_EN_MM_2_VENC_2ND	(BIT(1))
#define MT6893_TOP_AXI_PROT_EN_MM_VENC_CORE1	(BIT(28) | BIT(30))
#define MT6893_TOP_AXI_PROT_EN_MM_VENC_CORE1_2ND	(BIT(29) | BIT(31))
#define MT6893_TOP_AXI_PROT_EN_MDP	(BIT(10))
#define MT6893_TOP_AXI_PROT_EN_MM_MDP	(BIT(2) | BIT(4) |  \
			BIT(6) | BIT(8) |  \
			BIT(18) | BIT(22) |  \
			BIT(28) | BIT(30))
#define MT6893_TOP_AXI_PROT_EN_MM_2_MDP	(BIT(0) | BIT(2) |  \
			BIT(4) | BIT(6) |  \
			BIT(8))
#define MT6893_TOP_AXI_PROT_EN_MDP_2ND	(BIT(23))
#define MT6893_TOP_AXI_PROT_EN_MM_MDP_2ND	(BIT(3) | BIT(5) |  \
			BIT(7) | BIT(9) |  \
			BIT(19) | BIT(23) |  \
			BIT(29) | BIT(31))
#define MT6893_TOP_AXI_PROT_EN_MM_2_MDP_2ND	(BIT(1) | BIT(7) |  \
			BIT(9) | BIT(11))
#define MT6893_TOP_AXI_PROT_EN_SUB_INFRA_VDNR_MDP	(BIT(20))
#define MT6893_TOP_AXI_PROT_EN_MM_DISP	(BIT(0) | BIT(6) |  \
			BIT(8) | BIT(10) |  \
			BIT(12) | BIT(14) |  \
			BIT(16) | BIT(20) |  \
			BIT(24) | BIT(26))
#define MT6893_TOP_AXI_PROT_EN_DISP	(BIT(6))
#define MT6893_TOP_AXI_PROT_EN_MM_DISP_2ND	(BIT(1) | BIT(7) |  \
			BIT(9) | BIT(15) |  \
			BIT(17) | BIT(21) |  \
			BIT(25) | BIT(27))
#define MT6893_TOP_AXI_PROT_EN_SUB_INFRA_VDNR_DISP	(BIT(21))
#define MT6893_TOP_AXI_PROT_EN_2_AUDIO	(BIT(4))
#define MT6893_TOP_AXI_PROT_EN_2_ADSP_DORMANT	(BIT(3))
#define MT6893_TOP_AXI_PROT_EN_2_CAM	(BIT(1))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM	(BIT(0) | BIT(2) |  \
			BIT(4))
#define MT6893_TOP_AXI_PROT_EN_1_CAM	(BIT(22))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_2ND	(BIT(1) | BIT(3) |  \
			BIT(5))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_RAWA	(BIT(18))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_RAWA_2ND	(BIT(19))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_RAWB	(BIT(20))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_RAWB_2ND	(BIT(21))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_RAWC	(BIT(22))
#define MT6893_TOP_AXI_PROT_EN_MM_CAM_RAWC_2ND	(BIT(23))
#define MT6893_TOP_AXI_PROT_EN_MD	(BIT(7))
#define MT6893_TOP_AXI_PROT_EN_INFRA_VDNR_MD	(BIT(10) | BIT(21) |  \
			BIT(29))
#define MT6893_TOP_AXI_PROT_EN_SUB_INFRA_VDNR_MD	(BIT(6) | BIT(7))
#define MT6893_TOP_AXI_PROT_EN_CONN	(BIT(13))
#define MT6893_TOP_AXI_PROT_EN_CONN_2ND	(BIT(14))
#define MT6893_TOP_AXI_PROT_EN_2_CONN	(BIT(2))

#define MT6895_TOP_AXI_PROT_EN_INFRASYS1_MD	(BIT(9))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS0_MD	(BIT(28))
#define MT6895_TOP_AXI_PROT_EN_EMISYS0_MD	(BIT(17) | BIT(16))
#define MT6895_TOP_AXI_PROT_EN_MCU0_CONN	(BIT(1))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS1_CONN	(BIT(12))
#define MT6895_TOP_AXI_PROT_EN_MCU0_CONN_2ND	(BIT(0))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS0_CONN	(BIT(8))
#define MT6895_VLP_AXI_PROT_EN_UFS0	(BIT(7))
#define MT6895_TOP_AXI_PROT_EN_PERISYS0_UFS0	(BIT(4))
#define MT6895_VLP_AXI_PROT_EN_UFS0_2ND	(BIT(8))
#define MT6895_VLP_AXI_PROT_EN_ADSP_TOP	(BIT(14) | BIT(15) |  \
			BIT(16) | BIT(17))
#define MT6895_VLP_AXI_PROT_EN_ADSP_TOP_2ND	(BIT(23) | BIT(24))
#define MT6895_VLP_AXI_PROT_EN_ADSP_INFRA	(BIT(18) | BIT(19) |  \
			BIT(22) | BIT(26) |  \
			BIT(27) | BIT(28) |  \
			BIT(29) | BIT(30))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS1_ADSP_INFRA	(BIT(8))
#define MT6895_VLP_AXI_PROT_EN_ADSP_INFRA_2ND	(BIT(20) | BIT(21) |  \
			BIT(25) | BIT(31))
#define MT6895_TOP_AXI_PROT_EN_MMSYS2_ISP_MAIN	(BIT(0) | BIT(2) |  \
			BIT(10))
#define MT6895_TOP_AXI_PROT_EN_MMSYS2_ISP_MAIN_2ND	(BIT(1) | BIT(3) |  \
			BIT(11))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_ISP_VCORE	(BIT(14) | BIT(24))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_ISP_VCORE	(BIT(28))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_ISP_VCORE_2ND	(BIT(15) | BIT(25))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_ISP_VCORE_2ND	(BIT(29))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VDE0	(BIT(10))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VDE0	(BIT(26) | BIT(30))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VDE0_2ND	(BIT(11))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VDE0_2ND	(BIT(27) | BIT(31))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VDE1	(BIT(20))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VDE1	(BIT(24))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VDE1_2ND	(BIT(21))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VDE1_2ND	(BIT(25))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VEN0	(BIT(12))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VEN0	(BIT(14))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VEN0_2ND	(BIT(13))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VEN0_2ND	(BIT(15))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VEN1	(BIT(22))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VEN1	(BIT(16))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_VEN1_2ND	(BIT(23))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_VEN1_2ND	(BIT(17))
#define MT6895_TOP_AXI_PROT_EN_MMSYS2_CAM_MAIN	(BIT(4) | BIT(6) |  \
			BIT(8))
#define MT6895_TOP_AXI_PROT_EN_DRAMC0_CAM_MAIN	(BIT(10))
#define MT6895_TOP_AXI_PROT_EN_MMSYS2_CAM_MAIN_2ND	(BIT(5) | BIT(7) |  \
			BIT(9))
#define MT6895_TOP_AXI_PROT_EN_DRAMC0_CAM_MAIN_2ND	(BIT(11))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_CAM_VCORE	(BIT(16) | BIT(26))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_CAM_VCORE	(BIT(18))
#define MT6895_TOP_AXI_PROT_EN_DRAMC0_CAM_VCORE	(BIT(12))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_CAM_VCORE_2ND	(BIT(17) | BIT(27))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_CAM_VCORE_2ND	(BIT(19))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS0_CAM_VCORE	(BIT(13))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_MDP0	(BIT(18))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_MDP0	(BIT(20))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_MDP0_2ND	(BIT(19))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_MDP0_2ND	(BIT(21))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_MDP1	(BIT(28))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_MDP1	(BIT(22))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_MDP1_2ND	(BIT(29))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_MDP1_2ND	(BIT(23))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_DISP	(BIT(8) | BIT(30))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_DISP	(BIT(10))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_DISP_2ND	(BIT(9) | BIT(31))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_DISP_2ND	(BIT(11))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_DISP1	(BIT(0) | BIT(2) |  \
			BIT(12))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_DISP1_2ND	(BIT(1) | BIT(3) |  \
			BIT(13))
#define MT6895_TOP_AXI_PROT_EN_MMSYS0_MM_INFRA	(BIT(0) | BIT(2) |  \
			BIT(4) | BIT(6))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA	(BIT(4) | BIT(6))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS1_MM_INFRA	(BIT(11))
#define MT6895_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA_2ND	(BIT(9))
#define MT6895_TOP_AXI_PROT_EN_INFRASYS0_MM_INFRA	(BIT(14) | BIT(15))
#define MT6895_TOP_AXI_PROT_EN_EMISYS0_MM_INFRA	(BIT(21) | BIT(20))
#define MT6895_TOP_AXI_PROT_EN_EMISYS1_MM_INFRA	(BIT(21) | BIT(20))
#define MT6895_NEMI_PROT_EN_EMISYS0_MM_INFRA	(BIT(4) | BIT(5))
#define MT6895_SEMI_PROT_EN_EMISYS0_MM_INFRA	(BIT(4) | BIT(5))
#define MT6895_VLP_AXI_PROT_EN_MM_PROC	(BIT(10) | BIT(11) |  \
			BIT(13))
#define MT6895_TOP_AXI_PROT_EN_MMSYS2_MM_PROC	(BIT(12))
#define MT6895_VLP_AXI_PROT_EN_MM_PROC_2ND	(BIT(12))
#define MT6895_TOP_AXI_PROT_EN_MMSYS2_MM_PROC_2ND	(BIT(15) | BIT(17))
#define MT6895_TOP_AXI_PROT_EN_MD0_MFG1	(BIT(0) | BIT(1) |  \
			BIT(2) | BIT(3))
#define MT6895_MFGRPC_AXI_PROT_EN_MFG1	(BIT(16) | BIT(17) |  \
			BIT(18) | BIT(19))
#define MT6895_TOP_AXI_PROT_EN_EMISYS0_MFG1	(BIT(19) | BIT(18))
#define MT6895_TOP_AXI_PROT_EN_EMISYS1_MFG1	(BIT(19) | BIT(18))

#define MT6983_TOP_AXI_PROT_EN_1_MD1	(BIT(9))
#define MT6983_TOP_AXI_PROT_EN_MCU_CONNSYS_0_CONN	(BIT(1))
#define MT6983_TOP_AXI_PROT_EN_1_CONN	(BIT(12))
#define MT6983_TOP_AXI_PROT_EN_MCU_CONNSYS_0_CONN_2ND	(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_0_CONN_2ND	(BIT(8))
#define MT6983_TOP_AXI_PROT_EN_VLP_UFS0			(BIT(5))
#define MT6983_TOP_AXI_PROT_EN_PERISYS_0_UFS0_2ND	(BIT(4))
#define MT6983_TOP_AXI_PROT_EN_VLP_UFS0_2ND		(BIT(6))
#define MT6983_TOP_AXI_PROT_EN_MD_MFGSYS_0_MFG0_DORMANT	(BIT(4))
#define MT6983_TOP_AXI_PROT_EN_0_MFG0_DORMANT_2ND	(BIT(9))
#define MT6983_TOP_AXI_PROT_EN_VLP_ADSP_INFRA		(BIT(15) \
							| BIT(16) \
							| BIT(19) \
							| BIT(20) \
							| BIT(21) \
							| BIT(23) \
							| BIT(24) \
							| BIT(25) \
							| BIT(26) \
							| BIT(27))
#define MT6983_TOP_AXI_PROT_EN_1_ADSP_INFRA	(BIT(8))
#define MT6983_TOP_AXI_PROT_EN_VLP_ADSP_INFRA_2ND	(BIT(11) \
					| BIT(12) \
					| BIT(13) \
					| BIT(14) \
					| BIT(17) \
					| BIT(18) \
					| BIT(22) \
					| BIT(28))
#define MT6983_TOP_AXI_PROT_EN_0_ADSP_INFRA_2ND	(BIT(4) \
					| BIT(5))
#define MT6983_TOP_AXI_PROT_EN_MD_MFGSYS_0_MFG1	(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MD_MFGSYS_0_MFG1_2ND	(BIT(1))
#define MT6983_TOP_AXI_PROT_EN_MD_MFGSYS_0_MFG1_3RD	(BIT(2))
#define MT6983_TOP_AXI_PROT_EN_MD_MFGSYS_0_MFG1_4TH	(BIT(3))
#define MT6983_TOP_AXI_PROT_EN_VLP_ADSP_TOP_DORMANT	(BIT(11) \
					| BIT(12) \
					| BIT(13) \
					| BIT(14))
#define MT6983_TOP_AXI_PROT_EN_VLP_ADSP_TOP_DORMANT_2ND	(BIT(20) | BIT(21))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_2_ISP_MAIN	(BIT(0) | BIT(2))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_1_MM_INFRA		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_1_MM_INFRA		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_1_MM_INFRA_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_0_MM_INFRA_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_0_DIS0		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_2_CAM_VCORE		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_DRAMC_CCUSYS_0_CAM_VCORE		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_0_CAM_VCORE_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_0_VDE0		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_1_VDE0_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_0_VEN0		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_1_VEN0_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_0_CAM_MAIN		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_DRAMC_CCUSYS_0_CAM_MAIN		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_MMSYS_2_CAM_MAIN_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_DRAMC_CCUSYS_0_CAM_MAIN_2ND		(BIT(0))
#define MT6983_TOP_AXI_PROT_EN_INFRASYS0_CAM_VCORE	(BIT(13))
#define MT6983_TOP_AXI_PROT_EN_MMSYS0_DISP	(BIT(0) | BIT(1) |  \
			BIT(18))
#define MT6983_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA	(BIT(1) | BIT(2) |  \
			BIT(3) | BIT(6))
#define MT6983_TOP_AXI_PROT_EN_INFRASYS1_MM_INFRA	(BIT(11))
#define MT6983_TOP_AXI_PROT_EN_MMSYS1_MM_INFRA_2ND	(BIT(0) | BIT(4) |  \
			BIT(5) | BIT(7) |  \
			BIT(8) | BIT(9) |  \
			BIT(10) | BIT(11) |  \
			BIT(12) | BIT(13) |  \
			BIT(14) | BIT(15))
#define MT6983_TOP_AXI_PROT_EN_INFRASYS0_MM_INFRA	(BIT(14) | BIT(15) |  \
			BIT(16))
#define MT6983_VLP_AXI_PROT_EN_MM_PROC	(BIT(7) | BIT(8))
#define MT6983_VLP_AXI_PROT_EN_MM_PROC_2ND	(BIT(9) | BIT(10))
#define MT6983_TOP_AXI_PROT_EN_MMSYS2_CAM_VCORE	(BIT(4) | BIT(6))
#define MT6983_TOP_AXI_PROT_EN_DRAMC0_CAM_VCORE	(BIT(12))
#define MT6983_TOP_AXI_PROT_EN_INFRASYS0_CAM_VCORE	(BIT(13))
#define MT6983_TOP_AXI_PROT_EN_MMSYS0_VDE0	(BIT(20))
#define MT6983_TOP_AXI_PROT_EN_MMSYS1_VDE0	(BIT(13))
#define MT6983_TOP_AXI_PROT_EN_MMSYS0_VEN0	(BIT(12))
#define MT6983_TOP_AXI_PROT_EN_MMSYS1_VEN0	(BIT(12))
#define MT6983_TOP_AXI_PROT_EN_MMSYS0_CAM_MAIN	(BIT(16) | BIT(26))
#define MT6983_TOP_AXI_PROT_EN_DRAMC0_CAM_MAIN	(BIT(10))
#define MT6983_TOP_AXI_PROT_EN_MMSYS2_CAM_MAIN	(BIT(5) | BIT(7))
#define MT6983_TOP_AXI_PROT_EN_DRAMC0_CAM_MAIN_2ND	(BIT(11))

#define MT8173_TOP_AXI_PROT_EN_MM_M0		BIT(1)
#define MT8173_TOP_AXI_PROT_EN_MM_M1		BIT(2)
#define MT8173_TOP_AXI_PROT_EN_MFG_S		BIT(14)
#define MT8173_TOP_AXI_PROT_EN_MFG_M0		BIT(21)
#define MT8173_TOP_AXI_PROT_EN_MFG_M1		BIT(22)
#define MT8173_TOP_AXI_PROT_EN_MFG_SNOOP_OUT	BIT(23)

#define MT8192_TOP_AXI_PROT_EN_DISP			(BIT(6) | BIT(23))
#define MT8192_TOP_AXI_PROT_EN_CONN			(BIT(13) | BIT(18))
#define MT8192_TOP_AXI_PROT_EN_CONN_2ND		BIT(14)
#define MT8192_TOP_AXI_PROT_EN_MFG1			GENMASK(22, 21)
#define MT8192_TOP_AXI_PROT_EN_1_CONN			BIT(10)
#define MT8192_TOP_AXI_PROT_EN_1_MFG1			BIT(21)
#define MT8192_TOP_AXI_PROT_EN_1_CAM			BIT(22)
#define MT8192_TOP_AXI_PROT_EN_2_CAM			BIT(0)
#define MT8192_TOP_AXI_PROT_EN_2_ADSP			BIT(3)
#define MT8192_TOP_AXI_PROT_EN_2_AUDIO			BIT(4)
#define MT8192_TOP_AXI_PROT_EN_2_MFG1			GENMASK(6, 5)
#define MT8192_TOP_AXI_PROT_EN_2_MFG1_2ND		BIT(7)
#define MT8192_TOP_AXI_PROT_EN_MM_CAM			(BIT(0) | BIT(2))
#define MT8192_TOP_AXI_PROT_EN_MM_DISP			(BIT(0) | BIT(2) | \
							BIT(10) | BIT(12) | \
							BIT(14) | BIT(16) | \
							BIT(24) | BIT(26))
#define MT8192_TOP_AXI_PROT_EN_MM_CAM_2ND		(BIT(1) | BIT(3))
#define MT8192_TOP_AXI_PROT_EN_MM_DISP_2ND		(BIT(1) | BIT(3) | \
							BIT(15) | BIT(17) | \
							BIT(25) | BIT(27))
#define MT8192_TOP_AXI_PROT_EN_MM_ISP2			BIT(14)
#define MT8192_TOP_AXI_PROT_EN_MM_ISP2_2ND		BIT(15)
#define MT8192_TOP_AXI_PROT_EN_MM_IPE			BIT(16)
#define MT8192_TOP_AXI_PROT_EN_MM_IPE_2ND		BIT(17)
#define MT8192_TOP_AXI_PROT_EN_MM_VDEC			BIT(24)
#define MT8192_TOP_AXI_PROT_EN_MM_VDEC_2ND		BIT(25)
#define MT8192_TOP_AXI_PROT_EN_MM_VENC			BIT(26)
#define MT8192_TOP_AXI_PROT_EN_MM_VENC_2ND		BIT(27)
#define MT8192_TOP_AXI_PROT_EN_MM_2_ISP		BIT(8)
#define MT8192_TOP_AXI_PROT_EN_MM_2_DISP		(BIT(8) | BIT(12))
#define MT8192_TOP_AXI_PROT_EN_MM_2_ISP_2ND		BIT(9)
#define MT8192_TOP_AXI_PROT_EN_MM_2_DISP_2ND		(BIT(9) | BIT(13))
#define MT8192_TOP_AXI_PROT_EN_MM_2_MDP		BIT(12)
#define MT8192_TOP_AXI_PROT_EN_MM_2_MDP_2ND		BIT(13)
#define MT8192_TOP_AXI_PROT_EN_VDNR_CAM		BIT(21)

enum regmap_type {
	INVALID_TYPE = 0,
	IFR_TYPE,
	SMI_TYPE,
	VLP_TYPE,
	MFGRPC_TYPE,
	NEMI_TYPE,
	SEMI_TYPE,
};

struct bus_prot {
	enum regmap_type type;
	u32 set_ofs;
	u32 clr_ofs;
	u32 en_ofs;
	u32 sta_ofs;
	u32 mask;
	bool ignore_clr_ack;
};

#endif /* __SOC_MEDIATEK_SCPSYS_H */
