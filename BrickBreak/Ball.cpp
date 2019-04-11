#include "Ball.h"
void Ball::Update(std::chrono::milliseconds Time)
{
	OP::fvec2 movement = this->getMovement(Time);
	OP::fvec2 reflection = getVelocity();



	OP::fvec2 subpixel = { this->getSubPixel().x, this->getSubPixel().y};
	
	if (subpixel.x < 0) {
		setSubPixel({ 0,subpixel.y });
		reflection.x *= -1;
	}
	if (subpixel.x > bounds.x - getSize().x) {
		setSubPixel({ 1280 - getSize().x,subpixel.y });
		reflection.x *= -1;
	}
	if (subpixel.y < 0) {

		setSubPixel({subpixel.x,0 });
		reflection.y *= -1;
	}
	if (subpixel.y > bounds.y - int(getSize().y)) {
		setSubPixel({subpixel.x, 720 - getSize().y });
		reflection.y *= -1;
		game = true;
	}

	this->setVelocity(reflection);


	this->setYPos(subpixel.y);
	this->setXPos(subpixel.x);

	lastTime = Time.count();
}

void Ball::onCollision(Simple2DPhysics * left)
{
	OP::fvec2 reflection = getVelocity();

	if (left->GetName() == "bar") {
		float angle = left->getCollisionAngle(*this);
		std::cout << angle << '\n';
		reflection = { 400 * cos(angle / float((4 * atan(1))) ), 200 + 200 * abs(cos(angle)) };
	}

	int Quadrant = this->getCollisionQuadrant(*left);
	Quadrant = Quadrant;
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

bool Ball::gameover()
{
	return game;
}
