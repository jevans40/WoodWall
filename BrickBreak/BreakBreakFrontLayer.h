#pragma once
#include <Omega-Phi/Layer.h>
#include <Omega-Phi/Game.h>
#include <unordered_map>
#include "BoundString.h"
#include "Brick.h"
#include "Bar.h"

class BreakBreakFrontLayer : public OP::Layer  {
	std::unordered_map<Brick*,BoundString*>  BrickToString;
	Brick * touchedBrick = nullptr;
	Bar * thisbar;
public:


	BreakBreakFrontLayer(OP::Game * game) : Layer(game, (*new OP::Shader("./../res/Shaders/VertexShader.vert", "./../res/Shaders/FragShader.frag")), "BrickBreakFront", 0) {
		Init();
	}

	void Init();

	std::string getObjectGrid(Brick * brick);

	void Update(std::chrono::milliseconds Time) override;

	Brick * getTouched();

};