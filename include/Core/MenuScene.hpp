#ifndef CORE_MENUSCENE_HPP
#define CORE_MENUSCENE_HPP

#include "Core/Scene.hpp"

#include "ECS/World.hpp"

#include "Widgets/LayoutWidget.hpp"

class Button;

class MenuScene : public Scene
{
public:
	MenuScene() = delete;
	MenuScene(RenderWindow& window, InputHandler& input_handler);
	MenuScene(const MenuScene&) = delete;
	MenuScene(MenuScene&&) = default;
	~MenuScene() = default;

	void load() override;
	void unload() override;
	void update() override;

	Button& get_play_button();
	Button& get_quit_button();

	MenuScene& operator=(const MenuScene&) = delete;
	MenuScene& operator=(MenuScene&&) = default;
private:
	RenderWindow& m_window;
	InputHandler& m_input_handler;

	LayoutWidget m_central_widget;
	Button* m_play_button;
	Button* m_quit_button;
};

#endif


