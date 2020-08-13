#pragma once

#ifndef INPUT_H
#define INPUT_H

// STL
#include <map>

// Local
#include "Events/Events.h"
#include "Keycodes.h"

namespace Yugen::Input
{
	class InputHandler
	{
		public:
			static bool isKeyPressed(KeyCode keycode);
			static bool isMouseButtonPressed(MouseButtonCode button);
			static float getMouseX();
			static float getMouseY();

			static bool onKeyPressedEvent(Events::KeyPressedEvent& e);
			static bool onKeyReleasedEvent(Events::KeyReleasedEvent& e);

			static bool onMousePressedEvent(Events::MousePressedEvent& e);
			static bool onMouseReleasedEvent(Events::MouseReleasedEvent& e);
			static bool onMouseMovedEvent(Events::MouseMovedEvent& e);

		private:
			static std::map<int, bool> keyMap;
			static std::map<int, bool> mouseMap;
			static float mouseX, mouseY;
	};
}

#endif