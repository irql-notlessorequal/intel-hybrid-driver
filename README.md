# Intel Hybrid VA-API driver.

This is the optional extension to the main legacy Intel VA-API driver.

I don't plan to put much effort into this driver as it is fairly buggy and prone to hanging your GPU.

Expect minimal support with issues!

## Supported Codecs

| Platform | VP8 [1] | VP9 | HEVC 8bit [3] | HEVC 10bit [3] |
|----------|---------|-----|---------------|----------------|
| IVB      | ✔       | ❌   | TODO          | TODO           |
| HSW      | ✔       | ✔   | TODO          | TODO           |
| CHV      | ❌ [4]   | ✔   | ❌ [4]         | TODO           |
| BDW      | ❌ [2]   | ✔   | TODO          | TODO           |
| SKL      | ❌ [4]   | ✔   | ❌ [4]          | TODO           |

[1]: Encoding support only.

[2]: Disabled by default, available with build time option `--enable-bdw-vp8-enc`

[3]: Planned software-based (OpenHEVC) implementation.

[4]: Supported natively by the [main driver](https://github.com/irql-notlessorequal/intel-vaapi-driver).

## Known issues.

### Segmentation fault with VP9 decoding on Haswell GT1.5 GPUs

The following CPUs require a patched version of libcmrt in order to have functioning hybrid VP9 decoding:

- Intel(R) Core(TM) i3-4130
- Intel(R) Core(TM) i3-4130T
- Intel(R) Core(TM) i3-4150
- Intel(R) Core(TM) i3-4150T
- Intel(R) Core(TM) i3-4160
- Intel(R) Core(TM) i3-4160T
- Intel(R) Core(TM) i3-4170
- Intel(R) Core(TM) i3-4170T

The patch is available here: https://github.com/irql-notlessorequal/cmrt/tree/fix-hsw-gt1-fused