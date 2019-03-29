#pragma once
#include "SimpleSprite.h"
#include "Layer.h"




namespace OP{


	class StringSprite {
	
		std::vector<OP::SimpleSprite *> l_Sprites;
		std::string l_String;


		OP::fvec3 l_Pos;
		OP::Layer * p_Layer;


		bool l_wordWrap;
		int l_MaxSize;
		float l_Scale;

public:
	StringSprite(OP::Layer * Layer, OP::fvec3 pos = OP::fvec3(0, 0, 0), int MaxSize = 0, bool wordWrap = true, std::string string = "Error No Text", float scale = 1);

	void makeStringSprite();

	void setString();

	void toggleWordWrap();

	void setPos();

	void setMaxSize();

	void getMaxSize();

	void getString();

	void getWordWrap();

	void getPos();

	};
}