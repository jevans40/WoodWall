#pragma once
#include <Omega-Phi/SimpleSprite.h>
#include <Omega-Phi/Simple2DPhysics.h>
#include "BreakBreakFrontLayer.h"

class Ball : public OP::SimpleSprite, public OP::Simple2DPhysics {
	std::chrono::milliseconds::rep lastTime;
	BreakBreakFrontLayer * layer;

	OP::fvec2 bounds = { 1280,720 };


	public:
		Ball(OP::fvec3 pos, OP::fvec2 size, unsigned int Color, BreakBreakFrontLayer * layer) : SimpleSprite(pos, size, Color), Simple2DPhysics({ pos.x,pos.y }, { int(size.x),int(size.y)}, "ball"), layer(layer) {
			this->setVelocity({300, 300});
			this->setStatic(false);

		}

	void Update(std::chrono::milliseconds Time) override;

	void onCollision(Simple2DPhysics * left) override;
};