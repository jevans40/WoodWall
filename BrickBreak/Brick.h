#pragma once
#include <Omega-Phi/SimpleSprite.h>
#include <Omega-Phi/Simple2DPhysics.h>

class Brick : public OP::Simple2DPhysics, public OP::SimpleSprite  {
		bool Destroyed;
		int l_HP;
		int l_CurrentHP;
		char * color;
		bool hit = false;
		bool canHit = true;
		std::chrono::milliseconds::rep lastTime;
		OP::fvec3 origpos;

	public:
		~Brick() override;

		Brick(OP::fvec3 pos, OP::fvec2 size, int hp = 5) : SimpleSprite(pos, size, 0xffffffff), Simple2DPhysics( OP::fvec2(pos.x, pos.y),OP::ivec2(size.x,size.y)) {
			origpos = pos;
			this->setStatic(true);
			setSprite("sen.png");
			l_HP = hp;
			l_CurrentHP = l_HP;
			color;
		}

		void reset();

		void Update(std::chrono::milliseconds Time) override;

		bool getDestroyed();

		void onCollision(Simple2DPhysics * left) override;

		std::string getCoordString() {
			return this->getBoxes();
		}

};