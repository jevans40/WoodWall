#include "ivec3.h"



OP::ivec3::ivec3(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

OP::ivec3& OP::ivec3::operator=(const ivec3& other) {
	if (this == &other)
		return *this;
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

OP::ivec3& OP::ivec3::operator-=(const ivec3& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

OP::ivec3& OP::ivec3::operator+=(const ivec3& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

bool OP::ivec3::operator==(const ivec3& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

bool OP::ivec3::operator!=(const ivec3& other) {
	return !(*this == other);
}

int OP::ivec3::dotProduct(const ivec3& other) {
	return (this->x * other.x  + this->y * other.y + this->z * other.z);
}