#ifndef WINDOW_ACTION_HPP
#define WINDOW_ACTION_HPP

#include <memory>
#include <vector>

#include "Window/InputEvent.hpp"

class ActionEvent
{
public:
	virtual ~ActionEvent();

	virtual bool is_active(const std::vector<Input::Event>& pending_events) const = 0;
};

class InternalActionKeyboard : public ActionEvent
{
public:
	InternalActionKeyboard() = delete;
	InternalActionKeyboard(Input::Keyboard key);
	InternalActionKeyboard(const InternalActionKeyboard&) = delete;
	InternalActionKeyboard(InternalActionKeyboard&&) = default;
	~InternalActionKeyboard() override = default;

	bool is_active(const std::vector<Input::Event>& pending_events) const override;

	InternalActionKeyboard& operator=(const InternalActionKeyboard&) = delete;
	InternalActionKeyboard& operator=(InternalActionKeyboard&&) = default;
private:
	Input::Keyboard m_key;
};

class InternalActionWindow : public ActionEvent
{
public:
	InternalActionWindow() = delete;
	InternalActionWindow(Input::Window event);
	InternalActionWindow(const InternalActionWindow&) = delete;
	InternalActionWindow(InternalActionWindow&&) = default;
	~InternalActionWindow() override = default;

	bool is_active(const std::vector<Input::Event>& pending_events) const override;

	InternalActionWindow& operator=(const InternalActionWindow&) = delete;
	InternalActionWindow& operator=(InternalActionWindow&&) = default;
private:
	Input::Window m_event;
};

class InternalActionMouse : public ActionEvent
{
public:
	InternalActionMouse() = delete;
	InternalActionMouse(Input::Mouse button);
	InternalActionMouse(const InternalActionMouse&) = delete;
	InternalActionMouse(InternalActionMouse&&) = default;
	~InternalActionMouse() override = default;

	bool is_active(const std::vector<Input::Event>& pending_events) const override;

	InternalActionMouse& operator=(const InternalActionMouse&) = delete;
	InternalActionMouse& operator=(InternalActionMouse&&) = default;
private:
	Input::Mouse m_button;
};

class Action
{
public:
	Action() = delete;
	Action(Input::Keyboard key);
	Action(Input::Window event);
	Action(Input::Mouse button);
	Action(const Action&) = delete;
	Action(Action&&) = default;
	~Action() = default;

	bool is_active(const std::vector<Input::Event>& pending_events) const;

	Action& operator=(const Action&) = delete;
	Action& operator=(Action&&) = default;
private:
	std::unique_ptr<ActionEvent> m_action;
};

#endif