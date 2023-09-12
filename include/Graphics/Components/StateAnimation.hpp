#ifndef GRAPHICS_COMPONENTS_STATEANIMATION_HPP
#define GRAPHICS_COMPONENTS_STATEANIMATION_HPP

#include <unordered_map>
#include <optional>

#include "ECS/Components/State.hpp"
#include "Graphics/Components/Animation.hpp"
#include "Graphics/RessourceCache.hpp"
#include "Graphics/Texture.hpp"

class StateAnimation
{
public:
	struct AnimationData
	{
		Animation animation;
		RessourceHandle<Texture> texture;
	};

	StateAnimation() = default;
	StateAnimation(const StateAnimation&) = delete;
	StateAnimation(StateAnimation&&) = default;
	~StateAnimation() = default;

	void add_animation(State state, Animation animation, RessourceHandle<Texture> texture);
	const AnimationData& get_animation_data(State state);
	std::optional<State> get_previous_state() const;
	bool has_animation(State state) const;

	StateAnimation& operator=(const StateAnimation&) = delete;
	StateAnimation& operator=(StateAnimation&&) = default;

private:
	std::unordered_map<State, AnimationData> m_data;
	std::optional<State> m_previous_state;
};

#endif