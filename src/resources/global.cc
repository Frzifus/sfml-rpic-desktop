/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./resources/global.h"

#include <stdexcept>
#include <string>

Resources::Global::Global() {}

void Resources::Global::Init() {
  // Load global resources
  std::string fontPath{"resources/arial.ttf"};
  std::string backgroundPath{"resources/background.png"};
  if (!global_font.loadFromFile(fontPath)) {
    throw std::runtime_error("Font not found");
  }
  if (!menu_background_texture_.loadFromFile(backgroundPath)) {
    throw std::runtime_error("Background not found");
  }
  sf::Sprite menu_background_sprite(menu_background_texture_);
  menu_background_sprite_ = menu_background_sprite;
  menu_background_sprite_.setPosition(0, 0);
}

void Resources::Global::AddConfig(::Config::ConfParser *config) {
  config_ = config;
}

void Resources::Global::DrawBackground(sf::RenderWindow &window) {
  window.draw(menu_background_sprite_);
}
