#pragma once
#include <iostream>
#include <math.h>
#include ""

struct SimpleBoundingBox {

public:
	OP::ivec2 min = { 0,0 };
	OP::ivec2 max = { 0,0 };
	
	SimpleBoundingBox(OP::ivec2 min, OP::ivec2 max) {
		this->min = min;
		this->max = max;
	}

	bool Collision(SimpleBoundingBox &left) {
		if ((min.x - left.max.x) > 0 || (min.y - left.max.y) > 0) {
			return false;
		}
		
		if ((left.min.x - max.x) > 0 || (left.min.y - max.y) > 0) {
			return false;
		}
		return true;
	}

	float getCollisionAngle(SimpleBoundingBox &left) {
		OP::ivec2 thisMiddle = { min.x + (max.x - min.x) / 2 , min.y + (max.y - min.y) / 2 };
		OP::ivec2 leftMiddle = { left.min.x + (left.max.x - left.min.x) / 2 , left.min.y + (left.max.y - left.min.y) / 2 };
		float angle = atan2(leftMiddle.y - thisMiddle.y, leftMiddle.x - thisMiddle.x) * 180 / (atan(1) * 4);
		if (angle > 0) {
		//std::cout << angle << std::endl;
			return angle;
		}
		angle = (360 + angle);

		//std::cout << angle << std::endl;
		return angle;
	}
};