/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_SCREEN_FORM_MENUBUTTON_H_
#define RPIC_DESKTOP_INCLUDE_SCREEN_FORM_MENUBUTTON_H_

#include <SFML/Graphics/Text.hpp>

namespace Screen {

namespace Element {

class MenuButton {
public:
  explicit MenuButton(std::string text, sf::Font &font)
      : sf_text(text, font, 50), is_visable_(true), is_selected_(false) {}

  sf::Text sf_text;

  void set_Visibility(bool visibility) { is_visable_ = visibility; }
  void set_Selected(bool is_selected) {
    is_selected_ = is_selected;
  }

  bool isVisable() const { return is_visable_; }
  bool isSelected() const { return is_selected_; }

private:
  bool is_visable_;
  bool is_selected_;
};

} // namespace Form
} // namespace Screen

#endif //  RPIC_DESKTOP_INCLUDE_SCREEN_FORM_MENUBUTTON_H_
