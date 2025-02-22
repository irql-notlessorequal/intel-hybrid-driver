#ifndef SNA_CPUID_H
#define SNA_CPUID_H

#ifdef HAVE_CPUID_H
#include <cpuid.h>
#else
#define __get_cpuid_max(x, y) 0
#define __cpuid(level, a, b, c, d) a = b = c = d = 0
#define __cpuid_count(level, count, a, b, c, d) a = b = c = d = 0
#endif

#define BASIC_CPUID 0x0
#define EXTENDED_CPUID 0x80000000

#ifndef bit_MMX
#define bit_MMX		(1 << 23)
#endif

#ifndef bit_SSE
#define bit_SSE		(1 << 25)
#endif

#ifndef bit_SSE2
#define bit_SSE2	(1 << 26)
#endif

#ifndef bit_SSE3
#define bit_SSE3	(1 << 0)
#endif

#ifndef bit_SSSE3
#define bit_SSSE3	(1 << 9)
#endif

#ifndef bit_FMA3
#define bit_FMA3	(1 << 12)
#endif

#ifndef bit_SSE4_1
#define bit_SSE4_1	(1 << 19)
#endif

#ifndef bit_SSE4_2
#define bit_SSE4_2	(1 << 20)
#endif

#ifndef bit_OSXSAVE
#define bit_OSXSAVE	(1 << 27)
#endif

#ifndef bit_AVX
#define bit_AVX		(1 << 28)
#endif

#ifndef bit_AVX2
#define bit_AVX2	(1<<5)
#endif
#endif /* SNA_CPUID_H */

static unsigned int media_drv_cpu_detect(void);