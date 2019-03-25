#pragma once
#include "OPMath.h"
#include "OPImage.h"
#include <FreeImage.h>
#include <GL/glew.h>

namespace OP {

	void InitFreeImage();

	void DeInitFreeImage();
	
		
	OP::OPImage &LoadImage(const char* FileName);

	OP::OPImage &NewImage(ivec2 size);

	GLuint TurnBitMapToTextureNearest(OPImage &dib1);

	GLuint TurnBitMapToTextureLinear(OPImage &dib1);

	void drawToImage(OPImage &toDraw, OPImage &drawnTo, OP::ivec2 pos = { 0,0 });


}