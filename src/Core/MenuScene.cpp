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
{
}

void MenuScene::load()
{
	m_central_widget.set_size(m_window.get_size());

	std::unique_ptr<Button> play_button = std::make_unique<Button>("Play");
	play_button->on_click([](){ std::cout << "Play" << std::endl; });
	std::unique_ptr<Button> quit_button = std::make_unique<Button>("Quit");
	quit_button->on_click([]() { std::cout << "Quit" << std::endl; });

	std::unique_ptr<VerticalLayout> layout = std::make_unique<VerticalLayout>();
	layout->add_widget(std::move(play_button));
	layout->add_widget(std::move(quit_button));

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
