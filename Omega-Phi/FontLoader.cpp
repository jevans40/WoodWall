#include "FontLoader.h"
#include <vector>

FT_Library OP::FontLoader::ft;

FT_Face OP::FontLoader::face;

std::unordered_map<char,OP::OPchar *> OP::FontLoader::Charlist;


void OP::FontLoader::InitalizeFreeType(int FontSize)
{
	OP::FontLoader::Charlist = *new std::unordered_map<char,OPchar*>();
	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	if (FT_New_Face(ft, "./../res/Fonts/OpenSans-Regular.ttf", 0, &face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

	FT_Set_Pixel_Sizes(face, 0, FontSize);
}

OP::OPImage &OP::FontLoader::getCharImage(char toGet)
{
	if (FT_Load_Char(face, toGet , FT_LOAD_RENDER))
		std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	FT_Bitmap bitmap = face->glyph->bitmap;
	OPImage ImageTmp = *new OPImage();
	ImageTmp.Texels = new RGBQUAD[bitmap.width*bitmap.rows];
	ImageTmp.Height = bitmap.rows;
	ImageTmp.Width = bitmap.width;
	for (int i = 0; i < bitmap.width; i++) {
		for (int k = 0; k < bitmap.rows; k++) {
			char color = bitmap.buffer[k*ImageTmp.Width + i];
			
			ImageTmp.Texels[((bitmap.width)*(bitmap.rows)-1) - ((k)*ImageTmp.Width + (bitmap.width - i - 1))] = RGBQUAD({ 0, 0, 0, BYTE(color) });
		}
	}
	OPchar* newChar = new OPchar();
	newChar->name = toGet;
	newChar->xbearing = face->glyph->bitmap_left;
	newChar->ybearing = face->glyph->bitmap_top;
	newChar->width = bitmap.width;
	newChar->height = bitmap.rows;
	newChar->advancex = face->glyph->advance.x;
	newChar->advancey = face->descender;
	OP::FontLoader::Charlist[toGet] = newChar;

	return ImageTmp;
}

