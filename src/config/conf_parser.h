/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_CONFIG_CONFPARSER_H_
#define RPIC_DESKTOP_INCLUDE_CONFIG_CONFPARSER_H_

#include <array>
#include <memory>
#include <string>

namespace Config {

enum Resolution { Width, Height };

class ConfParser {
public:
  ConfParser();

  bool LoadConfig();

  void SaveConfig();

  std::array<unsigned int, 2> Resolution() const { return resolution_; }
  unsigned int ResolutionWidth() const { return resolution_[Width]; }
  unsigned int ResolutionHeight() const { return resolution_[Height]; }
  unsigned int FrameLimit() const { return frameLimit_; }
  bool MouseCursorVisable() const { return mouse_cursor_visable_; }
  bool VSync() const { return v_sync_; }
  std::string Ip() const { return ip_; }
  unsigned short Port() const { return port_; }
  bool isComplete() const { return is_complete_; }

  void set_Resolution(const unsigned int width, const unsigned int height) {
    resolution_[Width] = width;
    resolution_[Height] = height;
  }
  void set_Resolution(std::array<unsigned int, 2> resolution) {
    resolution_ = resolution;
  }
  void set_FrameLimit(unsigned int frameLimit) { frameLimit_ = frameLimit; }
  void set_MouseCursorVisable_(bool mouse_cursor_visable) {
    mouse_cursor_visable_ = mouse_cursor_visable;
  }
  void set_VSync(bool v_sync) { v_sync_ = v_sync; }
  void set_Ip(std::string ip) { ip_ = ip; }
  void set_Port(unsigned short port) { port_ = port; }

private:
  std::array<unsigned int, 2> resolution_;
  unsigned int frameLimit_;
  bool is_complete_;
  bool mouse_cursor_visable_;
  bool v_sync_;
  std::string ip_;
  unsigned short port_;
};

} // namespace Config

#endif // RPIC_DESKTOP_INCLUDE_CONFIG_CONFPARSER_H_
