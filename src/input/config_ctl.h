/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_INPUT_CONFIGCTL_H_
#define RPIC_DESKTOP_INCLUDE_INPUT_CONFIGCTL_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Screen {
// forward declaration
class Config;
} // namespace Screen

namespace Input {

class ConfigCtl {
public:
  explicit ConfigCtl(Screen::Config *config_instance);
  void Check(sf::RenderWindow &window);

private:
  void CheckKeyboardInput_();
  void CheckGamepadInput_();
  // Process events
  sf::Event event_;
  ::Screen::Config *config_instance_;
};

} // namespace Input

#endif // RPIC_DESKTOP_INCLUDE_INPUT_CONFIGCTL_H_
