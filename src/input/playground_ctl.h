/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_INPUT_PLAYGROUNDCTL_H_
#define RPIC_DESKTOP_INCLUDE_INPUT_PLAYGROUNDCTL_H_

#include <memory>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "./network/client.h"
#include "./network/sender.h"

namespace Screen {
// forward declaration
class Playground;
} // namespace Screen

namespace Input {

class PlaygroundCtl {
public:
  explicit PlaygroundCtl(Screen::Playground *config_tnstance);
  void Check(sf::RenderWindow &window);
  void Connect(std::string target, unsigned short port);

private:
  void CheckCameraKeys_(bool pressed = true);
  void CheckMovementKeys_(bool pressed = true);
  // Process events
  sf::Event event_;
  ::Screen::Playground *playground_instance_;
  // TODO: Move Client to playgroundInstance
  ::Network::Sender sender_;
  std::unique_ptr<::Network::Client> client_;
};

} // namespace Input

#endif // RPIC_DESKTOP_INCLUDE_INPUT_PLAYGROUNDCTL_H_
