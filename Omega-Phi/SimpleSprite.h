#pragma once
#include "Renderable.h"
#include "EventListener.h"
#include "EventCaller.h"
#include "ImageAtlas.h"
#include <vector>

namespace OP {

	class SimpleSprite : public Renderable, EventCaller{
	private:
		friend class ImageAtlas;
		static std::vector<SpriteLoc> l_spriteLocation;
		static const char* l_fileName;
	protected:
		static void setSpriteLoc(SpriteLoc &location);
	public:
		
		SimpleSprite(EventListner * TextureHandler,fvec3 pos = fvec3(0, 0, 0), fvec2 size = fvec2(1, 1), unsigned int Color = 0xffffffff);

		static void Initalize(ImageAtlas);

	};


}