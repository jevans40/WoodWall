#pragma once
#include <Omega-Phi/StringSprite.h>
#include <Omega-Phi/Simple2DPhysics.h>
#include "Brick.h"

class BreakBreakFrontLayer;

class BoundString : public OP::StringSprite {

	OP::fvec2 bounds = { 1280,720 };
	OP::SimpleSprite * bound;
	BreakBreakFrontLayer * layer;
public:
	BoundString(OP::fvec3 pos, int size, OP::SimpleSprite * boundObject, BreakBreakFrontLayer * thislayer) : StringSprite((OP::Layer *) thislayer, { pos.x,pos.y+ 20,pos.z }, size, true, "", 1.25) {
		bound = boundObject;
		this->layer = thislayer;
	}

	void Update(std::chrono::milliseconds Time);

};