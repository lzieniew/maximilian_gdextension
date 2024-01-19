extends GDExample
var playback # Will hold the AudioStreamGeneratorPlayback.
@onready var sample_hz = stream.mix_rate
var pulse_hz = 120.0 # The frequency of the sound wave.

# Called when the node enters the scene tree for the first time.
func _ready():
	play()
	playback = get_stream_playback()

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	fill_buffer()

func fill_buffer():
	var phase = 0.0
	var increment = pulse_hz / sample_hz
	var frames_available = playback.get_frames_available()

	for i in range(frames_available):
		playback.push_frame(Vector2.ONE * sin(phase * TAU))
		phase = fmod(phase + increment, 1.0)
