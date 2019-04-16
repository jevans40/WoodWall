#pragma once
#include <Omega-Phi/OPInclude.h>


class Menu : public OP::Layer {

	OP::SimpleSprite * Sprite1;
	OP::SimpleSprite * Sprite2;
	OP::SimpleSprite * Sprite3;
		
public:
	Menu(OP::Game * game, OP::Shader * Shader, std::string name, bool Visible = true, bool Loaded = true) : Layer(game, *Shader, name.c_str() , Visible, Loaded) {
		renderMenu();
	}

	void renderMenu();
	
	void Update(std::chrono::milliseconds Time) override;
};
