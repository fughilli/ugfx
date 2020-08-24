#include "ugfx/boards/base/framebuffer_cpp_shim/ugfx_framebuffer.h"

namespace ugfx {
namespace {
std::shared_ptr<UgfxFramebuffer> global_framebuffer;
} // namespace

void RegisterUgfxFramebuffer(std::shared_ptr<UgfxFramebuffer> framebuffer) {
  global_framebuffer = std::move(framebuffer);
}

void UgfxFramebuffer::InitCallback(int *width, int *height, int color_size,
                                   uint8_t **framebuffer, int *line_length) {
  *width = width_;
  *height = height_;
  *framebuffer = framebuffer_.data();
  *line_length = width_ * color_size;
}

bool UgfxFramebuffer::CopyByPixels(
    std::function<bool(int, int)> set_pixel_function) {
  for (int j = 0; j < height_; ++j) {
    for (int i = 0; i < width_; ++i) {
      if (framebuffer_[j * width_ + i]) {
        if (!set_pixel_function(i, j)) {
          return false;
        }
      }
    }
  }
  return true;
}

extern "C" void BoardInitShim(int *width, int *height, int color_size,
                              uint8_t **framebuffer, int *line_length) {
  ugfx::global_framebuffer->InitCallback(width, height, color_size, framebuffer,
                                         line_length);
}

} // namespace ugfx
