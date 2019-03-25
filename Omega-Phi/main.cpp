#include <iostream>
#include "Renderable.h"
#include "Game.h"
#include "SimpleSprite.h"
#include "Layer.h"
#include "Shader.h"

class WoodWall: public OP::Game {

	public:
	WoodWall() : Game("WoodWall", 1920, 1080) { Init(); }

	void Init() override {
		AddLayer(*new OP::Layer(Game::l_Window, (*new OP::Shader("VertexShader.vert" ,"FragShader.frag")), "WoodWallDefaultLayer", 0));
		int width;
		int height;
		glfwGetWindowSize(l_Window->getWindow(),&width,&height);

		OP::SimpleSprite * sprite = new OP::SimpleSprite(this,{ 0,0,-.75 }, { 1000,1000 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
		l_Layers[0]->AddRenderable(*sprite);

		OP::Renderable * sprite2 = new OP::Renderable({ 0,0,-.5 }, { 2000,1000 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
		l_Layers[0]->AddRenderable(*sprite2);
		//l_Layers[0]->AddRenderable(*new OP::Renderable({ 200,200,-.75}, { 100,100 }, OP::Renderable::GetColor(0xFF,0xFF,0xFF,128)));

		/*for (int i = 0; i < width/16; i++) {
			for (int v = 0; v < height/16; v++) {
				unsigned int Color = OP::Renderable::GetColor((i * (float) width / 32) / (float) width * 255, (v * (float) height / 200) / (float) height * 255, float(i * v)  / (width*height)  * 255, 0xFF);
				OP::fvec3 pos((i * 32), (v *  32),-.20);
				OP::fvec2 size(32, 32);
				l_Layers[0]->AddRenderable(*new OP::Renderable(pos , size, Color ));

			}
			std::cout << i << std::endl;
		}*/
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