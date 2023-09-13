#include "Graphics/Font.hpp"

Font::Font(const std::filesystem::path& filepath)
	: m_handle()
{
	if (!m_handle.loadFromFile(std::filesystem::absolute(filepath).generic_string()))
	{
		throw std::runtime_error("Canno't load " + std::filesystem::absolute(filepath).generic_string());
	}
}

Font::Font(Font&& other) noexcept
	: m_handle(std::move(other.m_handle))
{
}

const sf::Font& Font::get_handle() const
{
	return m_handle;
}

Font& Font::operator=(Font&& other) noexcept
{
	m_handle = std::move(other.m_handle);
	return *this;
}
