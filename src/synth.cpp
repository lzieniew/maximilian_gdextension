#include "synth.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

maxiOsc mySine, mySine2, mySine3;

void Synth::_bind_methods() {}

Synth::Synth() {
  // Initialize any variables here.
  if (Engine::get_singleton()->is_editor_hint())
    set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
}

Synth::~Synth() {
  // Add your cleanup here.
}

void Synth::_ready() {
  play();
  playback = get_stream_playback();
  mySine.phaseReset(0);
  mySine2.phaseReset(0);
  mySine3.phaseReset(0);
}

void Synth::_process(double delta) { fill_buffer(); }

void Synth::fill_buffer() {
  int frames_available = playback->get_frames_available();
  float value, value2, value3, mix = 0;

  for (int i = 0; i < frames_available; i++) {
    value = mySine.sinewave(196) / 4;
    value2 = mySine2.sinewave(392) / 4;
    value3 = mySine3.sinewave(784) / 4;
    mix = value + value2 + value3;
    playback->push_frame(Vector2(mix, mix));
  }
}
