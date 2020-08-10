//
// Created by Tim on 07.08.2020.
//

// STL
#include <algorithm>

// Local
#include "LayerHandler.h"
#include "Layer.h"

namespace Yugen
{
	LayerHandler::LayerHandler()
	{
		firstLayerIdx = 0;
	}

	LayerHandler::~LayerHandler()
	{
		for (auto& layer : layers) {
			delete layer;
		}
		layers.clear();
	}

	void LayerHandler::addLayer(Layer* layer)
	{
		layers.emplace(layers.begin() + firstLayerIdx, layer);
	}

	void LayerHandler::addOverlay(Layer* overlay)
	{
		layers.insert(layers.begin(), overlay);
		firstLayerIdx++;
	}

	void LayerHandler::removeLayer(Layer* layer)
	{
		auto it = std::find(begin(), end(), layer);
		if (it != end()) {
			layers.erase(it);
			firstLayerIdx--;
		}
	}

	void LayerHandler::removeOverlay(Layer* overlay)
	{
		auto it = std::find(begin(), end(), overlay);
		if (it != end()) {
			layers.erase(it);
		}
	}

	std::vector<Layer*>::iterator LayerHandler::begin()
	{
		return layers.begin();
	}

	std::vector<Layer*>::iterator LayerHandler::end()
	{
		return layers.end();
	}
}
