#pragma once
#include <Omega-Phi/Simple2DPhysics.h>
#include <Omega-Phi/SimpleSprite.h>
#include <Omega-Phi/Layer.h>
#include <chrono>


class Bar : public OP::Simple2DPhysics, public OP::SimpleSprite {
public:

	Bar(OP::fvec3 pos, OP::fvec2 size) : SimpleSprite(pos, size,0x404040ff ), Simple2DPhysics(OP::fvec2(pos.x, pos.y), OP::ivec2(size.x,size.y)) {
		this->setIncorpreal(true);
	}

	void Update(std::chrono::milliseconds Time) override;

	void onCollision(Simple2DPhysics * left) override { Collision = false; std::cout << this->getCollisionQuadrant(*left) << std::endl; }

};