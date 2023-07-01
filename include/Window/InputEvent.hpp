#ifndef WINDOW_INPUTEVENT_HPP
#define WINDOW_INPUTEVENT_HPP

#include <memory>

namespace sf
{
	class Event;
}

// Heavily inspired by SFML & SDL event structure
namespace Input 
{
	enum class Keyboard
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num8, Num9,
		Escape, LControl, LShift, LAlt, LSystem, RControl, RShift, RAlt, RSystem, Menu,
		LBracket, RBracket, Semilicon, Comma, Period, Apostrophe, Slash, Backslash, Grave, Equal, Hyphen,
		Space, Enter, Backspace, Tab,
		PageUp, PageDown, End, Home, Insert, Delete, Add, Substract, Multiply, Divide, Left, Right, Up, Down,
		Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad8, Numpad9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
		Pause, KeyCount
	};

	enum class Window
	{
		Closed, Resized, LostFocus, GainedFocus, TextEntered, KeyPressed, KeyReleased,
		MouseWheelMoved, MouseWheelScrolled, MouseButtonPressed, MouseButtonReleased, MouseMouved, MouseEntered, MouseLeft,
		JoystickMoved, JoystickConnected, JoystickDisconnected, TouchBegan, TouchEnded, SensorChanged
	};

	enum class Mouse
	{
		Left, Right, Middle,
		XButton1, XButton2
	};

	class Event
	{
	public:
		struct SizeEvent
		{
			unsigned int width;
			unsigned int height;
		};

		struct KeyEvent
		{
			Keyboard key;
		};

		struct MouseMoveEvent
		{
			int x;
			int y;
		};

		struct MouseButtonEvent
		{
			Mouse button;
			int x;
			int y;
		};

		struct MouseWheelEvent
		{
			int delta;
			int x;
			int y;
		};

		Window type;

		union
		{
			SizeEvent size;
			KeyEvent key;
			MouseMoveEvent mouse_move;
			MouseButtonEvent mouse_button;
			MouseWheelEvent mouse_wheel;
		};

		static Event From(const sf::Event& sf_event);
	};
}

#endif