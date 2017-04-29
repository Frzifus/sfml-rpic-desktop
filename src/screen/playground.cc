/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./screen/playground.h"

#include <memory>

#include "./input/playground_ctl.h"
#include "./screen/screen_digits.h"

Screen::Playground::Playground() {
  input_ctl_ = std::make_unique<::Input::PlaygroundCtl>(this);
}

Screen::Digits Screen::Playground::Run(sf::RenderWindow &window) {
  config_ = global_res->Config();
  next_screen = Digits::NOTHIG_TO_DO;
  input_ctl_->Connect(config_->Ip(), config_->Port());
  while (true) {
    // Check for input
    input_ctl_->Check(window);
    // Clear Screen
    window.clear();
    global_res->DrawBackground(window);

    // Draw sprites

    // Update window
    window.display();

    if (next_screen != Digits::NOTHIG_TO_DO) {
      // CloseConnection();
      return next_screen;
    }
  }
}
