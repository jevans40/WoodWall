#include "ImageLoader.h"
#include <iostream>


void OP::InitFreeImage()
{
	FreeImage_Initialise();
}

void OP::DeInitFreeImage()
{
	FreeImage_DeInitialise();
}

OP::OPImage &OP::LoadImage(const char * FileName)
{
	FIBITMAP *bitmap = FreeImage_Load(FIF_PNG, FileName);
	if (bitmap) {
		GLuint tex_id = 0;
		int x, y;
		int height, width;

		RGBQUAD rgbquad;
		RGBQUAD previous;

		FreeImage_GetPixelColor(bitmap, 0, 0, &previous);

		FREE_IMAGE_TYPE type;
		BITMAPINFOHEADER *header;

		type = FreeImage_GetImageType(bitmap);


		height = FreeImage_GetHeight(bitmap);
		width = FreeImage_GetWidth(bitmap);

		header = FreeImage_GetInfoHeader(bitmap);

		bool transparency = true;

		for (x = 0; x < width; x++)
			for (y = 0; y < height; y++)
			{
				FreeImage_GetPixelColor(bitmap, x, y, &rgbquad);
				if (rgbquad.rgbReserved != previous.rgbReserved) {
					transparency = false;
					break;
				}
			}
		int scanLineWidh = ((3 * width) % 4 == 0) ? 3 * width : ((3 * width) / 4) * 4 + 4;
		RGBQUAD * texels = new RGBQUAD[height*width];
		for (x = 0; x < width; x++)
			for (y = 0; y < height; y++)
			{
				FreeImage_GetPixelColor(bitmap, x, y, &rgbquad);

				if (rgbquad.rgbReserved > 0 || transparency) {
					rgbquad.rgbReserved = 255;
				}
				texels[y*width + x] = rgbquad;
			}
		FreeImage_Unload(bitmap);
		OPImage * image = new OP::OPImage(texels,width,height);
		return *image;

	}
	RGBQUAD * q = new RGBQUAD[0];
	return *new OP::OPImage( q , 0, 0);

}

OP::OPImage & OP::NewImage(ivec2 size)
{
	FIBITMAP *bitmap = FreeImage_Allocate(size.x,size.y,32);
	if (bitmap) {
		GLuint tex_id = 0;
		int x, y;
		int height, width;

		RGBQUAD rgbquad;


		FREE_IMAGE_TYPE type;
		BITMAPINFOHEADER *header;

		type = FreeImage_GetImageType(bitmap);


		height = FreeImage_GetHeight(bitmap);
		width = FreeImage_GetWidth(bitmap);

		header = FreeImage_GetInfoHeader(bitmap);
		int scanLineWidh = ((3 * width) % 4 == 0) ? 3 * width : ((3 * width) / 4) * 4 + 4;
		RGBQUAD * texels = new RGBQUAD[height*width];
		for (x = 0; x < width; x++)
			for (y = 0; y < height; y++)
			{
				FreeImage_GetPixelColor(bitmap, x, y, &rgbquad);
				if (rgbquad.rgbReserved > 0) {
					//rgbquad.rgbReserved = 255;
				}
				texels[y*width + x] = rgbquad;
			}
		FreeImage_Unload(bitmap);
		OPImage * image = new OP::OPImage(texels, width, height);
		return *image;

	}
	RGBQUAD * q = new RGBQUAD[0];
	return *new OP::OPImage(q, 0, 0);
}

GLuint OP::TurnBitMapToTextureNearest(OPImage &dib1)
{
	GLuint tex_id;
	int x, y;

	RGBQUAD rgbquad;

	int scanLineWidh = ((3 * dib1.Width) % 4 == 0) ? 4 * dib1.Width : ((4 * dib1.Width) / 4) * 4;
	GLubyte * texels = new GLubyte[dib1.Height*dib1.Width * 4];
	for (x = 0; x < dib1.Width; x++)
		for (y = 0; y < dib1.Height; y++)
		{
			rgbquad = dib1.Texels[y * dib1.Width + x];

			if (rgbquad.rgbReserved > 0) {
				rgbquad.rgbReserved = 255;
			}

			texels[(y*scanLineWidh + 4 * x)] = ((GLubyte*)&rgbquad)[2];
			texels[(y*scanLineWidh + 4 * x) + 1] = ((GLubyte*)&rgbquad)[1];
			texels[(y*scanLineWidh + 4 * x) + 2] = ((GLubyte*)&rgbquad)[0];
			texels[(y*scanLineWidh + 4 * x) + 3] = ((GLubyte*)&rgbquad)[3];


		}

	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
		dib1.Width, dib1.Height, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texels);
	glBindTexture(GL_TEXTURE_2D, 0);

	return tex_id;
}

GLuint OP::TurnBitMapToTextureLinear(OPImage &dib1)
{

	GLuint tex_id;
	int x, y;

	RGBQUAD rgbquad;

	int scanLineWidh = ((3 * dib1.Width) % 4 == 0) ? 4 * dib1.Width : ((4 * dib1.Width) / 4) * 4 + 4;
	GLubyte * texels = new GLubyte[dib1.Height*dib1.Width * 4];
	for (x = 0; x < dib1.Width; x++)
		for (y = 0; y < dib1.Height; y++)
		{
			rgbquad = dib1.Texels[y * dib1.Width + x];

			if (rgbquad.rgbReserved > 0) {
				//rgbquad.rgbReserved = 255;
			}

			texels[(y*scanLineWidh + 4 * x)] = ((GLubyte*)&rgbquad)[2];
			texels[(y*scanLineWidh + 4 * x) + 1] = ((GLubyte*)&rgbquad)[1];
			texels[(y*scanLineWidh + 4 * x) + 2] = ((GLubyte*)&rgbquad)[0];
			texels[(y*scanLineWidh + 4 * x) + 3] = ((GLubyte*)&rgbquad)[3];

		}

	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
		dib1.Width, dib1.Height, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texels);
	glBindTexture(GL_TEXTURE_2D, 0);

	return tex_id;
}

void OP::drawToImage(OPImage &toDrawImage, OPImage &drawnTo, OP::ivec2 pos)
{
	int height1, width1, height2, width2;

	RGBQUAD rgbquad;



	height1 = toDrawImage.Height;
	width1 = toDrawImage.Width;

	height2 = drawnTo.Height;
	width2 = drawnTo.Width;

	if (height1 > height2 || width1 > width2) {
		std::cout << "ERROR! TRYING TO DRAW AN IMAGE TO A SMALLER IMAGE!" << std::endl;
		return;
	}


	for (int x = 0; x < width1; x++)
		for (int y = 0; y < height1; y++)
		{
			drawnTo.Texels[ ( y + pos.y) * width2 + pos.x + x] = toDrawImage.Texels[y * width1 + x];
		}

	return;
}
