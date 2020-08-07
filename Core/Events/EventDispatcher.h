#pragma once

#include "Events.h"
#include <functional>

namespace Core::Events
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
				if ((__int32)m_Event.getType() & (__int32)T::getStaticType()) {
					m_Event.m_Handled = func(*(T*)&m_Event);
				}
			}
	};
}
