/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2022 MediaTek Inc.
 */

#ifndef __MDP_BASE_H__
#define __MDP_BASE_H__

#define MDP_HW_CHECK

static phys_addr_t mdp_base[ENGBASE_COUNT] = {
	[ENGBASE_MMSYS_CONFIG] = 0x1f000000,
	[ENGBASE_MDP_RDMA0] = 0x1f003000,
	[ENGBASE_MDP_AAL0] = 0x1f005000,
	[ENGBASE_MDP_HDR0] = 0x1f007000,
	[ENGBASE_MDP_RSZ0] = 0x1f008000,
	[ENGBASE_MDP_RSZ1] = 0x1f009000,
	[ENGBASE_MDP_WROT0] = 0x1f00a000,
	[ENGBASE_MDP_WROT1] = 0x1f00b000,
	[ENGBASE_MDP_TDSHP0] = 0x1f00c000,
	[ENGBASE_MMSYS_MUTEX] = 0x1f001000,
	[ENGBASE_IMGSYS] = 0x15020000,
	[ENGBASE_IMGSYS2_CONFIG] = 0x15820000,
	[ENGBASE_ISP_DIP_A0] = 0x15021000,
	[ENGBASE_ISP_DIP_A1] = 0x15022000,
	[ENGBASE_ISP_DIP_A7] = 0x15028000,
	[ENGBASE_ISP_MSS_B] = 0x15812000,
	[ENGBASE_ISP_MFB_B] = 0x15810000,
};

#endif
