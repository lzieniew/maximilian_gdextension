#include "gdexample.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

maxiOsc mySine;

void GDExample::_bind_methods() {}

GDExample::GDExample() {
  // Initialize any variables here.
  if (Engine::get_singleton()->is_editor_hint())
    set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
}

GDExample::~GDExample() {
  // Add your cleanup here.
}

void GDExample::_ready() {
  play();
  playback = get_stream_playback();
}

void GDExample::_process(double delta) { fill_buffer(); }

void GDExample::fill_buffer() {
  double phase = 0.0;
  double increment = pulse_hz / sample_hz;
  int frames_available = playback->get_frames_available();

  for (int i = 0; i < frames_available; i++) {
    float value = mySine.sinewave(240);
    playback->push_frame(Vector2(value, value));
    phase = fmod(phase + increment, 1.0);
  }
}
