#pragma once

#include "Events.h"
#include <functional>

namespace Yugen::Events
{
	class EventDispatcher
	{
		private:
			Event& m_Event;
		public:
			EventDispatcher(Event& event)
				: m_Event(event)
			{
			}

			template<typename T>
			void Dispatch(std::function<bool(T&)> func)
			{
				if ((int)m_Event.getType() & (int)T::getStaticType()) {
					m_Event.m_Handled = func(*(T*)&m_Event);
				}
			}
	};
}
