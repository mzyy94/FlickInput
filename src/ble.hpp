// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <stdint.h>

void start_ble_hid();
void send_key(uint8_t keycode, uint8_t modifier);