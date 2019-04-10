#include "BrickBreak.h"
#include "BreakBreakFrontLayer.h"

void BrickBreak::Init() {
	AddLayer(*new BreakBreakFrontLayer(this));
	int width;
	int height;


	OP::Renderable * sprite2 = new OP::Renderable({ 0,0,2002 }, { 1280,720 }, OP::Renderable::GetColor(0x00, 0x00, 0x00, 128));
	l_Layers[0]->AddRenderable(*sprite2);

}