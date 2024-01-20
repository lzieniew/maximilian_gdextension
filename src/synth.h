#ifndef SYNTH_H
#define SYNTH_H

#include <godot_cpp/classes/audio_stream_generator.hpp>
#include <godot_cpp/classes/audio_stream_generator_playback.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

#include "maximilian.h"

namespace godot {

class Synth : public AudioStreamPlayer {
  GDCLASS(Synth, AudioStreamPlayer)

private:
  Ref<AudioStreamGeneratorPlayback> playback;
  double pulse_hz = 100.0; // Frequency of the sound wave
  maxiOsc mySine;

protected:
  static void _bind_methods();

public:
  Synth();
  ~Synth();

  void _ready() override;
  void _process(double delta) override;
  void fill_buffer();
};

} // namespace godot

#endif
