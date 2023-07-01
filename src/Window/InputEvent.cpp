#include "Window/InputEvent.hpp"

#include <SFML/Window/Event.hpp>

Input::Event Input::Event::From(const sf::Event& sf_event)
{
	Input::Event custom_event;
	custom_event.type = static_cast<Input::Window>(sf_event.type);
	switch (sf_event.type)
	{
	case sf::Event::EventType::Resized:
		custom_event.size = Input::Event::SizeEvent{ sf_event.size.width, sf_event.size.height };
		break;
	case sf::Event::EventType::KeyPressed:
	case sf::Event::EventType::KeyReleased:
		custom_event.key = Input::Event::KeyEvent{ static_cast<Input::Keyboard>(sf_event.key.code) };
		break;
	case sf::Event::EventType::MouseWheelMoved:
		custom_event.mouse_wheel = Input::Event::MouseWheelEvent{ sf_event.mouseWheel.delta, sf_event.mouseWheel.x, sf_event.mouseWheel.y };
		break;
	case sf::Event::EventType::MouseButtonPressed:
	case sf::Event::EventType::MouseButtonReleased:
		custom_event.mouse_button = Input::Event::MouseButtonEvent{ static_cast<Input::Mouse>(sf_event.mouseButton.button), sf_event.mouseButton.x, sf_event.mouseButton.y };
		break;
	case sf::Event::EventType::MouseMoved:
	case sf::Event::EventType::MouseEntered:
	case sf::Event::EventType::MouseLeft:
		custom_event.mouse_move = Input::Event::MouseMoveEvent{ sf_event.mouseMove.x, sf_event.mouseMove.y };
		break;
	default:
		break;
	}
	return custom_event;
}
