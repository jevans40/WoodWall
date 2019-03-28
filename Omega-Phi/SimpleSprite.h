#pragma once
#include "Renderable.h"
#include "EventListener.h"
#include "EventCaller.h"
#include "Initalizer.h"
#include "ImageAtlas.h"
#include <vector>

namespace OP {

	class SimpleSprite : public Renderable, EventCaller {
	private:
		std::vector <std::string> files;
		static const std::vector < SpriteLoc* > * l_SpriteImages;
		int currentSprite;
	protected:

	public:
		static initializer init;

		SimpleSprite(EventListner * TextureHandler, fvec3 pos = fvec3(0, 0, 0), fvec2 size = fvec2(1, 1), unsigned int Color = 0xffffffff);

		void setSprite(int spriteIndex);
		void setSprite(std::string SpriteName);

		static void addSprite(const std::vector <SpriteLoc *>  * sprites);

		void * passEvent(const char * eventName, void * source, const char * eventMessage);
		static void setFiles();

	};


}