/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_NETWORK_SENDER_H_
#define RPIC_DESKTOP_INCLUDE_NETWORK_SENDER_H_

#include <memory>
#include <queue>
#include <string>

#include <SFML/Network.hpp>

#include <google/protobuf/message.h>

#include "./network/message_queue.h"
#include "./config/conf_parser.h"

namespace Network {

class Sender : public MessageQueue {
public:
  explicit Sender();
  void Connect(std::string target, unsigned short port);
  void AddMessage(std::unique_ptr<::google::protobuf::Message> protobufMessage);

private:
  // ::Config::ConfParser *config_;
  void CheckStatus_();
  bool is_connected_;
  sf::TcpSocket socket_;
  sf::Socket::Status status_;
  /* std::queue<std::unique_ptr<::google::protobuf::Message>> queue_; */
};

} // namespace Network

#endif // RPIC_DESKTOP_INCLUDE_NETWORK_SENDER_H_
