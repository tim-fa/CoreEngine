//
// Created by Tim on 07.08.2020.
//

#ifndef ENGINE_IMGUILAYER_H
#define ENGINE_IMGUILAYER_H

// Local
#include "Layers/Layer.h"
#include "Application.h"
#include "Events/Events.h"

namespace Core
{
	class ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer(Application& app);
			~ImGuiLayer() override;

			void onCreate() override;
			void onDestroy() override;
			void onUpdate() override;
			void onEvent(Events::Event& e) override;

			bool onMouseButtonPressedEvent(Events::MousePressedEvent& e);
			bool onMouseButtonReleasedEvent(Events::MouseReleasedEvent& e);
			bool onMouseScrolledEvent(Events::MouseScrolledEvent& e);
			bool onMouseMovedEvent(Events::MouseMovedEvent& e);
			bool onWindowResizedEvent(Events::ResizeWindowEvent& e);
			bool onKeyTypedEvent(Events::KeyTypedEvent& e);
			bool onKeyPressedEvent(Events::KeyPressedEvent& e);
			bool onKeyReleasedEvent(Events::KeyReleasedEvent& e);
		private:
			float time = 0;
			Application& app;
			Logger logger;
	};
}

#endif //ENGINE_IMGUILAYER_H
