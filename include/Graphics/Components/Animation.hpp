#ifndef GRAPHICS_COMPONENTS_ANIMATION_HPP
#define GRAPHICS_COMPONENTS_ANIMATION_HPP

#include "Maths/Vector2.hpp"

enum class AnimationRepetition
{
	REPEAT,
	SINGLE
};

class Animation
{
public:
	Animation() = delete;
	Animation(const Vector2u& sprite_size, Vector2u nb_frames, double duration, AnimationRepetition repetition = AnimationRepetition::SINGLE);
	Animation(const Animation&) = default;
	Animation(Animation&&) = default;
	~Animation() = default;

	double duration_per_frame;
	Vector2u frame_size;
	Vector2u nb_frames;
	AnimationRepetition repetition;

	double current_frame_duration;
	Vector2u current_frame_position;

	Animation& operator=(const Animation&) = default;
	Animation& operator=(Animation&&) = default;
};

#endif