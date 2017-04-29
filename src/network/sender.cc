/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./network/sender.h"

#include <memory>
#include <string>

#include <SFML/Network.hpp>

#include <google/protobuf/message.h>

#include "./config/conf_parser.h"
#include <iostream>

Network::Sender::Sender()
    : is_connected_(false),
      status_(sf::Socket::Status::Disconnected) {}

void Network::Sender::Connect(std::string target, unsigned short port) {
  if (!is_connected_) {
    status_ = socket_.connect(target, port);
    // status_ = socket_.connect(config_->Ip(), config_->Port());
  }
}

void Network::Sender::AddMessage(
    std::unique_ptr<::google::protobuf::Message> proto_message) {
  auto bytes = proto_message->SerializeAsString();
  status_ = socket_.send(bytes.c_str(), bytes.size());
}

void Network::Sender::CheckStatus_() {
  if (status_ == sf::Socket::Done) {
    std::cout << "The socket has sent / received the data" << std::endl;
  } else if (status_ == sf::Socket::NotReady) {
    std::cout << "The socket is not ready to send / receive data yet."
              << std::endl;
    is_connected_ = false;
  } else if (status_ == sf::Socket::Error) {
    std::cout << "An unexpected error happened." << std::endl;
    is_connected_ = false;
  } else if (status_ == sf::Socket::Disconnected) {
    std::cout << "The TCP socket has been disconnected." << std::endl;
    is_connected_ = false;
  }
}
