#include "Window/InputEvent.hpp"

#include <SFML/Window/Event.hpp>

InputEvent::Event InputEvent::Event::From(const sf::Event& sf_event)
{
	InputEvent::Event custom_event;
	custom_event.type = static_cast<InputEvent::Window>(sf_event.type);
	switch (sf_event.type)
	{
	case sf::Event::EventType::Resized:
		custom_event.size = InputEvent::Event::SizeEvent{ sf_event.size.width, sf_event.size.height };
		break;
	case sf::Event::EventType::KeyPressed:
	case sf::Event::EventType::KeyReleased:
		custom_event.key = InputEvent::Event::KeyEvent{ static_cast<InputEvent::Keyboard>(sf_event.key.code) };
		break;
	case sf::Event::EventType::MouseWheelMoved:
		custom_event.mouse_wheel = InputEvent::Event::MouseWheelEvent{ sf_event.mouseWheel.delta, sf_event.mouseWheel.x, sf_event.mouseWheel.y };
		break;
	case sf::Event::EventType::MouseButtonPressed:
	case sf::Event::EventType::MouseButtonReleased:
		custom_event.mouse_button = InputEvent::Event::MouseButtonEvent{ static_cast<InputEvent::Mouse>(sf_event.mouseButton.button), sf_event.mouseButton.x, sf_event.mouseButton.y };
		break;
	case sf::Event::EventType::MouseMoved:
	case sf::Event::EventType::MouseEntered:
	case sf::Event::EventType::MouseLeft:
		custom_event.mouse_move = InputEvent::Event::MouseMoveEvent{ sf_event.mouseMove.x, sf_event.mouseMove.y };
		break;
	default:
		break;
	}
	return custom_event;
}
