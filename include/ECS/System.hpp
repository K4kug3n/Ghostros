#ifndef ECS_SYSTEM_HPP
#define ECS_SYSTEM_HPP

class World;
class RenderWindow;
class InputHandler;

class System
{
public:
	System(World& world);
	System(const System&) = delete;
	System(System&&) = default;
	~System() = default;

	virtual void update(RenderWindow& window, InputHandler& input_handler, double delta_time) = 0;

	System& operator=(const System&) = delete;
	System& operator=(System&&) = default;
private:
	World& m_world;
};

#endif
