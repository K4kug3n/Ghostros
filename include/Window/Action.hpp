#ifndef WINDOW_ACTION_HPP
#define WINDOW_ACTION_HPP

#include <memory>
#include <vector>

#include "Window/InputEvent.hpp"

class ActionEvent
{
public:
	virtual ~ActionEvent();

	virtual bool is_active(const std::vector<InputEvent::Event>& pending_events) const = 0;
};

class InternalActionKeyboard : public ActionEvent
{
public:
	InternalActionKeyboard() = delete;
	InternalActionKeyboard(InputEvent::Keyboard key);
	InternalActionKeyboard(const InternalActionKeyboard&) = delete;
	InternalActionKeyboard(InternalActionKeyboard&&) = default;
	~InternalActionKeyboard() override = default;

	bool is_active(const std::vector<InputEvent::Event>& pending_events) const override;

	InternalActionKeyboard& operator=(const InternalActionKeyboard&) = delete;
	InternalActionKeyboard& operator=(InternalActionKeyboard&&) = default;
private:
	InputEvent::Keyboard m_key;
};

class InternalActionWindow : public ActionEvent
{
public:
	InternalActionWindow() = delete;
	InternalActionWindow(InputEvent::Window event);
	InternalActionWindow(const InternalActionWindow&) = delete;
	InternalActionWindow(InternalActionWindow&&) = default;
	~InternalActionWindow() override = default;

	bool is_active(const std::vector<InputEvent::Event>& pending_events) const override;

	InternalActionWindow& operator=(const InternalActionWindow&) = delete;
	InternalActionWindow& operator=(InternalActionWindow&&) = default;
private:
	InputEvent::Window m_event;
};

class InternalActionMouse : public ActionEvent
{
public:
	InternalActionMouse() = delete;
	InternalActionMouse(InputEvent::Mouse button);
	InternalActionMouse(const InternalActionMouse&) = delete;
	InternalActionMouse(InternalActionMouse&&) = default;
	~InternalActionMouse() override = default;

	bool is_active(const std::vector<InputEvent::Event>& pending_events) const override;

	InternalActionMouse& operator=(const InternalActionMouse&) = delete;
	InternalActionMouse& operator=(InternalActionMouse&&) = default;
private:
	InputEvent::Mouse m_button;
};

class Action
{
public:
	Action() = delete;
	Action(InputEvent::Keyboard key);
	Action(InputEvent::Window event);
	Action(InputEvent::Mouse button);
	Action(const Action&) = delete;
	Action(Action&&) = default;
	~Action() = default;

	bool is_active(const std::vector<InputEvent::Event>& pending_events) const;

	Action& operator=(const Action&) = delete;
	Action& operator=(Action&&) = default;
private:
	std::unique_ptr<ActionEvent> m_action;
};

#endif