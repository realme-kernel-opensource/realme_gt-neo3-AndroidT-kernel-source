/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */
/*****************************************************************************
 *
 * Filename:
 * ---------
 *     ov02b102q_Sensor_setting.h
 *
 * Project:
 * --------
 * Description:
 * ------------
 *     CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _OV02B10_21121_SENSOR_SETTING_H
#define _OV02B10_21121_SENSOR_SETTING_H

kal_uint16 addr_data_pair_init_ov02b10_21121[] = {
    0xfc, 0x01,
    0xfd, 0x00,
    0xfd, 0x00,
    0x24, 0x02,
    0x25, 0x06,
    0x29, 0x03,
    0x2a, 0x34,
    0x1e, 0x17,
    0x33, 0x07,
    0x35, 0x07,
    0x4a, 0x0c,
    0x3a, 0x05,
    0x3b, 0x02,
    0x3e, 0x00,
    0x46, 0x01,
    0x6d, 0x03,
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x18, 0x00,
    0x22, 0xff,
    0x23, 0x02,
    0x17, 0x2c,
    0x19, 0x20,
    0x1b, 0x06,
    0x1c, 0x04,
    0x20, 0x03,
    0x30, 0x01,
    0x33, 0x01,
    0x31, 0x0a,
    0x32, 0x09,
    0x38, 0x01,
    0x39, 0x01,
    0x3a, 0x01,
    0x3b, 0x01,
    0x4f, 0x04,
    0x4e, 0x05,
    0x50, 0x01,
    0x35, 0x0c,
    0x45, 0x2a,
    0x46, 0x2a,
    0x47, 0x2a,
    0x48, 0x2a,
    0x4a, 0x2c,
    0x4b, 0x2c,
    0x4c, 0x2c,
    0x4d, 0x2c,
    0x56, 0x3a,
    0x57, 0x0a,
    0x58, 0x24,
    0x59, 0x20,
    0x5a, 0x0a,
    0x5b, 0xff,
    0x37, 0x0a,
    0x42, 0x0e,
    0x68, 0x90,
    0x69, 0xcd,
    0x6a, 0x8f,
    0x7c, 0x0a,
    0x7d, 0x0a,
    0x7e, 0x0a,
    0x7f, 0x08,
    0x83, 0x14,
    0x84, 0x14,
    0x86, 0x14,
    0x87, 0x07,
    0x88, 0x0f,
    0x94, 0x02,
    0x98, 0xd1,
    0xfe, 0x02,
    0xfd, 0x03,
    0x97, 0x6c,
    0x98, 0x60,
    0x99, 0x60,
    0x9a, 0x6c,
    0xa1, 0x40,
    0xaf, 0x04,
    0xb1, 0x40,
    0xae, 0x0d,
    0x88, 0x5b,
    0x89, 0x7c,
    0xb4, 0x05,
    0x8c, 0x40,
    0x8e, 0x40,
    0x90, 0x40,
    0x92, 0x40,
    0x9b, 0x46,
    0xac, 0x40,
    0xfd, 0x00,
    0x5a, 0x15,
    0x74, 0x01,
    0xfd, 0x00,
    0x50, 0x40,
    0x52, 0xb0,
    0xfd, 0x01,
    0x03, 0x70,
    0x05, 0x10,
    0x07, 0x20,
    0x09, 0xb0,
    0xfd, 0x03,
    //mipi driver vol begin
    0xfd, 0x00,
    0x6f, 0x5f,
    //mipi driver vol end
    0xc2, 0x01,
    0xfb, 0x01,
    0xfd, 0x03,
    0xc2, 0x00,
};

/* RES_1600x1200_30fps */
kal_uint16 addr_data_pair_preview_ov02b10_21121[] = {
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x14, 0x00,
    0x15, 0x01,
    0xfe, 0x02,
};
/* RES_1600x1200_30fps */
kal_uint16 addr_data_pair_capture_ov02b10_21121[] = {
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x14, 0x00,
    0x15, 0x01,
    0xfe, 0x02,
};

/* RES_1600x1200_30fps */
kal_uint16 addr_data_pair_video_ov02b10_21121[] = {
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x14, 0x00,
    0x15, 0x01,
    0xfe, 0x02,
};

/* RES_1600x1200_30fps */
kal_uint16 addr_data_pair_hs_video_ov02b10_21121[] = {
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x14, 0x00,
    0x15, 0x01,
    0xfe, 0x02,
};

/* RES_1600x1200_30fps */
kal_uint16 addr_data_pair_slim_video_ov02b10_21121[] = {
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x14, 0x00,
    0x15, 0x01,
    0xfe, 0x02,
};

/* RES_1600x1200_24fps */
kal_uint16 addr_data_pair_custom1_21121[] = {
    0xfd, 0x01,
    0x0e, 0x02,
    0x0f, 0x1a,
    0x14, 0x01,
    0x15, 0x3b,
    0xfe, 0x02,
};
#endif
