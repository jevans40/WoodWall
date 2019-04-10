#pragma once
#include "EventListener.h"
#include "OPEvent.h"
#include <iostream>
namespace OP {
	class EventCaller {
	private:
		OP::EventListner * l_Listener;
	public:
		~EventCaller() {
			std::cout << "EventListner has been destroyed!" << std::endl;
		}

		void addListener(OP::EventListner * Listener);

		void * callListner(OPEvent * Event);
		void * callListner(const char* eventName, void * Source, const char* message = "");
	};
}