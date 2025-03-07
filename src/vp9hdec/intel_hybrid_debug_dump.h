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
 *     Zhao Yakui <yakui.zhao@intel.com>
 *
 */

#ifndef _INTEL_HYBRID_DEBUG_DUMP_H_
#define _INTEL_HYBRID_DEBUG_DUMP_H_

#include "intel_hybrid_common_vp9.h"


#ifdef __cplusplus
extern "C" {
#endif

extern int intel_hybrid_writefilefromptr(
	const char             *pFilename,
	void                   *lpBuffer,
	uint32_t                  writeSize);

extern int intel_hybrid_appendfilefromptr(
	const char              *pFilename,
	void                    *pData,
	uint32_t                    dwSize);


extern char *intel_alloc_zero_aligned_memory(uint32_t size, uint32_t alignment);

#ifdef __cplusplus
}
#endif

#endif
