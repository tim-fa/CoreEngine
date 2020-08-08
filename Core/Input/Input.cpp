#include "Input.h"

namespace Core
{
	std::map<int, bool> Input::keyMap;
	std::map<int, bool> Input::mouseMap;
	float Input::mouseX, Input::mouseY;

	bool Input::isKeyPressed(KeyCode keycode)
	{
		return keyMap[keycode];
	}

	bool Input::isMouseButtonPressed(MouseButtonCode button)
	{
		return mouseMap[static_cast<const int>(button)];
	}

	float Input::getMouseX()
	{
		return mouseX;
	}

	float Input::getMouseY()
	{
		return mouseY;
	}

	bool Input::onKeyPressedEvent(Events::KeyPressedEvent& e)
	{
		keyMap[e.getKeyCode()] = true;
		return false;
	}

	bool Input::onKeyReleasedEvent(Events::KeyReleasedEvent& e)
	{
		keyMap[e.getKeyCode()] = false;
		return false;
	}

	bool Input::onMousePressedEvent(Events::MousePressedEvent& e)
	{
		mouseMap[e.getButton()] = false;
		return false;
	}

	bool Input::onMouseReleasedEvent(Events::MouseReleasedEvent& e)
	{
		mouseMap[e.getButton()] = false;
		return false;
	}

	bool Input::onMouseMovedEvent(Events::MouseMovedEvent& e)
	{
		mouseX = e.getX();
		mouseY = e.getY();
		return false;
	}
}