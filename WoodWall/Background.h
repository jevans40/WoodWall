#pragma once
#include "Tile.h"
#include <vector>
#include <unordered_map>
#include <Omega-Phi/Layer.h>

class Background {
	bool * l_TileTypes;
	Tile ** l_Tiles;
	std::vector<int> l_weights;

	int l_gridSize;
	int l_squareSize;

	OP::Layer * p_Layer;

public:

	Background(int gridSize, int squareSize, OP::Layer * ParentLayer) {
		l_gridSize = gridSize;
		l_squareSize = squareSize;

		l_TileTypes = new bool[gridSize*gridSize];
		l_Tiles = new Tile*[gridSize*gridSize];
		
		for (int i = 0; i < gridSize * gridSize; i++) {
			l_Tiles[i] = 0;
		}
		
		l_weights.push_back(0);
		p_Layer = ParentLayer;
	}


	void setTileWeights(int TileType, int weight) {
		l_weights[TileType] = weight;
	}

	void regenerateTiles() {
		int maxWeight = 0;
		
		for (int i = 0; i < l_weights.size(); i++) {
			maxWeight += l_weights[i];
		}

		for (int i = 0; i < l_gridSize; i++) {
			if (l_TileTypes[i] != 0) {

				// Give the Tile a random type
				int roll = rand() % maxWeight;
				for (int k = 1; k < l_weights.size(); k++) {
					roll -= l_weights[k];
					if (roll < 0) {
						l_Tiles[i]->setTileType(k);
					}
				}
			}
		}
	}

	void setTile(OP::ivec2 Pos, bool IsTile) {
		if (Pos.x < 0 || Pos.x > l_gridSize) {
			Pos.x = 0;
		}
		if (Pos.y < 0 || Pos.y > l_gridSize) {
			Pos.y = 0;
		}

		l_TileTypes[Pos.x + Pos.y * l_squareSize] = IsTile;
		if (l_Tiles[Pos.x + Pos.y * l_squareSize] == nullptr) {

		}
	}

};