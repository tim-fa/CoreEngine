//
// Created by Tim on 07.08.2020.
//

#ifndef LAYERHANDLER_H
#define LAYERHANDLER_H

// STL
#include <vector>

namespace Yugen
{
	class Layer;
	class LayerHandler
	{
		public:
			LayerHandler();
			~LayerHandler();

			void addLayer(Layer* layer);
			void addOverlay(Layer* overlay);
			void removeLayer(Layer* layer);
			void removeOverlay(Layer* overlay);

			std::vector<Layer*>::iterator begin();
			std::vector<Layer*>::iterator end();

		private:
			std::vector<Layer*> layers;
			int firstLayerIdx;
	};
}

#endif //LAYERHANDLER_H
