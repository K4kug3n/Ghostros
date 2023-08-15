#ifndef GRAPHICS_COMPONENTS_ANIMATEDSPRITE_HPP
#define GRAPHICS_COMPONENTS_ANIMATEDSPRITE_HPP

#include <unordered_map>

#include "ECS/Components/Sprite.hpp"
#include "Graphics/TextureHandle.hpp"
#include "Maths/Vector2.hpp"

// Heavy class, should split texture management, animation data & animation player
class AnimatedSprite
{
public:
	AnimatedSprite();
	AnimatedSprite(AnimatedSprite&& other) noexcept;
	AnimatedSprite(const AnimatedSprite&) = delete;
	~AnimatedSprite() = default;

	void add_animation(std::string name, TextureHandle sprite_sheet, unsigned nb_rows, unsigned nb_cols, double duration);
	void play(const std::string& name);
	void update(double delta_t);

	Sprite& get_frame();

	AnimatedSprite& operator=(AnimatedSprite&& other) noexcept;
	AnimatedSprite& operator=(const AnimatedSprite&) = delete;

private:
	struct Animation {
		Animation() = delete;
		Sprite frame;
		double duration_per_frame;
		Vector2u frame_size;
		Vector2u nb_frames;
	};

	void update_frame();

	std::unordered_map<std::string, Animation> m_animations;
	double m_current_frame_duration;
	Vector2u m_current_frame_position;
	Animation* m_current_animation;
};

#endif