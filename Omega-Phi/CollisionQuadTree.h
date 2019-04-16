/**
 *			DEPRICATED!!!
 * @file	CollisionQuadTree.h.
 *
 * @brief	Declares the collision quad tree class
 * 			DEPRICATED
 */

#pragma once
#include "OPMath.h"
#include <vector>
#include "SimpleBoundingBox.h"
namespace OP {

	struct CollisionQuadTree {
	public:
		static const int l_MinimumSize = int(32);
		fvec2 Origin;
		int   Size;
		bool  Collision;

		CollisionQuadTree * Children[4] = { nullptr,nullptr,nullptr,nullptr };
		CollisionQuadTree * Parent;

		std::vector<SimpleBoundingBox *> Boxes;
		/*

		Quadrant Information
		_____
		|0|1|
		|---|
		|2|3|
		_____

		*/

		/**
		 * @fn	CollisionQuadTree(fvec2 Origin = { 0,0 }, int Size = 2048, CollisionQuadTree * Parent = nullptr);
		 *
		 * @brief	Constructor
		 *
		 * @param 		  	Origin	(Optional) The origin.
		 * @param 		  	Size  	(Optional) The size.
		 * @param [in,out]	Parent	(Optional) If non-null, the parent.
		 */

		CollisionQuadTree(fvec2 Origin , int Size, CollisionQuadTree * Parent);

		/**
		 * @fn	void getAllCollisions(std::vector&lt;SimpleBoundingBox*&gt; * Collection);
		 *
		 * @brief	Gets all collisions
		 *
		 * @param [in,out]	Collection	If non-null, the collection.
		 */

		void getAllCollisions(std::vector<SimpleBoundingBox*> * Collection);

		/**
		 * @fn	std::vector<SimpleBoundingBox*> * getCollisions(std::vector<SimpleBoundingBox*> * Collection);
		 *
		 * @brief	Gets the collisions
		 *
		 * @param [in,out]	Collection	If non-null, the collection.
		 *
		 * @returns	Null if it fails, else the collisions.
		 */

		std::vector<SimpleBoundingBox*> * getCollisions(std::vector<SimpleBoundingBox*> * Collection);

		/**
		 * @fn	int getNumCollisions();
		 *
		 * @brief	Gets number collisions
		 *
		 * @returns	The number collisions.
		 */

		int getNumCollisions();

		/**
		 * @fn	void Remove(SimpleBoundingBox * inserted);
		 *
		 * @brief	Removes the given inserted
		 *
		 * @param [in,out]	inserted	If non-null, the inserted to remove.
		 */

		void Remove(SimpleBoundingBox * inserted);

		/**
		 * @fn	CollisionQuadTree * searchForObject(SimpleBoundingBox * inserted);
		 *
		 * @brief	Searches for the first object
		 *
		 * @param [in,out]	inserted	If non-null, the inserted.
		 *
		 * @returns	Null if it fails, else the found object.
		 */

		CollisionQuadTree * searchForObject(SimpleBoundingBox * inserted);

		/**
		 * @fn	int getQuadrent(SimpleBoundingBox * inserted, fvec2 origin);
		 *
		 * @brief	Gets a quadrent
		 *
		 * @param [in,out]	inserted	If non-null, the inserted.
		 * @param 		  	origin  	The origin.
		 *
		 * @returns	The quadrent.
		 */

		int getQuadrent(SimpleBoundingBox * inserted, fvec2 origin);

		/**
		 * @fn	bool canFit(SimpleBoundingBox * inserted, fvec2 origin, int size);
		 *
		 * @brief	Determine if we can fit
		 *
		 * @param [in,out]	inserted	If non-null, the inserted.
		 * @param 		  	origin  	The origin.
		 * @param 		  	size		The size.
		 *
		 * @returns	True if we can fit, false if not.
		 */

		bool canFit(SimpleBoundingBox * inserted, fvec2 origin, int size);

		/**
		 * @fn	void Insert(SimpleBoundingBox * inserted);
		 *
		 * @brief	Inserts the given inserted
		 *
		 * @param [in,out]	inserted	If non-null, the inserted.
		 */

		void Insert(SimpleBoundingBox * inserted);

		/**
		 * @fn	void grow(int quadrant);
		 *
		 * @brief	Grows
		 *
		 * @param	quadrant	The quadrant.
		 */

		void grow(int quadrant);

	};
}
