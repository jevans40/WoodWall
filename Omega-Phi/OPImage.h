#pragma once
#include <FreeImage.h>

namespace OP {
	struct OPImage {
		RGBQUAD * Texels;
		int Width;
		int Height;
		
		OPImage(RGBQUAD * &texels, int width, int height) {
			Texels = texels;
			Width = width;
			Height = height;
		}
		OPImage() {
			Texels = new RGBQUAD[0];
			Width = 0;
			Height = 0;
		}
		~OPImage() {
			//delete[] Texels;
		}

	};
}