#include "ImageAtlas.h"
#include "SimpleSprite.h"
#include "FontLoader.h"
#include <algorithm>



void OP::ImageAtlas::growAtlas()
{
	l_Size = l_Size * 2;
	for (int i = 0; i < l_spriteImages.size(); i++) {
		l_spriteImages[i]->Pos.x = l_spriteImages[i]->Pos.x * .5;
		l_spriteImages[i]->Pos.y = l_spriteImages[i]->Pos.y * .5;
		l_spriteImages[i]->Size.x = l_spriteImages[i]->Size.x * .5;
		l_spriteImages[i]->Size.y = l_spriteImages[i]->Size.y * .5;
	}
	l_Grid = new MapGrid(l_Size, l_Grid);
	OP::OPImage * OPImagetmp = new OPImage();
	*OPImagetmp	= NewImage({ l_Size,l_Size });
	drawToImage(*l_OPImage, *OPImagetmp, {0,0});
	l_OPImage = OPImagetmp;
}

OP::ImageAtlas::ImageAtlas(const char * dirName, int imageMap, OP::EventListner * game)
{
	l_Grid = new MapGrid(512);
	addListener(game);
	
	l_Dir = dirName;

	GLint info;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &info);

	l_Size = 512;
	l_MaxSize = info;

	l_OPImage = &NewImage({ 512,512 });
	l_spriteImages.push_back(new SpriteLoc());
	std::vector<std::string> SpriteFiles = getFiles(dirName);
	for (int i = 0; i < SpriteFiles.size(); i++) {
		if (!addSprite(LoadImage(SpriteFiles[i].c_str()), SpriteFiles[i].c_str(), false)) {
			callListner("outOfAtlasSpace", this);
			for (int k = 0; k < SpriteFiles.size() - i; k++) {
				l_unallocatedFiles.push_back(SpriteFiles[i+k]);
			}
			break;
		}
	}

	for (int i = 0; i < 255; i++) {
		if (!addSprite(FontLoader::getCharImage(char(i)), std::string(1, char(i) ).c_str(), false)) {
			callListner("outOfAtlasSpace", this);
			for (int k = 0; k < SpriteFiles.size() - i; k++) {
				l_unallocatedFiles.push_back(SpriteFiles[i + k]);
			}
			break;
		}
	}

	l_GLImage = OP::TurnBitMapToTextureNearest(*l_OPImage);

	callListner("updateAtlas", this);
}



GLuint OP::ImageAtlas::getImage() 
{
	return l_GLImage;
}

std::vector<std::string>* OP::ImageAtlas::getUnallocated()
{
	return &l_unallocatedFiles;
}


bool OP::ImageAtlas::addSprite(OP::OPImage image, const char* filename, bool redraw = false)
{
	float width = image.Width;
	float height = image.Height;
	height = pow(2,ceil(log2(height)));
	width = pow(2,ceil(log2(width)));

	height = height < 16 ? 16 : height;
	width = width < 16 ? 16 : width;

	ivec2 Pos;

	if (l_Grid->willFit(width < height ? height : width)) {
		 Pos = l_Grid->fit((width < height ? height : width));
	}
	else if (l_Size < l_MaxSize) {
		growAtlas();
		return(addSprite(image, filename, redraw));
	}
	else {
		return false;
	}
	
	int deltaWidth = width - image.Width;
	int deltaHeight = height - image.Height;


	drawToImage(image, *l_OPImage, { Pos.x + deltaWidth / 2 ,Pos.y + deltaHeight / 2 });

	if (redraw) {
		l_GLImage = OP::TurnBitMapToTextureNearest(*l_OPImage);
	}
	
	SpriteLoc * sprite = new SpriteLoc();

	//THIS IS BROKEN FIX IT TOMORROW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	std::string str = std::string(filename).substr(0,l_Dir.size());
	try {
		if (str == l_Dir) {
			str = std::string(filename).erase(0, l_Dir.size() + 1);
		}
	}
	catch (std::out_of_range&) {
		//oops str is too short!!!
	}
	sprite->Name = str.c_str();
	sprite->Pos = fvec2((((float)Pos.x + deltaWidth/2) / l_OPImage->Width),(((float) Pos.y + deltaHeight/2) / l_OPImage->Height));
	sprite->Size = fvec2((float) image.Width / l_OPImage->Width,(float) image.Height / l_OPImage->Height);
	sprite->TexMap = l_ImageMap;
	l_spriteImages.push_back(sprite);
	return true;
}

const std::vector<OP::SpriteLoc *> * OP::ImageAtlas::getSpriteMap()
{
	return &l_spriteImages;
}



OP::SpriteLoc * OP::ImageAtlas::getSprite(const char* fileName)
{
	for (int i = 0; i < l_spriteImages.size(); i++) {
		if (l_spriteImages[i]->Name == fileName) {
			return l_spriteImages[i];
		}
	}
	return nullptr;
}

int OP::ImageAtlas::getImageMap()
{
	return l_ImageMap;
}
