/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_SCREEN_HOME_H_
#define RPIC_DESKTOP_INCLUDE_SCREEN_HOME_H_

#include <utility>
#include <vector>

#include "./input/home_ctl.h"
#include "./config/conf_parser.h"
#include "./screen/screen_digits.h"
#include "./screen/screen_interface.h"
#include "./screen/elements/menu_button.h"

namespace Screen {

class Home : public ScreenInterface {
public:
  Home();
  ~Home();
  Screen::Digits Run(sf::RenderWindow &window);
  void LoadResources(){};
  void MoveUp();
  void MoveDown();
  std::size_t CurrentChoice() const { return current_choise_; }

private:
  void InitMenuText_();
  void UpdateMenuText_();
  ::Config::ConfParser *config_;
  std::vector<Screen::Element::MenuButton> menu_text_;
  int text_size_;
  std::size_t current_choise_;
  ::Input::HomeCtl input_ctl_;
};

} // namespace Screen

#endif // RPIC_DESKTOP_INCLUDE_SCREEN_HOME_H_
