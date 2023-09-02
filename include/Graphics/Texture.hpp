#ifndef GRAPHICS_TEXTURE_HPP
#define GRAPHICS_TEXTURE_HPP

#include <filesystem>

#include <SFML/Graphics/Texture.hpp>

template<typename T> class Vector2;
using Vector2u = Vector2<unsigned int>;

class Texture
{
public:
	Texture() = delete;
	Texture(const std::filesystem::path& filepath);
	Texture(const Texture&) = delete;
	Texture(Texture&& other) noexcept;
	~Texture() = default;

	const sf::Texture& get_handle() const;
	unsigned get_height() const;
	Vector2u get_size() const;
	unsigned get_width() const;

	Texture& operator=(const Texture&) = delete;
	Texture& operator=(Texture&& other) noexcept;

private:
	sf::Texture m_texture;
};

#endif