#define GDISP_LLD_PIXELFORMAT GDISP_PIXELFORMAT_MONO
#define LLDCOLOR_TYPE gU8
#ifdef GDISP_DRIVER_VMT

#include "ugfx/src/gdisp/gdisp.h"
#include "ugfx/src/gdisp/gdisp_colors.h"
#include "ugfx/src/gdisp/gdisp_driver.h"


extern void BoardInitShim(int *width, int *height, int color_size,
                          uint8_t **framebuffer, int *line_length);

static void board_init(GDisplay *g, fbInfo *fbi) {
  int width, height;
  uint8_t *framebuffer;
  int line_length;
  BoardInitShim(&width, &height, sizeof(LLDCOLOR_TYPE), &framebuffer,
                &line_length);
  g->g.Width = width;
  g->g.Height = height;
  g->g.Backlight = 100;
  g->g.Contrast = 50;
  fbi->linelen = line_length;
  fbi->pixels = framebuffer;
}

#if GDISP_HARDWARE_FLUSH
static void board_flush(GDisplay *g) {
  // TODO: Can be an empty function if your hardware doesn't support this
  (void)g;
}
#endif

#if GDISP_NEED_CONTROL
static void board_backlight(GDisplay *g, gU8 percent) {
  // TODO: Can be an empty function if your hardware doesn't support this
  (void)g;
  (void)percent;
}

static void board_contrast(GDisplay *g, gU8 percent) {
  // TODO: Can be an empty function if your hardware doesn't support this
  (void)g;
  (void)percent;
}

static void board_power(GDisplay *g, gPowermode pwr) {
  // TODO: Can be an empty function if your hardware doesn't support this
  (void)g;
  (void)pwr;
}
#endif

#endif
