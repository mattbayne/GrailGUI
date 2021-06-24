#pragma once

#include <mpv/client.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "util/Ex.hh"

class AudioPlayer {
 private:
  std::unordered_map<std::string, mpv_handle *> contexts;
  mpv_handle *currentCtx;
  bool isPlaying;

  inline void checkError(int status) {
    if (status < 0) {
      printf("mpv API error: %s\n", mpv_error_string(status));
      throw Ex1(Errcode::MPV_FAILURE);
    }
  }

 public:
  AudioPlayer();
  ~AudioPlayer();
  AudioPlayer(const AudioPlayer &orig) = delete;
  AudioPlayer &operator=(const AudioPlayer &orig) = delete;
  void newContext(std::string name);
  void setCurrentContext(std::string name);
  void addFile(std::string filePath);
  void addPlaylist(std::string filePath, bool append = false);
  void setVolume(int volume);
  void seekLocation(std::string time, std::string type = "relative");
  void revertSeek();
  void nextTrack();
  void togglePause();
  void setPlaying();
  void setPaused();
  void printCurrentTime();
};
