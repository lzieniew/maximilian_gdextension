#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/audio_stream_generator_playback.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

#include "maximilian.h"

namespace godot {

class GDExample : public AudioStreamPlayer {
  GDCLASS(GDExample, AudioStreamPlayer)

private:
  Ref<AudioStreamGeneratorPlayback> playback;
  double sample_hz;        // Sample rate
  double pulse_hz = 440.0; // Frequency of the sound wave
  maxiOsc mySine;

protected:
  static void _bind_methods();

public:
  GDExample();
  ~GDExample();

  void _ready() override;
  void _process(double delta) override;
  void fill_buffer();
};

} // namespace godot

#endif
