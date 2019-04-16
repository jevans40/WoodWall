#pragma once
#include <Omega-Phi/OPInclude.h>

class WoodWall : public OP::Game {

public:
	WoodWall() : Game("WoodWall", 1920, 1080) { Init(); }

	void Init() override;

	void gameTick() override {}

	void gameUpdate() override {}

	void gameRender() override {}

};