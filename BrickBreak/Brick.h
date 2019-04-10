#pragma once
#include <Omega-Phi/SimpleSprite.h>
#include <Omega-Phi/Simple2DPhysics.h>

class Brick : public OP::Simple2DPhysics, public OP::SimpleSprite  {
		bool Destroyed;
		int l_HP;
		int l_CurrentHP;
		char * color;
	public:
		~Brick() override;

		Brick(OP::fvec3 pos, OP::fvec2 size,char * Color, int hp = 5) : SimpleSprite(pos, size, Renderable::GetColor(Color[0],Color[1],Color[2],Color[3])), Simple2DPhysics( OP::fvec2(pos.x, pos.y),OP::ivec2(size.x,size.y)) {
			setSprite("sen.png");
			l_HP = hp;
			l_CurrentHP = l_HP;
			color = Color;
		}

		void Update(std::chrono::milliseconds Time) override;

		bool getDestroyed();

		void onCollision(Simple2DPhysics * left) override;

		std::string getCoordString() {
			return this->getBoxes();
		}

};