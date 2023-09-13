#include "Core/MenuScene.hpp"

#include "Window/Systems/InputSystems.hpp"

#include "Graphics/Components/Camera.hpp"
#include "Graphics/Systems/RenderSystem.hpp"
#include "Graphics/RessourceHandle.hpp"
#include "Graphics/Font.hpp"

#include "Widgets/VerticalLayout.hpp"
#include "Widgets/Button.hpp"

MenuScene::MenuScene(RenderWindow& window, InputHandler& input_handler)
	: m_window(window)
	, m_input_handler(input_handler)
	, m_central_widget()
	, m_play_button(nullptr)
	, m_quit_button(nullptr)
{
}

void MenuScene::load()
{
	RessourceHandle<Texture> button_texture{ std::make_shared<Texture>("widgets/button.png") };
	RessourceHandle<Font> arial_font{ std::make_shared<Font>("fonts/arial.ttf") };

	m_central_widget.set_size(m_window.get_size());

	std::unique_ptr<Button> play_button = std::make_unique<Button>(Text{ arial_font, "Play" }, button_texture);
	std::unique_ptr<Button> quit_button = std::make_unique<Button>(Text{ arial_font, "Quit"}, std::move(button_texture));

	std::unique_ptr<VerticalLayout> layout = std::make_unique<VerticalLayout>();
	m_play_button = layout->add_widget(std::move(play_button));
	m_quit_button = layout->add_widget(std::move(quit_button));

	m_central_widget.set_layout(std::move(layout));
}

void MenuScene::unload()
{
}

void MenuScene::update()
{
	Camera camera{ { 0u, 0u }, m_window.get_size() };
	m_window.set_camera(camera);

	m_central_widget.set_size(m_window.get_size());

	m_central_widget.update(m_input_handler);
	m_central_widget.draw(m_window);
}

Button& MenuScene::get_play_button()
{
	assert(m_play_button != nullptr);
	return *m_play_button;
}

Button& MenuScene::get_quit_button()
{
	assert(m_quit_button != nullptr);
	return *m_quit_button;
}
