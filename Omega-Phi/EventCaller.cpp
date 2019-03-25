#include "EventCaller.h"
#include <memory>
void OP::EventCaller::addListener(OP::EventListner * Listener)
{
	l_Listener = Listener;
}

void OP::EventCaller::callListner(const char* eventName, void * Source)
{
	std::unique_ptr<OP::OPEvent> myEvent(new OPEvent(eventName, Source));
	l_Listener->HandleEvent(myEvent.get());
}

void OP::EventCaller::callListner(OPEvent * Event)
{
	l_Listener->HandleEvent(Event);
}