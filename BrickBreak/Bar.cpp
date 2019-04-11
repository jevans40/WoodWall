#include "Bar.h"
#include <Omega-Phi/Layer.h>

void Bar::Update(std::chrono::milliseconds Time)
{
	OP::fvec2 subpixel = this->getMovement(Time);
	OP::fvec2 velocity = { 0,0 };
	if (this->getLayer()->getKey("D") || this->getLayer()->getKey("d")) {
		velocity.x =600;
	}

	if (this->getLayer()->getKey("A")) {
		velocity.x = -600;
	}
	this->setVelocity(velocity);

	if (subpixel.x < 0) {
		subpixel.x = 0;
		setSubPixel({ 0, subpixel.y });
	} else if(subpixel.x + getSize().x > 1280) {

		subpixel.x = 1280 - this->getSize().x;
		setSubPixel(subpixel);
	}

	this->setXPos(subpixel.x);

}

void Bar::reset()
{
	this->setXPos(origpos.x);
	this->setSubPixel({ origpos.x, origpos.y });
}
