/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./screen/config.h"
#include "./input/config_ctl.h"

#include "./screen/screen_digits.h"

Screen::Config::Config() : inputCtl_(::Input::ConfigCtl(this)) {}

Screen::Config::~Config() {}

Screen::Digits Screen::Config::Run(sf::RenderWindow &window) {
  config_ = global_res->Config();
  // InitMenuText
  next_screen = Digits::NOTHIG_TO_DO;
  if (!config_) {
    return Screen::Digits::HOME_SCREEN;
  }
  while (true) {
    // Check for input
    inputCtl_.Check(window);
    // Clear Screen
    window.clear();
    global_res->DrawBackground(window);

    // Draw sprites

    // Update window
    window.display();
    if (next_screen != Digits::NOTHIG_TO_DO) {
      return next_screen;
    }
  }
}

bool Screen::Config::SaveConfig() {
  config_->SaveConfig();
  return true;
}

void Screen::Config::MoveUp() {}
void Screen::Config::MoveDown() {}
void Screen::Config::MoveRight() {}
void Screen::Config::MoveLeft() {}
