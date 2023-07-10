#ifndef GRAPHICS_SCENEITEM_HPP
#define GRAPHICS_SCENEITEM_HPP

class InputHandler;
class RenderWindow;

class SceneItem
{
public:
	virtual ~SceneItem();

	virtual void update(RenderWindow& window, InputHandler& input_handler, double delta_time) = 0;
};


#endif