#pragma once
#include "ivec2.h"
#include "FileLoader.h"
#include "EventCaller.h"
#include "ImageLoader.h"
#include "DataStructure.h"
#include <string>

namespace OP {


	class ImageAtlas : public EventCaller {

		int l_Size;
		int l_MaxSize;
		int l_ImageMap;

		std::string l_Dir;

		std::vector<std::string> l_unallocatedFiles;
		std::vector<SpriteLoc *> l_spriteImages;

		MapGrid * l_Grid;
		OPImage * l_OPImage;
		GLuint l_GLImage;

	protected:
		void growAtlas();


	public:
		ImageAtlas(const char* dirName, int imageMap, EventListner * game);

		GLuint getImage();

		std::vector<std::string> * getUnallocated();

		bool addSprite(OP::OPImage image, const char* filename, bool redraw);

		const std::vector<SpriteLoc *> * getSpriteMap();


		SpriteLoc * getSprite(const char * fileName);

		int getImageMap();



	};

}
