#include "Widgets/Button.hpp"

#include "Window/InputHandler.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Texture.hpp"

#include "Maths/Vector3.hpp"

Button::Button(const std::string& text, Vector2u position, Vector2u size)
	: Widget(position, size)
	, m_sprite(RessourceHandle<Texture>{ std::make_shared<Texture>("widgets/button.png") })
	, m_text(text)
	, m_on_click_callback([](){})
{
}

void Button::draw(RenderWindow& render_window)
{
	m_sprite.set_position({ static_cast<float>(m_position.x), static_cast<float>(m_position.y), 0.f });
	m_sprite.set_size(m_size);

	const Vector2u text_pos = m_position + (m_size / 2u) - (m_text.get_size() / 2u);
	m_text.set_position(text_pos.as<float>());

	render_window.draw(m_sprite.get_handle());
	render_window.draw(m_text.get_handle());
}

void Button::on_click(std::function<void()> callback)
{
	m_on_click_callback = std::move(callback);
}

void Button::update(InputHandler& input_handler)
{
	if (input_handler.is_active(Action{ InputEvent::Mouse::Left }))
	{
		const Vector2i& mouse_position = input_handler.get_mouse_position();
		if (mouse_position.x < static_cast<int>(m_position.x) || mouse_position.x > static_cast<int>(m_position.x + m_size.x) ||
			mouse_position.y < static_cast<int>(m_position.y) || mouse_position.y > static_cast<int>(m_position.y + m_size.y))
		{
			return;
		}
		
		m_on_click_callback();
	}
}
