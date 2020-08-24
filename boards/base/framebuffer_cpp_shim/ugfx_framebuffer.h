#ifndef UGFX_BOARDS_BASE_FRAMEBUFFER_CPP_SHIM_BOARD_FRAMEBUFFER_H_
#define UGFX_BOARDS_BASE_FRAMEBUFFER_CPP_SHIM_BOARD_FRAMEBUFFER_H_

#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

namespace ugfx {

class UgfxFramebuffer {
public:
  UgfxFramebuffer(int width, int height) : width_(width), height_(height) {
    framebuffer_.resize(width_ * height_);
  }
  virtual ~UgfxFramebuffer() {}

  virtual void InitCallback(int *width, int *height, int color_size,
                            uint8_t **framebuffer, int *line_length);

  bool CopyByPixels(std::function<bool(int,int)> set_pixel_function) ;

private:
  int width_;
  int height_;
  std::vector<uint8_t> framebuffer_;
};

void RegisterUgfxFramebuffer(std::shared_ptr<UgfxFramebuffer> framebuffer);

} // namespace ugfx

#endif
