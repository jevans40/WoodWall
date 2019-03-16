#include "ivec4.h"



OP::ivec4::ivec4(int x, int y, int z, int w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

OP::ivec4& OP::ivec4::operator=(const ivec4& other) {
	if (this == &other)
		return *this;
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
	return *this;
}

OP::ivec4& OP::ivec4::operator-=(const ivec4& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
	return *this;
}

OP::ivec4& OP::ivec4::operator+=(const ivec4& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
	return *this;
}

bool OP::ivec4::operator==(const ivec4& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
}

bool OP::ivec4::operator!=(const ivec4& other) {
	return !(*this == other);
}

int OP::ivec4::dotProduct(const ivec4& other) {
	return (this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w);
}