#include "Brick.h"

Brick::~Brick()
{
	std::cout << "Deleted Brick!" << '\n';
}

void Brick::Update(std::chrono::milliseconds Time)
{
	if (Destroyed) {
		this->setXPos(this->getSubPixel().x - 9000);
		this->setSubPixel({int(this->getSubPixel().x - 9000), int(this->getSubPixel().y)});
	}
	this->setColor(OP::Renderable::GetColor(255 - float(l_CurrentHP)/l_HP * 255, color[1],color[2],color[3]));
}

bool Brick::getDestroyed()
{
	return Destroyed;
}

void Brick::onCollision(Simple2DPhysics * left)
{
	if (left->GetName() == "ball" ) {
		l_CurrentHP = l_CurrentHP - 1;
		if (l_CurrentHP == 0) {
			Destroyed = true;
		}
	}
}
