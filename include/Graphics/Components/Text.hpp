#ifndef GRAPHICS_COMPONENTS_TEXT_HPP
#define GRAPHICS_COMPONENTS_TEXT_HPP

#include <string>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Maths/Vector2.hpp"

class Text
{
public:
	Text(const std::string& text);
	Text(Text&& other) noexcept;
	Text(const Text&) = delete;
	~Text() = default;

	const sf::Text& get_handle() const;
	Vector2u get_size() const;
	void set_position(const Vector2f& position);
	void set_text(const std::string& text);

	Text& operator=(Text&& other) noexcept;
	Text& operator=(const Text&) = delete;

private:
	sf::Font m_font; // Should not be there
	sf::Text m_handle;
};

#endif