#include "fvec2.h"


OP::fvec2::fvec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

OP::fvec2& OP::fvec2::operator=(const fvec2& other) {
	if (this == &other)
		return *this;
	this->x = other.x;
	this->y = other.y;
	return *this;
}

OP::fvec2& OP::fvec2::operator-=(const fvec2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

OP::fvec2& OP::fvec2::operator+=(const fvec2& other) {
	this->x += other.x;
	this->y += other.y;

	return *this;
}

bool OP::fvec2::operator==(const fvec2& other) {
	return (this->x == other.x && this->y == other.y);
}

bool OP::fvec2::operator!=(const fvec2& other) {
	return !(*this == other);
}

float OP::fvec2::dotProduct(const fvec2& other) {
	return (this->x * other.x + this->y * other.y);
}