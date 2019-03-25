#include "Renderable.h"
#include <iostream>
void OP::Renderable::setTexSize(fvec2 size)
{
	TexSize = size;
	setTexx(TexPos.x);
	setTexy(TexPos.y);
}
OP::Renderable::Renderable()
{
	setSize();
	setZPos(0);
	setColor(0xffffffff);
	setTexx(0);
	setTexy(0);
	setTexMap(-1);
}

OP::Renderable::Renderable(fvec3 pos , fvec2 size, unsigned int Color)
{
	setSize(size);
	setXPos(pos.x);
	setYPos(pos.y);
	setZPos(pos.z);
	setColor(Color);
	setTexx(0);
	setTexy(0);
	setTexMap(-1);
}

void OP::Renderable::setXPos(float x)
{
	Pos.x = x;
	VertData[0].pos.x = x ;
	VertData[1].pos.x = x + Size.x ;
	VertData[2].pos.x = x + Size.x ;
	VertData[3].pos.x = x ;
}

void OP::Renderable::setYPos(float y)
{
	Pos.y = y;
	VertData[0].pos.y = y;
	VertData[0].pos.y = y ;
	VertData[1].pos.y = y ;
	VertData[2].pos.y = y + Size.y ;
	VertData[3].pos.y = y + Size.y ;
}

void OP::Renderable::setZPos(float z)
{
	Pos.z = z;
	VertData[0].pos.z = z ;
	VertData[1].pos.z = z ;
	VertData[2].pos.z = z ;
	VertData[3].pos.z = z ;
}

void OP::Renderable::setColor(unsigned int Color)
{
	this->Color = Color;
	VertData[0].color = Color;
	VertData[1].color = Color;
	VertData[2].color = Color;
	VertData[3].color = Color;
}

void OP::Renderable::setSize(fvec2 size)
{
	this->Size.x = size.x;
	this->Size.y = size.y;
	this->setXPos(this->Pos.x);
	this->setYPos(this->Pos.y);
}

float OP::Renderable::getXPos()
{
	return Pos.x;
}

float OP::Renderable::getYPos()
{
	return Pos.y;
}

float OP::Renderable::getZPos()
{
	return Pos.z;
}

OP::Vertex OP::Renderable::getVertex(int vertex)
{
	return (vertex < 4 && vertex > -1 ? VertData[vertex] : Vertex());
}

OP::Vertex * OP::Renderable::getVertexArray()
{
	return VertData;
}

void OP::Renderable::Update(int time)
{

}

unsigned int OP::Renderable::GetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xFF)
{
	unsigned int Color = (int(a) << 24) + (int(b) << 16) + (int(g) << 8) + (int(r) << 0) ;
	return Color;
}

void OP::Renderable::setTexx(float Texx)
{
	TexPos.x = Texx;
	VertData[0].texPos.x = Texx;
	VertData[1].texPos.x = Texx + TexSize.x;
	VertData[2].texPos.x = Texx + TexSize.x;
	VertData[3].texPos.x = Texx;
}

void OP::Renderable::setTexy(float Texy)
{
	TexPos.y = Texy;
	VertData[0].texPos.y = Texy;
	VertData[1].texPos.y = Texy;
	VertData[2].texPos.y = Texy + TexSize.y;
	VertData[3].texPos.y = Texy + TexSize.y;
}

void OP::Renderable::setTexMap(int TexMap)
{
	TexMap = TexMap < 32 ? TexMap : -1;
	this->TexMap = TexMap;
	VertData[0].texMap = TexMap;
	VertData[1].texMap = TexMap;
	VertData[2].texMap = TexMap;
	VertData[3].texMap = TexMap;
}



