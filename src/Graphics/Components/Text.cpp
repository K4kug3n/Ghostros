#include "Graphics/Components/Text.hpp"

#include "Maths/Vector2.hpp"

Text::Text(const std::string& text)
	: m_handle()
	, m_font()
{
	if (!m_font.loadFromFile("fonts/arial.ttf"))
	{
		throw std::runtime_error("Canno't load arial font");
	}
	m_handle.setFont(m_font);
	set_text(text);
}

Text::Text(Text&& other) noexcept
	: m_handle(std::move(other.m_handle))
	, m_font(std::move(other.m_font))
{
}

const sf::Text& Text::get_handle() const
{
	return m_handle;
}

Vector2u Text::get_size() const
{
	const sf::FloatRect rect = m_handle.getGlobalBounds();
	return Vector2u{ static_cast<unsigned>(rect.width), static_cast<unsigned>(rect.height) };
}

void Text::set_position(const Vector2f& position)
{
	m_handle.setPosition({ position.x, position.y });
}

void Text::set_text(const std::string& text)
{
	m_handle.setString(text);
}

Text& Text::operator=(Text&& other) noexcept
{
	m_handle = std::move(other.m_handle);
	m_font = std::move(other.m_font);

	return *this;
}
