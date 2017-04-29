/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./config/conf_parser.h"

Config::ConfParser::ConfParser() {
  resolution_[Config::Width] = 1600;
  resolution_[Config::Height] = 900;
  frameLimit_ = 60;
 mouse_cursor_visable_ = false;
  ip_ = "127.0.0.1";
  port_ = 4444;
  is_complete_ = true;
}

bool Config::ConfParser::LoadConfig() {
  // set isComplete true
  return false;
}

void Config::ConfParser::SaveConfig() {
  // set isComplete true
}
