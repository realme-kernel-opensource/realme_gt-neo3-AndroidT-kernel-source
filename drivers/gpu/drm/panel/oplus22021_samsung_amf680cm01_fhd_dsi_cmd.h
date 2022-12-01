#ifndef PANEL_SAMSUNG_AMB670YF07_H
#define PANEL_SAMSUNG_AMB670YF07_H

#include <linux/trace_events.h>
#ifdef CONFIG_MTK_ROUND_CORNER_SUPPORT
#include "../mediatek/mediatek_v2/mtk_corner_pattern/mtk_data_hw_roundedpattern_2k.h"
#endif

#define REGFLAG_CMD				0xFFFA
#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD

#define MODE_NUM	2

#define mtk_drm_trace_begin(fmt, args...) do { \
	if (g_trace_log) { \
		preempt_disable(); \
		event_trace_printk(mtk_drm_get_tracing_mark(), \
			"B|%d|"fmt"\n", current->tgid, ##args); \
		preempt_enable();\
	} \
} while (0)

#define mtk_drm_trace_end() do { \
	if (g_trace_log) { \
		preempt_disable(); \
		event_trace_printk(mtk_drm_get_tracing_mark(), "E\n"); \
		preempt_enable(); \
	} \
} while (0)

#define mtk_drm_trace_c(fmt, args...) do { \
	if (g_trace_log) { \
		preempt_disable(); \
		event_trace_printk(mtk_drm_get_tracing_mark(), \
			"C|"fmt"\n", ##args); \
		preempt_enable();\
	} \
} while (0)

//#ifdef OPLUS_ADFR
enum MODE_ID {
	FHD_SDC60 = 0,
    FHD_SDC90 = 1,
    FHD_SDC120 = 2,
};
//#endif
#define FRAME_WIDTH 			(1080)
#define FRAME_HEIGHT			(2520)
#define DSC_ENABLE                  1
#define DSC_VER                     17
#define DSC_SLICE_MODE              1
#define DSC_RGB_SWAP                0
#define DSC_DSC_CFG                 34
#define DSC_RCT_ON                  1
#define DSC_BIT_PER_CHANNEL         8
#define DSC_DSC_LINE_BUF_DEPTH      9
#define DSC_BP_ENABLE               1
#define DSC_BIT_PER_PIXEL           128
#define DSC_SLICE_HEIGHT            40
#define DSC_SLICE_WIDTH             540
#define DSC_CHUNK_SIZE              540
#define DSC_XMIT_DELAY              512
#define DSC_DEC_DELAY               571
#define DSC_SCALE_VALUE             32
#define DSC_INCREMENT_INTERVAL      914
#define DSC_DECREMENT_INTERVAL      7
#define DSC_LINE_BPG_OFFSET         14
#define DSC_NFL_BPG_OFFSET          736
#define DSC_SLICE_BPG_OFFSET        651
#define DSC_INITIAL_OFFSET          6144
#define DSC_FINAL_OFFSET            4336
#define DSC_FLATNESS_MINQP          3
#define DSC_FLATNESS_MAXQP          12
#define DSC_RC_MODEL_SIZE           8192
#define DSC_RC_EDGE_FACTOR          6
#define DSC_RC_QUANT_INCR_LIMIT0    11
#define DSC_RC_QUANT_INCR_LIMIT1    11
#define DSC_RC_TGT_OFFSET_HI        3
#define DSC_RC_TGT_OFFSET_LO        3

extern bool g_trace_log;
extern unsigned long mtk_drm_get_tracing_mark(void);

struct LCM_setting_table {
	unsigned int cmd;
	unsigned int count;
	unsigned char para_list[256];
};

/* ------------------------- timming parameters ------------------------- */

/* --------------- DSC Setting --------------- */
/* FHD DSC1.2 10bit */
struct LCM_setting_table fhd_dsc_cmd[] = {
};

/* WQHD DSC1.2 10bit */
struct LCM_setting_table wqhd_dsc_cmd[] = {
};

/* --------------- timing@fhd_sdc_60 --------------- */
/* timing-switch cmd */
struct LCM_setting_table fhd_timing_switch_cmd_sdc60[] = {
	/* 90Hz → 120Hz Transition (120Hz on) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 3, {0xBD, 0xE1, 0x02}},
	{REGFLAG_CMD, 2, {0x60, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* HOP Low Freq. (@HS 120Hz, Manual Mode) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xBD, 0xE1}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x1F, 0xBD}},
	{REGFLAG_CMD, 3, {0xBD, 0x00, 0x01}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* TE Modulation */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB9, 0x61, 0x00, 0x05}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x0C, 0xB9}},
	{REGFLAG_CMD, 5, {0xB9, 0x09, 0xD8, 0x00, 0x24}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
};

struct LCM_setting_table fhd_timing_switch_cmd_sdc90[] = {
	/* 120Hz → 90Hz Transition (90Hz on) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x01, 0xBD}},
	{REGFLAG_CMD, 2, {0xBD, 0x42}},
	{REGFLAG_CMD, 3, {0x60, 0x00, 0x08}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* TE Modulation */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB9, 0x61, 0x00, 0x02}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x0C, 0xB9}},
	{REGFLAG_CMD, 5, {0xB9, 0x09, 0xD8, 0x00, 0x24}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
};

struct LCM_setting_table fhd_timing_switch_cmd_sdc120[] = {
	/* 90Hz → 120Hz Transition (120Hz on) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 3, {0xBD, 0xE1, 0x02}},
	{REGFLAG_CMD, 2, {0x60, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* HOP Low Freq. (@HS 120Hz, Manual Mode) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xBD, 0xE1}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x1F, 0xBD}},
	{REGFLAG_CMD, 3, {0xBD, 0x00, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* TE Modulation */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB9, 0x61, 0x00, 0x02}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x0C, 0xB9}},
	{REGFLAG_CMD, 5, {0xB9, 0x09, 0xD8, 0x00, 0x24}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
};

/* dsi-on cmd */
struct LCM_setting_table fhd_dsi_on_cmd_sdc60[] = {
	/* DSC Setting */
	{REGFLAG_CMD, 90, {0x9E, 0x11, 0x00, 0x00, 0x89, 0x30, 0x80, 0x09, 0xD8, 0x04, 0x38,
						0x00, 0x28, 0x02, 0x1C, 0x02, 0x1C, 0x02, 0x00, 0x02, 0x3B,
						0x00, 0x20, 0x03, 0x92, 0x00, 0x07, 0x00, 0x0E, 0x02, 0xE0,
						0x02, 0x8B, 0x18, 0x00, 0x10, 0xF0, 0x03, 0x0C, 0x20, 0x00,
						0x06, 0x0B, 0x0B, 0x33, 0x0E, 0x1C, 0x2A, 0x38, 0x46, 0x54,
						0x62, 0x69, 0x70, 0x77, 0x79, 0x7B, 0x7D, 0x7E, 0x01, 0x02,
						0x01, 0x00, 0x09, 0x40, 0x09, 0xBE, 0x19, 0xFC, 0x19, 0xFA,
						0x19, 0xF8, 0x1A, 0x38, 0x1A, 0x78, 0x1A, 0xB6, 0x2A, 0xB6,
						0x2A, 0xF4, 0x2A, 0xF4, 0x4B, 0x34, 0x63, 0x74, 0x00}},
	{REGFLAG_CMD, 2, {0x9D, 0x01}},
	/* Sleep Out(11h) */
	{REGFLAG_CMD, 1, {0x11}},
	{REGFLAG_DELAY, 121, {}},
	/* TE(Vsync) On */
	{REGFLAG_CMD, 2, {0x35, 0x00}},
	/* TSP_VSYNC Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x29, 0xB9}},
	{REGFLAG_CMD, 2, {0xB9, 0x09}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* CASET/PASET Setting */
	{REGFLAG_CMD, 5, {0x2A, 0x00, 0x00, 0x04, 0x37}},
	{REGFLAG_CMD, 5, {0x2B, 0x00, 0x00, 0x09, 0xD7}},
	/* Pentile Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x01, 0x60, 0x92}},
	{REGFLAG_CMD, 5, {0x92, 0xD8, 0xD8, 0xC0, 0xC0}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* ERR_FG Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xE5, 0x15}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x3D, 0xF4}},
	{REGFLAG_CMD, 2, {0xF4, 0x10}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x01, 0xED}},
	{REGFLAG_CMD, 3, {0xED, 0x41, 0x03}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* FFC Setting */
	{REGFLAG_CMD, 3, {0xFC, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x36, 0xC5}},
	{REGFLAG_CMD, 2, {0xC5, 0x11}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x3E, 0xC5}},
	{REGFLAG_CMD, 3, {0xC5, 0x5E, 0x13}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x56, 0xC5}},
	{REGFLAG_CMD, 3, {0xC5, 0x5E, 0x13}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xFC, 0xA5, 0xA5}},
	/* Dimming Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0x53, 0x20}},
	/* {REGFLAG_CMD, 3, {0x51, 0x01, 0xFF}}, */
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* 90Hz → 120Hz Transition (120Hz on) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 3, {0xBD, 0xE1, 0x02}},
	{REGFLAG_CMD, 2, {0x60, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* HOP Low Freq. (@HS 120Hz, Manual Mode) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xBD, 0xE1}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x1F, 0xBD}},
	{REGFLAG_CMD, 3, {0xBD, 0x00, 0x01}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* TE Modulation */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB9, 0x61, 0x00, 0x05}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x0C, 0xB9}},
	{REGFLAG_CMD, 5, {0xB9, 0x09, 0xD8, 0x00, 0x24}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* SPR */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x01, 0x5E, 0x92}},
	{REGFLAG_CMD, 8, {0x92, 0x0A, 0x00, 0xDB, 0xDB, 0xC0, 0xC0, 0x40}},
	{REGFLAG_CMD, 3, {0xF0,0xA5,0xA5}},
	/* Display On(29h) */
	{REGFLAG_CMD, 1, {0x29}},
};

/* dsi-on cmd */
struct LCM_setting_table fhd_dsi_on_cmd_sdc90[] = {
	/* DSC Setting */
	{REGFLAG_CMD, 90, {0x9E, 0x11, 0x00, 0x00, 0x89, 0x30, 0x80, 0x09, 0xD8, 0x04, 0x38,
						0x00, 0x28, 0x02, 0x1C, 0x02, 0x1C, 0x02, 0x00, 0x02, 0x3B,
						0x00, 0x20, 0x03, 0x92, 0x00, 0x07, 0x00, 0x0E, 0x02, 0xE0,
						0x02, 0x8B, 0x18, 0x00, 0x10, 0xF0, 0x03, 0x0C, 0x20, 0x00,
						0x06, 0x0B, 0x0B, 0x33, 0x0E, 0x1C, 0x2A, 0x38, 0x46, 0x54,
						0x62, 0x69, 0x70, 0x77, 0x79, 0x7B, 0x7D, 0x7E, 0x01, 0x02,
						0x01, 0x00, 0x09, 0x40, 0x09, 0xBE, 0x19, 0xFC, 0x19, 0xFA,
						0x19, 0xF8, 0x1A, 0x38, 0x1A, 0x78, 0x1A, 0xB6, 0x2A, 0xB6,
						0x2A, 0xF4, 0x2A, 0xF4, 0x4B, 0x34, 0x63, 0x74, 0x00}},
	{REGFLAG_CMD, 2, {0x9D, 0x01}},
	/* Sleep Out(11h) */
	{REGFLAG_CMD, 1, {0x11}},
	{REGFLAG_DELAY, 121, {}},
	/* TE(Vsync) On */
	{REGFLAG_CMD, 2, {0x35, 0x00}},
	/* TSP_VSYNC Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x29, 0xB9}},
	{REGFLAG_CMD, 2, {0xB9, 0x09}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* CASET/PASET Setting */
	{REGFLAG_CMD, 5, {0x2A, 0x00, 0x00, 0x04, 0x37}},
	{REGFLAG_CMD, 5, {0x2B, 0x00, 0x00, 0x09, 0xD7}},
	/* Pentile Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x01, 0x60, 0x92}},
	{REGFLAG_CMD, 5, {0x92, 0xD8, 0xD8, 0xC0, 0xC0}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* ERR_FG Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xE5, 0x15}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x3D, 0xF4}},
	{REGFLAG_CMD, 2, {0xF4, 0x10}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x01, 0xED}},
	{REGFLAG_CMD, 3, {0xED, 0x41, 0x03}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* FFC Setting */
	{REGFLAG_CMD, 3, {0xFC, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x36, 0xC5}},
	{REGFLAG_CMD, 2, {0xC5, 0x11}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x3E, 0xC5}},
	{REGFLAG_CMD, 3, {0xC5, 0x5E, 0x13}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x56, 0xC5}},
	{REGFLAG_CMD, 3, {0xC5, 0x5E, 0x13}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xFC, 0xA5, 0xA5}},
	/* Dimming Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0x53, 0x20}},
	/* {REGFLAG_CMD, 3, {0x51, 0x01, 0xFF}}, */
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* 120Hz → 90Hz Transition (90Hz on) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x01, 0xBD}},
	{REGFLAG_CMD, 2, {0xBD, 0x42}},
	{REGFLAG_CMD, 3, {0x60, 0x00, 0x08}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* TE Modulation */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB9, 0x61, 0x00, 0x02}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x0C, 0xB9}},
	{REGFLAG_CMD, 5, {0xB9, 0x09, 0xD8, 0x00, 0x24}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* SPR */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x01, 0x5E, 0x92}},
	{REGFLAG_CMD, 8, {0x92, 0x0A, 0x00, 0xDB, 0xDB, 0xC0, 0xC0, 0x40}},
	{REGFLAG_CMD, 3, {0xF0,0xA5,0xA5}},
	/* Display On(29h) */
	{REGFLAG_CMD, 1, {0x29}},
};

/* dsi-on cmd */
struct LCM_setting_table fhd_dsi_on_cmd_sdc120[] = {
	/* DSC Setting */
	{REGFLAG_CMD, 90, {0x9E, 0x11, 0x00, 0x00, 0x89, 0x30, 0x80, 0x09, 0xD8, 0x04, 0x38,
						0x00, 0x28, 0x02, 0x1C, 0x02, 0x1C, 0x02, 0x00, 0x02, 0x3B,
						0x00, 0x20, 0x03, 0x92, 0x00, 0x07, 0x00, 0x0E, 0x02, 0xE0,
						0x02, 0x8B, 0x18, 0x00, 0x10, 0xF0, 0x03, 0x0C, 0x20, 0x00,
						0x06, 0x0B, 0x0B, 0x33, 0x0E, 0x1C, 0x2A, 0x38, 0x46, 0x54,
						0x62, 0x69, 0x70, 0x77, 0x79, 0x7B, 0x7D, 0x7E, 0x01, 0x02,
						0x01, 0x00, 0x09, 0x40, 0x09, 0xBE, 0x19, 0xFC, 0x19, 0xFA,
						0x19, 0xF8, 0x1A, 0x38, 0x1A, 0x78, 0x1A, 0xB6, 0x2A, 0xB6,
						0x2A, 0xF4, 0x2A, 0xF4, 0x4B, 0x34, 0x63, 0x74, 0x00}},
	{REGFLAG_CMD, 2, {0x9D, 0x01}},
	/* Sleep Out(11h) */
	{REGFLAG_CMD, 1, {0x11}},
	{REGFLAG_DELAY, 121, {}},
	/* TE(Vsync) On */
	{REGFLAG_CMD, 2, {0x35, 0x00}},
	/* TSP_VSYNC Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x29, 0xB9}},
	{REGFLAG_CMD, 2, {0xB9, 0x09}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* CASET/PASET Setting */
	{REGFLAG_CMD, 5, {0x2A, 0x00, 0x00, 0x04, 0x37}},
	{REGFLAG_CMD, 5, {0x2B, 0x00, 0x00, 0x09, 0xD7}},
	/* Pentile Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x01, 0x60, 0x92}},
	{REGFLAG_CMD, 5, {0x92, 0xD8, 0xD8, 0xC0, 0xC0}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* ERR_FG Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xE5, 0x15}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x3D, 0xF4}},
	{REGFLAG_CMD, 2, {0xF4, 0x10}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x01, 0xED}},
	{REGFLAG_CMD, 3, {0xED, 0x41, 0x03}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* FFC Setting */
	{REGFLAG_CMD, 3, {0xFC, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x36, 0xC5}},
	{REGFLAG_CMD, 2, {0xC5, 0x11}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x3E, 0xC5}},
	{REGFLAG_CMD, 3, {0xC5, 0x5E, 0x13}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x56, 0xC5}},
	{REGFLAG_CMD, 3, {0xC5, 0x5E, 0x13}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xFC, 0xA5, 0xA5}},
	/* Dimming Setting */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0x53, 0x20}},
	/* {REGFLAG_CMD, 3, {0x51, 0x01, 0xFF}}, */
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* 90Hz → 120Hz Transition (120Hz on) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 3, {0xBD, 0xE1, 0x02}},
	{REGFLAG_CMD, 2, {0x60, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* HOP Low Freq. (@HS 120Hz, Manual Mode) */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xBD, 0xE1}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x1F, 0xBD}},
	{REGFLAG_CMD, 3, {0xBD, 0x00, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* TE Modulation */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB9, 0x61, 0x00, 0x02}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x0C, 0xB9}},
	{REGFLAG_CMD, 5, {0xB9, 0x09, 0xD8, 0x00, 0x24}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
	/* SPR */
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 4, {0xB0, 0x01, 0x5E, 0x92}},
	{REGFLAG_CMD, 8, {0x92, 0x0A, 0x00, 0xDB, 0xDB, 0xC0, 0xC0, 0x40}},
	{REGFLAG_CMD, 3, {0xF0,0xA5,0xA5}},
	/* Display On(29h) */
	{REGFLAG_CMD, 1, {0x29}},
};

/* --------------- timing@wqhd_oplus_120 --------------- */
/* timing-switch cmd */
struct LCM_setting_table wqhd_timing_switch_cmd_oplus120[] = {
};

/* dsi-on cmd */
struct LCM_setting_table wqhd_dsi_on_cmd_oplus120[] = {
};

/* ------------------------- common parameters ------------------------- */

/* --------------- panel common --------------- */
/* aod/fod command */
struct LCM_setting_table aod_on_cmd[] = {

};

struct LCM_setting_table aod_off_cmd[] = {

};

struct LCM_setting_table aod_high_mode[] = {

};

struct LCM_setting_table aod_low_mode[] = {

};

struct LCM_setting_table hbm_on_cmd[] = {

};

struct LCM_setting_table hbm_off_cmd[] = {

};

/* loading effect */
struct LCM_setting_table lcm_seed_mode0[] = {
	/* Loading/Effect Setting mode0 off */
	{REGFLAG_CMD,0x03,{0xF0,0x5A,0x5A}},
	{REGFLAG_CMD,0x04,{0xB0,0x02,0x79,0x92}},
	{REGFLAG_CMD,0x02,{0x92,0x07}},
	{REGFLAG_CMD,0x03,{0xF0,0xA5,0xA5}},
};

struct LCM_setting_table lcm_seed_mode1[] = {
	/* Loading/Effect Setting mode1 100%*/
	{REGFLAG_CMD,0x03,{0xF0,0x5A,0x5A}},
	{REGFLAG_CMD,0x04,{0xB0,0x02,0x79,0x92}},
	{REGFLAG_CMD,0x02,{0x92,0x27}},
	{REGFLAG_CMD,0x04,{0xB0,0x03,0x61,0x92}},
	{REGFLAG_CMD,0x09,{0x92,0xE2,0x00,0x00,0x00,0x92,0x2C,0x6A,0x80}},
	{REGFLAG_CMD,0x04,{0xB0,0x03,0x69,0x92}},
	{REGFLAG_CMD,0x0A,{0x92,0x00,0x00,0x00,0x00,0xFF,0x90,0x00,0x00,0x01}},
	{REGFLAG_CMD,0x03,{0xF0,0xA5,0xA5}},
};

struct LCM_setting_table lcm_seed_mode2[] = {
	/* Loading/Effect Setting mode2 110% */
	{REGFLAG_CMD,0x03,{0xF0,0x5A,0x5A}},
	{REGFLAG_CMD,0x04,{0xB0,0x02,0x79,0x92}},
	{REGFLAG_CMD,0x02,{0x92,0x27}},
	{REGFLAG_CMD,0x04,{0xB0,0x03,0x61,0x92}},
	{REGFLAG_CMD,0x09,{0x92,0xE2,0x00,0x00,0x00,0x92,0x2C,0x6A,0x80}},
	{REGFLAG_CMD,0x04,{0xB0,0x03,0x69,0x92}},
	{REGFLAG_CMD,0x0A,{0x92,0x6D,0x57,0x77,0x5F,0xFF,0x90,0x00,0x00,0x01}},
	{REGFLAG_CMD,0x03,{0xF0,0xA5,0xA5}},
};

/* --------------- adfr common --------------- */
/* pre-switch cmd */
struct LCM_setting_table pre_switch_cmd[] = {
};

/* fake frame cmd, used for sdc 90/120 */
struct LCM_setting_table fakeframe_cmd[] = {
};

/* SDC Auto On */
struct LCM_setting_table auto_on_cmd[] = {
};

/* SDC Auto Off */
struct LCM_setting_table auto_off_cmd[] = {
};

/* SDC Auto Off Min Fps */
struct LCM_setting_table auto_off_minfps_cmd[] = {
	{REGFLAG_CMD, 3, {0xF0, 0x5A, 0x5A}},
	{REGFLAG_CMD, 2, {0xBD, 0xE1}},
	{REGFLAG_CMD, 4, {0xB0, 0x00, 0x1F, 0xBD}},
	{REGFLAG_CMD, 3, {0xBD, 0x00, 0x00}},
	{REGFLAG_CMD, 2, {0xF7, 0x0F}},
	{REGFLAG_CMD, 3, {0xF0, 0xA5, 0xA5}},
};

/* SDC Auto On Min Fps */
struct LCM_setting_table auto_on_minfps_cmd[] = {
};

#endif