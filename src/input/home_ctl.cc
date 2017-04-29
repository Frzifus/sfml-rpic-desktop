/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./input/home_ctl.h"
#include "./screen/home.h"
#include "./screen/screen_digits.h"

Input::HomeCtl::HomeCtl(::Screen::Home *home_instance) {
  home_instance_ = home_instance;
}

void Input::HomeCtl::Check(sf::RenderWindow &window) {
  if (window.pollEvent(event_)) {
    // Close window: exit
    if (event_.type == sf::Event::Closed) {
      home_instance_->next_screen = ::Screen::Digits::CLOSE;
    }
    CheckKeyboardInput_();
  }
}

void Input::HomeCtl::CheckKeyboardInput_() {
  if (event_.type == sf::Event::KeyPressed) {
    if (event_.key.code == sf::Keyboard::Escape) {
      home_instance_->next_screen = ::Screen::Digits::CLOSE;
    } else if (event_.key.code == sf::Keyboard::Up) {
      home_instance_->MoveUp();
    } else if (event_.key.code == sf::Keyboard::Down) {
      home_instance_->MoveDown();
    } else if (event_.key.code == sf::Keyboard::Return) {
      CheckScreenChoice_();
    }
  }
}

void Input::HomeCtl::CheckGamepadInput_() {}

void Input::HomeCtl::CheckScreenChoice_() {
  if (home_instance_->CurrentChoice() == 0) {
    home_instance_->next_screen = ::Screen::Digits::PLAYGROUND_SCREEN;
  } else if (home_instance_->CurrentChoice() == 1) {
    home_instance_->next_screen = ::Screen::Digits::CONFIG_SCREEN;
  } else if (home_instance_->CurrentChoice() == 2) {
    home_instance_->next_screen = ::Screen::Digits::CLOSE;
  }
}
