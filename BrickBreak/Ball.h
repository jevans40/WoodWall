#pragma once
#include <Omega-Phi/SimpleSprite.h>
#include <Omega-Phi/Simple2DPhysics.h>

class Ball : public OP::SimpleSprite, public OP::Simple2DPhysics {
	std::chrono::milliseconds::rep lastTime;

	OP::fvec2 bounds = { 1280,720 };
	OP::fvec3 origpos;

	bool game = false;

	public:
		Ball(OP::fvec3 pos, OP::fvec2 size, unsigned int Color) : SimpleSprite(pos, size, Color), Simple2DPhysics({ pos.x,pos.y }, { int(size.x),int(size.y)}, "ball") {
			this->setVelocity({400, -300});
			this->setStatic(false);
			this->origpos = pos;
		}

	void Update(std::chrono::milliseconds Time) override;

	void onCollision(Simple2DPhysics * left) override;

	bool gameover();

	void reset() {
		OP::fvec2 veloc = { 300,-400 };
		this->setVelocity(veloc);
		this->setXPos(origpos.x);
		this->setYPos(origpos.y);
		this->setSubPixel({ origpos.x, origpos.y });
		game = false;
	}
};