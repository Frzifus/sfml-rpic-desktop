/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./screen/playground.h"

#include <memory>

#include "./input/playground_ctl.h"
#include "./network/sender.h"
#include "./screen/screen_digits.h"

Input::PlaygroundCtl::PlaygroundCtl(::Screen::Playground *playground_instance) {
  client_ = std::make_unique<::Network::Client>(&sender_);
  playground_instance_ = playground_instance;
}

void Input::PlaygroundCtl::Connect(std::string target, unsigned short port) {
  sender_.Connect(target, port);
}

void Input::PlaygroundCtl::Check(sf::RenderWindow &window) {
  if (window.pollEvent(event_)) {
    switch (event_.type) {
    case sf::Event::Closed:
      playground_instance_->next_screen = ::Screen::Digits::CLOSE;
      break;
    case sf::Event::KeyPressed:
    case sf::Event::KeyReleased:
      if (event_.type == sf::Event::KeyPressed &&
          event_.key.code == sf::Keyboard::Escape) {
        playground_instance_->next_screen = ::Screen::Digits::HOME_SCREEN;
        return;
      }
      CheckCameraKeys_(event_.type == sf::Event::KeyPressed);
      CheckMovementKeys_(event_.type == sf::Event::KeyPressed);
      break;
    default:
      break;
    }
  }
}

void Input::PlaygroundCtl::CheckCameraKeys_(bool pressed) {
  // TODO: Use speed from config.
  const int speed = pressed ? 1000 : 0;
  switch (event_.key.code) {
  case sf::Keyboard::Up:
    client_->Move<Network::Client::Type::CAMERA, Network::Client::Direction::Y>(
        speed);
    break;
  case sf::Keyboard::Down:
    client_->Move<Network::Client::Type::CAMERA, Network::Client::Direction::Y>(
        -speed);
    break;
  case sf::Keyboard::Left:
    client_->Move<Network::Client::Type::CAMERA, Network::Client::Direction::X>(
        speed);
    break;
  case sf::Keyboard::Right:
    client_->Move<Network::Client::Type::CAMERA, Network::Client::Direction::X>(
        -speed);
    break;
  default:
    break;
  }
}

void Input::PlaygroundCtl::CheckMovementKeys_(bool pressed) {
  // TODO: Use speed from config.
  const int speed = pressed ? 1000 : 0;
  switch (event_.key.code) {
  case sf::Keyboard::W:
    client_
        ->Move<Network::Client::Type::VEHICLE, Network::Client::Direction::Y>(
            speed);
    break;
  case sf::Keyboard::S:
    client_
        ->Move<Network::Client::Type::VEHICLE, Network::Client::Direction::Y>(
            -speed);
    break;
  case sf::Keyboard::A:
    client_
        ->Move<Network::Client::Type::VEHICLE, Network::Client::Direction::X>(
            speed);
    break;
  case sf::Keyboard::D:
    client_
        ->Move<Network::Client::Type::VEHICLE, Network::Client::Direction::X>(
            -speed);
    break;
  default:
    break;
  }
}
