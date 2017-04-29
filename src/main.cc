/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include <iostream>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "./resources/global.h"
#include "./screen/screen_digits.h"
#include "./screen/screen_interface.h"
#include "./screen/screens.h"

int main() {
  Config::ConfParser config;

  Resources::Global globalRes;

  try {
    globalRes.Init();
  } catch (std::exception &ex) {
    std::cerr << "Ouch! That hurts, because: " << ex.what() << "!\n";
    return EXIT_FAILURE;
  }
  bool missingConfig = !config.LoadConfig();
  if (missingConfig) {
    std::clog << "Configuration file does not exist\n";
  }

  // Add config to globalRes
  globalRes.AddConfig(&config);

  // Window creation
  sf::RenderWindow window(
      sf::VideoMode(config.ResolutionWidth(), config.ResolutionHeight()),
      "rpic-desktop"); //, sf::Style::Fullscreen);

  // set framelimit
  window.setFramerateLimit(config.FrameLimit());
  // configure cursor
  window.setMouseCursorVisible(config.MouseCursorVisable());
  // configure Vsync
  window.setVerticalSyncEnabled(config.VSync());

  // Screens preparations

  std::unordered_map<Screen::Digits, Screen::ScreenInterface *> screens;
  Screen::Digits screen = Screen::Digits::HOME_SCREEN;

  Screen::Home homeScreen;
  screens[Screen::Digits::HOME_SCREEN] = &homeScreen;

  Screen::Config configScreen;
  screens[Screen::Digits::CONFIG_SCREEN] = &configScreen;

  Screen::Playground playgroundScreen;
  screens[Screen::Digits::PLAYGROUND_SCREEN] = &playgroundScreen;

  Screen::ScreenInterface::global_res = &globalRes;

  // FIXME: This seems evil since it implies that somewhere there's a while
  // true.
  while (screen != Screen::Digits::CLOSE) {
    auto currentScreen = screens[screen];
    screen = currentScreen->Run(window);
  }
}
