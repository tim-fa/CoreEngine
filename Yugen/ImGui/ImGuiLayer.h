#pragma once
//
// Created by Tim on 07.08.2020.
//

#ifndef ENGINE_IMGUILAYER_H
#define ENGINE_IMGUILAYER_H

// Library
#include "Log/Logger.h"

// Local
#include "Layers/Layer.h"
#include "Events/Events.h"

namespace Yugen
{
	class ImGuiLayer : public Layers::Layer
	{
		public:
			explicit ImGuiLayer(class Application& app);
			~ImGuiLayer() override;

			void onCreate() override;
			void onDestroy() override;
			void onImGuiRender() override;

			void begin();
			void end();

		private:
			float time = 0;
			Application& app;
			Log::Logger logger;
	};
}

#endif //ENGINE_IMGUILAYER_H
