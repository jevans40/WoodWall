#include <iostream>
#include "Renderable.h"
#include "Game.h"
#include "Layer.h"
#include "Shader.h"

class WoodWall: public OP::Game {

	public:
	WoodWall() : Game("WoodWall", 600, 480) { Init(); }

	void Init() override {
		AddLayer(*new OP::Layer(Game::l_Window, (*new OP::Shader("FragShader.frag", "VertexShader.vert")), "WoodWallDefaultLayer", 0));
		int width;
		int height;
		glfwGetWindowSize(l_Window->getWindow(),&width,&height);
		for (int i = 0; i < width / 20; i++) {
			for (int v = 0; v < height /20; v++) {
				unsigned int Color = OP::Renderable::GetColor((i * width / 20) / width * 255, (v * height / 20) / height * 255, (i * v * width * height / 20) / (width * height) * 255, 0xFF);
				OP::fvec3 pos((i * width / 20) / width, (v * height / 20) / height);
				OP::fvec2 size((width / 20) / width, (height / 20) / height);
				l_Layers[0]->AddRenderable(*new OP::Renderable(pos , size, Color ));

			}
		}
	}

};




//Try to keep as few lines in here as possible
int main() {
	//RUN THIS FIRST YOU SHITWARD
	// 
	WoodWall TheFirstWall;




	TheFirstWall.Start();
	


	return 0;
}