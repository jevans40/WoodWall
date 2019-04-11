#include "Simple2DPhysics.h"


//This value allows us to go up to half a million in each direction //LET JESSE KNOW IF THIS IS NOT ENOUGH FOR WHAT EVER REASON
OP::CollisionGrid OP::Simple2DPhysics::CollisionDetector = OP::CollisionGrid(3162,256);


void OP::Simple2DPhysics::setVelocity(fvec2 newVelocity)
{
	Velocity = newVelocity;
}

OP::fvec2 OP::Simple2DPhysics::getVelocity()
{
	return Velocity;
}

void OP::Simple2DPhysics::removeCollision(Simple2DPhysics * collision)
{
	for (int i = 0; i < Collisions.size(); i++) {
		if (Collisions[i] == collision) {
			Collisions.erase(Collisions.begin() + i);
		}
	}
}

void OP::Simple2DPhysics::addCollision(Simple2DPhysics * collision)
{
	Collisions.push_back(collision);
}

bool OP::Simple2DPhysics::isIncorpreal()
{
	return incorpreal;
}

void OP::Simple2DPhysics::setIncorpreal(bool incorpreal)
{
	this->incorpreal = incorpreal;
}

OP::fvec2 OP::Simple2DPhysics::getMovement(std::chrono::milliseconds Time)
{



	CollisionDetector.RemoveBox(this);

	if (!this->isStatic()) {
		std::vector<SimpleBoundingBox * > PossibleCollisions = CollisionDetector.getCollisions(this);
		Collisions.erase(Collisions.begin(), Collisions.end());

		for (SimpleBoundingBox * box : PossibleCollisions) {
			if (box->checkCollision(*this)) {
				Collisions.push_back(box);
				Collision = true;
			}
		}
	}
	
	int deltaTime = Time.count() - lastTime;
	lastTime = Time.count();
	
	deltaTime = deltaTime > 150 ? 15 : deltaTime;
	deltaTime = deltaTime < 0 ? 0 : deltaTime;

	//Move the object
	SubPixel.x += Velocity.x *(float(deltaTime) / 1000);
	SubPixel.y += Velocity.y *(float(deltaTime) / 1000);

	//Handle the collisions
	if (Collision != false && !this->isStatic()) {
		for (int i = 0; i < Collisions.size(); i++) {

			((Simple2DPhysics *)Collisions[i])->onCollision(this);
			onCollision(((Simple2DPhysics *)Collisions[i]));
			//Place the object outside the new object
			// If its actually hit and needs to be moved
			if (!incorpreal && !((Simple2DPhysics *)Collisions[i])->isIncorpreal()) {

				/*if(this->checkCollision(*Collisions[i])){
					int quad = this->getCollisionQuadrant(*Collisions[i]);
					if (quad == 0) {
						SubPixel.x = Collisions[i]->getMax().x;
					}
					if (quad == 1) {
						SubPixel.y = Collisions[i]->getMax().y;
					}
					if (quad == 2) {
						SubPixel.x = Collisions[i]->getMin().x-Size.x;
					}
					if (quad == 3) {
						SubPixel.y = Collisions[i]->getMin().y - Size.y;
					}
				}*/
			}
		}
	}
	//Update the bounding box
	this->setMin({ int(SubPixel.x),int(SubPixel.y) });
	this->setMax({ int(SubPixel.x + Size.x),int(SubPixel.y + Size.y)});



	//Make sure final product is in bounds
	CollisionDetector.InsertBox(this);
	return { SubPixel.x, SubPixel.y};
}

bool OP::Simple2DPhysics::CollidesWith(Simple2DPhysics * collision)
{
	for (int i = 0; i < Collisions.size(); i++) {
		if (Collisions[i] = collision)
			return true;
	}
	return false;
}

OP::Simple2DPhysics * OP::Simple2DPhysics::getFirstCollision()
{
	return (Simple2DPhysics *)Collisions[0];
}

OP::fvec2 OP::Simple2DPhysics::getSubPixel()
{
	return SubPixel;
}

void OP::Simple2DPhysics::setSubPixel(fvec2 newPosition)
{

	this->setMin({ int(newPosition.x),int(newPosition.y)});
	this->setMax({ int(newPosition.x + Size.x), int(newPosition.y + Size.y)});
	this->SubPixel = { float(newPosition.x),float(newPosition.y)};
}
