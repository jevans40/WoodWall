#include "FontLoader.h"

void OP::FontLoader::InitalizeFreeType(int FontSize)
{
	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	if (FT_New_Face(ft, "./../res/Fonts/OpenSans-Regular.ttf", 0, &face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

	FT_Set_Pixel_Sizes(face, 0, FontSize);
}

OP::OPImage OP::FontLoader::getCharImage(char toGet)
{
	if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
		std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	FT_Bitmap bitmap = face->glyph->bitmap;
	OPImage ImageTmp;
	ImageTmp.Texels = new RGBQUAD[bitmap.width*bitmap.rows];
	ImageTmp.Height = bitmap.rows;
	ImageTmp.Width = bitmap.width;
	for (int i = 0; i < bitmap.rows; i++) {
		for (int k = 0; k < bitmap.width; k++) {
			char color = bitmap.buffer[k*ImageTmp.Height + i];
			ImageTmp.Texels[k*ImageTmp.Height + i] = RGBQUAD({ 0, 0, 0, BYTE(color) });
		}
	}

	return OPImage();
}

