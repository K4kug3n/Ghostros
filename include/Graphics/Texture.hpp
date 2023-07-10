#ifndef GRAPHICS_TEXTURE_HPP
#define GRAPHICS_TEXTURE_HPP

#include <filesystem>

#include <SFML/Graphics/Texture.hpp>

class Texture
{
public:
	Texture() = delete;
	Texture(const std::filesystem::path& filepath);
	Texture(const Texture&) = delete;
	Texture(Texture&&) = default;
	~Texture() = default;

	const sf::Texture& get_handle() const;

	Texture& operator=(const Texture&) = delete;
	Texture& operator=(Texture&&) = default;

private:
	sf::Texture m_texture;
};

#endif