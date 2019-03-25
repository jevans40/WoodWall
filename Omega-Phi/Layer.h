#pragma once
#include "Window.h"
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

	/**
	 * @class	Layer
	 *
	 * @brief	A layer.
	 */

	class Layer : EventListner {
	private:
		const char* l_name;
		Window* l_Window;
		int l_Priority;
		Shader l_Shader;
		VertexBuffer l_VertexBuffer; 
		//EVENT HANDLER FOR SENDING A DELETE SIGNAL TO GAME
		std::vector<Renderable*> l_Sprites;

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


		Layer(Window* window, Shader &shader, const char* name = "Default Name", int priority = 0) : l_Shader(shader), l_Window(window), l_name(name), l_Priority(priority) {
			std::cout << " I made it here before I crashed yay";
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

		void Update(int time);

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
		 * @fn	int Layer::getPriority();
		 *
		 * @brief	Gets the priority
		 *
		 * @returns	The priority.
		 */

		int getPriority() const;

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

		// Inherited via EventListner
		virtual void HandleEvent(OPEvent * Event) override;
	};

}