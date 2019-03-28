#include "EventCaller.h"
#include <memory>
void OP::EventCaller::addListener(OP::EventListner * Listener)
{
	l_Listener = Listener;
}

void * OP::EventCaller::callListner(const char* eventName, void * Source, const char* message)
{
	std::unique_ptr<OP::OPEvent> myEvent(new OPEvent(eventName, Source, message));
	return l_Listener->HandleEvent(myEvent.get());
}

void * OP::EventCaller::callListner(OPEvent * Event)
{
	return l_Listener->HandleEvent(Event);
}