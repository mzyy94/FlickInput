#pragma once
#include <stdint.h>
extern bool sec_conn;

void init_ble_hid();
void send_key(uint8_t keycode, uint8_t modifier);