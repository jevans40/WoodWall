#include "CollisionQuadTree.h"
namespace OP {

	CollisionQuadTree::
		CollisionQuadTree(fvec2 Origin = { 0,0 }, int Size = 2048, CollisionQuadTree * Parent = nullptr) {
		this->Parent = Parent;
		this->Origin = Origin;
		this->Size = Size;

	}

	void CollisionQuadTree::getAllCollisions(std::vector<SimpleBoundingBox*> * Collection) {
		for (int i = 0; i < 4; i++) {
			if (Children[i] != nullptr) {
				Children[i]->getAllCollisions(Collection);


			}
		}
		for (int i = 0; i < Boxes.size(); i++) {
			Collection->push_back(Boxes[i]);
		}
	}

	std::vector<SimpleBoundingBox*> *CollisionQuadTree::getCollisions(std::vector<SimpleBoundingBox*> * Collection) {
		int num;
		if (Boxes.size() > 0) {
			if (Boxes.size() > 1) {
				getAllCollisions(Collection);
			}
			else {
				if (getNumCollisions() - Boxes.size() > 0) {
					getAllCollisions(Collection);
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				Children[i]->getCollisions(Collection);
			}
		}
		return Collection;
	}

	int CollisionQuadTree::getNumCollisions() {
		int num = 0;
		for (int i = 0; i < 4; i++) {
			if (Children[i] != nullptr) {
				num += Children[i]->getNumCollisions();
			}
		}
		return Boxes.size() + num;
	}

	/*

	Quadrant Information::
	_____
	|0|1|
	|---|
	|2|3|
	_____

	*/

	void CollisionQuadTree::Remove(SimpleBoundingBox * inserted) {
		CollisionQuadTree * tree = searchForObject(inserted);
		if (tree != nullptr) {
			for (int i = 0; i < tree->Boxes.size(); i++) {
				if (tree->Boxes[i] == inserted) {
					tree->Boxes.erase(tree->Boxes.begin() + i);
				}
			}
		}
	}


	CollisionQuadTree * CollisionQuadTree::searchForObject(SimpleBoundingBox * inserted) {
		for (int i = 0; i < Boxes.size(); i++) {
			if (Boxes[i] == inserted) {
				return this;
			}
		}
		if (Children[getQuadrent(inserted, Origin)] != nullptr) {
			return Children[getQuadrent(inserted, Origin)]->searchForObject(inserted);
		}
		return nullptr;

	}

	int CollisionQuadTree::getQuadrent(SimpleBoundingBox * inserted, fvec2 origin) {

		int Quadrent = 0;

		if (inserted->getMin().y - (origin.y + Size) < -1) {
			if (inserted->getMin().x - (origin.x + Size) < -1) {
				Quadrent = 0;
			}
			else {
				Quadrent = 1;
			}
		}
		else {
			if (inserted->getMin().x - (origin.x + Size) < -1) {
				Quadrent = 2;
			}
			else {
				Quadrent = 3;
			}
		}
		return Quadrent;
	}

	bool CollisionQuadTree::canFit(SimpleBoundingBox * inserted, fvec2 origin, int size) {
		if (inserted->getMin().x < origin.x || inserted->getMin().y < origin.y || inserted->getMax().y > origin.y + size || inserted->getMax().x > origin.x + size) {
			return false;
		}
		return true;
	}

	void CollisionQuadTree::Insert(SimpleBoundingBox * inserted) {

		int Quadrent = getQuadrent(inserted, Origin);

		//Make sure it exists in the current box
		if (!canFit(inserted, Origin, Size)) {
			if (Parent == nullptr) {
				grow(Quadrent);
				Parent->Insert(inserted);
				return;
			}
		}

		Quadrent = getQuadrent(inserted, { Origin.x + Size / 2,Origin.y + Size / 2 });

		//Find if it fits in a smaller box
		int offSetY = 0;
		int offSetX = 0;
		if (Quadrent == 1 || Quadrent == 3) {
			offSetX += Size / 2;
		}
		if (Quadrent == 1 || Quadrent == 3) {
			offSetY += Size / 2;
		}


		if (canFit(inserted, { Origin.x + offSetX, Origin.y + offSetY }, Size / 2)) {
			//If a child exists, insert it, if not make a child
			if (Children[Quadrent] != nullptr) {
				Children[Quadrent]->Insert(inserted);
			}
			else {
				Children[Quadrent] = new CollisionQuadTree({ Origin.x + offSetX, Origin.y + offSetY }, Size / 2, this);
			}
		}
		else {
			//Put it in this box
			this->Boxes.push_back(inserted);
		}


	}


	/*

	Quadrant Information::
	_____
	|0|1|
	|---|
	|2|3|
	_____

	*/
	void CollisionQuadTree::grow(int quadrant) {
		int offSetX = Size * -1;
		int offSetY = Size * -1;


		if (quadrant == 2) {
			offSetY = 0;
			offSetX = offSetX * 2;
		}

		if (quadrant == 1) {
			offSetX = 0;
			offSetY = offSetY * 2;
		}


		if (quadrant == 0) {
			offSetX = 0;
			offSetY = 0;
		}

		fvec2 newOrigin = { Origin.x + offSetX,Origin.y + offSetY };
		CollisionQuadTree * newParent = new CollisionQuadTree(newOrigin, Size * 2, nullptr);

		Parent = newParent;
		Parent->Children[3 - quadrant] = this;
		return;
	}
};