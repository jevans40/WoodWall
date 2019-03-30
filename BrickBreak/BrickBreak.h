#pragma once
#include <Omega-Phi/OPInclude.h>



class BrickBreak : public OP::Game {

public:
	BrickBreak() : Game("BrickBreak", 1920, 1080) { Init(); }

	void Init() override;

};



inline void BrickBreak::Init() {
	AddLayer(*new OP::Layer(Game::l_Window, (*new OP::Shader("VertexShader.vert", "FragShader.frag")), "BrickBreakDefaultLayer", 0));
	int width;
	int height;



	OP::StringSprite * string = new OP::StringSprite(l_Layers[0], { 20,20,20 }, 720, true, "", 1.25);

	OP::Renderable * sprite2 = new OP::Renderable({ 0,0,2002 }, { 1920,1080 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
	l_Layers[0]->AddRenderable(*sprite2);

}
