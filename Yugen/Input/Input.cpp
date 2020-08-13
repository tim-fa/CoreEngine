#include "Input.h"

namespace Yugen::Input
{
	std::map<int, bool> InputHandler::keyMap;
	std::map<int, bool> InputHandler::mouseMap;
	float InputHandler::mouseX, InputHandler::mouseY;

	bool InputHandler::isKeyPressed(KeyCode keycode)
	{
		return keyMap[keycode];
	}

	bool InputHandler::isMouseButtonPressed(MouseButtonCode button)
	{
		return mouseMap[static_cast<const int>(button)];
	}

	float InputHandler::getMouseX()
	{
		return mouseX;
	}

	float InputHandler::getMouseY()
	{
		return mouseY;
	}

	bool InputHandler::onKeyPressedEvent(Events::KeyPressedEvent& e)
	{
		keyMap[e.getKeyCode()] = true;
		return false;
	}

	bool InputHandler::onKeyReleasedEvent(Events::KeyReleasedEvent& e)
	{
		keyMap[e.getKeyCode()] = false;
		return false;
	}

	bool InputHandler::onMousePressedEvent(Events::MousePressedEvent& e)
	{
		mouseMap[e.getButton()] = false;
		return false;
	}

	bool InputHandler::onMouseReleasedEvent(Events::MouseReleasedEvent& e)
	{
		mouseMap[e.getButton()] = false;
		return false;
	}

	bool InputHandler::onMouseMovedEvent(Events::MouseMovedEvent& e)
	{
		mouseX = e.getX();
		mouseY = e.getY();
		return false;
	}
}