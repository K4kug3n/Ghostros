#include "Graphics/Components/StateAnimation.hpp"

void StateAnimation::add_animation(State state, Animation animation, TextureHandle texture)
{
	m_data.emplace(state, StateAnimation::AnimationData{ animation, texture });
}

const StateAnimation::AnimationData& StateAnimation::get_animation_data(State state)
{
	m_previous_state = std::make_optional<State>(state);
	return m_data.at(state);
}

std::optional<State> StateAnimation::get_previous_state() const
{
	return m_previous_state;
}

bool StateAnimation::has_animation(State state) const
{
	return m_data.find(state) != m_data.cend();
}
