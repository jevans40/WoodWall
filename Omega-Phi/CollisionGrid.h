#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "SimpleBoundingBox.h"
#include "BoxNode.h"

namespace OP {

	struct CollisionGridSquare
	{
		//A linked list for all tiles in the Grid Square
		BoxNode* FirstBox = nullptr;

		/**
		 * @fn	CollisionGridSquare()
		 *
		 * @brief	Default constructor
		 */

		CollisionGridSquare() {
			FirstBox = nullptr;
		}

		/**
		 * @fn	bool removeBox(SimpleBoundingBox * Box)
		 *
		 * @brief	Removes the box described by Box
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 *
		 * @returns	True if it succeeds, false if it fails.
		 */

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

		/**
		 * @fn	void addBox(SimpleBoundingBox * Box)
		 *
		 * @brief	Adds a box
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 */

		void addBox(SimpleBoundingBox * Box) {
			if (FirstBox == nullptr) {
				FirstBox = new BoxNode();
				FirstBox->Box = Box;
			}
			else {
				FirstBox->addBox(Box);
			}

		}

		/**
		 * @fn	std::vector<SimpleBoundingBox *> * getBoxNodes(std::vector<SimpleBoundingBox * > * Collection)
		 *
		 * @brief	Gets box nodes
		 *
		 * @param [in,out]	Collection	If non-null, the collection.
		 *
		 * @returns	Null if it fails, else the box nodes.
		 */

		std::vector<SimpleBoundingBox *> * getBoxNodes(std::vector<SimpleBoundingBox * > * Collection) {
			if (FirstBox == nullptr) {
				return Collection;
			}
			else {
				return FirstBox->getBoxNodes(Collection);
			}
		}


	};


	struct CollisionGrid {


		CollisionGridSquare * l_Grids;
		int l_Size;
		int l_SquareSize;

		/**
		 * @fn	CollisionGrid(int Size, int SquareSize);
		 *
		 * @brief	Constructor
		 *
		 * @param	Size	  	The size of the collision grid in Tiles
		 * @param	SquareSize	Size of each Tile.
		 */

		CollisionGrid(int Size, int SquareSize);

		/**
		 * @fn	std::vector<SimpleBoundingBox *> getCollisions(SimpleBoundingBox * Box);
		 *
		 * @brief	Gets the possible Collisions of a specified Box
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 *
		 * @returns	Null if it fails, else the collisions.
		 */

		std::vector<SimpleBoundingBox *> getCollisions(SimpleBoundingBox * Box);

		/**
		 * @fn	int getGrid(ivec2 point);
		 *
		 * @brief	Get the grid tile at the given point
		 *
		 * @param	point	The point.
		 *
		 * @returns	The grid tile.
		 */

		int getGrid(ivec2 point);

		/**
		 * @fn	std::vector<int> getIntersectingGrids(SimpleBoundingBox * Box);
		 *
		 * @brief	Gets all grids intersecting a given box
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 *
		 * @returns	The intersecting grids.
		 */

		std::vector<int> getIntersectingGrids(SimpleBoundingBox * Box);

		/**
		 * @fn	void InsertBox(SimpleBoundingBox * Box);
		 *
		 * @brief	Inserts a box into the tile grid
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 */

		void InsertBox(SimpleBoundingBox * Box);

		/**
		 * @fn	void RemoveBox(SimpleBoundingBox * Box);
		 *
		 * @brief	Removes the box from the tile Grid
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 */

		void RemoveBox(SimpleBoundingBox * Box);

		/**
		 * @fn	std::string getIntersectedTileNames(SimpleBoundingBox * Box);
		 *
		 * @brief	Gets the numbers of Tiles this box intersects
		 *
		 * @param [in,out]	Box	If non-null, the box.
		 *
		 * @returns	The Tiles the boxes touches.
		 */

		std::string getIntersectedTileNames(SimpleBoundingBox * Box);

	};
}

