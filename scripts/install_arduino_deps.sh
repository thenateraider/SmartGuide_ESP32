#!/usr/bin/env bash
set -euo pipefail

if ! command -v arduino-cli >/dev/null 2>&1; then
  echo "arduino-cli not found."
  echo "Install it from https://arduino.github.io/arduino-cli/latest/installation/"
  exit 1
fi

echo "Updating Arduino core index..."
arduino-cli core update-index

echo "Installing ESP32 core..."
arduino-cli core install esp32:esp32

echo "Installing Arduino libraries..."
arduino-cli lib install "ArduinoJson"
arduino-cli lib install "Adafruit PN532"
arduino-cli lib install "Adafruit BusIO"
arduino-cli lib install "lvgl"

echo "Trying to install ESP32 audio library used by Audio.h..."
if ! arduino-cli lib install "ESP32-audioI2S"; then
  echo "Could not install ESP32-audioI2S automatically."
  echo "Install a compatible Audio.h library manually if compilation cannot find Audio.h."
fi

echo "Done."

