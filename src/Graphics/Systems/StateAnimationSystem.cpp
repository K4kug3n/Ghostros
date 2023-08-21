#include "Graphics/Systems/StateAnimationSystem.hpp"

#include "ECS/World.hpp"
#include "ECS/EntityHandler.hpp"
#include "ECS/Components/State.hpp"
#include "ECS/Components/Sprite.hpp"

#include "Graphics/Components/StateAnimation.hpp"

StateAnimationSystem::StateAnimationSystem(World& world)
	: System(world)
{
}

void StateAnimationSystem::update(double)
{
	/*m_world.view<const State, StateAnimation, Sprite>().each(
		[this](entt::entity id, State state, StateAnimation& state_animation, Sprite& sprite)
		{
			if (state == state_animation.get_previous_state() || !state_animation.has_animation(state))
			{
				return;
			}

			EntityHandler handler{ m_world, id };
			StateAnimation::AnimationData animation_data = state_animation.get_animation_data(state);

			handler.add_or_replace_component<Animation>(animation_data.animation);
			sprite.set_texture(animation_data.texture);
		}
	);*/

	for (auto [id, state, state_animation, sprite] : m_world.view<const State, StateAnimation, Sprite>().each())
	{
		if (state == state_animation.get_previous_state() || !state_animation.has_animation(state))
		{
			return;
		}

		EntityHandler handler{ m_world, id };
		StateAnimation::AnimationData animation_data = state_animation.get_animation_data(state);

		handler.add_or_replace_component<Animation>(animation_data.animation);
		sprite.set_texture(animation_data.texture);
	}
}
