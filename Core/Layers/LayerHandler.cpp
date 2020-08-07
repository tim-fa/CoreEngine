//
// Created by Tim on 07.08.2020.
//

// STL
#include <algorithm>

// Local
#include "LayerHandler.h"
#include "Layer.h"

namespace Core
{
	LayerHandler::LayerHandler()
	{
		layerInserter = layers.begin();
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
		layerInserter = layers.emplace(layerInserter, layer);
	}

	void LayerHandler::addOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerHandler::removeLayer(Layer* layer)
	{
		auto it = std::find(begin(), end(), layer);
		if (it != end()) {
			layers.erase(it);
			layerInserter--;
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
