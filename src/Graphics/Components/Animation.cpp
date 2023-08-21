#include "Graphics/Components/Animation.hpp"

Animation::Animation(const Vector2u& sprite_size, Vector2u nb_frames, double duration, AnimationRepetition repetition)
	: duration_per_frame(duration / (nb_frames.x * nb_frames.y))
	, frame_size(sprite_size / nb_frames)
	, nb_frames(std::move(nb_frames))
	, repetition(repetition)
	, current_frame_duration(0.f)
	, current_frame_position(0u, 0u)
{
}
