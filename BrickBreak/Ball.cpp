#include "Ball.h"
void Ball::Update(std::chrono::milliseconds Time)
{
	OP::ivec2 movement = this->getMovement(Time);
	OP::fvec2 reflection = getVelocity();



	OP::ivec2 subpixel = { int(this->getSubPixel().x),int(this->getSubPixel().y)};
	
	if (subpixel.x < 0) {
		setSubPixel({ 0,subpixel.y });
		reflection.x *= -1;
	}
	if (subpixel.x > bounds.x - int(getSize().x)) {
		setSubPixel({ 1280 - int(getSize().x),subpixel.y });
		reflection.x *= -1;
	}
	if (subpixel.y < 0) {

		setSubPixel({subpixel.x,0 });
		reflection.y *= -1;
	}
	if (subpixel.y > bounds.y - int(getSize().y)) {
		setSubPixel({subpixel.x, 720 - int(getSize().y) });
		reflection.y *= -1;
	}

	this->setVelocity(reflection);


	this->setYPos(subpixel.y);
	this->setXPos(subpixel.x);

	lastTime = Time.count();
}

void Ball::onCollision(Simple2DPhysics * left)
{
	OP::fvec2 reflection = getVelocity();

	int Quadrant = this->getCollisionQuadrant(*left);
	Quadrant = Quadrant;
	std::cout << Quadrant << std::endl;
	if (Quadrant == 0 && reflection.x > 0) {
		reflection.x *= -1;
	}
	if(Quadrant == 1 && reflection.y < 0) {
		reflection.y *= -1;
	}
	if (Quadrant == 2 && reflection.x < 0) {
		reflection.x *= -1;
	}
	if (Quadrant == 3 && reflection.y > 0) {
		reflection.y *= -1;
	}


	this->setVelocity(reflection);
	Collision = false;
}
