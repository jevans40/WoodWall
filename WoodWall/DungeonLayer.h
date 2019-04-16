#pragma once
#include <Omega-Phi/OPInclude.h>

class DungeonLayer : OP::Layer {

	public:
		DungeonLayer(OP::Game * game,OP::Shader * shader) : Layer(game,*shader,"Dungeon",false,false) {

		}

};