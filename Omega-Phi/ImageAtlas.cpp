#include "ImageAtlas.h"
#include "SimpleSprite.h"
#include <algorithm>



OP::ImageAtlas::ImageAtlas(const char * dirName, int imageMap) : Grid(2048)
{
	l_OPImage = NewImage({ 2048,2048 });
	spriteImages.push_back(new SpriteLoc());
	std::vector<std::string> SpriteFiles = getFiles(dirName);
	for (int i = 0; i < SpriteFiles.size(); i++) {
		addSprite(LoadImage(SpriteFiles[i].c_str()),SpriteFiles[i].c_str(),false);
	}
	GLImage = OP::TurnBitMapToTextureNearest(l_OPImage);


}

GLuint OP::ImageAtlas::getImage() 
{
	return GLImage;
}

void OP::ImageAtlas::addSprite(OP::OPImage image, const char* filename, bool redraw = false)
{
	ivec2 Pos;
	if (Grid.willFit(image.Width < image.Height ? image.Height : image.Width)) {
		 Pos = Grid.fit((image.Width < image.Height ? image.Height : image.Width));
	}
	
	drawToImage(image, l_OPImage, Pos);

	if (redraw) {
		GLImage = OP::TurnBitMapToTextureLinear(l_OPImage);
	}
	
	SpriteLoc * sprite = new SpriteLoc();
	sprite->Name = filename;
	sprite->Pos = fvec2((float)Pos.x /l_OPImage.Width,(float) Pos.y / l_OPImage.Height);
	sprite->Size = fvec2((float) image.Width / l_OPImage.Width,(float) image.Height / l_OPImage.Height);
	sprite->TexMap = ImageMap;
	spriteImages.push_back(sprite);
	
}

OP::SpriteLoc &OP::ImageAtlas::getSprite(const char* fileName)
{
	for (int i = 0; i < spriteImages.size(); i++) {
		if (spriteImages[i]->Name == fileName) {
			return *spriteImages[i];
		}
	}
	return *spriteImages[0];
}

int OP::ImageAtlas::getImageMap()
{
	return ImageMap;
}
