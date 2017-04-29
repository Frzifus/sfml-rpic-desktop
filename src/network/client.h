/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#ifndef RPIC_DESKTOP_INCLUDE_NETWORK_CLIENT_H_
#define RPIC_DESKTOP_INCLUDE_NETWORK_CLIENT_H_

#include "./network/ctl_message.pb.h"
#include "./network/message_queue.h"

#include <memory>
#include <unordered_map>
#include <iostream>

namespace Network {

class Client {
 public:
  enum class Direction { X, Y };
  enum class Type { CAMERA, VEHICLE };
  explicit Client(MessageQueue *messageQueue);

  template <Type type, Direction direction>
  void Move(int speed = 1000) {
    static std::unordered_map<Direction, int> previous_state{{Direction::X, 0},
                                                             {Direction::Y, 0}};
    if (previous_state[direction] == speed) {
      return;
    }
    previous_state[direction] = speed;
    auto ctl_message = std::make_unique<CtlMessage>();
    ctl_message->set_direction(
        direction == Direction::Y
            ? CtlMessage_Direction::CtlMessage_Direction_Y
            : CtlMessage_Direction::CtlMessage_Direction_X);
    ctl_message->set_value(speed);
    ctl_message->set_ctl_type(
        type == Type::CAMERA ? CtlMessage_CtlType::CtlMessage_CtlType_CAMERA
                             : CtlMessage_CtlType::CtlMessage_CtlType_VEHICLE);
    message_queue_->AddMessage(std::move(ctl_message));
  }

 private:
  std::unique_ptr<CtlMessage> MakeCtlMessage_(Direction direction, int speed);
  MessageQueue *message_queue_;
};

}  // namespace Network

#endif  // RPIC_DESKTOP_INCLUDE_NETWORK_CLIENT_H_
