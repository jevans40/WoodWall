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
		
		virtual ~SimpleSprite() override;


		SimpleSprite(fvec3 pos = fvec3(0, 0, 0), fvec2 size = fvec2(1, 1), unsigned int Color = 0xffffffff);

		void setSprite(int spriteIndex);
		void setSprite(std::string SpriteName);

		virtual void Update(std::chrono::milliseconds Time) override;

		static void addSprite(const std::vector <SpriteLoc *>  * sprites);

		void * passEvent(const char * eventName, void * source, const char * eventMessage);

		/**
		/* DEPRICATED
		 * @fn	static void SimpleSprite::setFiles();
		 *
		 * @brief	Sets the files
		 * 	DEPRICATED
		 */

		static void setFiles();

	};


}