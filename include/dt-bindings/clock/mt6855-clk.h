/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2021 MediaTek Inc.
 * Author: Owen Chen <owen.chen@mediatek.com>
 */

#ifndef _DT_BINDINGS_CLK_MT6855_H
#define _DT_BINDINGS_CLK_MT6855_H

/* TOPCKGEN */
#define CLK_TOP_AXI_SEL					0
#define CLK_TOP_AXIP_SEL				1
#define CLK_TOP_AXI_U_SEL				2
#define CLK_TOP_BUS_AXIMEM_SEL				3
#define CLK_TOP_DISP0_SEL				4
#define CLK_TOP_MDP0_SEL				5
#define CLK_TOP_MMINFRA_SEL				6
#define CLK_TOP_MMUP_SEL				7
#define CLK_TOP_CAMTG_SEL				8
#define CLK_TOP_CAMTG2_SEL				9
#define CLK_TOP_CAMTG3_SEL				10
#define CLK_TOP_CAMTG4_SEL				11
#define CLK_TOP_CAMTG5_SEL				12
#define CLK_TOP_CAMTG6_SEL				13
#define CLK_TOP_UART_SEL				14
#define CLK_TOP_SPI_SEL					15
#define CLK_TOP_MSDC_0P_MACRO_SEL			16
#define CLK_TOP_MSDC50_0_HCLK_SEL			17
#define CLK_TOP_MSDC50_0_SEL				18
#define CLK_TOP_AES_MSDCFDE_SEL				19
#define CLK_TOP_MSDC_MACRO_SEL				20
#define CLK_TOP_MSDC30_1_SEL				21
#define CLK_TOP_AUDIO_SEL				22
#define CLK_TOP_AUD_INTBUS_SEL				23
#define CLK_TOP_ATB_SEL					24
#define CLK_TOP_DISP_PWM_SEL				25
#define CLK_TOP_USB_TOP_SEL				26
#define CLK_TOP_USB_XHCI_SEL				27
#define CLK_TOP_I2C_SEL					28
#define CLK_TOP_SENINF_SEL				29
#define CLK_TOP_SENINF1_SEL				30
#define CLK_TOP_SENINF2_SEL				31
#define CLK_TOP_SENINF3_SEL				32
#define CLK_TOP_DXCC_SEL				33
#define CLK_TOP_AUD_ENGEN1_SEL				34
#define CLK_TOP_AUD_ENGEN2_SEL				35
#define CLK_TOP_AES_UFSFDE_SEL				36
#define CLK_TOP_U_SEL					37
#define CLK_TOP_U_MBIST_SEL				38
#define CLK_TOP_AUD_1_SEL				39
#define CLK_TOP_AUD_2_SEL				40
#define CLK_TOP_DPMAIF_MAIN_SEL				41
#define CLK_TOP_VENC_SEL				42
#define CLK_TOP_VDEC_SEL				43
#define CLK_TOP_PWM_SEL					44
#define CLK_TOP_AUDIO_H_SEL				45
#define CLK_TOP_MCUPM_SEL				46
#define CLK_TOP_MEM_SUB_SEL				47
#define CLK_TOP_MEM_SUBP_SEL				48
#define CLK_TOP_MEM_SUB_U_SEL				49
#define CLK_TOP_EMI_N_SEL				50
#define CLK_TOP_DSI_OCC_SEL				51
#define CLK_TOP_AP2CONN_HOST_SEL			52
#define CLK_TOP_MCU_ACP_SEL				53
#define CLK_TOP_IMG1_SEL				54
#define CLK_TOP_IPE_SEL					55
#define CLK_TOP_CAM_SEL					56
#define CLK_TOP_CAMTM_SEL				57
#define CLK_TOP_MSDC_1P_RX_SEL				58
#define CLK_TOP_APLL_I2S0_MCK_SEL			59
#define CLK_TOP_APLL_I2S1_MCK_SEL			60
#define CLK_TOP_APLL_I2S2_MCK_SEL			61
#define CLK_TOP_APLL_I2S3_MCK_SEL			62
#define CLK_TOP_APLL_I2S4_MCK_SEL			63
#define CLK_TOP_APLL_I2S5_MCK_SEL			64
#define CLK_TOP_APLL_I2S6_MCK_SEL			65
#define CLK_TOP_APLL_I2S7_MCK_SEL			66
#define CLK_TOP_APLL_I2S8_MCK_SEL			67
#define CLK_TOP_APLL_I2S9_MCK_SEL			68
#define CLK_TOP_APLL12_CK_DIV0				69
#define CLK_TOP_APLL12_CK_DIV1				70
#define CLK_TOP_APLL12_CK_DIV2				71
#define CLK_TOP_APLL12_CK_DIV3				72
#define CLK_TOP_APLL12_CK_DIV4				73
#define CLK_TOP_APLL12_CK_DIVB				74
#define CLK_TOP_APLL12_CK_DIV5				75
#define CLK_TOP_APLL12_CK_DIV6				76
#define CLK_TOP_APLL12_CK_DIV7				77
#define CLK_TOP_APLL12_CK_DIV8				78
#define CLK_TOP_APLL12_CK_DIV9				79
#define CLK_TOP_MAINPLL_D3				80
#define CLK_TOP_MAINPLL_D4				81
#define CLK_TOP_MAINPLL_D4_D2				82
#define CLK_TOP_MAINPLL_D4_D4				83
#define CLK_TOP_MAINPLL_D4_D8				84
#define CLK_TOP_MAINPLL_D4_D16				85
#define CLK_TOP_MAINPLL_D5				86
#define CLK_TOP_MAINPLL_D5_D2				87
#define CLK_TOP_MAINPLL_D5_D4				88
#define CLK_TOP_MAINPLL_D5_D8				89
#define CLK_TOP_MAINPLL_D6				90
#define CLK_TOP_MAINPLL_D6_D2				91
#define CLK_TOP_MAINPLL_D6_D4				92
#define CLK_TOP_MAINPLL_D6_D8				93
#define CLK_TOP_MAINPLL_D7				94
#define CLK_TOP_MAINPLL_D7_D2				95
#define CLK_TOP_MAINPLL_D7_D4				96
#define CLK_TOP_MAINPLL_D7_D8				97
#define CLK_TOP_MAINPLL_D9				98
#define CLK_TOP_UNIVPLL_D3				99
#define CLK_TOP_UNIVPLL_D4				100
#define CLK_TOP_UNIVPLL_D4_D2				101
#define CLK_TOP_UNIVPLL_D4_D4				102
#define CLK_TOP_UNIVPLL_D4_D8				103
#define CLK_TOP_UNIVPLL_D5				104
#define CLK_TOP_UNIVPLL_D5_D2				105
#define CLK_TOP_UNIVPLL_D5_D4				106
#define CLK_TOP_UNIVPLL_D6				107
#define CLK_TOP_UNIVPLL_D6_D2				108
#define CLK_TOP_UNIVPLL_D6_D4				109
#define CLK_TOP_UNIVPLL_D6_D8				110
#define CLK_TOP_UNIVPLL_D7				111
#define CLK_TOP_UNIVPLL_D7_D2				112
#define CLK_TOP_UNIVPLL_192M				113
#define CLK_TOP_UNIVPLL_192M_D2				114
#define CLK_TOP_UNIVPLL_192M_D4				115
#define CLK_TOP_UNIVPLL_192M_D8				116
#define CLK_TOP_UNIVPLL_192M_D10			117
#define CLK_TOP_UNIVPLL_192M_D16			118
#define CLK_TOP_UNIVPLL_192M_D32			119
#define CLK_TOP_APLL1					120
#define CLK_TOP_APLL1_D2				121
#define CLK_TOP_APLL1_D4				122
#define CLK_TOP_APLL1_D8				123
#define CLK_TOP_APLL2					124
#define CLK_TOP_APLL2_D2				125
#define CLK_TOP_APLL2_D4				126
#define CLK_TOP_APLL2_D8				127
#define CLK_TOP_EMIPLL					128
#define CLK_TOP_IMGPLL					129
#define CLK_TOP_MMPLL_D4				130
#define CLK_TOP_MMPLL_D4_D2				131
#define CLK_TOP_MMPLL_D5				132
#define CLK_TOP_MMPLL_D5_D2				133
#define CLK_TOP_MMPLL_D6				134
#define CLK_TOP_MMPLL_D6_D2				135
#define CLK_TOP_MMPLL_D7				136
#define CLK_TOP_MMPLL_D9				137
#define CLK_TOP_TVDPLL					138
#define CLK_TOP_TVDPLL_D2				139
#define CLK_TOP_MSDCPLL					140
#define CLK_TOP_MSDCPLL_D2				141
#define CLK_TOP_CLKRTC					142
#define CLK_TOP_TCK_26M_MX9				143
#define CLK_TOP_F26M_CK_D2				144
#define CLK_TOP_OSC					145
#define CLK_TOP_OSC_D2					146
#define CLK_TOP_OSC_D4					147
#define CLK_TOP_OSC_D7					148
#define CLK_TOP_OSC_D8					149
#define CLK_TOP_OSC_D16					150
#define CLK_TOP_OSC_D10					151
#define CLK_TOP_F26M					152
#define CLK_TOP_AXI					153
#define CLK_TOP_AXI_PERI				154
#define CLK_TOP_DISP0					155
#define CLK_TOP_MDP0					156
#define CLK_TOP_MMINFRA					157
#define CLK_TOP_UART					158
#define CLK_TOP_MSDC50_0_HCLK				159
#define CLK_TOP_MSDC50_0				160
#define CLK_TOP_AES_MSDCFDE				161
#define CLK_TOP_MSDC30_1				162
#define CLK_TOP_AUDIO					163
#define CLK_TOP_DISP_PWM				164
#define CLK_TOP_USB_TOP					165
#define CLK_TOP_I2C					166
#define CLK_TOP_DXCC					167
#define CLK_TOP_AUD_ENGEN1				168
#define CLK_TOP_AUD_ENGEN2				169
#define CLK_TOP_AES_UFSFDE				170
#define CLK_TOP_UFS					171
#define CLK_TOP_AUD_1					172
#define CLK_TOP_DPMAIF_MAIN				173
#define CLK_TOP_VENC					174
#define CLK_TOP_VDEC					175
#define CLK_TOP_PWM					176
#define CLK_TOP_AUDIO_H					177
#define CLK_TOP_MEM_SUB					178
#define CLK_TOP_MEM_SUB_UFS				179
#define CLK_TOP_EMI_N					180
#define CLK_TOP_IMG1					181
#define CLK_TOP_IPE					182
#define CLK_TOP_CAM					183
#define CLK_TOP_U_SAP_CFG				184
#define CLK_TOP_U_TICK1US				185
#define CLK_TOP_NR_CLK					186

/* INFRACFG_AO */
#define CLK_IFRAO_THERM					0
#define CLK_IFRAO_CQ_DMA_FPC				1
#define CLK_IFRAO_TRNG					2
#define CLK_IFRAO_CPUM					3
#define CLK_IFRAO_CCIF1_AP				4
#define CLK_IFRAO_CCIF1_MD				5
#define CLK_IFRAO_CCIF_AP				6
#define CLK_IFRAO_DEBUGSYS				7
#define CLK_IFRAO_CCIF_MD				8
#define CLK_IFRAO_DXCC_SEC_CORE				9
#define CLK_IFRAO_DXCC_AO				10
#define CLK_IFRAO_DBG_TRACE				11
#define CLK_IFRAO_CLDMA_BCLK				12
#define CLK_IFRAO_CQ_DMA				13
#define CLK_IFRAO_CCIF5_AP				14
#define CLK_IFRAO_CCIF5_MD				15
#define CLK_IFRAO_CCIF2_AP				16
#define CLK_IFRAO_CCIF2_MD				17
#define CLK_IFRAO_CCIF3_AP				18
#define CLK_IFRAO_CCIF3_MD				19
#define CLK_IFRAO_FBIST2FPC				20
#define CLK_IFRAO_DEVICE_APC_SYNC			21
#define CLK_IFRAO_DPMAIF_MAIN				22
#define CLK_IFRAO_CCIF4_AP				23
#define CLK_IFRAO_CCIF4_MD				24
#define CLK_IFRAO_RG_MMW_DPMAIF26M_CK			25
#define CLK_IFRAO_RG_MEM_SUB_CK				26
#define CLK_IFRAO_NR_CLK				27

/* APMIXEDSYS */
#define CLK_APMIXED_ARMPLL_LL				0
#define CLK_APMIXED_ARMPLL_BL				1
#define CLK_APMIXED_CCIPLL				2
#define CLK_APMIXED_MAINPLL				3
#define CLK_APMIXED_UNIVPLL				4
#define CLK_APMIXED_MSDCPLL				5
#define CLK_APMIXED_MMPLL				6
#define CLK_APMIXED_TVDPLL				7
#define CLK_APMIXED_APLL1				8
#define CLK_APMIXED_APLL2				9
#define CLK_APMIXED_MPLL				10
#define CLK_APMIXED_EMIPLL				11
#define CLK_APMIXED_IMGPLL				12
#define CLK_APMIXED_NR_CLK				13

/* IMP_IIC_WRAP */
#define CLK_IMP_AP_CLOCK_I2C11				0
#define CLK_IMP0_NR_CLK					1

#define CLK_IMP_AP_CLOCK_I2C5				0
#define CLK_IMP3_NR_CLK					1

#define CLK_IMP_AP_CLOCK_I2C3				0
#define CLK_IMP_AP_CLOCK_I2C6				1
#define CLK_IMP_AP_CLOCK_I2C7				2
#define CLK_IMP_AP_CLOCK_I2C8				3
#define CLK_IMP_AP_CLOCK_I2C10				4
#define CLK_IMP2_NR_CLK					5

#define CLK_IMP_AP_CLOCK_I2C1				0
#define CLK_IMP_AP_CLOCK_I2C2				1
#define CLK_IMP_AP_CLOCK_I2C4				2
#define CLK_IMP_AP_CLOCK_I2C9				3
#define CLK_IMP_AP_CLOCK_I2C0				4
#define CLK_IMP1_NR_CLK					5


/* PERICFG_AO */
#define CLK_PERAOP_UART0				0
#define CLK_PERAOP_UART1				1
#define CLK_PERAOP_PWM_HCLK				2
#define CLK_PERAOP_PWM_BCLK				3
#define CLK_PERAOP_PWM_FBCLK1				4
#define CLK_PERAOP_PWM_FBCLK2				5
#define CLK_PERAOP_PWM_FBCLK3				6
#define CLK_PERAOP_PWM_FBCLK4				7
#define CLK_PERAOP_BTIF_BCLK				8
#define CLK_PERAOP_DISP_PWM0				9
#define CLK_PERAOP_SPI0_BCLK				10
#define CLK_PERAOP_SPI1_BCLK				11
#define CLK_PERAOP_SPI2_BCLK				12
#define CLK_PERAOP_SPI3_BCLK				13
#define CLK_PERAOP_SPI4_BCLK				14
#define CLK_PERAOP_SPI5_BCLK				15
#define CLK_PERAOP_SPI6_BCLK				16
#define CLK_PERAOP_SPI7_BCLK				17
#define CLK_PERAOP_APDMA				18
#define CLK_PERAOP_USB_PHY				19
#define CLK_PERAOP_USB_SYS				20
#define CLK_PERAOP_USB_DMA_BUS				21
#define CLK_PERAOP_USB_MCU_BUS				22
#define CLK_PERAOP_MSDC1				23
#define CLK_PERAOP_MSDC1_HCLK				24
#define CLK_PERAOP_FMSDC50				25
#define CLK_PERAOP_FMSDC50_HCLK				26
#define CLK_PERAOP_FAES_MSDCFDE				27
#define CLK_PERAOP_MSDC50_XCLK				28
#define CLK_PERAOP_MSDC50_HCLK				29
#define CLK_PERAO_AUDIO_SLV_CK_PERI			30
#define CLK_PERAO_AUDIO_MST_CK_PERI			31
#define CLK_PERAO_INTBUS_CK_PERI			32
#define CLK_PERAO_NR_CLK				33

/* AFE */
#define CLK_AFE_AFE					0
#define CLK_AFE_22M					1
#define CLK_AFE_24M					2
#define CLK_AFE_APLL2_TUNER				3
#define CLK_AFE_APLL_TUNER				4
#define CLK_AFE_TDM					5
#define CLK_AFE_ADC					6
#define CLK_AFE_DAC					7
#define CLK_AFE_DAC_PREDIS				8
#define CLK_AFE_TML					9
#define CLK_AFE_NLE					10
#define CLK_AFE_GENERAL3_ASRC				11
#define CLK_AFE_CONNSYS_I2S_ASRC			12
#define CLK_AFE_GENERAL1_ASRC				13
#define CLK_AFE_GENERAL2_ASRC				14
#define CLK_AFE_DAC_HIRES				15
#define CLK_AFE_ADC_HIRES				16
#define CLK_AFE_ADC_HIRES_TML				17
#define CLK_AFE_3RD_DAC					18
#define CLK_AFE_3RD_DAC_PREDIS				19
#define CLK_AFE_3RD_DAC_TML				20
#define CLK_AFE_3RD_DAC_HIRES				21
#define CLK_AFE_I2S5_BCLK				22
#define CLK_AFE_I2S6_BCLK				23
#define CLK_AFE_I2S7_BCLK				24
#define CLK_AFE_I2S8_BCLK				25
#define CLK_AFE_I2S9_BCLK				26
#define CLK_AFE_ETDM_IN0_BCLK				27
#define CLK_AFE_ETDM_OUT0_BCLK				28
#define CLK_AFE_I2S1_BCLK				29
#define CLK_AFE_I2S2_BCLK				30
#define CLK_AFE_I2S3_BCLK				31
#define CLK_AFE_I2S4_BCLK				32
#define CLK_AFE_ETDM_IN1_BCLK				33
#define CLK_AFE_ETDM_OUT1_BCLK				34
#define CLK_AFE_NR_CLK					35

/* MFG_PLL_CTRL */
#define CLK_MFG_AO_MFGPLL				0
#define CLK_MFG_AO_MFGSCPLL				1
#define CLK_MFG_AO_NR_CLK				2

/* DISPSYS_CONFIG */
#define CLK_MM_DISP_MUTEX0				0
#define CLK_MM_DISP_OVL0				1
#define CLK_MM_DISP_MERGE0				2
#define CLK_MM_DISP_FAKE_ENG0				3
#define CLK_MM_DISP_INLINEROT0				4
#define CLK_MM_DISP_WDMA0				5
#define CLK_MM_DISP_FAKE_ENG1				6
#define CLK_MM_DISP_DPI0				7
#define CLK_MM_DISP_OVL0_2L_NW				8
#define CLK_MM_DISP_RDMA0				9
#define CLK_MM_DISP_RDMA1				10
#define CLK_MM_DISP_DLI_ASYNC0				11
#define CLK_MM_DISP_DLI_ASYNC1				12
#define CLK_MM_DISP_DLI_ASYNC2				13
#define CLK_MM_DISP_DLO_ASYNC0				14
#define CLK_MM_DISP_DLO_ASYNC1				15
#define CLK_MM_DISP_DLO_ASYNC2				16
#define CLK_MM_DISP_RSZ0				17
#define CLK_MM_DISP_COLOR0				18
#define CLK_MM_DISP_CCORR0				19
#define CLK_MM_DISP_CCORR1				20
#define CLK_MM_DISP_AAL0				21
#define CLK_MM_DISP_GAMMA0				22
#define CLK_MM_DISP_POSTMASK0				23
#define CLK_MM_DISP_DITHER0				24
#define CLK_MM_DISP_CM0					25
#define CLK_MM_DISP_SPR0				26
#define CLK_MM_DISP_DSC_WRAP0				27
#define CLK_MM_DISP_DSI0				28
#define CLK_MM_DISP_UFBC_WDMA0				29
#define CLK_MM_DISP_WDMA1				30
#define CLK_MM_DISP_DP_INTF0				31
#define CLK_MM_DISP_APB_BUS				32
#define CLK_MM_DISP_TDSHP0				33
#define CLK_MM_DISP_C3D0				34
#define CLK_MM_DISP_Y2R0				35
#define CLK_MM_MDP_AAL0					36
#define CLK_MM_DISP_CHIST0				37
#define CLK_MM_DISP_CHIST1				38
#define CLK_MM_DISP_OVL0_2L				39
#define CLK_MM_DISP_DLI_ASYNC3				40
#define CLK_MM_DISP_DL0_ASYNC3				41
#define CLK_MM_DISP_OVL1_2L				42
#define CLK_MM_DISP_OVL1_2L_NW				43
#define CLK_MM_SMI_COMMON				44
#define CLK_MM_DSI					45
#define CLK_MM_DPI					46
#define CLK_MM_DISP_DUMMY_MOD_B0					47
#define CLK_MM_26M					48
#define CLK_MM_NR_CLK					49

/* IMGSYS1 */
#define CLK_IMGSYS1_LARB9				0
#define CLK_IMGSYS1_LARB10				1
#define CLK_IMGSYS1_DIP					2
#define CLK_IMGSYS1_GALS				3
#define CLK_IMGSYS1_NR_CLK				4

/* IMGSYS2 */
#define CLK_IMGSYS2_LARB9				0
#define CLK_IMGSYS2_LARB10				1
#define CLK_IMGSYS2_MFB					2
#define CLK_IMGSYS2_WPE					3
#define CLK_IMGSYS2_MSS					4
#define CLK_IMGSYS2_GALS				5
#define CLK_IMGSYS2_NR_CLK				6

/* VDEC_GCON_BASE */
#define CLK_VDE2_LARB1_CKEN				0
#define CLK_VDE2_LAT_CKEN				1
#define CLK_VDE2_LAT_CKEN_ENG				2
#define CLK_VDE2_MINI_MDP_CKEN_CFG_RG			3
#define CLK_VDE2_VDEC_CKEN				4
#define CLK_VDE2_VDEC_ACTIVE				5
#define CLK_VDE2_VDEC_CKEN_ENG				6
#define CLK_VDE2_NR_CLK					7

/* VENC_GCON */
#define CLK_VEN1_CKE0_LARB				0
#define CLK_VEN1_CKE1_VENC				1
#define CLK_VEN1_CKE2_JPGENC				2
#define CLK_VEN1_CKE5_GALS				3
#define CLK_VEN1_NR_CLK					4

/* VLP_CKSYS */
#define CLK_VLP_CK_SCP_SEL				0
#define CLK_VLP_CK_PWRAP_ULPOSC_SEL			1
#define CLK_VLP_CK_DXCC_VLP_SEL				2
#define CLK_VLP_CK_SPMI_P_MST_SEL			3
#define CLK_VLP_CK_SPMI_M_MST_SEL			4
#define CLK_VLP_CK_DVFSRC_SEL				5
#define CLK_VLP_CK_PWM_VLP_SEL				6
#define CLK_VLP_CK_AXI_VLP_SEL				7
#define CLK_VLP_CK_DBGAO_26M_SEL			8
#define CLK_VLP_CK_SYSTIMER_26M_SEL			9
#define CLK_VLP_CK_SSPM_SEL				10
#define CLK_VLP_CK_SSPM_F26M_SEL			11
#define CLK_VLP_CK_SRCK_SEL				12
#define CLK_VLP_CK_SRAMRC_SEL				13
#define CLK_VLP_CK_SCP_SPI_SEL				14
#define CLK_VLP_CK_SCP_IIC_SEL				15
#define CLK_VLP_CK_DXCC_VLP				16
#define CLK_VLP_CK_SSPM					17
#define CLK_VLP_CK_U_SAP_CFG				18
#define CLK_VLP_CK_U_TICK1US				19
#define CLK_VLP_CK_NR_CLK				20

/* CAMSYS_MAIN */
#define CLK_CAM_M_LARB13				0
#define CLK_CAM_M_DFP_VAD				1
#define CLK_CAM_M_LARB14				2
#define CLK_CAM_M_CAM					3
#define CLK_CAM_M_CAMTG					4
#define CLK_CAM_M_SENINF				5
#define CLK_CAM_M_CAMSV0				6
#define CLK_CAM_M_CAMSV1				7
#define CLK_CAM_M_CAMSV2				8
#define CLK_CAM_M_CAMSV3				9
#define CLK_CAM_M_CCU0					10
#define CLK_CAM_M_CCU1					11
#define CLK_CAM_M_MRAW0					12
#define CLK_CAM_M_FAKE_ENG				13
#define CLK_CAM_M_CCU_GALS				14
#define CLK_CAM_M_CAM2MM_GALS				15
#define CLK_CAM_M_CAMSV4				16
#define CLK_CAM_M_PDA					17
#define CLK_CAM_M_NR_CLK				18

/* CAMSYS_RAWA */
#define CLK_CAM_RA_LARBX				0
#define CLK_CAM_RA_CAM					1
#define CLK_CAM_RA_CAMTG				2
#define CLK_CAM_RA_NR_CLK				3

/* CAMSYS_RAWB */
#define CLK_CAM_RB_LARBX				0
#define CLK_CAM_RB_CAM					1
#define CLK_CAM_RB_CAMTG				2
#define CLK_CAM_RB_NR_CLK				3

/* IPESYS */
#define CLK_IPE_LARB19					0
#define CLK_IPE_LARB20					1
#define CLK_IPE_SMI_SUBCOM				2
#define CLK_IPE_FD					3
#define CLK_IPE_FE					4
#define CLK_IPE_RSC					5
#define CLK_IPE_GALS					6
#define CLK_IPE_NR_CLK					7

/* MMINFRA_CONFIG */
#define CLK_MMINFRA_GCE_D				0
#define CLK_MMINFRA_GCE_M				1
#define CLK_MMINFRA_SMI					2
#define CLK_MMINFRA_GCE_26M				3
#define CLK_MMINFRA_CONFIG_NR_CLK			4

/* MDPSYS_CONFIG */
#define CLK_MDP_MUTEX0					0
#define CLK_MDP_APB_BUS					1
#define CLK_MDP_SMI0					2
#define CLK_MDP_RDMA0					3
#define CLK_MDP_FG0					4
#define CLK_MDP_HDR0					5
#define CLK_MDP_AAL0					6
#define CLK_MDP_RSZ0					7
#define CLK_MDP_TDSHP0					8
#define CLK_MDP_COLOR0					9
#define CLK_MDP_WROT0					10
#define CLK_MDP_FAKE_ENG0				11
#define CLK_MDP_DLI_ASYNC0				12
#define CLK_MDP_DLI_ASYNC1				13
#define CLK_MDP_RDMA1					14
#define CLK_MDP_FG1					15
#define CLK_MDP_HDR1					16
#define CLK_MDP_AAL1					17
#define CLK_MDP_RSZ1					18
#define CLK_MDP_TDSHP1					19
#define CLK_MDP_COLOR1					20
#define CLK_MDP_WROT1					21
#define CLK_MDP_RSZ2					22
#define CLK_MDP_WROT2					23
#define CLK_MDP_DLO_ASYNC0				24
#define CLK_MDP_RSZ3					25
#define CLK_MDP_WROT3					26
#define CLK_MDP_DLO_ASYNC1				27
#define CLK_MDP_HRE_TOP_MDPSYS				28
#define CLK_MDP_FMM_IMG_DL_ASYNC0			29
#define CLK_MDP_FMM_IMG_DL_ASYNC1			30
#define CLK_MDP_FIMG_IMG_DL_ASYNC0			31
#define CLK_MDP_FIMG_IMG_DL_ASYNC1			32
#define CLK_MDP_NR_CLK					33

/* MDPSYS1_CONFIG */
#define CLK_MDP1_MDP_MUTEX0				0
#define CLK_MDP1_APB_BUS				1
#define CLK_MDP1_SMI0					2
#define CLK_MDP1_MDP_RDMA0				3
#define CLK_MDP1_MDP_FG0				4
#define CLK_MDP1_MDP_HDR0				5
#define CLK_MDP1_MDP_AAL0				6
#define CLK_MDP1_MDP_RSZ0				7
#define CLK_MDP1_MDP_TDSHP0				8
#define CLK_MDP1_MDP_COLOR0				9
#define CLK_MDP1_MDP_WROT0				10
#define CLK_MDP1_MDP_FAKE_ENG0				11
#define CLK_MDP1_MDP_DLI_ASYNC0				12
#define CLK_MDP1_MDP_DLI_ASYNC1				13
#define CLK_MDP1_MDP_RDMA1				14
#define CLK_MDP1_MDP_FG1				15
#define CLK_MDP1_MDP_HDR1				16
#define CLK_MDP1_MDP_AAL1				17
#define CLK_MDP1_MDP_RSZ1				18
#define CLK_MDP1_MDP_TDSHP1				19
#define CLK_MDP1_MDP_COLOR1				20
#define CLK_MDP1_MDP_WROT1				21
#define CLK_MDP1_MDP_RSZ2				22
#define CLK_MDP1_MDP_WROT2				23
#define CLK_MDP1_MDP_DLO_ASYNC0				24
#define CLK_MDP1_MDP_RSZ3				25
#define CLK_MDP1_MDP_WROT3				26
#define CLK_MDP1_MDP_DLO_ASYNC1				27
#define CLK_MDP1_HRE_TOP_MDPSYS				28
#define CLK_MDP1_FMM_IMG_DL_ASYNC0			29
#define CLK_MDP1_FMM_IMG_DL_ASYNC1			30
#define CLK_MDP1_FIMG_IMG_DL_ASYNC0			31
#define CLK_MDP1_FIMG_IMG_DL_ASYNC1			32
#define CLK_MDP1_NR_CLK					33

#endif /* _DT_BINDINGS_CLK_MT6855_H */
