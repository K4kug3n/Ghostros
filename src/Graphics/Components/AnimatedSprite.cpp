#include "Graphics/Components/AnimatedSprite.hpp"

#include <cassert>

AnimatedSprite::AnimatedSprite()
	: m_animations()
	, m_current_frame_duration(0.f)
	, m_current_frame_position(1, 0)
	, m_current_animation(nullptr)
{
}

AnimatedSprite::AnimatedSprite(AnimatedSprite&& other) noexcept
	: m_animations(std::move(other.m_animations))
	, m_current_frame_duration(other.m_current_frame_duration)
	, m_current_frame_position(std::move(other.m_current_frame_position))
	, m_current_animation(other.m_current_animation)
{
}

void AnimatedSprite::add_animation(std::string name, Texture sprite_sheet, unsigned nb_rows, unsigned nb_cols, double duration)
{
	Vector2u frame_size{ sprite_sheet.get_width() / nb_cols, sprite_sheet.get_height() / nb_rows };
	Animation new_animation{
		std::move(sprite_sheet),
		sf::Sprite{},
		duration / (nb_cols * nb_rows),
		std::move(frame_size),
		Vector2u{ nb_cols, nb_rows }
	};

	m_animations.insert({ name, std::move(new_animation) });

	Animation& animation = m_animations.at(name);
	animation.frame.setTexture(animation.texture.get_handle());
}

void AnimatedSprite::play(const std::string& name)
{
	m_current_frame_duration = 0.f;
	m_current_frame_position = { 0, 0 };
	m_current_animation = &m_animations.at(name);

	update_frame();
}

void AnimatedSprite::update(double delta_t)
{
	assert(m_current_animation != nullptr);
	m_current_frame_duration += delta_t;

	while (m_current_frame_duration >= m_current_animation->duration_per_frame)
	{
		m_current_frame_duration -= m_current_animation->duration_per_frame;
		m_current_frame_position.x += 1;
		if (m_current_frame_position.x >= m_current_animation->nb_frames.x)
		{
			m_current_frame_position.x = 0;
			m_current_frame_position.y += 1;
			if (m_current_frame_position.y >= m_current_animation->nb_frames.y)
			{
				m_current_frame_position.y = 0;
			}
		}
	}

	update_frame();
}

sf::Sprite& AnimatedSprite::get_frame()
{
	return m_current_animation->frame;
}

AnimatedSprite& AnimatedSprite::operator=(AnimatedSprite&& other) noexcept
{
	m_animations = std::move(other.m_animations);
	m_current_frame_duration = other.m_current_frame_duration;
	m_current_frame_position = std::move(other.m_current_frame_position);
	m_current_animation = other.m_current_animation;

	return *this;
}

void AnimatedSprite::update_frame()
{
	m_current_animation->frame.setTextureRect(sf::IntRect{
		static_cast<int>(m_current_frame_position.x * m_current_animation->frame_size.x),
		static_cast<int>(m_current_frame_position.y * m_current_animation->frame_size.y),
		static_cast<int>(m_current_animation->frame_size.x),
		static_cast<int>(m_current_animation->frame_size.y)
	});
}