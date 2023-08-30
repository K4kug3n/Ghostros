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
	virtual ~System();

	virtual void update(double delta_time) = 0;

	System& operator=(const System&) = delete;
	System& operator=(System&&) = default;
protected:
	World& m_world;
};

#endif
