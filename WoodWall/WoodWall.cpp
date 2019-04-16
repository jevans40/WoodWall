#include "WoodWall.h"
#include "MenuLayer.h"

void WoodWall::Init() {

	AddLayer(*new Menu((OP::Game *)  this, (new OP::Shader("./../res/Shaders/VertexShader.vert", "./../res/Shaders/FragShader.frag")), "WoodWallDefaultLayer", true,true));
	int width;
	int height;

	

}