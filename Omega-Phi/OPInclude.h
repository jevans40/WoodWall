#pragma once
#include "OPMath.h"
 


#include "Game.h"
#include "DataStructure.h"
 
#include "FontLoader.h"
#include "FileLoader.h"
#include "ImageLoader.h"

void InitializeOmegaPhi() {

	OP::InitFreeImage;
	OP::FontLoader::InitalizeFreeType(64);
	OP::Initalization::run_init();
}