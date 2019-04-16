#pragma once
#include "SimpleBoundingBox.h"
#include <vector>

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
			if (next != newNext) delete next;
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