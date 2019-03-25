#include "OPEvent.h"

OP::OPEvent::OPEvent(const char * name, void * Source)
{
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