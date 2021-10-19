#pragma once
#include <esp_event.h>
void update_button_event();

#define register_button_pressed(BTN, callback, arg) esp_event_handler_register_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_##BTN, callback, arg)
#define unregister_button_pressed(BTN, callback) esp_event_handler_unregister_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_##BTN, callback)
#define register_button_hold(BTN, callback, arg) esp_event_handler_register_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_HOLD_##BTN, callback, arg)
#define unregister_button_hold(BTN, callback) esp_event_handler_unregister_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_HOLD_##BTN, callback)