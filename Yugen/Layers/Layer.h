//
// Created by Tim on 07.08.2020.
//

#ifndef LAYER_H
#define LAYER_H

// Local
#include "Events/Event.h"

namespace Yugen
{
	class Layer
	{
		public:
			Layer(const std::string& debugName);
			virtual ~Layer();

			virtual void onCreate()
			{
			}

			virtual void onDestroy()
			{
			}

			virtual void onUpdate()
			{
			}

			virtual void onEvent(Events::Event& e)
			{
			}

			virtual void onImGuiRender()
			{
			}

			const std::string& getDebugName() const;

		private:
			std::string debugName;
	};
}
#endif //ENGINE_LAYER_H
