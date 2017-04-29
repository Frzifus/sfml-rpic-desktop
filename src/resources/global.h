/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_RESOURCES_GLOBAL_H_
#define RPIC_DESKTOP_INCLUDE_RESOURCES_GLOBAL_H_

#include "./config/conf_parser.h"

#include <memory>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Resources {

class Global {
public:
  Global();
  sf::Font global_font;
  void DrawBackground(sf::RenderWindow &window);

  void Init();

  void AddConfig(::Config::ConfParser *config);

  ::Config::ConfParser *Config() const { return config_; };

private:
  sf::Texture menu_background_texture_;
  sf::Sprite menu_background_sprite_;
  ::Config::ConfParser *config_;
};

} // namespace Resources

#endif // ! RPIC_DESKTOP_INCLUDE_RESOURCES_GLOBAL_H_
