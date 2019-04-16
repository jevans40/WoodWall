#include "CollisionGrid.h"

OP::CollisionGrid::CollisionGrid(int Size, int SquareSize) {
	l_Grids = new CollisionGridSquare[Size * Size]();
	l_Size = Size;
	l_SquareSize = SquareSize;
}


std::vector<SimpleBoundingBox*> OP::CollisionGrid::getCollisions(SimpleBoundingBox * Box) {
	std::vector<SimpleBoundingBox *> tmp;
	std::vector<int> grids = getIntersectingGrids(Box);

	for (int i = 0; i < grids.size(); i++) {
		l_Grids[grids[i]].getBoxNodes(&tmp);
	}


	std::unordered_map<SimpleBoundingBox *, int> map;
	std::vector<SimpleBoundingBox *> tmp2;

	for (int i = 0; i < tmp.size(); i++) {
		map[tmp[i]] = 0;
	}

	for (auto key : map) {
		if (key.first != Box)
			tmp2.push_back(key.first);
	}

	return tmp2;
}


int OP::CollisionGrid::getGrid(ivec2 point) {
	point = { point.x + (l_Size / 2 * l_SquareSize), point.y + (l_Size / 2 * l_SquareSize) };
	return int((point.x / l_SquareSize) + (point.y / l_SquareSize)* l_Size);
}


std::vector<int> OP::CollisionGrid::getIntersectingGrids(SimpleBoundingBox * Box) {
	ivec2 minPoint = Box->getMin();
	ivec2 maxPoint = Box->getMax();

	int SizeX = maxPoint.x / l_SquareSize - minPoint.x / l_SquareSize + 1;
	int SizeY = maxPoint.y / l_SquareSize - minPoint.y / l_SquareSize + 1;


	std::vector<int> grids;

	if (SizeX == 1 && SizeY == 1) {
		grids.push_back(getGrid(minPoint));
	}
	else {
		for (int i = 0; i < SizeX * SizeY; i++) {
			grids.push_back(getGrid(minPoint) + i % SizeX + (i / SizeX * l_Size));
		}
	}
	return grids;
}


void OP::CollisionGrid::InsertBox(SimpleBoundingBox * Box) {
	std::vector<int> grids = getIntersectingGrids(Box);
	for (int i = 0; i < grids.size(); i++) {
		l_Grids[grids[i]].addBox(Box);
	}
}


void OP::CollisionGrid::RemoveBox(SimpleBoundingBox * Box) {
	std::vector<int> grids = getIntersectingGrids(Box);
	for (int i = 0; i < grids.size(); i++) {
		l_Grids[grids[i]].removeBox(Box);
	}
}


std::string OP::CollisionGrid::getIntersectedTileNames(SimpleBoundingBox * Box) {
	std::vector<int> grids = getIntersectingGrids(Box);
	std::string boxes;
	for (int i = 0; i < grids.size(); i++) {
		boxes = boxes + std::to_string(grids[i]) + '\n';
	}
	return boxes;
}
