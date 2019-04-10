#pragma once
//#define FREEIMAGE_LIB
#include <string.h>
#include "FreeImage.h"

#include "OPMath.h"
 
#include "Renderable.h"
#include "SimpleSprite.h"
#include "StringSprite.h"

#include "Game.h"
#include "DataStructure.h"
 
#include "FontLoader.h"
#include "FileLoader.h"
#include "ImageLoader.h"

void InitializeOmegaPhi() {

	OP::InitFreeImage();
	OP::FontLoader::InitalizeFreeType(16);
	OP::Initalization::run_init();
}