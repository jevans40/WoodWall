#pragma once
#include <Omega-Phi/Layer.h>
#include <Omega-Phi/Game.h>
#include <unordered_map>
#include <Omega-Phi/StringSprite.h>
#include "Brick.h"
#include "Bar.h"
#include "Ball.h"

class BreakBreakFrontLayer : public OP::Layer  {
	std::vector<Brick*>  BrickToString;
	Brick * touchedBrick = nullptr;
	Bar * thisbar;
	Ball * thisball;
	OP::StringSprite myString;
	

	bool start;
	bool reset = false;
public:


	BreakBreakFrontLayer(OP::Game * game) : Layer(game, (*new OP::Shader("./../res/Shaders/VertexShader.vert", "./../res/Shaders/FragShader.frag")), "BrickBreakFront", 0), myString(this, { -100,100,100 }) {
		Init();
	}

	void Init();

	std::string getObjectGrid(Brick * brick);

	void Update(std::chrono::milliseconds Time) override;

	Brick * getTouched();

};