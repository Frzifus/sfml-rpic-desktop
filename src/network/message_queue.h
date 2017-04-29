/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_NETWORK_MESSAGEQUEUE_H_
#define RPIC_DESKTOP_INCLUDE_NETWORK_MESSAGEQUEUE_H_

#include <google/protobuf/message.h>

#include <memory>

namespace Network {

class MessageQueue {
public:
  virtual ~MessageQueue() = default;
  virtual void
  AddMessage(std::unique_ptr<::google::protobuf::Message> proto_Message) = 0;
};

} // namespace Network

#endif // RPIC_DESKTOP_INCLUDE_NETWORK_MESSAGEQUEUE_H_
