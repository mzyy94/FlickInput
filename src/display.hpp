#pragma once
#include "event.hpp"
void draw_statusbar(void * = nullptr, const char * = nullptr, int event_id = STATUS_EVENT_UPDATE_ONLY_REFRESH, void *event_data = nullptr);
void draw_logo(bool inverse = false);
void update_display();