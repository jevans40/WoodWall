#pragma once
#include "SimpleSprite.h"

class House : public OP::SimpleSprite{
private:
	static OP::initializer init;
	static std::vector <std::string> files;
	std::vector < OP::SpriteLoc* > l_SpriteImages;
	int currentSprite;
public:
	House(OP::EventListner * TextureHandler, OP::fvec3 pos = OP::fvec3(0, 0, 0), OP::fvec2 size = OP::fvec2(1, 1), unsigned int Color = 0xffffffff) : SimpleSprite(pos, size, Color) {

		
		setSprite("House.png");
	}

	static void setFiles() {
		files.push_back("House.png");
	}
};