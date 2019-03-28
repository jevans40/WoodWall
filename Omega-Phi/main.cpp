#include <Omega-Phi/OPInclude.h>
#include "House.h"

std::vector <std::string> House::files;
OP::initializer House::init = OP::initializer(House::setFiles);

class WoodWall: public OP::Game {

	public:
	WoodWall() : Game("WoodWall", 1920, 1080) { Init(); }

	void Init() override {
		AddLayer(*new OP::Layer(Game::l_Window, (*new OP::Shader("VertexShader.vert", "FragShader.frag")), "WoodWallDefaultLayer", 0));
		int width;
		int height;

		House * sprite = new House(this, { 0,0,1 }, { 1080,1080 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
		l_Layers[0]->AddRenderable(*sprite);

		//OP::Renderable * sprite2 = new OP::Renderable({ 0,0,200 }, { 1920,1080 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
		//l_Layers[0]->AddRenderable(*sprite2);
		/*
		int sizeofbackground = width/(10);

		for (int i = 0; i < width/sizeofbackground + 1; i++) {
			for (int v = 0; v < height/sizeofbackground + 1; v++) {
				unsigned int Color = OP::Renderable::GetColor((i * (float) width / 32) / (float) width * 255, (v * (float) height / 200) / (float) height * 255, float(i * v)  / (width*height)  * 255, 0xFF);
				OP::fvec3 pos((i * sizeofbackground), (v *  sizeofbackground),100);
				OP::fvec2 size(sizeofbackground, sizeofbackground);
				l_Layers[0]->AddRenderable(*new OP::SimpleSprite(this,pos , size, Color ));

			}
			std::cout << i << std::endl;
		}
		std::cout << "Sprites: " << (width / (width / (1280 / 2)))* (width / (width / (1280 / 2))) << std::endl;
	}*/
	}

};




//Try to keep as few lines in here as possible
int main() {
	//RUN THIS FIRST YOU SHITWARD 
	// 
	OP::FontLoader::InitalizeFreeType(48);
	OP::FontLoader::getCharImage('l');
	OP::Initalization::run_init();
	
	WoodWall TheFirstWall;
	



	TheFirstWall.Start();
	


	return 0;
}