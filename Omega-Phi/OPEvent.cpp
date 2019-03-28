#include "OPEvent.h"

OP::OPEvent::OPEvent(const char * name, void * Source, const char* message)
{
	l_message = message;
	l_name = name;
	l_Source = Source;
}

OP::OPEvent::~OPEvent()
{
}

void * OP::OPEvent::getSource()
{
	return l_Source;
}

const char * OP::OPEvent::getName()
{
	return l_name;
}

const char * OP::OPEvent::getMessage()
{
	return l_message;
}
