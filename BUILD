load(":variables.bzl", "UGFX_COPTS")

cc_library(
    name = "ugfx",
    srcs = glob(
        [
            "src/gdisp/*.c",
            "src/gdisp/mcufont/*.c",
            "src/gdriver/*.c",
        ],
        exclude = [
            "**/*_mk.c",
        ],
    ) + [
        "src/gos/gos_linux.c",
        "src/gfx.c",
        "drivers/gdisp/framebuffer/gdisp_lld_framebuffer.c",
        "boards/base/framebuffer_cpp_shim/ugfx_framebuffer.cc",
    ],
    hdrs = glob(
        [
            "src/gdisp/**/*.h",
            "src/gdisp/fonts/DejaVuSans*.c",
            "src/**/*_options.h",
            "src/**/*_rules.h",
        ],
        exclude = [
            "src/gdisp/**/*_aa.c",
        ],
    ) + [
        "gfx.h",
        "gfxconf.h",
        "src/gos/gos.h",
        "src/gos/gos_linux.h",
        "src/gfx.h",
        "src/gfx_compilers.h",
        "src/gfx_types.h",
        "src/gadc/gadc.h",
        "src/gaudio/gaudio.h",
        "src/gdriver/gdriver.h",
        "src/gevent/gevent.h",
        "src/gfile/gfile.h",
        "src/ginput/ginput.h",
        "src/gmisc/gmisc.h",
        "src/gqueue/gqueue.h",
        "src/gtimer/gtimer.h",
        "src/gtrans/gtrans.h",
        "src/gwin/gwin.h",
        "drivers/gdisp/framebuffer/gdisp_lld_config.h",
        "boards/base/framebuffer_cpp_shim/board_framebuffer.h",
        "boards/base/framebuffer_cpp_shim/ugfx_framebuffer.h",
    ],
    copts = UGFX_COPTS,
    linkopts = [
        "-lpthread",
    ],
    linkstatic = 1,
    visibility = ["//visibility:public"],
)
