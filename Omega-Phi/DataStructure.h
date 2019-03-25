#pragma once
#include "OPMath.h"
#include <string>

namespace OP {

	/**
	 * @struct	MapGrid
	 *
	 * @brief	A volitile data structure that allocates power of two chunks.
	 */

	struct MapGrid {
		MapGrid * grids[4];
		bool boolgrid[4] = { false,false,false,false };
		int size;


		MapGrid(int newsize) {
			size = newsize;
			if (newsize > 16) {
				grids[0] = new MapGrid(size / 2);
				grids[1] = new MapGrid(size / 2);
				grids[2] = new MapGrid(size / 2);
				grids[3] = new MapGrid(size / 2);

			}
			else {
				boolgrid[0] = false;
				boolgrid[1] = false;
				boolgrid[2] = false;
				boolgrid[3] = false;
			}
		}

		~MapGrid() {
			if (size > 16) {

			if (!boolgrid[0]) {
				delete grids[0];
			}
			if (!boolgrid[1]) {
				delete grids[1];
			}
			if (!boolgrid[2]) {
				delete grids[2];
			}
			if (!boolgrid[3]) {
				delete grids[3];
			}
			}
		}

		bool isFull() {
			return BoolSum();
		}

		bool isEmpty() {
			if (!BoolSum() && size > 16) {
				return (grids[0]->isEmpty() && grids[1]->isEmpty() && grids[2]->isEmpty() && grids[3]->isEmpty());
			}
			else if (size <= 16) {
				return !BoolSum();
			}
			return false;
		}

		bool willFit(int objSize) {
			if (objSize <= size && isEmpty()) {
				return true;
			}
			else {
				if (size < objSize) {
					return false;
				}
				return grids[0]->willFit(objSize) || grids[1]->willFit(objSize) || grids[2]->willFit(objSize) || grids[3]->willFit(objSize);
			}
		}

		OP::ivec2 fit(int objSize, int offsetx = 0, int offsety = 0, MapGrid * previous = nullptr) {
			if (size > 16) {
				if (!boolgrid[0] ? grids[0]->willFit(objSize) : !boolgrid[0]) {
					return grids[0]->fit(objSize, offsetx * 2, offsety * 2, this);
				}
				if (!boolgrid[1] ? grids[1]->willFit(objSize) : !boolgrid[1]) {
					return grids[1]->fit(objSize, offsetx * 2 + 1, offsety * 2, this);
				}
				if (!boolgrid[2] ? grids[2]->willFit(objSize) : !boolgrid[2]) {
					return grids[2]->fit(objSize, offsetx * 2, offsety * 2 + 1, this);
				}
				if (!boolgrid[3] ? grids[3]->willFit(objSize) : !boolgrid[3]) {
					return grids[3]->fit(objSize, offsetx * 2 + 1, offsety * 2 + 1, this);
				}
			}
			Allocate();

			if (previous->grids[0] == this) {
				previous->boolgrid[0] = true;
			}
			if (previous->grids[1] == this) {
				previous->boolgrid[1] = true;
			}
			if (previous->grids[2] == this) {
				previous->boolgrid[2] = true;
			}
			if (previous->grids[3] == this) {
				previous->boolgrid[3] = true;
			}

			return { offsetx * size,offsety * size };
		}

		void Allocate() {
			if (!boolgrid[0]) {
	
			}
			if (!boolgrid[1]) {

			}
			if (!boolgrid[2]) {
			}
			if (!boolgrid[3]) {
			}
			boolgrid[0] = true;
			boolgrid[1] = true;
			boolgrid[2] = true;
			boolgrid[3] = true;
			if (size > 16) {
			grids[0]->Allocate();
			grids[1]->Allocate();
			grids[2]->Allocate();
			grids[3]->Allocate();
			}
		}

		bool BoolSum() {
			return (boolgrid[0] && boolgrid[1] && boolgrid[2] && boolgrid[3]);
		}
	};

	/**
	 * @struct	SpriteLoc
	 *
	 * @brief	A sprite location on an Image.
	 */

	struct SpriteLoc
	{
		SpriteLoc(const char * name = "Error", OP::fvec2 pos = { 0,0 }, OP::fvec2 size = { 0,0 }, int texMap = -1) {
			Name = name;
			Pos = pos;
			Size = size;
			TexMap = texMap;
		}
		std::string Name;
		OP::fvec2 Pos;
		OP::fvec2 Size;
		int TexMap;
	};

#pragma pack(push, 0)

	struct Vertex {
		fvec3 pos = fvec3(0, 0, 0);
		fvec2 texPos = fvec2(0, 0);
		unsigned int color = 0;
		int texMap = 0;

		Vertex() {};

	};

#pragma pack(pop)
}