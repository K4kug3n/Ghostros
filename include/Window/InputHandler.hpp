#ifndef WINDOW_INPUTHANDLER_HPP
#define WINDOW_INPUTHANDLER_HPP

#include <unordered_map>
#include <vector>
#include <string>

#include "Window/InputEvent.hpp"
#include "Window/Action.hpp"

class RenderWindow;

class InputHandler
{
public:
	InputHandler();
	InputHandler(InputHandler&&) = default;
	InputHandler(const InputHandler&) = delete;
	~InputHandler()= default;

	bool is_active(const std::string& name) const;
	void update(RenderWindow& render_window);
	void register_action(std::string name, Action action);

	InputHandler& operator=(InputHandler&&) = default;
	InputHandler& operator=(const InputHandler&) = delete;
private:
	std::unordered_map<std::string, Action> m_registered_actions;

	std::vector<InputEvent::Event> m_pending_events;
};

#endif