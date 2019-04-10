#pragma once
#include <vector>
#include "SimpleBoundingBox.h"
#include <unordered_map>
#include <string>

namespace OP {


	struct BoxNode
	{
		BoxNode * next = nullptr;
		SimpleBoundingBox * Box = nullptr;

		BoxNode() {
			next = nullptr;
			Box = nullptr;
		}

		void addBox(SimpleBoundingBox * Box) {
			if (next == nullptr) {
				next = new BoxNode();
				next->Box = Box;
				return;
			}
			next->addBox(Box);
		}

		BoxNode * removeBox(SimpleBoundingBox * toRemove) {
			if (Box == toRemove) {
				return next;
			}
			if (next == nullptr) {
				return this;
			}
			else {
				BoxNode * newNext = next->removeBox(toRemove);
				if(next != newNext) delete next;
				next = newNext;
				return this;
			}
		}

		std::vector<SimpleBoundingBox *> * getBoxNodes(std::vector<SimpleBoundingBox * > * Collection) {
			if (next != nullptr) next->getBoxNodes(Collection);
			Collection->push_back(Box);
			return Collection;
		}

	};

	struct CollisionGridSquare
	{
		BoxNode* FirstBox = nullptr;
		
		CollisionGridSquare() {
			FirstBox = nullptr;
		}

		bool removeBox(SimpleBoundingBox * Box) {
			if (FirstBox == nullptr) {
				return false;
			}
			if (FirstBox->Box == Box) {
				BoxNode * tmp = FirstBox;
				FirstBox = FirstBox->removeBox(Box);
				delete tmp;
				return true;
			}
			FirstBox = FirstBox->removeBox(Box);
			return true;
		}

		void addBox(SimpleBoundingBox * Box) {
			if (FirstBox == nullptr) {
				FirstBox = new BoxNode();
				FirstBox->Box = Box;
			}
			else {
				FirstBox->addBox(Box);
			}

		}

		std::vector<SimpleBoundingBox *> * getBoxNodes(std::vector<SimpleBoundingBox * > * Collection) {
			if (FirstBox == nullptr) {
				return Collection;
			}
			else {
				return FirstBox->getBoxNodes(Collection);
			}
		}


	};


	struct CollisionGrid{
		CollisionGridSquare * l_Grids;
		int l_Size;
		int l_SquareSize;


		CollisionGrid(int Size, int SquareSize) {
			l_Grids = new CollisionGridSquare[Size * Size]();
			l_Size = Size;
			l_SquareSize = SquareSize;
		/*	for (int i = 0; i < Size * Size; i++) {
				l_Grids[i] = *new CollisionGridSquare();
			}*/
		}

		std::vector<SimpleBoundingBox *> getCollisions(SimpleBoundingBox * Box) {
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
				if(key.first != Box)
				tmp2.push_back(key.first);
			}

			return tmp2;
		}

		int getGrid(ivec2 point) {
			point = { point.x + (l_Size / 2 * l_SquareSize), point.y + (l_Size / 2 * l_SquareSize) };
			return int ((point.x / l_SquareSize) + (point.y / l_SquareSize)* l_Size );
		}

		std::vector<int> getIntersectingGrids(SimpleBoundingBox * Box) {
			ivec2 minPoint = Box->getMin();
			ivec2 maxPoint = Box->getMax();

			int SizeX = maxPoint.x / l_SquareSize - minPoint.x / l_SquareSize + 1;
			int SizeY = maxPoint.y / l_SquareSize - minPoint.y / l_SquareSize + 1;


			std::vector<int> grids;
			
			if (SizeX == 1 && SizeY == 1) {
				grids.push_back(getGrid(minPoint));
			}else{
				for (int i = 0; i < SizeX * SizeY; i++) {
					grids.push_back(getGrid(minPoint) + i % SizeX + (i / SizeX * l_Size));
				}
			}
			return grids;
		 }

		void InsertBox(SimpleBoundingBox * Box) {
			std::vector<int> grids = getIntersectingGrids(Box);
			for (int i = 0; i < grids.size(); i++) {
				l_Grids[grids[i]].addBox(Box);
			}
		}

		void RemoveBox(SimpleBoundingBox * Box) {
			std::vector<int> grids = getIntersectingGrids(Box);
			for (int i = 0; i < grids.size(); i++) {
				l_Grids[grids[i]].removeBox(Box);
			}
		}

		std::string getBoxes(SimpleBoundingBox * Box) {
			std::vector<int> grids = getIntersectingGrids(Box);
			std::string boxes;
			for (int i = 0; i < grids.size(); i++) {
				boxes = boxes + std::to_string(grids[i]) + '\n';
			}
			return boxes;
		}

	};
}

