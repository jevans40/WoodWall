#pragma once
#include "Renderable.h"
#include <vector>
#include "Shader.h"
#include "VertexBuffer.h"
#include "EventListener.h"
#include "SimpleSprite.h"


/**
 * @namespace	OP
 *
 * @brief	The Engine Namespace
 */

namespace OP {
	
	class Game;

	/**
	 * @class	Layer
	 *
	 * @brief	A layer.
	 */

	class Layer {
	protected:
		const char* l_name;
		Game * p_Game;
		Shader l_Shader;
		VertexBuffer l_VertexBuffer; 
		std::vector<Renderable*> l_Sprites;

		bool l_Visibility;
		bool l_Loaded;

	public:

		/**
		 * @fn	Layer::Layer(Window* window, Shader& shader, const char* name, int priority);
		 *
		 * @brief	Constructor
		 *
		 * @param [in,out]	window  	The window this layer will be on.
		 * @param [in,out]	shader  	The shader.
		 * @param 		  	name		The name.
		 * @param 		  	priority	The priority.
		 */


		Layer(Game * game, Shader &shader, const char* name = "Default Name", bool Visible= true, bool Loaded = true) : l_Shader(shader), p_Game(game), l_name(name), l_Sprites(), l_Visibility(Visible), l_Loaded(Loaded) {
		}

		/**
		 * @fn	Layer::~Layer();
		 *
		 * @brief	Destructor
		 */

		~Layer();

		/**
		 * @fn	void Layer::update(int time);
		 *
		 * @brief	Update all sprites associated with this layer
		 *
		 * @param	time	The time in ms.
		 */

		virtual void Update(std::chrono::milliseconds time);

		/**
		 * @fn	void Layer::Render();
		 *
		 * @brief	Renders the sprites in this layer
		 */

		void Render();

		/**
		 * @fn	void Layer::AddRenderable(Renderable &renderable);
		 *
		 * @brief	Adds a renderable
		 *
		 * @param [in,out]	renderable	The renderable.
		 */

		void AddRenderable(Renderable &renderable);

		/**
		 * @fn	void Layer::removeRenderable(Renderable &renderable);
		 *
		 * @brief	Removes the renderable described by renderable
		 *
		 * @param [in,out]	renderable	The renderable.
		 */

		void removeRenderable(Renderable &renderable);

		/**
		/* DEPRICATED
		 * @fn	int Layer::getPriority();
		 *
		 * @brief	Gets the priority
		 *
		 * @returns	The priority.
		 * DEPRICATED
		 */

		int getPriority() const;

		/**
		 * @fn	void Layer::AddTexture(GLuint texID, GLuint texUnit);
		 *
		 * @brief	Adds a texture to 'texUnit'
		 *
		 * @param	texID  	Identifier for the tex.
		 * @param	texUnit	The tex unit.
		 */

		void AddTexture(GLuint texID, GLuint texUnit);

		/**
		 * @fn	Shader Layer::getShader();
		 *
		 * @brief	Gets the shader
		 *
		 * @returns	The shader.
		 */

		const Shader &getShader();

		/**
		 * @fn	VertexBuffer Layer::getVertexBuffer();
		 *
		 * @brief	Gets vertex buffer
		 *
		 * @returns	The vertex buffer.
		 */

		const VertexBuffer &getVertexBuffer();

		/**
		 * @fn	bool Layer::getKey(const char* key);
		 *
		 * @brief	Gets a key
		 *
		 * @param	key	The key.
		 *
		 * @returns	True if it succeeds, false if it fails.
		 */

		bool getKey(const char* key);

		/**
		 * @fn	fvec2 Layer::getWindowSize();
		 *
		 * @brief	Gets window size
		 *
		 * @returns	The window size.
		 */

		fvec2 getWindowSize();
	};

}