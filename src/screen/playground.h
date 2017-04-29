/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_SCREEN_PLAYGROUND_H_
#define RPIC_DESKTOP_INCLUDE_SCREEN_PLAYGROUND_H_

#include "./input/playground_ctl.h"
#include "./screen/screen_digits.h"
#include "./screen/screen_interface.h"

#include <memory>

#include "./network/ctl_message.pb.h"

namespace Screen {

class Playground : public ScreenInterface {
public:
  Playground();
  Screen::Digits Run(sf::RenderWindow &window);
  void LoadResources(){};

  // void InitConnection();
  // void CloseConnection();

private:
  ::Config::ConfParser *config_;
  std::unique_ptr<::Input::PlaygroundCtl> input_ctl_;
};
} // namespace Screen

#endif // RPIC_DESKTOP_INCLUDE_SCREEN_PLAYGROUND_H_
