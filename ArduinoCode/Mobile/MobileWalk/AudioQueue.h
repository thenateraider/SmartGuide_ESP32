#pragma once

#include <Arduino.h>
#include <functional>

void queue_mp3_file(const char* directory, const char* filename, std::function<void()> onFinish = nullptr);
void audioLoopCheck();
void debug_check_mp3_file(const char* directory, const char* filename);

