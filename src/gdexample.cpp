#include "gdexample.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

maxiOsc mySineOther;

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
  // sample_hz = get_stream()->get_mix_rate();
  sample_hz =
      Object::cast_to<AudioStreamGenerator>(*get_stream())->get_mix_rate();
}

void GDExample::_process(double delta) { fill_buffer(); }

void GDExample::fill_buffer() {
  double increment = pulse_hz / sample_hz;
  int frames_available = playback->get_frames_available();

  for (int i = 0; i < frames_available; i++) {
    // float value = mySineOther.sinewave(240);
    float value = mySineOther.sinewave(pulse_hz);
    playback->push_frame(Vector2(value, value));
  }
}
