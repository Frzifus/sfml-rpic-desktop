/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_SCREEN_CONFIG_H_
#define RPIC_DESKTOP_INCLUDE_SCREEN_CONFIG_H_

#include "./config/conf_parser.h"
#include "./input/config_ctl.h"
#include "./screen/screen_digits.h"
#include "./screen/screen_interface.h"

namespace Screen {

class Config : public ScreenInterface {
public:
  Config();
  ~Config();
  Screen::Digits Run(sf::RenderWindow &window);
  void LoadResources(){};
  bool SaveConfig();
  void MoveUp();
  void MoveDown();
  void MoveRight();
  void MoveLeft();

private:
  ::Config::ConfParser *config_;
  ::Input::ConfigCtl inputCtl_;
};

} // namespace Screen

#endif // ! RPIC_DESKTOP_INCLUDE_SCREEN_CONFIG_H_
