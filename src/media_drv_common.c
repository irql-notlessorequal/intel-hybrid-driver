/*
 * Copyright (C) 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    Midhunchandra Kodiyath <midhunchandra.kodiyath@intel.com>
 *
 */
#include "media_drv_defines.h"
const UINT SEARCH_PATH_TABLE[2][8][16] = {
	// I-Frame & P-Frame
	{
		// MEMethod: 0
		{
			0x120FF10F, 0x1E22E20D, 0x20E2FF10, 0x2EDD06FC, 0x11D33FF1, 0xEB1FF33D,
			0x4EF1F1F1, 0xF1F21211,
			0x0DFFFFE0, 0x11201F1F, 0x1105F1CF, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		},
		// MEMethod: 1
		{
			0x120FF10F, 0x1E22E20D, 0x20E2FF10, 0x2EDD06FC, 0x11D33FF1, 0xEB1FF33D,
			0x4EF1F1F1, 0xF1F21211,
			0x0DFFFFE0, 0x11201F1F, 0x1105F1CF, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		},
		// MEMethod: 2
		{
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		},
		// MEMethod: 3
		{
			0x01010101, 0x11010101, 0x01010101, 0x11010101, 0x01010101, 0x11010101,
			0x01010101, 0x11010101,
			0x01010101, 0x11010101, 0x01010101, 0x00010101, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		},
		// MEMethod: 4
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000
		},
		// MEMethod: 5
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000
		},
		// MEMethod: 6
		{
			0x120FF10F, 0x1E22E20D, 0x20E2FF10, 0x2EDD06FC, 0x11D33FF1, 0xEB1FF33D,
			0x4EF1F1F1, 0xF1F21211,
			0x0DFFFFE0, 0x11201F1F, 0x1105F1CF, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		},
		// MEMethod: 7
		{
			0x1F11F10F, 0x2E22E2FE, 0x20E220DF, 0x2EDD06FC, 0x11D33FF1, 0xEB1FF33D,
			0x02F1F1F1, 0x1F201111,
			0xF1EFFF0C, 0xF01104F1, 0x10FF0A50, 0x000FF1C0, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		}
	},
	// B-Frame
	{
		// MEMethod: 0
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000},
		// MEMethod: 1
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000},
		// MEMethod: 2
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000},
		// MEMethod: 3
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000},
		// MEMethod: 4
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000},
		// MEMethod: 5
		{
			0x0101F00F, 0x0F0F1010, 0xF0F0F00F, 0x01010101, 0x10101010, 0x0F0F0F0F,
			0xF0F0F00F, 0x0101F0F0,
			0x01010101, 0x10101010, 0x0F0F1010, 0x0F0F0F0F, 0xF0F0F00F, 0xF0F0F0F0,
			0x00000000, 0x00000000},
		// MEMethod: 6
		{
			0x120FF10F, 0x1E22E20D, 0x20E2FF10, 0x2EDD06FC, 0x11D33FF1, 0xEB1FF33D,
			0x4EF1F1F1, 0xF1F21211,
			0x0DFFFFE0, 0x11201F1F, 0x1105F1CF, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000},
		// MEMethod: 7 used for mpeg2 encoding B frames
		{
			0x1F11F10F, 0x2E22E2FE, 0x20E220DF, 0x2EDD06FC, 0x11D33FF1, 0xEB1FF33D,
			0x02F1F1F1, 0x1F201111,
			0xF1EFFF0C, 0xF01104F1, 0x10FF0A50, 0x000FF1C0, 0x00000000, 0x00000000,
			0x00000000, 0x00000000
		}
	}
};

const UINT ME_CURBE_INIT_DATA[30] = {
	0x00000000, 0x00200010, 0x00003939, 0x77A41000, 0x00000000, 0x28300000,
	0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};
