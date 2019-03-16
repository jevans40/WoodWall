#include "fvec4.h"


OP::fvec4::fvec4(int x, int y, int z, int w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

OP::fvec4& OP::fvec4::operator=(const fvec4& other) {
	if (this == &other)
		return *this;
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
	return *this;
}

OP::fvec4& OP::fvec4::operator-=(const fvec4& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
	return *this;
}

OP::fvec4& OP::fvec4::operator+=(const fvec4& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
	return *this;
}

bool OP::fvec4::operator==(const fvec4& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
}

bool OP::fvec4::operator!=(const fvec4& other) {
	return !(*this == other);
}

int OP::fvec4::dotProduct(const fvec4& other) {
	return (this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w);
}