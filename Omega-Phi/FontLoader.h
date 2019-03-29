#pragma once
#include <iostream>
#include <unordered_map>
#include "OPImage.h"
#include <ft2build.h>
#include FT_FREETYPE_H 
# 


namespace OP {

	struct OPchar {
		char name = 'a';
		int xbearing = 0;
		int ybearing = 0;
		int height = 0;
		int width = 0;
		int advancex = 0;
		int advancey = 0;
	};



	class FontLoader{
	public:
	static FT_Library ft;

	static FT_Face face;

	static std::unordered_map<char,OPchar *> Charlist;

	static void InitalizeFreeType(int FontSize);

	static OPImage &getCharImage(char toGet);
	



	

	};
}
