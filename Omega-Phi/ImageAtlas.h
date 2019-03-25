#pragma once
#include "ivec2.h"
#include "FileLoader.h"
#include "ImageLoader.h"
#include "DataStructure.h"
#include <string>

namespace OP {


	class ImageAtlas {
		MapGrid Grid;
		int ImageMap;
		std::vector<SpriteLoc *> spriteImages;
		OPImage l_OPImage;
		GLuint GLImage;
	public:
		ImageAtlas(const char* dirName, int imageMap);

		GLuint getImage();

		void addSprite(OP::OPImage image, const char* filename, bool redraw);

		SpriteLoc &getSprite(const char * fileName);

		int getImageMap();



	};

}
