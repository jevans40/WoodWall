#pragma once
#include "EventListener.h"
#include "OPEvent.h"
namespace OP {
	class EventCaller {
	private:
		OP::EventListner * l_Listener;
	public:
		void addListener(OP::EventListner * Listener);

		void callListner(OPEvent * Event);
		void callListner(const char* eventName, void * Source);
	};
}