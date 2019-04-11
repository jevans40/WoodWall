#include "BreakBreakFrontLayer.h"
#include "Ball.h"
#include "Bar.h"
#include <Omega-Phi/Game.h>
#include <Omega-Phi/Simple2DPhysics.h>
void BreakBreakFrontLayer::Init()
{
	for (int i = 0; i < ((OP::Game *)p_Game)->getWidth() / 128; i++) {
		for (int k = 0; k < ((OP::Game *)p_Game)->getHeight() / 64; k++) {
		
			Brick * brick = new Brick({ float(i * 128), float(k * 32),20 }, { float(((OP::Game *)p_Game)->getWidth()) / 10, 32 }, (12-k)/3 + 1);
			BrickToString.push_back(brick);
			AddRenderable(*brick);
		}
	}
	OP::SimpleSprite * renderable = new OP::SimpleSprite(OP::fvec3(0, 0, 21), OP::fvec2(1280, 720), OP::Renderable::GetColor(68, 84,124, 255));
	AddRenderable(*renderable);

	Ball * ourBall = new Ball(OP::fvec3(200,600,20 ), OP::fvec2( 20,20 ), OP::Renderable::GetColor(0, 255, 0, 255));
	AddRenderable(*ourBall);

	Bar * bar = new Bar(OP::fvec3(700, 600, 20), OP::fvec2(200, 10));
	AddRenderable(*bar);
	thisbar = bar;
	thisball = ourBall;


}

std::string BreakBreakFrontLayer::getObjectGrid(Brick * brick )
{
	return brick->getCoordString();
}

void BreakBreakFrontLayer::Update(std::chrono::milliseconds Time)
{
	if (getKey("R") || reset || thisball->gameover()) {
		thisbar->reset();
		thisball->reset();
		for (int i = 0; i < BrickToString.size(); i++) {
			BrickToString[i]->reset();
		}
		start = false;
		reset = false;
	}
	if (getKey("A") || getKey("D")) {
		start = true;
	}
	
	if (start) {

		for (int i = 0; i < l_Sprites.size(); i++) {
			l_Sprites[i]->Update(Time);

		}
	}

}



Brick * BreakBreakFrontLayer::getTouched()
{
	if(touchedBrick != nullptr)
	return touchedBrick;
	return (Brick *)thisbar;
}

