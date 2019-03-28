#pragma once
#include "OPEvent.h"
namespace OP {
	class EventListner {
	public:
		virtual void* HandleEvent(OPEvent * Event) = 0;
	};
}