#include "ivec2.h"



OP::ivec2::ivec2(int x, int y)
{
	this->x = x;
	this->y = y;
}

 OP::ivec2& OP::ivec2::operator=(const ivec2& other) {
	 if (this == &other)
		 return *this;
	 this->x = other.x;
	 this->y = other.y;
	 return *this;
}

 OP::ivec2& OP::ivec2::operator-=(const ivec2& other) {
	 this->x -= other.x;
	 this->y -= other.y;
	 return *this;
 }

 OP::ivec2& OP::ivec2::operator+=(const ivec2& other) {
	 this->x += other.x;
	 this->y += other.y;

	 return *this;
 }

 bool OP::ivec2::operator==(const ivec2& other) {
	 return (this->x == other.x && this->y == other.y);
 }

 bool OP::ivec2::operator!=(const ivec2& other) {
	 return !(*this == other);
 }

 int OP::ivec2::dotProduct(const ivec2& other) {
	 return (this->x * other.x + this->y * other.y);
 }