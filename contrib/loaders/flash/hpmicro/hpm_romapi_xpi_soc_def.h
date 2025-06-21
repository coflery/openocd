/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2021 HPMicro
 */

#ifndef HPM_ROMAPI_XPI_SOC_DEF_H
#define HPM_ROMAPI_XPI_SOC_DEF_H

#include "hpm_common.h"
#include "hpm_romapi_xpi_def.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

#define XPI_CLK_OUT_FREQ_OPTION_30MHZ (1U)
#define XPI_CLK_OUT_FREQ_OPTION_50MHZ (2U)
#define XPI_CLK_OUT_FREQ_OPTION_66MHZ (3U)
#define XPI_CLK_OUT_FREQ_OPTION_80MHZ (4U)
#define XPI_CLK_OUT_FREQ_OPTION_104MHZ (5U)
#define XPI_CLK_OUT_FREQ_OPTION_120MHZ (6U)
#define XPI_CLK_OUT_FREQ_OPTION_133MHZ (7U)
#define XPI_CLK_OUT_FREQ_OPTION_166MHZ (8U)
#define XPI_CLK_OUT_FREQ_OPTION_200MHZ (9U)


typedef struct {
	uint8_t data_pads;
	xpi_channel_t channel;
	xpi_io_group_t io_group;
	uint8_t drive_strength;
	bool enable_dqs;
	bool enable_diff_clk;
} xpi_io_config_t;

typedef enum {
	xpi_freq_type_typical,
	xpi_freq_type_mhz,
} clk_freq_type_t;

typedef enum {
	xpi_clk_src_auto,
	xpi_clk_src_osc,
	xpi_clk_src_pll0clk0,
	xpi_clk_src_pll1clk0,
	xpi_clk_src_pll1clk1,
	xpi_clk_src_pll2clk0,
	xpi_clk_src_pll2clk1,
	xpi_clk_src_pll3clk0,
	xpi_clk_src_pll4clk0,
} xpi_clk_src_t;


typedef union {
	struct {
		uint8_t freq;
		bool enable_ddr;
		xpi_clk_src_t clk_src;
		clk_freq_type_t freq_type;
	};
	uint32_t freq_opt;
} xpi_clk_config_t;

typedef enum {
	xpi_clock_bus,
	xpi_clock_serial_root,
	xpi_clock_serial,
} xpi_clock_t;

#endif /* HPM_ROMAPI_XPI_SOC_DEF_H */
