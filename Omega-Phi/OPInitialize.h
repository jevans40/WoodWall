#pragma once
#include "OPInclude.h"
void InitializeOmegaPhi() {

	OP::InitFreeImage();
	OP::FontLoader::InitalizeFreeType(16);
	OP::Initalization::run_init();
}