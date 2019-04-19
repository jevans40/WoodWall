#pragma once
#include <Omega-Phi/OPInitialize.h>


class Tile : public OP::SimpleSprite {
private:

public:
	Tile(OP::fvec3 pos = OP::fvec3(0, 0, 0), OP::fvec2 size = OP::fvec2(1, 1), unsigned int Color = 0xffffffff, int TileType = 0) : SimpleSprite(pos, size, Color) {
		setTileType(TileType);
	}

	~Tile() override {
	}

	void setTileType(int TileType) {
		if (TileType == 0) {

		}
		else if (TileType == 1) {
			setSprite("Tile_0");
		}
		else if (TileType == 2) {
			setSprite("Tile_1");
		}
		else if (TileType == 3) {
			setSprite("Tile_2");
		}
	}

};