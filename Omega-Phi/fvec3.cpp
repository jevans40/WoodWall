#include "fvec3.h"



OP::fvec3::fvec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

OP::fvec3& OP::fvec3::operator=(const fvec3& other) {
	if (this == &other)
		return *this;
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

OP::fvec3& OP::fvec3::operator-=(const fvec3& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

OP::fvec3& OP::fvec3::operator+=(const fvec3& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

bool OP::fvec3::operator==(const fvec3& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

bool OP::fvec3::operator!=(const fvec3& other) {
	return !(*this == other);
}

float OP::fvec3::dotProduct(const fvec3& other) {
	return (this->x * other.x + this->y * other.y + this->z * other.z);
}