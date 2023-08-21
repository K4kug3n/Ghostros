#include "Graphics/Systems/AnimationSystem.hpp"

#include "ECS/World.hpp"

#include "Graphics/Components/Animation.hpp"
#include "Graphics/Components/Sprite.hpp"

AnimationSystem::AnimationSystem(World& world)
	: System(world)
{
}

void AnimationSystem::update(double delta_t)
{
	for (auto [id, animation, sprite] : m_world.view<Animation, Sprite>().each())
	{
		if(animation.repetition == AnimationRepetition::SINGLE && animation.current_frame_position == (animation.nb_frames - Vector2u{ 1, 1 }))
		{
			m_world.remove<Animation>(id);
		}

		animation.current_frame_duration += delta_t;

		while (animation.current_frame_duration >= animation.duration_per_frame)
		{
			animation.current_frame_duration -= animation.duration_per_frame;
			animation.current_frame_position.x += 1;
			if (animation.current_frame_position.x >= animation.nb_frames.x)
			{
				animation.current_frame_position.x = 0;
				animation.current_frame_position.y += 1;
				if (animation.current_frame_position.y >= animation.nb_frames.y)
				{
					animation.current_frame_position.y = 0;
				}
			}
		}


		sprite.set_texture_rect(
			{
				animation.current_frame_position.x * animation.frame_size.x,
				animation.current_frame_position.y * animation.frame_size.y,
			},
			{
				animation.frame_size.x,
				animation.frame_size.y
			}
		);
	}
}
