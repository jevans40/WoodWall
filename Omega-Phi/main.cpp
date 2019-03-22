#include <iostream>
#include "Renderable.h"
#include "Game.h"
#include "Layer.h"
#include "Shader.h"

class WoodWall: public OP::Game {

	public:
	WoodWall() : Game("WoodWall", 2040, 2040) { Init(); }

	void Init() override {
		AddLayer(*new OP::Layer(Game::l_Window, (*new OP::Shader("VertexShader.vert" ,"FragShader.frag")), "WoodWallDefaultLayer", 0));
		int width;
		int height;
		glfwGetWindowSize(l_Window->getWindow(),&width,&height);

		l_Layers[0]->AddRenderable(*new OP::Renderable({ 200,200,-40 }, { 100,100 }, 0xffffffff));

		for (int i = 0; i < width/4; i++) {
			for (int v = 0; v < height/4; v++) {
				unsigned int Color = OP::Renderable::GetColor((i * (float) width / 200) / (float) width * 255, (v * (float) height / 200) / (float) height * 255, float(i * v)  / (width*height)  * 255, 0xFF);
				OP::fvec3 pos((i * (float) width / 200), (v * (float) height / 200), 0);
				OP::fvec2 size(((float) width / 200), ((float) height / 200));
				l_Layers[0]->AddRenderable(*new OP::Renderable(pos , size, Color ));

			}
			std::cout << i << std::endl;
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