#pragma once
#include "Layer.h"
#include <vector>

namespace OP {

	class Renderer {
	private:
		 std::vector<Layer *> l_Layers;
		 int numOfSprites;

	public:
		 Renderer();

		 void Init();

		 void AddTexture(/*Texture goes here*/);

		 void RemoveTexture(int TextureIndex);

		 void addLayer(Layer *toRender);

		 void RenderFont();

		 void commitRender();



	};

}