#include "AudioQueue.h"

#include "Audio_PCM5101.h"
#include "SD_Card.h"
#include <queue>

struct AudioTask {
  String directory;
  String filename;
  std::function<void()> onFinish = nullptr;
};

std::queue<AudioTask> audioQueue;
static AudioTask currentTask;
static bool isTaskRunning = false;

void queue_mp3_file(const char* directory, const char* filename, std::function<void()> onFinish) {
  audioQueue.push({String(directory), String(filename), onFinish});
  printf("[QUEUE] Added %s/%s\n", directory, filename);
}

void audioLoopCheck() {
  if (!audio.isRunning()) {
    if (isTaskRunning && currentTask.onFinish) {
      currentTask.onFinish();
    }
    isTaskRunning = false;

    if (!audioQueue.empty()) {
      currentTask = audioQueue.front();
      audioQueue.pop();
      isTaskRunning = true;

      char path[128];
      snprintf(path, sizeof(path), "%s/%s", currentTask.directory.c_str(), currentTask.filename.c_str());

      if (!File_Search(currentTask.directory.c_str(), currentTask.filename.c_str())) {
        printf("[ERROR] File '%s/%s' not found.\n", currentTask.directory.c_str(), currentTask.filename.c_str());
        isTaskRunning = false;
        return;
      }

      bool ret = audio.connecttoFS(SD_MMC, path);
      printf("[DEBUG] connecttoFS('%s') returned: %s\n", path, ret ? "true" : "false");
      if (!ret) {
        printf("[ERROR] Failed to start audio playback.\n");
        isTaskRunning = false;
      } else {
        printf("[INFO] Now playing: %s\n", currentTask.filename.c_str());
      }
    }
  }
}

void debug_check_mp3_file(const char* directory, const char* filename) {
  queue_mp3_file(directory, filename);
}

