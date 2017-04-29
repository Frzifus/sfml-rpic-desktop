/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./input/config_ctl.h"
#include "./screen/config.h"
#include "./screen/screen_digits.h"

Input::ConfigCtl::ConfigCtl(::Screen::Config *config_instance) {
  config_instance_ = config_instance;
}

void Input::ConfigCtl::Check(sf::RenderWindow &window) {
  if (window.pollEvent(event_)) {
    // Close window: exit
    if (event_.type == sf::Event::Closed) {
      config_instance_->next_screen = ::Screen::Digits::CLOSE;
    }
    CheckKeyboardInput_();
  }
}

void Input::ConfigCtl::CheckGamepadInput_() {}

void Input::ConfigCtl::CheckKeyboardInput_() {
  if (event_.type == sf::Event::KeyPressed) {
    if (event_.key.code == sf::Keyboard::Escape) {
      config_instance_->next_screen = ::Screen::Digits::HOME_SCREEN;
    } else if (event_.key.code == sf::Keyboard::Up) {
      config_instance_->MoveUp();
    } else if (event_.key.code == sf::Keyboard::Down) {
      config_instance_->MoveDown();
    } else if (event_.key.code == sf::Keyboard::Return) {
      config_instance_->SaveConfig();
      config_instance_->next_screen = ::Screen::Digits::HOME_SCREEN;
    }
  }
}
