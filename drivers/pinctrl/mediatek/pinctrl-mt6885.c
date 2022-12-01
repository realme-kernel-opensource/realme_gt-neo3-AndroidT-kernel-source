// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2019 MediaTek Inc.
 * Author: Andy Teng <andy.teng@mediatek.com>
 *
 */

#include <linux/module.h>
#include "pinctrl-mtk-mt6885.h"
#include "pinctrl-paris.h"

/* MT6885 have multiple bases to program pin configuration listed as the below:
 * gpio:0x10005000,     iocfg_rm:0x11C20000, iocfg_br:0x11D10000,
 * iocfg_lm:0x11E20000, iocfg_lb:0x11E70000, iocfg_rt:0x11EA0000,
 * iocfg_lt:0x11F20000, iocfg_tm:0x11F30000
 * _i_based could be used to indicate what base the pin should be mapped into.
 */

#define PIN_FIELD_BASE(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits) \
	PIN_FIELD_CALC(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits, \
		       32, 0)

#define PINS_FIELD_BASE(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits) \
	PIN_FIELD_CALC(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits,  \
		       32, 1)

static const struct mtk_pin_field_calc mt6885_pin_mode_range[] = {
	PIN_FIELD_BASE(0, 7, 0, 0x0300, 0x10, 0, 4),
	PIN_FIELD_BASE(8, 15, 0, 0x0310, 0x10, 0, 4),
	PIN_FIELD_BASE(16, 23, 0, 0x0320, 0x10, 0, 4),
	PIN_FIELD_BASE(24, 31, 0, 0x0330, 0x10, 0, 4),
	PIN_FIELD_BASE(32, 39, 0, 0x0340, 0x10, 0, 4),
	PIN_FIELD_BASE(40, 47, 0, 0x0350, 0x10, 0, 4),
	PIN_FIELD_BASE(48, 55, 0, 0x0360, 0x10, 0, 4),
	PIN_FIELD_BASE(56, 63, 0, 0x0370, 0x10, 0, 4),
	PIN_FIELD_BASE(64, 71, 0, 0x0380, 0x10, 0, 4),
	PIN_FIELD_BASE(72, 79, 0, 0x0390, 0x10, 0, 4),
	PIN_FIELD_BASE(80, 87, 0, 0x03A0, 0x10, 0, 4),
	PIN_FIELD_BASE(88, 95, 0, 0x03B0, 0x10, 0, 4),
	PIN_FIELD_BASE(96, 103, 0, 0x03C0, 0x10, 0, 4),
	PIN_FIELD_BASE(104, 111, 0, 0x03D0, 0x10, 0, 4),
	PIN_FIELD_BASE(112, 119, 0, 0x03E0, 0x10, 0, 4),
	PIN_FIELD_BASE(120, 127, 0, 0x03F0, 0x10, 0, 4),
	PIN_FIELD_BASE(128, 135, 0, 0x0400, 0x10, 0, 4),
	PIN_FIELD_BASE(136, 143, 0, 0x0410, 0x10, 0, 4),
	PIN_FIELD_BASE(144, 151, 0, 0x0420, 0x10, 0, 4),
	PIN_FIELD_BASE(152, 159, 0, 0x0430, 0x10, 0, 4),
	PIN_FIELD_BASE(160, 167, 0, 0x0440, 0x10, 0, 4),
	PIN_FIELD_BASE(168, 175, 0, 0x0450, 0x10, 0, 4),
	PIN_FIELD_BASE(176, 183, 0, 0x0460, 0x10, 0, 4),
	PIN_FIELD_BASE(184, 191, 0, 0x0470, 0x10, 0, 4),
	PIN_FIELD_BASE(192, 199, 0, 0x0480, 0x10, 0, 4),
	PIN_FIELD_BASE(200, 207, 0, 0x0490, 0x10, 0, 4),
	PIN_FIELD_BASE(208, 215, 0, 0x04A0, 0x10, 0, 4),
	PIN_FIELD_BASE(216, 219, 0, 0x04B0, 0x10, 0, 4),
};

static const struct mtk_pin_field_calc mt6885_pin_dir_range[] = {
	PIN_FIELD_BASE(0, 31, 0, 0x0000, 0x10, 0, 1),
	PIN_FIELD_BASE(32, 63, 0, 0x0010, 0x10, 0, 1),
	PIN_FIELD_BASE(64, 95, 0, 0x0020, 0x10, 0, 1),
	PIN_FIELD_BASE(96, 127, 0, 0x0030, 0x10, 0, 1),
	PIN_FIELD_BASE(128, 159, 0, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(160, 191, 0, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(192, 219, 0, 0x0060, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_di_range[] = {
	PIN_FIELD_BASE(0, 31, 0, 0x0200, 0x10, 0, 1),
	PIN_FIELD_BASE(32, 63, 0, 0x0210, 0x10, 0, 1),
	PIN_FIELD_BASE(64, 95, 0, 0x0220, 0x10, 0, 1),
	PIN_FIELD_BASE(96, 127, 0, 0x0230, 0x10, 0, 1),
	PIN_FIELD_BASE(128, 159, 0, 0x0240, 0x10, 0, 1),
	PIN_FIELD_BASE(160, 191, 0, 0x0250, 0x10, 0, 1),
	PIN_FIELD_BASE(192, 219, 0, 0x0260, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_do_range[] = {
	PIN_FIELD_BASE(0, 31, 0, 0x0100, 0x10, 0, 1),
	PIN_FIELD_BASE(32, 63, 0, 0x0110, 0x10, 0, 1),
	PIN_FIELD_BASE(64, 95, 0, 0x0120, 0x10, 0, 1),
	PIN_FIELD_BASE(96, 127, 0, 0x0130, 0x10, 0, 1),
	PIN_FIELD_BASE(128, 159, 0, 0x0140, 0x10, 0, 1),
	PIN_FIELD_BASE(160, 191, 0, 0x0150, 0x10, 0, 1),
	PIN_FIELD_BASE(192, 219, 0, 0x0160, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_smt_range[] = {
	PINS_FIELD_BASE(0, 9, 2, 0x00f0, 0x10, 7, 1),
	PINS_FIELD_BASE(10, 15, 1, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(16, 17, 5, 0x00c0, 0x10, 8, 1),
	PINS_FIELD_BASE(18, 25, 7, 0x00f0, 0x10, 1, 1),
	PINS_FIELD_BASE(26, 30, 6, 0x00e0, 0x10, 6, 1),
	PINS_FIELD_BASE(31, 35, 6, 0x00e0, 0x10, 2, 1),
	PIN_FIELD_BASE(36, 36, 6, 0x00e0, 0x10, 16, 1),
	PINS_FIELD_BASE(37, 39, 6, 0x00e0, 0x10, 15, 1),
	PIN_FIELD_BASE(40, 41, 6, 0x00e0, 0x10, 0, 1),
	PIN_FIELD_BASE(42, 42, 6, 0x00e0, 0x10, 5, 1),
	PIN_FIELD_BASE(43, 44, 6, 0x00e0, 0x10, 3, 1),
	PIN_FIELD_BASE(45, 45, 6, 0x00e0, 0x10, 12, 1),
	PIN_FIELD_BASE(46, 46, 6, 0x00e0, 0x10, 14, 1),
	PIN_FIELD_BASE(47, 47, 6, 0x00e0, 0x10, 13, 1),
	PIN_FIELD_BASE(48, 49, 6, 0x00e0, 0x10, 10, 1),
	PIN_FIELD_BASE(50, 50, 6, 0x00e0, 0x10, 9, 1),
	PIN_FIELD_BASE(51, 52, 3, 0x0090, 0x10, 6, 1),
	PINS_FIELD_BASE(53, 56, 3, 0x0090, 0x10, 8, 1),
	PIN_FIELD_BASE(57, 60, 3, 0x0090, 0x10, 2, 1),
	PIN_FIELD_BASE(61, 61, 3, 0x0090, 0x10, 1, 1),
	PIN_FIELD_BASE(62, 62, 4, 0x0050, 0x10, 1, 1),
	PINS_FIELD_BASE(63, 73, 3, 0x0090, 0x10, 0, 1),
	PINS_FIELD_BASE(74, 84, 4, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(85, 86, 4, 0x0050, 0x10, 4, 1),
	PIN_FIELD_BASE(87, 88, 4, 0x0050, 0x10, 2, 1),
	PIN_FIELD_BASE(89, 90, 2, 0x00f0, 0x10, 26, 1),
	PIN_FIELD_BASE(91, 91, 2, 0x00f0, 0x10, 0, 1),
	PINS_FIELD_BASE(92, 95, 2, 0x0100, 0x10, 0, 1),
	PIN_FIELD_BASE(96, 96, 2, 0x00f0, 0x10, 30, 1),
	PIN_FIELD_BASE(97, 97, 2, 0x00f0, 0x10, 28, 1),
	PIN_FIELD_BASE(98, 98, 2, 0x00f0, 0x10, 31, 1),
	PINS_FIELD_BASE(99, 102, 2, 0x00f0, 0x10, 29, 1),
	PINS_FIELD_BASE(103, 105, 2, 0x00f0, 0x10, 24, 1),
	PIN_FIELD_BASE(106, 106, 2, 0x00f0, 0x10, 25, 1),
	PIN_FIELD_BASE(107, 108, 2, 0x00f0, 0x10, 5, 1),
	PINS_FIELD_BASE(109, 113, 2, 0x00f0, 0x10, 8, 1),
	PINS_FIELD_BASE(114, 116, 2, 0x00f0, 0x10, 16, 1),
	PIN_FIELD_BASE(117, 117, 2, 0x00f0, 0x10, 17, 1),
	PIN_FIELD_BASE(118, 118, 2, 0x00f0, 0x10, 10, 1),
	PIN_FIELD_BASE(119, 119, 2, 0x00f0, 0x10, 18, 1),
	PIN_FIELD_BASE(120, 120, 2, 0x00f0, 0x10, 15, 1),
	PIN_FIELD_BASE(121, 121, 2, 0x00f0, 0x10, 23, 1),
	PIN_FIELD_BASE(122, 122, 2, 0x00f0, 0x10, 14, 1),
	PIN_FIELD_BASE(123, 123, 2, 0x00f0, 0x10, 22, 1),
	PIN_FIELD_BASE(124, 124, 2, 0x00f0, 0x10, 13, 1),
	PIN_FIELD_BASE(125, 125, 2, 0x00f0, 0x10, 21, 1),
	PINS_FIELD_BASE(126, 129, 2, 0x00f0, 0x10, 9, 1),
	PINS_FIELD_BASE(130, 135, 2, 0x00f0, 0x10, 4, 1),
	PIN_FIELD_BASE(136, 138, 2, 0x00f0, 0x10, 1, 1),
	PIN_FIELD_BASE(139, 139, 2, 0x00f0, 0x10, 12, 1),
	PIN_FIELD_BASE(140, 140, 2, 0x00f0, 0x10, 20, 1),
	PIN_FIELD_BASE(141, 141, 2, 0x00f0, 0x10, 11, 1),
	PIN_FIELD_BASE(142, 142, 2, 0x00f0, 0x10, 19, 1),
	PINS_FIELD_BASE(143, 148, 1, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(149, 151, 1, 0x0090, 0x10, 0, 1),
	PINS_FIELD_BASE(152, 155, 5, 0x00c0, 0x10, 10, 1),
	PIN_FIELD_BASE(156, 156, 5, 0x00c0, 0x10, 14, 1),
	PINS_FIELD_BASE(157, 159, 5, 0x00c0, 0x10, 13, 1),
	PIN_FIELD_BASE(160, 161, 5, 0x00c0, 0x10, 11, 1),
	PINS_FIELD_BASE(162, 171, 5, 0x00c0, 0x10, 0, 1),
	PIN_FIELD_BASE(172, 173, 5, 0x00c0, 0x10, 4, 1),
	PIN_FIELD_BASE(174, 174, 5, 0x00c0, 0x10, 3, 1),
	PIN_FIELD_BASE(175, 175, 5, 0x00c0, 0x10, 6, 1),
	PIN_FIELD_BASE(176, 177, 5, 0x00c0, 0x10, 1, 1),
	PINS_FIELD_BASE(178, 182, 5, 0x00c0, 0x10, 7, 1),
	PIN_FIELD_BASE(183, 183, 7, 0x00f0, 0x10, 3, 1),
	PINS_FIELD_BASE(184, 190, 7, 0x00f0, 0x10, 4, 1),
	PIN_FIELD_BASE(191, 191, 7, 0x00f0, 0x10, 5, 1),
	PIN_FIELD_BASE(192, 192, 7, 0x00f0, 0x10, 2, 1),
	PIN_FIELD_BASE(193, 193, 7, 0x00f0, 0x10, 4, 1),
	PIN_FIELD_BASE(194, 194, 7, 0x00f0, 0x10, 6, 1),
	PIN_FIELD_BASE(195, 195, 7, 0x00f0, 0x10, 12, 1),
	PINS_FIELD_BASE(196, 199, 7, 0x00f0, 0x10, 0, 1),
	PIN_FIELD_BASE(200, 200, 7, 0x00f0, 0x10, 11, 1),
	PIN_FIELD_BASE(201, 201, 7, 0x00f0, 0x10, 14, 1),
	PIN_FIELD_BASE(202, 202, 7, 0x00f0, 0x10, 10, 1),
	PIN_FIELD_BASE(203, 203, 7, 0x00f0, 0x10, 13, 1),
	PIN_FIELD_BASE(204, 205, 6, 0x00e0, 0x10, 7, 1),
	PIN_FIELD_BASE(206, 208, 7, 0x00f0, 0x10, 15, 1),
	PINS_FIELD_BASE(209, 211, 7, 0x00f0, 0x10, 7, 1),
	PIN_FIELD_BASE(212, 213, 7, 0x00f0, 0x10, 8, 1),
	PINS_FIELD_BASE(214, 219, 7, 0x00f0, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_ies_range[] = {
	PIN_FIELD_BASE(0, 9, 2, 0x0060, 0x10, 12, 1),
	PIN_FIELD_BASE(10, 15, 1, 0x0020, 0x10, 9, 1),
	PIN_FIELD_BASE(16, 17, 5, 0x0030, 0x10, 21, 1),
	PIN_FIELD_BASE(18, 25, 7, 0x0050, 0x10, 10, 1),
	PIN_FIELD_BASE(26, 30, 6, 0x0040, 0x10, 10, 1),
	PIN_FIELD_BASE(31, 31, 6, 0x0040, 0x10, 6, 1),
	PIN_FIELD_BASE(32, 32, 6, 0x0040, 0x10, 3, 1),
	PIN_FIELD_BASE(33, 33, 6, 0x0040, 0x10, 5, 1),
	PIN_FIELD_BASE(34, 34, 6, 0x0040, 0x10, 2, 1),
	PIN_FIELD_BASE(35, 35, 6, 0x0040, 0x10, 4, 1),
	PIN_FIELD_BASE(36, 39, 6, 0x0040, 0x10, 23, 1),
	PIN_FIELD_BASE(40, 41, 6, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(42, 42, 6, 0x0040, 0x10, 9, 1),
	PIN_FIELD_BASE(43, 44, 6, 0x0040, 0x10, 7, 1),
	PIN_FIELD_BASE(45, 45, 6, 0x0040, 0x10, 20, 1),
	PIN_FIELD_BASE(46, 46, 6, 0x0040, 0x10, 22, 1),
	PIN_FIELD_BASE(47, 47, 6, 0x0040, 0x10, 21, 1),
	PIN_FIELD_BASE(48, 49, 6, 0x0040, 0x10, 18, 1),
	PIN_FIELD_BASE(50, 50, 6, 0x0040, 0x10, 17, 1),
	PIN_FIELD_BASE(51, 52, 3, 0x0020, 0x10, 16, 1),
	PIN_FIELD_BASE(53, 53, 3, 0x0020, 0x10, 21, 1),
	PIN_FIELD_BASE(54, 54, 3, 0x0020, 0x10, 18, 1),
	PIN_FIELD_BASE(55, 55, 3, 0x0020, 0x10, 20, 1),
	PIN_FIELD_BASE(56, 56, 3, 0x0020, 0x10, 19, 1),
	PIN_FIELD_BASE(57, 60, 3, 0x0020, 0x10, 12, 1),
	PIN_FIELD_BASE(61, 61, 3, 0x0020, 0x10, 11, 1),
	PIN_FIELD_BASE(62, 62, 4, 0x0010, 0x10, 11, 1),
	PIN_FIELD_BASE(63, 64, 3, 0x0020, 0x10, 0, 1),
	PIN_FIELD_BASE(65, 72, 3, 0x0020, 0x10, 3, 1),
	PIN_FIELD_BASE(73, 73, 3, 0x0020, 0x10, 2, 1),
	PIN_FIELD_BASE(74, 84, 4, 0x0010, 0x10, 0, 1),
	PIN_FIELD_BASE(85, 86, 4, 0x0010, 0x10, 14, 1),
	PIN_FIELD_BASE(87, 88, 4, 0x0010, 0x10, 12, 1),
	PIN_FIELD_BASE(89, 90, 2, 0x0070, 0x10, 19, 1),
	PIN_FIELD_BASE(91, 91, 2, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(92, 92, 2, 0x0070, 0x10, 28, 1),
	PIN_FIELD_BASE(93, 93, 2, 0x0070, 0x10, 30, 1),
	PIN_FIELD_BASE(94, 94, 2, 0x0070, 0x10, 29, 1),
	PIN_FIELD_BASE(95, 95, 2, 0x0070, 0x10, 31, 1),
	PIN_FIELD_BASE(96, 96, 2, 0x0070, 0x10, 26, 1),
	PIN_FIELD_BASE(97, 97, 2, 0x0070, 0x10, 21, 1),
	PIN_FIELD_BASE(98, 98, 2, 0x0070, 0x10, 27, 1),
	PIN_FIELD_BASE(99, 102, 2, 0x0070, 0x10, 22, 1),
	PIN_FIELD_BASE(103, 103, 2, 0x0070, 0x10, 17, 1),
	PIN_FIELD_BASE(104, 104, 2, 0x0070, 0x10, 16, 1),
	PIN_FIELD_BASE(105, 105, 2, 0x0070, 0x10, 18, 1),
	PIN_FIELD_BASE(106, 106, 2, 0x0070, 0x10, 15, 1),
	PIN_FIELD_BASE(107, 108, 2, 0x0060, 0x10, 10, 1),
	PIN_FIELD_BASE(109, 109, 2, 0x0060, 0x10, 25, 1),
	PIN_FIELD_BASE(110, 110, 2, 0x0060, 0x10, 22, 1),
	PIN_FIELD_BASE(111, 111, 2, 0x0060, 0x10, 24, 1),
	PIN_FIELD_BASE(112, 112, 2, 0x0060, 0x10, 26, 1),
	PIN_FIELD_BASE(113, 113, 2, 0x0060, 0x10, 23, 1),
	PIN_FIELD_BASE(114, 114, 2, 0x0070, 0x10, 7, 1),
	PIN_FIELD_BASE(115, 115, 2, 0x0070, 0x10, 6, 1),
	PIN_FIELD_BASE(116, 116, 2, 0x0070, 0x10, 8, 1),
	PIN_FIELD_BASE(117, 117, 2, 0x0070, 0x10, 5, 1),
	PIN_FIELD_BASE(118, 118, 2, 0x0060, 0x10, 31, 1),
	PIN_FIELD_BASE(119, 119, 2, 0x0070, 0x10, 9, 1),
	PIN_FIELD_BASE(120, 120, 2, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(121, 121, 2, 0x0070, 0x10, 14, 1),
	PIN_FIELD_BASE(122, 122, 2, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(123, 123, 2, 0x0070, 0x10, 13, 1),
	PIN_FIELD_BASE(124, 124, 2, 0x0070, 0x10, 2, 1),
	PIN_FIELD_BASE(125, 125, 2, 0x0070, 0x10, 12, 1),
	PIN_FIELD_BASE(126, 129, 2, 0x0060, 0x10, 27, 1),
	PIN_FIELD_BASE(130, 132, 2, 0x0060, 0x10, 7, 1),
	PIN_FIELD_BASE(133, 135, 2, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(136, 138, 2, 0x0060, 0x10, 1, 1),
	PIN_FIELD_BASE(139, 139, 2, 0x0070, 0x10, 1, 1),
	PIN_FIELD_BASE(140, 140, 2, 0x0070, 0x10, 11, 1),
	PIN_FIELD_BASE(141, 141, 2, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(142, 142, 2, 0x0070, 0x10, 10, 1),
	PIN_FIELD_BASE(143, 145, 1, 0x0020, 0x10, 6, 1),
	PIN_FIELD_BASE(146, 148, 1, 0x0020, 0x10, 3, 1),
	PIN_FIELD_BASE(149, 151, 1, 0x0020, 0x10, 0, 1),
	PIN_FIELD_BASE(152, 152, 5, 0x0030, 0x10, 26, 1),
	PIN_FIELD_BASE(153, 153, 5, 0x0030, 0x10, 25, 1),
	PIN_FIELD_BASE(154, 155, 5, 0x0030, 0x10, 23, 1),
	PIN_FIELD_BASE(156, 158, 5, 0x0030, 0x10, 29, 1),
	PIN_FIELD_BASE(159, 159, 5, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(160, 161, 5, 0x0030, 0x10, 27, 1),
	PIN_FIELD_BASE(162, 171, 5, 0x0030, 0x10, 0, 1),
	PIN_FIELD_BASE(172, 173, 5, 0x0030, 0x10, 13, 1),
	PIN_FIELD_BASE(174, 174, 5, 0x0030, 0x10, 12, 1),
	PIN_FIELD_BASE(175, 175, 5, 0x0030, 0x10, 15, 1),
	PIN_FIELD_BASE(176, 177, 5, 0x0030, 0x10, 10, 1),
	PIN_FIELD_BASE(178, 182, 5, 0x0030, 0x10, 16, 1),
	PIN_FIELD_BASE(183, 184, 7, 0x0050, 0x10, 19, 1),
	PIN_FIELD_BASE(185, 185, 7, 0x0050, 0x10, 22, 1),
	PIN_FIELD_BASE(186, 186, 7, 0x0050, 0x10, 24, 1),
	PIN_FIELD_BASE(187, 187, 7, 0x0050, 0x10, 26, 1),
	PIN_FIELD_BASE(188, 188, 7, 0x0050, 0x10, 21, 1),
	PIN_FIELD_BASE(189, 189, 7, 0x0050, 0x10, 25, 1),
	PIN_FIELD_BASE(190, 191, 7, 0x0050, 0x10, 27, 1),
	PIN_FIELD_BASE(192, 192, 7, 0x0050, 0x10, 18, 1),
	PIN_FIELD_BASE(193, 193, 7, 0x0050, 0x10, 23, 1),
	PIN_FIELD_BASE(194, 194, 7, 0x0050, 0x10, 29, 1),
	PIN_FIELD_BASE(195, 195, 7, 0x0060, 0x10, 5, 1),
	PIN_FIELD_BASE(196, 196, 7, 0x0050, 0x10, 6, 1),
	PIN_FIELD_BASE(197, 197, 7, 0x0050, 0x10, 8, 1),
	PIN_FIELD_BASE(198, 198, 7, 0x0050, 0x10, 7, 1),
	PIN_FIELD_BASE(199, 199, 7, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(200, 200, 7, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(201, 201, 7, 0x0060, 0x10, 7, 1),
	PIN_FIELD_BASE(202, 202, 7, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(203, 203, 7, 0x0060, 0x10, 6, 1),
	PIN_FIELD_BASE(204, 205, 6, 0x0040, 0x10, 15, 1),
	PIN_FIELD_BASE(206, 208, 7, 0x0060, 0x10, 8, 1),
	PIN_FIELD_BASE(209, 209, 7, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(210, 210, 7, 0x0050, 0x10, 31, 1),
	PIN_FIELD_BASE(211, 211, 7, 0x0060, 0x10, 1, 1),
	PIN_FIELD_BASE(212, 212, 7, 0x0050, 0x10, 30, 1),
	PIN_FIELD_BASE(213, 213, 7, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(214, 214, 7, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(215, 215, 7, 0x0050, 0x10, 9, 1),
	PIN_FIELD_BASE(216, 217, 7, 0x0050, 0x10, 4, 1),
	PIN_FIELD_BASE(218, 219, 7, 0x0050, 0x10, 1, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_pu_range[] = {
	PIN_FIELD_BASE(0, 9, 2, 0x00a0, 0x10, 12, 1),
	PIN_FIELD_BASE(16, 17, 5, 0x0070, 0x10, 21, 1),
	PIN_FIELD_BASE(18, 25, 7, 0x0090, 0x10, 10, 1),
	PIN_FIELD_BASE(26, 30, 6, 0x0080, 0x10, 10, 1),
	PIN_FIELD_BASE(31, 31, 6, 0x0080, 0x10, 6, 1),
	PIN_FIELD_BASE(32, 32, 6, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(33, 33, 6, 0x0080, 0x10, 5, 1),
	PIN_FIELD_BASE(34, 34, 6, 0x0080, 0x10, 2, 1),
	PIN_FIELD_BASE(35, 35, 6, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(36, 39, 6, 0x0080, 0x10, 17, 1),
	PIN_FIELD_BASE(40, 41, 6, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(42, 42, 6, 0x0080, 0x10, 9, 1),
	PIN_FIELD_BASE(43, 44, 6, 0x0080, 0x10, 7, 1),
	PIN_FIELD_BASE(57, 60, 3, 0x0050, 0x10, 12, 1),
	PIN_FIELD_BASE(61, 61, 3, 0x0050, 0x10, 11, 1),
	PIN_FIELD_BASE(62, 62, 4, 0x0030, 0x10, 11, 1),
	PIN_FIELD_BASE(63, 64, 3, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(65, 72, 3, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(73, 73, 3, 0x0050, 0x10, 2, 1),
	PIN_FIELD_BASE(74, 84, 4, 0x0030, 0x10, 0, 1),
	PIN_FIELD_BASE(85, 86, 4, 0x0030, 0x10, 14, 1),
	PIN_FIELD_BASE(87, 88, 4, 0x0030, 0x10, 12, 1),
	PIN_FIELD_BASE(89, 90, 2, 0x00b0, 0x10, 19, 1),
	PIN_FIELD_BASE(91, 91, 2, 0x00a0, 0x10, 0, 1),
	PIN_FIELD_BASE(92, 92, 2, 0x00b0, 0x10, 28, 1),
	PIN_FIELD_BASE(93, 93, 2, 0x00b0, 0x10, 30, 1),
	PIN_FIELD_BASE(94, 94, 2, 0x00b0, 0x10, 29, 1),
	PIN_FIELD_BASE(95, 95, 2, 0x00b0, 0x10, 31, 1),
	PIN_FIELD_BASE(96, 96, 2, 0x00b0, 0x10, 26, 1),
	PIN_FIELD_BASE(97, 97, 2, 0x00b0, 0x10, 21, 1),
	PIN_FIELD_BASE(98, 98, 2, 0x00b0, 0x10, 27, 1),
	PIN_FIELD_BASE(99, 102, 2, 0x00b0, 0x10, 22, 1),
	PIN_FIELD_BASE(103, 103, 2, 0x00b0, 0x10, 17, 1),
	PIN_FIELD_BASE(104, 104, 2, 0x00b0, 0x10, 16, 1),
	PIN_FIELD_BASE(105, 105, 2, 0x00b0, 0x10, 18, 1),
	PIN_FIELD_BASE(106, 106, 2, 0x00b0, 0x10, 15, 1),
	PIN_FIELD_BASE(107, 108, 2, 0x00a0, 0x10, 10, 1),
	PIN_FIELD_BASE(109, 109, 2, 0x00a0, 0x10, 25, 1),
	PIN_FIELD_BASE(110, 110, 2, 0x00a0, 0x10, 22, 1),
	PIN_FIELD_BASE(111, 111, 2, 0x00a0, 0x10, 24, 1),
	PIN_FIELD_BASE(112, 112, 2, 0x00a0, 0x10, 26, 1),
	PIN_FIELD_BASE(113, 113, 2, 0x00a0, 0x10, 23, 1),
	PIN_FIELD_BASE(114, 114, 2, 0x00b0, 0x10, 7, 1),
	PIN_FIELD_BASE(115, 115, 2, 0x00b0, 0x10, 6, 1),
	PIN_FIELD_BASE(116, 116, 2, 0x00b0, 0x10, 8, 1),
	PIN_FIELD_BASE(117, 117, 2, 0x00b0, 0x10, 5, 1),
	PIN_FIELD_BASE(118, 118, 2, 0x00a0, 0x10, 31, 1),
	PIN_FIELD_BASE(119, 119, 2, 0x00b0, 0x10, 9, 1),
	PIN_FIELD_BASE(120, 120, 2, 0x00b0, 0x10, 4, 1),
	PIN_FIELD_BASE(121, 121, 2, 0x00b0, 0x10, 14, 1),
	PIN_FIELD_BASE(122, 122, 2, 0x00b0, 0x10, 3, 1),
	PIN_FIELD_BASE(123, 123, 2, 0x00b0, 0x10, 13, 1),
	PIN_FIELD_BASE(124, 124, 2, 0x00b0, 0x10, 2, 1),
	PIN_FIELD_BASE(125, 125, 2, 0x00b0, 0x10, 12, 1),
	PIN_FIELD_BASE(126, 129, 2, 0x00a0, 0x10, 27, 1),
	PIN_FIELD_BASE(130, 132, 2, 0x00a0, 0x10, 7, 1),
	PIN_FIELD_BASE(133, 135, 2, 0x00a0, 0x10, 4, 1),
	PIN_FIELD_BASE(136, 138, 2, 0x00a0, 0x10, 1, 1),
	PIN_FIELD_BASE(139, 139, 2, 0x00b0, 0x10, 1, 1),
	PIN_FIELD_BASE(140, 140, 2, 0x00b0, 0x10, 11, 1),
	PIN_FIELD_BASE(141, 141, 2, 0x00b0, 0x10, 0, 1),
	PIN_FIELD_BASE(142, 142, 2, 0x00b0, 0x10, 10, 1),
	PIN_FIELD_BASE(143, 145, 1, 0x0050, 0x10, 6, 1),
	PIN_FIELD_BASE(146, 148, 1, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(149, 151, 1, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(156, 159, 5, 0x0070, 0x10, 25, 1),
	PIN_FIELD_BASE(160, 161, 5, 0x0070, 0x10, 23, 1),
	PIN_FIELD_BASE(162, 171, 5, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(172, 173, 5, 0x0070, 0x10, 13, 1),
	PIN_FIELD_BASE(174, 174, 5, 0x0070, 0x10, 12, 1),
	PIN_FIELD_BASE(175, 175, 5, 0x0070, 0x10, 15, 1),
	PIN_FIELD_BASE(176, 177, 5, 0x0070, 0x10, 10, 1),
	PIN_FIELD_BASE(178, 182, 5, 0x0070, 0x10, 16, 1),
	PIN_FIELD_BASE(195, 195, 7, 0x0090, 0x10, 25, 1),
	PIN_FIELD_BASE(196, 196, 7, 0x0090, 0x10, 6, 1),
	PIN_FIELD_BASE(197, 197, 7, 0x0090, 0x10, 8, 1),
	PIN_FIELD_BASE(198, 198, 7, 0x0090, 0x10, 7, 1),
	PIN_FIELD_BASE(199, 199, 7, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(200, 200, 7, 0x0090, 0x10, 24, 1),
	PIN_FIELD_BASE(201, 201, 7, 0x0090, 0x10, 27, 1),
	PIN_FIELD_BASE(202, 202, 7, 0x0090, 0x10, 23, 1),
	PIN_FIELD_BASE(203, 203, 7, 0x0090, 0x10, 26, 1),
	PIN_FIELD_BASE(204, 205, 6, 0x0080, 0x10, 15, 1),
	PIN_FIELD_BASE(206, 208, 7, 0x0090, 0x10, 28, 1),
	PIN_FIELD_BASE(209, 209, 7, 0x0090, 0x10, 20, 1),
	PIN_FIELD_BASE(210, 210, 7, 0x0090, 0x10, 19, 1),
	PIN_FIELD_BASE(211, 211, 7, 0x0090, 0x10, 21, 1),
	PIN_FIELD_BASE(212, 212, 7, 0x0090, 0x10, 18, 1),
	PIN_FIELD_BASE(213, 213, 7, 0x0090, 0x10, 22, 1),
	PIN_FIELD_BASE(214, 214, 7, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(215, 215, 7, 0x0090, 0x10, 9, 1),
	PIN_FIELD_BASE(216, 217, 7, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(218, 219, 7, 0x0090, 0x10, 1, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_pd_range[] = {
	PIN_FIELD_BASE(0, 9, 2, 0x0080, 0x10, 12, 1),
	PIN_FIELD_BASE(16, 17, 5, 0x0050, 0x10, 21, 1),
	PIN_FIELD_BASE(18, 25, 7, 0x0070, 0x10, 10, 1),
	PIN_FIELD_BASE(26, 30, 6, 0x0060, 0x10, 10, 1),
	PIN_FIELD_BASE(31, 31, 6, 0x0060, 0x10, 6, 1),
	PIN_FIELD_BASE(32, 32, 6, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(33, 33, 6, 0x0060, 0x10, 5, 1),
	PIN_FIELD_BASE(34, 34, 6, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(35, 35, 6, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(36, 39, 6, 0x0060, 0x10, 17, 1),
	PIN_FIELD_BASE(40, 41, 6, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(42, 42, 6, 0x0060, 0x10, 9, 1),
	PIN_FIELD_BASE(43, 44, 6, 0x0060, 0x10, 7, 1),
	PIN_FIELD_BASE(57, 60, 3, 0x0030, 0x10, 12, 1),
	PIN_FIELD_BASE(61, 61, 3, 0x0030, 0x10, 11, 1),
	PIN_FIELD_BASE(62, 62, 4, 0x0020, 0x10, 11, 1),
	PIN_FIELD_BASE(63, 64, 3, 0x0030, 0x10, 0, 1),
	PIN_FIELD_BASE(65, 72, 3, 0x0030, 0x10, 3, 1),
	PIN_FIELD_BASE(73, 73, 3, 0x0030, 0x10, 2, 1),
	PIN_FIELD_BASE(74, 84, 4, 0x0020, 0x10, 0, 1),
	PIN_FIELD_BASE(85, 86, 4, 0x0020, 0x10, 14, 1),
	PIN_FIELD_BASE(87, 88, 4, 0x0020, 0x10, 12, 1),
	PIN_FIELD_BASE(89, 90, 2, 0x0090, 0x10, 19, 1),
	PIN_FIELD_BASE(91, 91, 2, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(92, 92, 2, 0x0090, 0x10, 28, 1),
	PIN_FIELD_BASE(93, 93, 2, 0x0090, 0x10, 30, 1),
	PIN_FIELD_BASE(94, 94, 2, 0x0090, 0x10, 29, 1),
	PIN_FIELD_BASE(95, 95, 2, 0x0090, 0x10, 31, 1),
	PIN_FIELD_BASE(96, 96, 2, 0x0090, 0x10, 26, 1),
	PIN_FIELD_BASE(97, 97, 2, 0x0090, 0x10, 21, 1),
	PIN_FIELD_BASE(98, 98, 2, 0x0090, 0x10, 27, 1),
	PIN_FIELD_BASE(99, 102, 2, 0x0090, 0x10, 22, 1),
	PIN_FIELD_BASE(103, 103, 2, 0x0090, 0x10, 17, 1),
	PIN_FIELD_BASE(104, 104, 2, 0x0090, 0x10, 16, 1),
	PIN_FIELD_BASE(105, 105, 2, 0x0090, 0x10, 18, 1),
	PIN_FIELD_BASE(106, 106, 2, 0x0090, 0x10, 15, 1),
	PIN_FIELD_BASE(107, 108, 2, 0x0080, 0x10, 10, 1),
	PIN_FIELD_BASE(109, 109, 2, 0x0080, 0x10, 25, 1),
	PIN_FIELD_BASE(110, 110, 2, 0x0080, 0x10, 22, 1),
	PIN_FIELD_BASE(111, 111, 2, 0x0080, 0x10, 24, 1),
	PIN_FIELD_BASE(112, 112, 2, 0x0080, 0x10, 26, 1),
	PIN_FIELD_BASE(113, 113, 2, 0x0080, 0x10, 23, 1),
	PIN_FIELD_BASE(114, 114, 2, 0x0090, 0x10, 7, 1),
	PIN_FIELD_BASE(115, 115, 2, 0x0090, 0x10, 6, 1),
	PIN_FIELD_BASE(116, 116, 2, 0x0090, 0x10, 8, 1),
	PIN_FIELD_BASE(117, 117, 2, 0x0090, 0x10, 5, 1),
	PIN_FIELD_BASE(118, 118, 2, 0x0080, 0x10, 31, 1),
	PIN_FIELD_BASE(119, 119, 2, 0x0090, 0x10, 9, 1),
	PIN_FIELD_BASE(120, 120, 2, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(121, 121, 2, 0x0090, 0x10, 14, 1),
	PIN_FIELD_BASE(122, 122, 2, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(123, 123, 2, 0x0090, 0x10, 13, 1),
	PIN_FIELD_BASE(124, 124, 2, 0x0090, 0x10, 2, 1),
	PIN_FIELD_BASE(125, 125, 2, 0x0090, 0x10, 12, 1),
	PIN_FIELD_BASE(126, 129, 2, 0x0080, 0x10, 27, 1),
	PIN_FIELD_BASE(130, 132, 2, 0x0080, 0x10, 7, 1),
	PIN_FIELD_BASE(133, 135, 2, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(136, 138, 2, 0x0080, 0x10, 1, 1),
	PIN_FIELD_BASE(139, 139, 2, 0x0090, 0x10, 1, 1),
	PIN_FIELD_BASE(140, 140, 2, 0x0090, 0x10, 11, 1),
	PIN_FIELD_BASE(141, 141, 2, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(142, 142, 2, 0x0090, 0x10, 10, 1),
	PIN_FIELD_BASE(143, 145, 1, 0x0030, 0x10, 6, 1),
	PIN_FIELD_BASE(146, 148, 1, 0x0030, 0x10, 3, 1),
	PIN_FIELD_BASE(149, 151, 1, 0x0030, 0x10, 0, 1),
	PIN_FIELD_BASE(156, 159, 5, 0x0050, 0x10, 25, 1),
	PIN_FIELD_BASE(160, 161, 5, 0x0050, 0x10, 23, 1),
	PIN_FIELD_BASE(162, 171, 5, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(172, 173, 5, 0x0050, 0x10, 13, 1),
	PIN_FIELD_BASE(174, 174, 5, 0x0050, 0x10, 12, 1),
	PIN_FIELD_BASE(175, 175, 5, 0x0050, 0x10, 15, 1),
	PIN_FIELD_BASE(176, 177, 5, 0x0050, 0x10, 10, 1),
	PIN_FIELD_BASE(178, 182, 5, 0x0050, 0x10, 16, 1),
	PIN_FIELD_BASE(195, 195, 7, 0x0070, 0x10, 25, 1),
	PIN_FIELD_BASE(196, 196, 7, 0x0070, 0x10, 6, 1),
	PIN_FIELD_BASE(197, 197, 7, 0x0070, 0x10, 8, 1),
	PIN_FIELD_BASE(198, 198, 7, 0x0070, 0x10, 7, 1),
	PIN_FIELD_BASE(199, 199, 7, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(200, 200, 7, 0x0070, 0x10, 24, 1),
	PIN_FIELD_BASE(201, 201, 7, 0x0070, 0x10, 27, 1),
	PIN_FIELD_BASE(202, 202, 7, 0x0070, 0x10, 23, 1),
	PIN_FIELD_BASE(203, 203, 7, 0x0070, 0x10, 26, 1),
	PIN_FIELD_BASE(204, 205, 6, 0x0060, 0x10, 15, 1),
	PIN_FIELD_BASE(206, 208, 7, 0x0070, 0x10, 28, 1),
	PIN_FIELD_BASE(209, 209, 7, 0x0070, 0x10, 20, 1),
	PIN_FIELD_BASE(210, 210, 7, 0x0070, 0x10, 19, 1),
	PIN_FIELD_BASE(211, 211, 7, 0x0070, 0x10, 21, 1),
	PIN_FIELD_BASE(212, 212, 7, 0x0070, 0x10, 18, 1),
	PIN_FIELD_BASE(213, 213, 7, 0x0070, 0x10, 22, 1),
	PIN_FIELD_BASE(214, 214, 7, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(215, 215, 7, 0x0070, 0x10, 9, 1),
	PIN_FIELD_BASE(216, 217, 7, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(218, 219, 7, 0x0070, 0x10, 1, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_drv_range[] = {
	PINS_FIELD_BASE(0, 9, 2, 0x0000, 0x10, 21, 3),
	PINS_FIELD_BASE(10, 15, 1, 0x0000, 0x10, 12, 3),
	PIN_FIELD_BASE(16, 17, 5, 0x0000, 0x10, 18, 3),
	PINS_FIELD_BASE(18, 25, 7, 0x0000, 0x10, 3, 3),
	PINS_FIELD_BASE(26, 30, 6, 0x0000, 0x10, 15, 3),
	PINS_FIELD_BASE(31, 35, 6, 0x0000, 0x10, 6, 3),
	PIN_FIELD_BASE(36, 36, 6, 0x0010, 0x10, 7, 3),
	PINS_FIELD_BASE(37, 39, 6, 0x0010, 0x10, 4, 3),
	PIN_FIELD_BASE(40, 41, 6, 0x0000, 0x10, 0, 3),
	PIN_FIELD_BASE(42, 42, 6, 0x0000, 0x10, 12, 3),
	PINS_FIELD_BASE(43, 44, 6, 0x0000, 0x10, 9, 3),
	PIN_FIELD_BASE(45, 45, 6, 0x0000, 0x10, 30, 2),
	PIN_FIELD_BASE(46, 46, 6, 0x0010, 0x10, 2, 2),
	PIN_FIELD_BASE(47, 47, 6, 0x0010, 0x10, 0, 2),
	PIN_FIELD_BASE(48, 49, 6, 0x0000, 0x10, 26, 2),
	PIN_FIELD_BASE(50, 50, 6, 0x0000, 0x10, 24, 2),
	PIN_FIELD_BASE(51, 52, 3, 0x0000, 0x10, 18, 3),
	PINS_FIELD_BASE(53, 56, 3, 0x0000, 0x10, 24, 3),
	PIN_FIELD_BASE(57, 60, 3, 0x0000, 0x10, 6, 3),
	PIN_FIELD_BASE(61, 61, 3, 0x0000, 0x10, 3, 3),
	PIN_FIELD_BASE(62, 62, 4, 0x0000, 0x10, 3, 3),
	PINS_FIELD_BASE(63, 73, 3, 0x0000, 0x10, 0, 3),
	PINS_FIELD_BASE(74, 84, 4, 0x0000, 0x10, 0, 3),
	PIN_FIELD_BASE(85, 86, 4, 0x0000, 0x10, 12, 3),
	PIN_FIELD_BASE(87, 88, 4, 0x0000, 0x10, 6, 3),
	PIN_FIELD_BASE(89, 90, 2, 0x0020, 0x10, 15, 3),
	PIN_FIELD_BASE(91, 91, 2, 0x0000, 0x10, 0, 3),
	PINS_FIELD_BASE(92, 95, 2, 0x0030, 0x10, 3, 3),
	PIN_FIELD_BASE(96, 96, 2, 0x0020, 0x10, 27, 3),
	PIN_FIELD_BASE(97, 97, 2, 0x0020, 0x10, 21, 3),
	PIN_FIELD_BASE(98, 98, 2, 0x0030, 0x10, 0, 3),
	PINS_FIELD_BASE(99, 102, 2, 0x0020, 0x10, 24, 3),
	PINS_FIELD_BASE(103, 105, 2, 0x0020, 0x10, 9, 3),
	PIN_FIELD_BASE(106, 106, 2, 0x0020, 0x10, 12, 3),
	PIN_FIELD_BASE(107, 108, 2, 0x0000, 0x10, 15, 3),
	PINS_FIELD_BASE(109, 113, 2, 0x0000, 0x10, 24, 3),
	PINS_FIELD_BASE(114, 117, 2, 0x0010, 0x10, 18, 3),
	PIN_FIELD_BASE(118, 118, 2, 0x0010, 0x10, 0, 3),
	PIN_FIELD_BASE(119, 119, 2, 0x0010, 0x10, 21, 3),
	PIN_FIELD_BASE(120, 120, 2, 0x0010, 0x10, 15, 3),
	PIN_FIELD_BASE(121, 121, 2, 0x0020, 0x10, 6, 3),
	PIN_FIELD_BASE(122, 122, 2, 0x0010, 0x10, 12, 3),
	PIN_FIELD_BASE(123, 123, 2, 0x0020, 0x10, 3, 3),
	PIN_FIELD_BASE(124, 124, 2, 0x0010, 0x10, 9, 3),
	PIN_FIELD_BASE(125, 125, 2, 0x0020, 0x10, 0, 3),
	PINS_FIELD_BASE(126, 129, 2, 0x0000, 0x10, 27, 3),
	PINS_FIELD_BASE(130, 135, 2, 0x0000, 0x10, 12, 3),
	PIN_FIELD_BASE(136, 138, 2, 0x0000, 0x10, 3, 3),
	PIN_FIELD_BASE(139, 139, 2, 0x0010, 0x10, 6, 3),
	PIN_FIELD_BASE(140, 140, 2, 0x0010, 0x10, 27, 3),
	PIN_FIELD_BASE(141, 141, 2, 0x0010, 0x10, 3, 3),
	PIN_FIELD_BASE(142, 142, 2, 0x0010, 0x10, 24, 3),
	PINS_FIELD_BASE(143, 148, 1, 0x0000, 0x10, 9, 3),
	PIN_FIELD_BASE(149, 151, 1, 0x0000, 0x10, 0, 3),
	PINS_FIELD_BASE(152, 155, 5, 0x0000, 0x10, 24, 3),
	PIN_FIELD_BASE(156, 156, 5, 0x0010, 0x10, 6, 3),
	PINS_FIELD_BASE(157, 159, 5, 0x0010, 0x10, 3, 3),
	PIN_FIELD_BASE(160, 160, 5, 0x0000, 0x10, 27, 3),
	PIN_FIELD_BASE(161, 161, 5, 0x0010, 0x10, 0, 3),
	PINS_FIELD_BASE(162, 171, 5, 0x0000, 0x10, 0, 3),
	PIN_FIELD_BASE(172, 172, 5, 0x0000, 0x10, 15, 3),
	PIN_FIELD_BASE(173, 173, 5, 0x0000, 0x10, 3, 3),
	PIN_FIELD_BASE(174, 174, 5, 0x0000, 0x10, 12, 3),
	PIN_FIELD_BASE(175, 177, 5, 0x0000, 0x10, 3, 3),
	PINS_FIELD_BASE(178, 182, 5, 0x0000, 0x10, 3, 3),
	PIN_FIELD_BASE(183, 183, 7, 0x0000, 0x10, 9, 3),
	PINS_FIELD_BASE(184, 190, 7, 0x0000, 0x10, 12, 3),
	PIN_FIELD_BASE(191, 191, 7, 0x0000, 0x10, 15, 3),
	PIN_FIELD_BASE(192, 192, 7, 0x0000, 0x10, 6, 3),
	PIN_FIELD_BASE(193, 193, 7, 0x0000, 0x10, 12, 3),
	PIN_FIELD_BASE(194, 194, 7, 0x0000, 0x10, 18, 3),
	PIN_FIELD_BASE(195, 195, 7, 0x0010, 0x10, 3, 3),
	PINS_FIELD_BASE(196, 199, 7, 0x0000, 0x10, 0, 3),
	PIN_FIELD_BASE(200, 200, 7, 0x0010, 0x10, 0, 3),
	PIN_FIELD_BASE(201, 201, 7, 0x0010, 0x10, 9, 3),
	PIN_FIELD_BASE(202, 202, 7, 0x0000, 0x10, 27, 3),
	PIN_FIELD_BASE(203, 203, 7, 0x0010, 0x10, 6, 3),
	PIN_FIELD_BASE(204, 205, 6, 0x0000, 0x10, 18, 3),
	PIN_FIELD_BASE(206, 208, 7, 0x0010, 0x10, 12, 3),
	PINS_FIELD_BASE(209, 212, 7, 0x0000, 0x10, 21, 3),
	PIN_FIELD_BASE(213, 213, 7, 0x0000, 0x10, 24, 3),
	PINS_FIELD_BASE(214, 219, 7, 0x0000, 0x10, 0, 3),
};

static const struct mtk_pin_field_calc mt6885_pin_pupd_range[] = {
	PIN_FIELD_BASE(10, 15, 1, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(45, 45, 6, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(46, 46, 6, 0x0070, 0x10, 5, 1),
	PIN_FIELD_BASE(47, 47, 6, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(48, 49, 6, 0x0070, 0x10, 1, 1),
	PIN_FIELD_BASE(50, 50, 6, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(51, 52, 3, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(53, 53, 3, 0x0040, 0x10, 5, 1),
	PIN_FIELD_BASE(54, 54, 3, 0x0040, 0x10, 2, 1),
	PIN_FIELD_BASE(55, 55, 3, 0x0040, 0x10, 4, 1),
	PIN_FIELD_BASE(56, 56, 3, 0x0040, 0x10, 3, 1),
	PIN_FIELD_BASE(152, 152, 5, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(153, 153, 5, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(154, 155, 5, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(183, 184, 7, 0x0080, 0x10, 1, 1),
	PIN_FIELD_BASE(185, 185, 7, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(186, 186, 7, 0x0080, 0x10, 6, 1),
	PIN_FIELD_BASE(187, 187, 7, 0x0080, 0x10, 8, 1),
	PIN_FIELD_BASE(188, 188, 7, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(189, 189, 7, 0x0080, 0x10, 7, 1),
	PIN_FIELD_BASE(190, 191, 7, 0x0080, 0x10, 9, 1),
	PIN_FIELD_BASE(192, 192, 7, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(193, 193, 7, 0x0080, 0x10, 5, 1),
	PIN_FIELD_BASE(194, 194, 7, 0x0080, 0x10, 11, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_r0_range[] = {
	PIN_FIELD_BASE(10, 15, 1, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(45, 45, 6, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(46, 46, 6, 0x0090, 0x10, 5, 1),
	PIN_FIELD_BASE(47, 47, 6, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(48, 49, 6, 0x0090, 0x10, 1, 1),
	PIN_FIELD_BASE(50, 50, 6, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(51, 52, 3, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(53, 53, 3, 0x0060, 0x10, 5, 1),
	PIN_FIELD_BASE(54, 54, 3, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(55, 55, 3, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(56, 56, 3, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(152, 152, 5, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(153, 153, 5, 0x0080, 0x10, 2, 1),
	PIN_FIELD_BASE(154, 155, 5, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(183, 184, 7, 0x00a0, 0x10, 1, 1),
	PIN_FIELD_BASE(185, 185, 7, 0x00a0, 0x10, 4, 1),
	PIN_FIELD_BASE(186, 186, 7, 0x00a0, 0x10, 6, 1),
	PIN_FIELD_BASE(187, 187, 7, 0x00a0, 0x10, 8, 1),
	PIN_FIELD_BASE(188, 188, 7, 0x00a0, 0x10, 3, 1),
	PIN_FIELD_BASE(189, 189, 7, 0x00a0, 0x10, 7, 1),
	PIN_FIELD_BASE(190, 191, 7, 0x00a0, 0x10, 9, 1),
	PIN_FIELD_BASE(192, 192, 7, 0x00a0, 0x10, 0, 1),
	PIN_FIELD_BASE(193, 193, 7, 0x00a0, 0x10, 5, 1),
	PIN_FIELD_BASE(194, 194, 7, 0x00a0, 0x10, 11, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_r1_range[] = {
	PIN_FIELD_BASE(10, 15, 1, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(45, 45, 6, 0x00a0, 0x10, 3, 1),
	PIN_FIELD_BASE(46, 46, 6, 0x00a0, 0x10, 5, 1),
	PIN_FIELD_BASE(47, 47, 6, 0x00a0, 0x10, 4, 1),
	PIN_FIELD_BASE(48, 49, 6, 0x00a0, 0x10, 1, 1),
	PIN_FIELD_BASE(50, 50, 6, 0x00a0, 0x10, 0, 1),
	PIN_FIELD_BASE(51, 52, 3, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(53, 53, 3, 0x0070, 0x10, 5, 1),
	PIN_FIELD_BASE(54, 54, 3, 0x0070, 0x10, 2, 1),
	PIN_FIELD_BASE(55, 55, 3, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(56, 56, 3, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(152, 152, 5, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(153, 153, 5, 0x0090, 0x10, 2, 1),
	PIN_FIELD_BASE(154, 155, 5, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(183, 184, 7, 0x00b0, 0x10, 1, 1),
	PIN_FIELD_BASE(185, 185, 7, 0x00b0, 0x10, 4, 1),
	PIN_FIELD_BASE(186, 186, 7, 0x00b0, 0x10, 6, 1),
	PIN_FIELD_BASE(187, 187, 7, 0x00b0, 0x10, 8, 1),
	PIN_FIELD_BASE(188, 188, 7, 0x00b0, 0x10, 3, 1),
	PIN_FIELD_BASE(189, 189, 7, 0x00b0, 0x10, 7, 1),
	PIN_FIELD_BASE(190, 191, 7, 0x00b0, 0x10, 9, 1),
	PIN_FIELD_BASE(192, 192, 7, 0x00b0, 0x10, 0, 1),
	PIN_FIELD_BASE(193, 193, 7, 0x00b0, 0x10, 5, 1),
	PIN_FIELD_BASE(194, 194, 7, 0x00b0, 0x10, 11, 1),
};

static const struct mtk_pin_field_calc mt6885_pin_eh_range[] = {
	PIN_FIELD_BASE(24, 24, 7, 0x0030, 0x10, 0, 3),
	PIN_FIELD_BASE(25, 25, 7, 0x0030, 0x10, 3, 3),
	PIN_FIELD_BASE(89, 89, 2, 0x0050, 0x10, 6, 5),
	PIN_FIELD_BASE(90, 90, 2, 0x0050, 0x10, 11, 5),
	PIN_FIELD_BASE(118, 118, 2, 0x0040, 0x10, 0, 3),
	PIN_FIELD_BASE(119, 119, 2, 0x0040, 0x10, 18, 3),
	PIN_FIELD_BASE(120, 120, 2, 0x0040, 0x10, 15, 3),
	PIN_FIELD_BASE(121, 121, 2, 0x0050, 0x10, 3, 3),
	PIN_FIELD_BASE(122, 122, 2, 0x0040, 0x10, 12, 3),
	PIN_FIELD_BASE(123, 123, 2, 0x0050, 0x10, 0, 3),
	PIN_FIELD_BASE(124, 124, 2, 0x0040, 0x10, 9, 3),
	PIN_FIELD_BASE(125, 125, 2, 0x0040, 0x10, 27, 3),
	PIN_FIELD_BASE(139, 139, 2, 0x0040, 0x10, 6, 3),
	PIN_FIELD_BASE(140, 140, 2, 0x0040, 0x10, 24, 3),
	PIN_FIELD_BASE(141, 141, 2, 0x0040, 0x10, 3, 3),
	PIN_FIELD_BASE(142, 142, 2, 0x0040, 0x10, 21, 3),
	PIN_FIELD_BASE(160, 160, 5, 0x0020, 0x10, 0, 3),
	PIN_FIELD_BASE(161, 161, 5, 0x0020, 0x10, 3, 3),
	PIN_FIELD_BASE(200, 200, 7, 0x0030, 0x10, 9, 3),
	PIN_FIELD_BASE(201, 201, 7, 0x0030, 0x10, 15, 3),
	PIN_FIELD_BASE(202, 202, 7, 0x0030, 0x10, 6, 3),
	PIN_FIELD_BASE(203, 203, 7, 0x0030, 0x10, 12, 3),
	PIN_FIELD_BASE(204, 204, 6, 0x0020, 0x10, 0, 3),
	PIN_FIELD_BASE(205, 205, 6, 0x0020, 0x10, 3, 3),
};

static const struct mtk_pin_field_calc mt6885_pin_rsel_range[] = {
	PIN_FIELD_BASE(24, 24, 7, 0x00e0, 0x10, 0, 2),
	PIN_FIELD_BASE(25, 25, 7, 0x00e0, 0x10, 2, 2),
	PIN_FIELD_BASE(118, 118, 2, 0x00e0, 0x10, 0, 2),
	PIN_FIELD_BASE(119, 119, 2, 0x00e0, 0x10, 12, 2),
	PIN_FIELD_BASE(120, 120, 2, 0x00e0, 0x10, 10, 2),
	PIN_FIELD_BASE(121, 121, 2, 0x00e0, 0x10, 22, 2),
	PIN_FIELD_BASE(122, 122, 2, 0x00e0, 0x10, 8, 2),
	PIN_FIELD_BASE(123, 123, 2, 0x00e0, 0x10, 20, 2),
	PIN_FIELD_BASE(124, 124, 2, 0x00e0, 0x10, 6, 2),
	PIN_FIELD_BASE(125, 125, 2, 0x00e0, 0x10, 18, 2),
	PIN_FIELD_BASE(139, 139, 2, 0x00e0, 0x10, 4, 2),
	PIN_FIELD_BASE(140, 140, 2, 0x00e0, 0x10, 16, 2),
	PIN_FIELD_BASE(141, 141, 2, 0x00e0, 0x10, 2, 2),
	PIN_FIELD_BASE(142, 142, 2, 0x00e0, 0x10, 14, 2),
	PIN_FIELD_BASE(160, 160, 5, 0x00b0, 0x10, 0, 2),
	PIN_FIELD_BASE(161, 161, 5, 0x00b0, 0x10, 2, 2),
	PIN_FIELD_BASE(200, 200, 7, 0x00e0, 0x10, 6, 2),
	PIN_FIELD_BASE(201, 201, 7, 0x00e0, 0x10, 10, 2),
	PIN_FIELD_BASE(202, 202, 7, 0x00e0, 0x10, 4, 2),
	PIN_FIELD_BASE(203, 203, 7, 0x00e0, 0x10, 8, 2),
	PIN_FIELD_BASE(204, 204, 6, 0x00d0, 0x10, 0, 2),
	PIN_FIELD_BASE(205, 205, 6, 0x00d0, 0x10, 2, 2),
};

static const struct mtk_pin_reg_calc mt6885_reg_cals[PINCTRL_PIN_REG_MAX] = {
	[PINCTRL_PIN_REG_MODE] = MTK_RANGE(mt6885_pin_mode_range),
	[PINCTRL_PIN_REG_DIR] = MTK_RANGE(mt6885_pin_dir_range),
	[PINCTRL_PIN_REG_DI] = MTK_RANGE(mt6885_pin_di_range),
	[PINCTRL_PIN_REG_DO] = MTK_RANGE(mt6885_pin_do_range),
	[PINCTRL_PIN_REG_SR] = MTK_RANGE(mt6885_pin_dir_range),
	[PINCTRL_PIN_REG_SMT] = MTK_RANGE(mt6885_pin_smt_range),
	[PINCTRL_PIN_REG_IES] = MTK_RANGE(mt6885_pin_ies_range),
	[PINCTRL_PIN_REG_PU] = MTK_RANGE(mt6885_pin_pu_range),
	[PINCTRL_PIN_REG_PD] = MTK_RANGE(mt6885_pin_pd_range),
	[PINCTRL_PIN_REG_DRV] = MTK_RANGE(mt6885_pin_drv_range),
	[PINCTRL_PIN_REG_PUPD] = MTK_RANGE(mt6885_pin_pupd_range),
	[PINCTRL_PIN_REG_R0] = MTK_RANGE(mt6885_pin_r0_range),
	[PINCTRL_PIN_REG_R1] = MTK_RANGE(mt6885_pin_r1_range),
	[PINCTRL_PIN_REG_DRV_EH] = MTK_RANGE(mt6885_pin_eh_range),
	[PINCTRL_PIN_REG_RSEL] = MTK_RANGE(mt6885_pin_rsel_range),
};

static const unsigned int mt6885_pull_type[] = {
	1 /* 0 */, 1 /* 1 */, 1 /* 2 */, 1 /* 3 */, 1 /* 4 */,
	1 /* 5 */, 1 /* 6 */, 1 /* 7 */, 1 /* 8 */, 1 /* 9 */,
	4 /* 10 */, 4 /* 11 */, 4 /* 12 */, 4 /* 13 */, 4 /* 14 */,
	4 /* 15 */, 1 /* 16 */, 1 /* 17 */, 1 /* 18 */, 1 /* 19 */,
	1 /* 20 */, 1 /* 21 */, 1 /* 22 */, 1 /* 23 */, 9 /* 24 */,
	9 /* 25 */, 1 /* 26 */, 1 /* 27 */, 1 /* 28 */, 1 /* 29 */,
	1 /* 30 */, 1 /* 31 */, 1 /* 32 */, 1 /* 33 */, 1 /* 34 */,
	1 /* 35 */, 1 /* 36 */, 1 /* 37 */, 1 /* 38 */, 1 /* 39 */,
	1 /* 40 */, 1 /* 41 */, 1 /* 42 */, 1 /* 43 */, 1 /* 44 */,
	4 /* 45 */, 4 /* 46 */, 4 /* 47 */, 4 /* 48 */, 4 /* 49 */,
	4 /* 50 */, 4 /* 51 */, 4 /* 52 */, 4 /* 53 */, 4 /* 54 */,
	4 /* 55 */, 4 /* 56 */, 1 /* 57 */, 1 /* 58 */, 1 /* 59 */,
	1 /* 60 */, 1 /* 61 */, 1 /* 62 */, 1 /* 63 */, 1 /* 64 */,
	1 /* 65 */, 1 /* 66 */, 1 /* 67 */, 1 /* 68 */, 1 /* 69 */,
	1 /* 70 */, 1 /* 71 */, 1 /* 72 */, 1 /* 73 */, 1 /* 74 */,
	1 /* 75 */, 1 /* 76 */, 1 /* 77 */, 1 /* 78 */, 1 /* 79 */,
	1 /* 80 */, 1 /* 81 */, 1 /* 82 */, 1 /* 83 */, 1 /* 84 */,
	1 /* 85 */, 1 /* 86 */, 1 /* 87 */, 1 /* 88 */, 1 /* 89 */,
	1 /* 90 */, 1 /* 91 */, 1 /* 92 */, 1 /* 93 */, 1 /* 94 */,
	1 /* 95 */, 1 /* 96 */, 1 /* 97 */, 1 /* 98 */, 1 /* 99 */,
	1 /* 100 */, 1 /* 101 */, 1 /* 102 */, 1 /* 103 */, 1 /* 104 */,
	1 /* 105 */, 1 /* 106 */, 1 /* 107 */, 1 /* 108 */, 1 /* 109 */,
	1 /* 110 */, 1 /* 111 */, 1 /* 112 */, 1 /* 113 */, 1 /* 114 */,
	1 /* 115 */, 1 /* 116 */, 1 /* 117 */, 9 /* 118 */, 9 /* 119 */,
	9 /* 120 */, 9 /* 121 */, 9 /* 122 */, 9 /* 123 */, 9 /* 124 */,
	9 /* 125 */, 1 /* 126 */, 1 /* 127 */, 1 /* 128 */, 1 /* 129 */,
	1 /* 130 */, 1 /* 131 */, 1 /* 132 */, 1 /* 133 */, 1 /* 134 */,
	1 /* 135 */, 1 /* 136 */, 1 /* 137 */, 1 /* 138 */, 1 /* 139 */,
	9 /* 140 */, 9 /* 141 */, 9 /* 142 */, 1 /* 143 */, 1 /* 144 */,
	1 /* 145 */, 1 /* 146 */, 1 /* 147 */, 1 /* 148 */, 1 /* 149 */,
	1 /* 150 */, 1 /* 151 */, 4 /* 152 */, 4 /* 153 */, 4 /* 154 */,
	4 /* 155 */, 1 /* 156 */, 1 /* 157 */, 1 /* 158 */, 1 /* 159 */,
	9 /* 160 */, 9 /* 161 */, 1 /* 162 */, 1 /* 163 */, 1 /* 164 */,
	1 /* 165 */, 1 /* 166 */, 1 /* 167 */, 1 /* 168 */, 1 /* 169 */,
	1 /* 170 */, 1 /* 171 */, 1 /* 172 */, 1 /* 173 */, 1 /* 174 */,
	1 /* 175 */, 1 /* 176 */, 1 /* 177 */, 1 /* 178 */, 1 /* 179 */,
	1 /* 180 */, 1 /* 181 */, 1 /* 182 */, 4 /* 183 */, 4 /* 184 */,
	4 /* 185 */, 4 /* 186 */, 4 /* 187 */, 4 /* 188 */, 4 /* 189 */,
	4 /* 190 */, 4 /* 191 */, 4 /* 192 */, 4 /* 193 */, 4 /* 194 */,
	1 /* 195 */, 1 /* 196 */, 1 /* 197 */, 1 /* 198 */, 1 /* 199 */,
	9 /* 200 */, 9 /* 201 */, 9 /* 202 */, 9 /* 203 */, 9 /* 204 */,
	9 /* 205 */, 1 /* 206 */, 1 /* 207 */, 1 /* 208 */, 1 /* 209 */,
	1 /* 210 */, 1 /* 211 */, 1 /* 212 */, 1 /* 213 */, 1 /* 214 */,
	1 /* 215 */, 1 /* 216 */, 1 /* 217 */, 1 /* 218 */, 1 /* 219 */,
};

static const struct mtk_eh_pin_pinmux mt6885_eh_pin_pinmux_list[] = {
	/* pin number, pinmux number */
	{24, 6},
	{25, 6},
	{89, 2},
	{90, 2},
	{118, 1},
	{119, 1},
	{120, 1},
	{121, 1},
	{122, 1},
	{123, 1},
	{124, 1},
	{125, 1},
	{139, 1},
	{140, 1},
	{141, 1},
	{142, 1},
	{160, 1},
	{161, 1},
	{200, 1},
	{201, 1},
	{202, 1},
	{203, 1},
	{204, 1},
	{205, 1},
};

static const struct mtk_pin_soc mt6885_data = {
	.reg_cal = mt6885_reg_cals,
	.pins = mtk_pins_mt6885,
	.npins = ARRAY_SIZE(mtk_pins_mt6885),
	.ngrps = ARRAY_SIZE(mtk_pins_mt6885),
	.nfuncs = 8,
	.gpio_m = 0,
	.capability_flags = FLAG_RACE_FREE_ACCESS
				| FLAG_DRIVE_SET_RAW,
	.pull_type = mt6885_pull_type,
	.eh_pin_pinmux = mt6885_eh_pin_pinmux_list,
	.neh_pins = ARRAY_SIZE(mt6885_eh_pin_pinmux_list),
	.bias_set_combo = mtk_pinconf_bias_set_combo,
	.bias_get_combo = mtk_pinconf_bias_get_combo,
	.adv_drive_get = mtk_pinconf_adv_drive_get,
	.adv_drive_set = mtk_pinconf_adv_drive_set,
};

static const struct of_device_id mt6885_pinctrl_of_match[] = {
	{ .compatible = "mediatek,mt6885-pinctrl", },
	{ }
};

static int mt6885_pinctrl_probe(struct platform_device *pdev)
{
	return mtk_paris_pinctrl_probe(pdev, &mt6885_data);
}

static struct platform_driver mt6885_pinctrl_driver = {
	.driver = {
		.name = "mt6885-pinctrl",
		.of_match_table = mt6885_pinctrl_of_match,
		.pm = &mtk_paris_pinctrl_pm_ops,
	},
	.probe = mt6885_pinctrl_probe,
};

static int __init mt6885_pinctrl_init(void)
{
	return platform_driver_register(&mt6885_pinctrl_driver);
}
arch_initcall(mt6885_pinctrl_init);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("MediaTek MT6885 Pinctrl Driver");
