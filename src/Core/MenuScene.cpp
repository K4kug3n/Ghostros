#include "Core/MenuScene.hpp"

#include "Window/Systems/InputSystems.hpp"

#include "Graphics/Systems/RenderSystem.hpp"

#include "Widgets/VerticalLayout.hpp"
#include "Widgets/Button.hpp"

#include "Graphics/Components/Camera.hpp"

#include <iostream>

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
	m_central_widget.set_size(m_window.get_size());

	std::unique_ptr<Button> play_button = std::make_unique<Button>("Play");
	std::unique_ptr<Button> quit_button = std::make_unique<Button>("Quit");

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
