#include "SimpleSprite.h"
#include <stdlib.h>
OP::SimpleSprite::SimpleSprite(EventListner * TextureHandler, fvec3 pos, fvec2 size, unsigned int Color) : Renderable(pos,size,Color)
{
	addListener(TextureHandler);
	setTexx(0);
	setTexy(0);
	setTexSize({ 1,1});
	setTexMap(0);


	

}

void OP::SimpleSprite::Initalize(OP::ImageAtlas)
{

}



