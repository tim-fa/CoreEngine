//
// Created by Tim on 07.08.2020.
//

#ifndef ENGINE_IMGUILAYER_H
#define ENGINE_IMGUILAYER_H

// Local
#include "Layers/Layer.h"
#include "Events/Events.h"
#include "Log/Logger.h"

namespace Core
{
	class Application;

	class ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer(Application& app);
			~ImGuiLayer() override;

			void onCreate() override;
			void onDestroy() override;
			void onImGuiRender() override;

			void begin();
			void end();

		private:
			float time = 0;
			Application& app;
			Logger logger;
	};
}

#endif //ENGINE_IMGUILAYER_H