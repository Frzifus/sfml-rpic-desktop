/**
 * Copyright(c) [2017] <Frzifus> All Rights Reserved.
 * Distributed under MIT license.
 * See file LICENSE for detail at LICENSE file.
 */

#include "./screen/screen_interface.h"

#include "./screen/screen_digits.h"
#include "./resources/global.h"

Resources::Global *Screen::ScreenInterface::global_res = nullptr;
Screen::Digits Screen::ScreenInterface::next_screen = Screen::Digits::CLOSE;
