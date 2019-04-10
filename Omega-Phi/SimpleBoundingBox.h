#pragma once
#include <iostream>
#include <math.h>
#include "OPMath.h"

class SimpleBoundingBox {

private:

	//The top right and bottom left of an AABB
	OP::ivec2 min = { 0,0 };
	OP::ivec2 max = { 0,0 };

	//This scales the hit box of the object
	float Scale = 1;

	//This means that the Object does NOT move
	bool StaticMovement;

	
public:

	SimpleBoundingBox(OP::ivec2 min, OP::ivec2 max, float Scale = 1, bool isstatic = true);


	bool checkCollision(SimpleBoundingBox &left);

	float getCollisionAngle(SimpleBoundingBox &left);

	int getCollisionQuadrant(SimpleBoundingBox &left);


	OP::ivec2 getMin();


	OP::ivec2 getMax();

	float getScale();

	void setMin(OP::ivec2 Min);

	void setMax(OP::ivec2 Max);

	void setScale(float Scale);

	bool isStatic();

	void setStatic(bool staticState);



};