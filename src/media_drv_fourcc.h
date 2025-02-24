#include <stdint.h>

#include <drm_fourcc.h>
#include <va/va.h>

#define SUBSAMPLE_YUV400 0
#define SUBSAMPLE_YUV420 1
#define SUBSAMPLE_YUV422H 2
#define SUBSAMPLE_YUV422V 3
#define SUBSAMPLE_YUV444 4
#define SUBSAMPLE_YUV411 5
#define SUBSAMPLE_RGBX 6

#define I965_MAX_PLANES 4
#define I965_MAX_COMPONENTS 4

#define I965_COLOR_YUV 0
#define I965_COLOR_RGB 1
#define I965_COLOR_INDEX 2

typedef struct
{
	uint8_t plane;	/* the plane which the pixel belongs to */
	uint8_t offset; /* bits offset within a macro-pixel for packed YUV formats or pixel for other formats in the plane */
} __attribute__((packed)) i965_component_info;

typedef struct
{
	uint32_t fourcc;			  /* fourcc */
	uint32_t format;			  /* 0: YUV, 1: RGB, 2: Indexed format */
	uint32_t subsampling;		  /* Sub sampling */
	uint8_t flag;				  /* 1: only supported by vaCreateSurfaces(), 2: only supported by vaCreateImage(), 3: both */
	uint8_t hfactor;			  /* horizontal sampling factor */
	uint8_t vfactor;			  /* vertical sampling factor */
	uint8_t num_planes;			  /* number of planes */
	uint8_t bpp[I965_MAX_PLANES]; /* bits per pixel within a plane */
	uint8_t num_components;		  /* number of components */
	/*
	 * Components in the array are ordered in Y, U, V, A (up to 4 components)
	 * for YUV formats, R, G, B, A (up to 4 components) for RGB formats and
	 * I, A (2 components) for indexed formats
	 */
	i965_component_info components[I965_MAX_COMPONENTS];
} __attribute__((packed)) i965_fourcc_info;

#define I965_BIT 1
#define I965_2BITS (I965_BIT << 1)
#define I965_4BITS (I965_BIT << 2)
#define I965_8BITS (I965_BIT << 3)
#define I965_16BITS (I965_BIT << 4)
#define I965_32BITS (I965_BIT << 5)

#define PLANE_0 0
#define PLANE_1 1
#define PLANE_2 2

#define OFFSET_0 0
#define OFFSET_4 4
#define OFFSET_8 8
#define OFFSET_16 16
#define OFFSET_24 24

/* hfactor, vfactor, num_planes, bpp[], num_components, components[] */
#define I_NV12                                                          \
	2, 2, 2, {I965_8BITS, I965_4BITS}, 3,                               \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_1, OFFSET_8 } \
	}
#define I_I420                                                          \
	2, 2, 3, {I965_8BITS, I965_2BITS, I965_2BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_2, OFFSET_0 } \
	}
#define I_IYUV I_I420
#define I_IMC3 I_I420
#define I_YV12                                                          \
	2, 2, 3, {I965_8BITS, I965_2BITS, I965_2BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_2, OFFSET_0}, { PLANE_1, OFFSET_0 } \
	}
#define I_IMC1 I_YV12

#define I_P010                                                           \
	2, 2, 2, {I965_16BITS, I965_8BITS}, 3,                               \
	{                                                                    \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_1, OFFSET_16 } \
	}

#define I_I010                                                          \
	2, 2, 3, {I965_16BITS, I965_4BITS, I965_4BITS}, 3,                  \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_2, OFFSET_0 } \
	}

#define I_422H                                                          \
	2, 1, 3, {I965_8BITS, I965_4BITS, I965_4BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_2, OFFSET_0 } \
	}
#define I_422V                                                          \
	1, 2, 3, {I965_8BITS, I965_4BITS, I965_4BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_2, OFFSET_0 } \
	}
#define I_YV16                                                          \
	2, 1, 3, {I965_8BITS, I965_4BITS, I965_4BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_2, OFFSET_0}, { PLANE_1, OFFSET_0 } \
	}
#define I_YUY2                                                           \
	2, 1, 1, {I965_16BITS}, 3,                                           \
	{                                                                    \
		{PLANE_0, OFFSET_0}, {PLANE_0, OFFSET_8}, { PLANE_0, OFFSET_24 } \
	}
#define I_UYVY                                                           \
	2, 1, 1, {I965_16BITS}, 3,                                           \
	{                                                                    \
		{PLANE_0, OFFSET_8}, {PLANE_0, OFFSET_0}, { PLANE_0, OFFSET_16 } \
	}

#define I_444P                                                          \
	1, 1, 3, {I965_8BITS, I965_8BITS, I965_8BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_2, OFFSET_0 } \
	}

#define I_411P                                                          \
	4, 1, 3, {I965_8BITS, I965_2BITS, I965_2BITS}, 3,                   \
	{                                                                   \
		{PLANE_0, OFFSET_0}, {PLANE_1, OFFSET_0}, { PLANE_2, OFFSET_0 } \
	}

#define I_Y800                \
	1, 1, 1, {I965_8BITS}, 1, \
	{                         \
		{                     \
			PLANE_0, OFFSET_0 \
		}                     \
	}

#define I_RGBA                                                                                 \
	1, 1, 1, {I965_32BITS}, 4,                                                                 \
	{                                                                                          \
		{PLANE_0, OFFSET_0}, {PLANE_0, OFFSET_8}, {PLANE_0, OFFSET_16}, { PLANE_0, OFFSET_24 } \
	}
#define I_RGBX                                                           \
	1, 1, 1, {I965_32BITS}, 3,                                           \
	{                                                                    \
		{PLANE_0, OFFSET_0}, {PLANE_0, OFFSET_8}, { PLANE_0, OFFSET_16 } \
	}
#define I_BGRA                                                                                 \
	1, 1, 1, {I965_32BITS}, 4,                                                                 \
	{                                                                                          \
		{PLANE_0, OFFSET_16}, {PLANE_0, OFFSET_8}, {PLANE_0, OFFSET_0}, { PLANE_0, OFFSET_24 } \
	}
#define I_BGRX                                                           \
	1, 1, 1, {I965_32BITS}, 3,                                           \
	{                                                                    \
		{PLANE_0, OFFSET_16}, {PLANE_0, OFFSET_8}, { PLANE_0, OFFSET_0 } \
	}

#define I_ARGB                                                                                 \
	1, 1, 1, {I965_32BITS}, 4,                                                                 \
	{                                                                                          \
		{PLANE_0, OFFSET_8}, {PLANE_0, OFFSET_16}, {PLANE_0, OFFSET_24}, { PLANE_0, OFFSET_0 } \
	}
#define I_ABGR                                                                                 \
	1, 1, 1, {I965_32BITS}, 4,                                                                 \
	{                                                                                          \
		{PLANE_0, OFFSET_24}, {PLANE_0, OFFSET_16}, {PLANE_0, OFFSET_8}, { PLANE_0, OFFSET_0 } \
	}

#define I_IA88                                     \
	1, 1, 1, {I965_16BITS}, 2,                     \
	{                                              \
		{PLANE_0, OFFSET_0}, { PLANE_0, OFFSET_8 } \
	}
#define I_AI88                                     \
	1, 1, 1, {I965_16BITS}, 2,                     \
	{                                              \
		{PLANE_0, OFFSET_8}, { PLANE_0, OFFSET_0 } \
	}

#define I_IA44                                     \
	1, 1, 1, {I965_8BITS}, 2,                      \
	{                                              \
		{PLANE_0, OFFSET_0}, { PLANE_0, OFFSET_4 } \
	}
#define I_AI44                                     \
	1, 1, 1, {I965_8BITS}, 2,                      \
	{                                              \
		{PLANE_0, OFFSET_4}, { PLANE_0, OFFSET_0 } \
	}

/* flag */
#define I_S 1
#define I_I 2
#define I_SI (I_S | I_I)

#define DEF_FOUCC_INFO(FOURCC, FORMAT, SUB, FLAG) {VA_FOURCC_##FOURCC, I965_COLOR_##FORMAT, SUBSAMPLE_##SUB, FLAG, I_##FOURCC}
#define DEF_YUV(FOURCC, SUB, FLAG) DEF_FOUCC_INFO(FOURCC, YUV, SUB, FLAG)
#define DEF_RGB(FOURCC, SUB, FLAG) DEF_FOUCC_INFO(FOURCC, RGB, SUB, FLAG)
#define DEF_INDEX(FOURCC, SUB, FLAG) DEF_FOUCC_INFO(FOURCC, INDEX, SUB, FLAG)

static const i965_fourcc_info i965_fourcc_infos[] = {
	DEF_YUV(NV12, YUV420, I_SI),

	DEF_RGB(RGBA, RGBX, I_SI),
	DEF_RGB(RGBX, RGBX, I_SI),
	DEF_RGB(BGRA, RGBX, I_SI),
	DEF_RGB(BGRX, RGBX, I_SI),

	DEF_RGB(ARGB, RGBX, I_I),
	DEF_RGB(ABGR, RGBX, I_I),
};

const i965_fourcc_info *get_fourcc_info(unsigned int fourcc)
{
	unsigned int i;

	for (i = 0; i < ARRAY_ELEMS(i965_fourcc_infos); i++)
	{
		const i965_fourcc_info *const info = &i965_fourcc_infos[i];

		if (info->fourcc == fourcc)
			return info;
	}

	return NULL;
}

static uint32_t drm_format_of_separate_plane(uint32_t fourcc, int plane)
{
	if (plane == 0)
	{
		switch (fourcc)
		{
		case VA_FOURCC_NV12:
		case VA_FOURCC_I420:
		case VA_FOURCC_IMC3:
		case VA_FOURCC_YV12:
		case VA_FOURCC_YV16:
		case VA_FOURCC_Y800:
			return DRM_FORMAT_R8;
		case VA_FOURCC_P010:
		case VA_FOURCC_I010:
			return DRM_FORMAT_R16;

		case VA_FOURCC_YUY2:
		case VA_FOURCC_UYVY:
			// These are not representable as separate planes.
			return 0;

		case VA_FOURCC_RGBA:
			return DRM_FORMAT_ABGR8888;
		case VA_FOURCC_RGBX:
			return DRM_FORMAT_XBGR8888;
		case VA_FOURCC_BGRA:
			return DRM_FORMAT_ARGB8888;
		case VA_FOURCC_BGRX:
			return DRM_FORMAT_XRGB8888;
		case VA_FOURCC_ARGB:
			return DRM_FORMAT_BGRA8888;
		case VA_FOURCC_ABGR:
			return DRM_FORMAT_RGBA8888;
		}
	}
	else
	{
		switch (fourcc)
		{
		case VA_FOURCC_NV12:
			return DRM_FORMAT_GR88;
		case VA_FOURCC_I420:
		case VA_FOURCC_IMC3:
		case VA_FOURCC_YV12:
		case VA_FOURCC_YV16:
			return DRM_FORMAT_R8;
		case VA_FOURCC_P010:
			return DRM_FORMAT_GR1616;
		case VA_FOURCC_I010:
			return DRM_FORMAT_R16;
		}
	}
	return 0;
}

static uint32_t drm_format_of_composite_object(uint32_t fourcc)
{
	switch (fourcc)
	{
	case VA_FOURCC_NV12:
		return DRM_FORMAT_NV12;
	case VA_FOURCC_I420:
		return DRM_FORMAT_YUV420;
	case VA_FOURCC_YV12:
		return DRM_FORMAT_YVU420;
	case VA_FOURCC_YV16:
		return DRM_FORMAT_YVU422;
	case VA_FOURCC_YUY2:
		return DRM_FORMAT_YUYV;
	case VA_FOURCC_UYVY:
		return DRM_FORMAT_UYVY;
	case VA_FOURCC_Y800:
		return DRM_FORMAT_R8;

	case VA_FOURCC_P010:
	case VA_FOURCC_I010:
		// These currently have no composite DRM format - they are usable
		// only as separate planes.
		return 0;

	case VA_FOURCC_RGBA:
		return DRM_FORMAT_ABGR8888;
	case VA_FOURCC_RGBX:
		return DRM_FORMAT_XBGR8888;
	case VA_FOURCC_BGRA:
		return DRM_FORMAT_ARGB8888;
	case VA_FOURCC_BGRX:
		return DRM_FORMAT_XRGB8888;
	case VA_FOURCC_ARGB:
		return DRM_FORMAT_BGRA8888;
	case VA_FOURCC_ABGR:
		return DRM_FORMAT_RGBA8888;
	}
	return 0;
}