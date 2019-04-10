#include "SimpleSprite.h"


const std::vector < OP::SpriteLoc* > * OP::SimpleSprite::l_SpriteImages;

OP::SimpleSprite::~SimpleSprite()
{
	std::cout << "Simple Sprite Destroyed!" << std::endl;
}

OP::SimpleSprite::SimpleSprite(fvec3 pos, fvec2 size, unsigned int Color) : Renderable(pos, size, Color)
{
	setTexx(0);
	setTexy(0);
	setTexSize({ 1,1 });
	setTexMap(-1);
	setSprite(0);
}

void OP::SimpleSprite::setSprite(int spriteIndex)
{
	currentSprite = spriteIndex;
	if (l_SpriteImages != NULL) {

		if (spriteIndex >= 0 && spriteIndex < l_SpriteImages->size()) {
			if ((*l_SpriteImages)[spriteIndex] != nullptr) {
				this->setTexx(-(*l_SpriteImages)[spriteIndex]->Pos.x);
				this->setTexy( -(*l_SpriteImages)[spriteIndex]->Pos.y);
				this->setTexSize({((*l_SpriteImages)[spriteIndex]->Size.x * -1),((*l_SpriteImages)[spriteIndex]->Size.y * -1) });
				this->setTexMap((*l_SpriteImages)[spriteIndex]->TexMap);
			}
			else {
				this->setTexx(0);
				this->setTexy(0);
				this->setTexSize({ 0,0 });
				this->setTexMap(-1);
			}
		
		}
	}
}

void OP::SimpleSprite::setSprite(std::string SpriteName)
{
	for (int i = 0; i < l_SpriteImages->size(); i++) {
		if ((*l_SpriteImages)[i]->Name == SpriteName) {
			setSprite(i);
			break;
		}
	}
}

void OP::SimpleSprite::Update(std::chrono::milliseconds Time)
{
}

void OP::SimpleSprite::addSprite(const std::vector <SpriteLoc *>  * sprites)
{
	l_SpriteImages = sprites;
}




void * OP::SimpleSprite::passEvent(const char * eventName, void * source, const char * eventMessage)
{
	return callListner(eventName,source,eventMessage );
}





