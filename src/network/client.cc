/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./network/client.h"

#include <iostream>
#include <memory>
#include <unordered_map>

#include "./network/ctl_message.pb.h"

Network::Client::Client(MessageQueue *message_queue)
    : message_queue_(message_queue) {}
