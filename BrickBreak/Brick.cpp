#include "Brick.h"

Brick::~Brick()
{
	std::cout << "Deleted Brick!" << '\n';
}

void Brick::reset()
{
	l_CurrentHP = l_HP;
	if (Destroyed) {
		setXPos(origpos.x);
		this->setSubPixel({ origpos.x, this->getSubPixel().y});
		Destroyed = false;
	}
	this->setColor(OP::Renderable::GetColor((255 - (float(l_CurrentHP) / l_HP * 255)),
		255 - (255 - (float(l_CurrentHP) / l_HP * 255)),
		(255 * (float(getXPos()) + this->getSize().x) / 1280) * (255 - (float(l_CurrentHP) / l_HP * 255)),
		255));
}

void Brick::Update(std::chrono::milliseconds Time)
{
	if (Destroyed) {
		this->setXPos(this->getXPos() - 9000);
		this->setSubPixel({this->getSubPixel().x - 9000, this->getSubPixel().y});
	}
	if (hit) {
		canHit = false;
		lastTime = Time.count() + 15;
		hit = false;
	}
	if (lastTime < Time.count()) {
		canHit = true;
	}
	

	this->setColor(OP::Renderable::GetColor((255 - (float(l_CurrentHP)/l_HP * 255)),
											 255 - (255 - (float(l_CurrentHP) / l_HP * 255)),
											(255 * (float(getXPos()) + this->getSize().x)/1280) * ((float(l_CurrentHP) / l_HP * 255)),
											 255));
}



bool Brick::getDestroyed()
{
	return Destroyed;
}

void Brick::onCollision(Simple2DPhysics * left)
{
	if (left->GetName() == "ball" && canHit == true && hit == false) {
		l_CurrentHP = l_CurrentHP - 1;
		hit = true;
		canHit = false;
		if (l_CurrentHP == 0) {
			Destroyed = true;
		}
	}
}
