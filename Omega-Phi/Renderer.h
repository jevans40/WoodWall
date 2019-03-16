#pragma once
#include "Renderable.h"
#include <vector>

namespace OP {

	class Renderer {
	private:
		 std::vector<Vertex> VertexBuffer;
		 int numOfSprites;

		 Renderer();

		 void Init();

		 void AddTexture(/*Texture goes here*/);

		 void RemoveTexture(int TextureIndex);

		 void Submit(Renderable toRender);

		 void RenderFont();

		 void commitRender();



	};

}