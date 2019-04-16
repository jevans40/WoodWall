#include "MenuLayer.h"
#include <Omega-Phi/StringSprite.h>
#include <math.h>
void Menu::renderMenu()
{
	OP::SimpleSprite * sprite = new OP::SimpleSprite({ 0,0,10 }, { this->getWindowSize().x, this->getWindowSize().y });
	AddRenderable(*sprite);
	sprite->setSprite("front.png");
	Sprite1 = sprite;


	OP::SimpleSprite * sprite2 = new OP::SimpleSprite({ this->getWindowSize().x,0,10 }, { this->getWindowSize().x,this->getWindowSize().y });
	AddRenderable(*sprite2);
	sprite2->setSprite("front.png");
	Sprite2 = sprite2;


	OP::SimpleSprite * sprite3 = new OP::SimpleSprite({ 0,0,11 }, { this->getWindowSize().x,this->getWindowSize().y });
	AddRenderable(*sprite3);
	sprite3->setSprite("Background.png");
	Sprite3 = sprite3;
	
	OP::SimpleSprite * Title = new OP::SimpleSprite({ this->getWindowSize().x / 10,this->getWindowSize().y / 8 , 9 }, { this->getWindowSize().x / 1.25f ,this->getWindowSize().y / 1.25f});
	AddRenderable(*Title);
	Title->setSprite("Title.png");

	OP::SimpleSprite * button = new OP::SimpleSprite({ this->getWindowSize().x * 0.5f - 300,this->getWindowSize().y * 0.8f , 8 }, { 600 ,200 });
	AddRenderable(*button);
	button->setSprite("Play.png");

}

static std::chrono::milliseconds::rep lastTime = 0;
void Menu::Update(std::chrono::milliseconds Time)
{
	
	float velocity = float(Time.count() - lastTime)/1000;
	lastTime = Time.count();

	

	Sprite1->setXPos( remainder((Sprite1->getXPos() - velocity * 50), getWindowSize().x * 2));
	Sprite2->setXPos(remainder(Sprite1->getXPos() + getWindowSize().x, getWindowSize().x * 2));

}


