/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./screen/home.h"

#include <SFML/Graphics.hpp>

#include "./input/home_ctl.h"
#include "./screen/screen_digits.h"

Screen::Home::Home() : text_size_(50), input_ctl_(::Input::HomeCtl(this)) {
  menu_text_.clear();
}

Screen::Home::~Home() {}

void Screen::Home::InitMenuText_() {
  current_choise_ = 0;
  menu_text_.clear();
  menu_text_.push_back(
      Screen::Element::MenuButton("Connect", global_res->global_font));
  menu_text_.push_back(
      Screen::Element::MenuButton("Config", global_res->global_font));
  menu_text_.push_back(
      Screen::Element::MenuButton("Exit", global_res->global_font));
  if (!config_->isComplete()) {
    current_choise_++;
    menu_text_.at(0).set_Visibility(false);
  }
  UpdateMenuText_();
}

void Screen::Home::UpdateMenuText_() {
  float topPos{200};
  for (auto &button : menu_text_) {
    button.set_Selected(false);
    button.sf_text.setFillColor(sf::Color::White);
    button.sf_text.setPosition(50, topPos);
    topPos += 100;
  }
  menu_text_[current_choise_].set_Selected(true);
  menu_text_[current_choise_].sf_text.setFillColor(sf::Color::Red);
}

Screen::Digits Screen::Home::Run(sf::RenderWindow &window) {
  config_ = global_res->Config();
  InitMenuText_();
  next_screen = Digits::NOTHIG_TO_DO;
  while (true) {
    // check for input
    input_ctl_.Check(window);
    // Clear Screen
    window.clear();
    global_res->DrawBackground(window);

    // Draw text
    for (std::vector<Screen::Element::MenuButton>::iterator it =
             menu_text_.begin();
         it != menu_text_.end(); ++it) {
      if (!it->isVisable()) {
        continue;
      }
      window.draw(it->sf_text);
    }

    // Update window
    window.display();

    if (next_screen != Digits::NOTHIG_TO_DO) {
      return next_screen;
    }
  }
}

void Screen::Home::MoveUp() {
  if (current_choise_ > 1) {
    current_choise_--;
  } else if (current_choise_ > 0 && menu_text_[0].isVisable()) {
    current_choise_--;
  }
  UpdateMenuText_();
}

void Screen::Home::MoveDown() {
  if (current_choise_ < menu_text_.size() - 1) {
    current_choise_++;
  }
  UpdateMenuText_();
}
