#pragma once
#include <Omega-Phi/Game.h>
#include <Omega-Phi/StringSprite.h>


class BrickBreak : public OP::Game {

public:
	BrickBreak() : Game("BrickBreak", 1280, 720) { Init(); }

	void Init() override;

};




