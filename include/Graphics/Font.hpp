#ifndef GRAPHICS_FONT_HPP
#define GRAPHICS_FONT_HPP

#include <filesystem>

#include <SFML/Graphics/Font.hpp>

class Font
{
public:
	Font() = delete;
	Font(const std::filesystem::path& filepath);
	Font(Font&& other) noexcept;
	Font(const Font&) = delete;
	~Font() = default;

	const sf::Font& get_handle() const;

	Font& operator=(Font&& other) noexcept;
	Font& operator=(const Font&) = delete;

private:
	sf::Font m_handle;
};

#endif