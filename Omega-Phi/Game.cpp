#include "Game.h"
#include "ImageLoader.h"
#include "SimpleSprite.h"
#include <cstdint>
#include <cassert>
#include <FreeImage.h>

OP::Game::Game(const char* gameName, int x, int y) : l_Window(new Window(gameName, x, y)), l_Renderer(l_Window)
{
	l_SpriteAtlas = new ImageAtlas("./../res",0);

}

OP::Game::~Game()
{
	l_Layers.clear();
	l_Layers.shrink_to_fit();
	glfwTerminate();
}

void OP::Game::Start()
{
	int time = 1;
	while (l_Window->isRunning()) {
		//TODO  add a timer
		
		Render();
		Update(time);
		time++;

	}
}

void OP::Game::Init()
{
	//~~~To be implemented
}

void OP::Game::AddLayer(Layer &newLayer)
{
	l_Renderer.addLayer(&newLayer);
	l_Layers.push_back(&newLayer);
	//Add multiple layers later
	newLayer.AddTexture(l_SpriteAtlas->getImage(),l_SpriteAtlas->getImageMap());
}


void OP::Game::Render()
{
	//Ready the layers for Rendering
	for (int i = 0; i < l_Layers.size(); i++) {
		l_Layers[i]->Render();
	}

	//Render the layers	
	l_Renderer.commitRender();

	/* Swap front and back buffers */
	glfwSwapBuffers(l_Window->getWindow());



}

void OP::Game::Update(int time)
{
	glfwPollEvents();


}


void OP::Game::HandleEvent(OP::OPEvent * event) {
	
}