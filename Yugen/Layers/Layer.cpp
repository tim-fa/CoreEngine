//
// Created by Tim on 07.08.2020.
//

#include "Layer.h"

namespace Yugen
{
	Layer::Layer(const std::string& debugName)
		: debugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}

	const std::string& Layer::getDebugName() const
	{
		return debugName;
	}
}
