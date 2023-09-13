#ifndef GRAPHICS_TEXT_HPP
#define GRAPHICS_TEXT_HPP

#include <string>

#include <SFML/Graphics/Text.hpp>

#include "Maths/Vector2.hpp"

#include "Graphics/RessourceHandle.hpp"
#include "Graphics/Font.hpp"

class Text
{
public:
	Text(RessourceHandle<Font> font);
	Text(RessourceHandle<Font> font, const std::string& text);
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
	RessourceHandle<Font> m_font;
	sf::Text m_handle;
};

#endif