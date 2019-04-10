#include "SimpleBoundingBox.h"

OP::ivec2 SimpleBoundingBox::getMin()
{
	return min;
}

OP::ivec2 SimpleBoundingBox::getMax()
{
	return max;
}

float SimpleBoundingBox::getScale()
{
	return Scale;
}

void SimpleBoundingBox::setMin(OP::ivec2 Min)
{
	min = Min;
}

void SimpleBoundingBox::setMax(OP::ivec2 Max)
{
	max = Max;
}

void SimpleBoundingBox::setScale(float Scale)
{
	this->Scale = Scale;
}

bool SimpleBoundingBox::isStatic()
{
	return StaticMovement;
}

void SimpleBoundingBox::setStatic(bool staticState)
{
	StaticMovement = staticState;
}

 SimpleBoundingBox::SimpleBoundingBox(OP::ivec2 min, OP::ivec2 max, float Scale, bool isstatic) {
	this->min = { int(min.x * Scale), int(min.y * Scale) };
	this->max = { int(max.x * Scale), int(max.y * Scale) };
	this->Scale = Scale;
	StaticMovement = isstatic;

}


bool SimpleBoundingBox::checkCollision(SimpleBoundingBox &left) {
	if ((min.x - left.max.x) > 0 || (min.y - left.max.y) > 0) {
		return false;
	}

	if ((left.min.x - max.x) > 0 || (left.min.y - max.y) > 0) {
		return false;
	}
	return true;
}

float SimpleBoundingBox::getCollisionAngle(SimpleBoundingBox &left) {
	OP::ivec2 thisMiddle = { min.x + (max.x - min.x) / 2 , min.y + (max.y - min.y) / 2 };
	OP::ivec2 leftMiddle = { left.min.x + (left.max.x - left.min.x) / 2 , left.min.y + (left.max.y - left.min.y) / 2 };
	float angle = atan2(leftMiddle.y - thisMiddle.y, leftMiddle.x - thisMiddle.x) * 180 / (atan(1) * 4);
	if (angle > 0) {
		return angle;
	}
	angle = (360 + angle);

	return angle;
}

int SimpleBoundingBox::getCollisionQuadrant(SimpleBoundingBox & left)
{
	int v = abs(left.getMax().y - min.y);
	if (abs(left.getMax().y - min.y) < 2) {
		return 1;
	}
	v = abs(max.y - left.getMin().y);
	if (abs(max.y - left.getMin().y) < 2) {
		return 3;
	}
	if (this->min.x > left.getMin().x) {
		return 2;
	}
	return 0;
	

}

