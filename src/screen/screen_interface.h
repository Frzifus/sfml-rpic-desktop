/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_SCREEN_SCREENINTERFACE_H_
#define RPIC_DESKTOP_INCLUDE_SCREEN_SCREENINTERFACE_H_

#include "./screen/screen_digits.h"
#include "./resources/global.h"

namespace Screen {
class ScreenInterface {
public:
  static ::Resources::Global *global_res;
  static ::Screen::Digits next_screen;
  virtual Screen::Digits Run(sf::RenderWindow &window) = 0;
  virtual void LoadResources() = 0;
};
} // Screen

#endif // RPIC_DESKTOP_INCLUDE_SCREEN_SCREENINTERFACE_H_
