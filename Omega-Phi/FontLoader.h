#pragma once
#include <iostream>
#include "OPImage.h"
#include <ft2build.h>
#include FT_FREETYPE_H 


namespace OP {
	namespace FontLoader {

	static FT_Library ft;

	static FT_Face face;

	void InitalizeFreeType(int FontSize);

	OPImage getCharImage(char toGet);
	



	

	}
}
