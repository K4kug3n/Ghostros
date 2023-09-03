#ifndef CORE_MENUSCENE_HPP
#define CORE_MENUSCENE_HPP

#include "Core/Scene.hpp"

#include "ECS/World.hpp"

#include "Widgets/LayoutWidget.hpp"

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

	MenuScene& operator=(const MenuScene&) = delete;
	MenuScene& operator=(MenuScene&&) = default;
private:
	RenderWindow& m_window;
	InputHandler& m_input_handler;

	LayoutWidget m_central_widget;
};

#endif


