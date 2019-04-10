#include "BoundString.h"
#include "BreakBreakFrontLayer.h"

void BoundString::Update(std::chrono::milliseconds Time) {
	if(this->getString() != layer->getObjectGrid((Brick *)bound))
	//this->setString(layer->getObjectGrid((Brick *)bound));
	if (OP::fvec3(this->getPos().x,getPos().y - 20,getPos().z)  != OP::fvec3(bound->getXPos(), bound->getYPos(), bound->getZPos()))
	this->setPos({ bound->getXPos(),bound->getYPos() + 20,bound->getZPos() });
}
