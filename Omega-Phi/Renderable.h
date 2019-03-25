#pragma once
#include "OPMath.h"
#include "DataStructure.h"
namespace OP {



	class Renderable {
	private:
		
		Vertex VertData[4];
		fvec2 Size;
		fvec3 Pos;
		fvec2 TexPos;
		fvec2 TexSize;
		unsigned int Color;
		int TexMap;


	protected:
		/**
		 * @fn	void Renderable::setTexx(float Texx);
		 *
		 * @brief	Sets a texx
		 *
		 * @param	Texx	The x texture.
		 */

		void setTexx(float Texx);

		/**
		 * @fn	void Renderable::setTexy(float Texy);
		 *
		 * @brief	Sets a texy
		 *
		 * @param	Texy	The y texture.
		 */

		void setTexy(float Texy);

		/**
		 * @fn	void Renderable::setTexMap(int TexMap);
		 *
		 * @brief	Sets tex map
		 *
		 * @param	TexMap	The tex map.
		 */

		void setTexMap(int TexMap);

		/**
		 * @fn	void Renderable::setTexSize(fvec2 size = fvec2(0, 0));
		 *
		 * @brief	Sets texture size
		 *
		 * @param	size	(Optional) The size.
		 */

		void setTexSize(fvec2 size = fvec2(0, 0));



	public:

		Renderable();

		/**
		 * @fn	Renderable::Renderable(float x = 0, float y = 0, float z = 0, unsigned int Color = 0xffffffff, float Texx = 0, float Texy = 0, int TexMap = -1);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	  	(Optional) The x coordinate based off of top left.
		 * @param	y	  	(Optional) The y coordinate based off of top left.
		 * @param	z	  	(Optional) The z coordinate based off of top left.
		 * @param	Color 	(Optional) The color.
		 * @param	Texx  	(Optional) The texture x coordinate.
		 * @param	Texy  	(Optional) The texture y coordinate.
		 * @param	TexMap	(Optional) The texture map.
		 */

		Renderable(fvec3 pos = fvec3(0, 0, 0), fvec2 size = fvec2(1,1), unsigned int Color = 0xffffffff);

		/**
		 * @fn	void Renderable::setXPos(float x);
		 *
		 * @brief	Sets x coordinate position based off of top left
		 *
		 * @param	x	The x coordinate.
		 * 				
		 */

		void setXPos(float x);

		/**
		 * @fn	void Renderable::setYPos(float y);
		 *
		 * @brief	Sets y coordinate position
		 *
		 * @param	y	The y coordinate.
		 */

		void setYPos(float y);

		/**
		 * @fn	void Renderable::setZPos(float z);
		 *
		 * @brief	Sets z coordinate position
		 *
		 * @param	z	The z coordinate.
		 */

		void setZPos(float z);

		/**
		 * @fn	void Renderable::setColor(unsigned int Color);
		 *
		 * @brief	Sets a color
		 *
		 * @param	Color	The color.
		 */

		void setColor(unsigned int Color);

		/**
		 * @fn	void Renderable::setSize();
		 *
		 * @brief	Sets the size
		 */

		void setSize(fvec2 size = fvec2(1,1));

		/**
		 * @fn	float Renderable::getXPos();
		 *
		 * @brief	Get x coordinate position
		 *
		 * @returns	The x coordinate position.
		 */

		float getXPos();

		/**
		 * @fn	float Renderable::getYPos();
		 *
		 * @brief	Get y coordinate position
		 *
		 * @returns	The y coordinate position.
		 */

		float getYPos();

		/**
		 * @fn	float Renderable::getZPos();
		 *
		 * @brief	Get z coordinate position
		 *
		 * @returns	The z coordinate position.
		 */

		float getZPos();
					

		/**
		 * @fn	Vertex Renderable::getVertexArray(int vertexIndex);
		 *
		 * @brief	Gets vertex array
		 *
		 * @param	vertexIndex	Zero-based index of the vertex.
		 *
		 * @returns	The vertex array.
		 */

		Vertex  getVertex(int vertexIndex);

		/**
		 * @fn	Vertex * Renderable::getVertexArray();
		 *
		 * @brief	Gets vertex array
		 *
		 * @returns	Null if it fails, else the vertex array.
		 */

		Vertex * getVertexArray();

		/**
		 * @fn	virtual void Renderable::Update(int time);
		 *
		 * @brief	Updates the given time
		 *
		 * @param	time	The time.
		 */

		virtual void Update(int time);

		/**
		 * @fn	static unsigned int Renderable::GetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		 *
		 * @brief	Gets a color
		 *
		 * @param	r	Red Color Value
		 * @param	g	Green Color Value
		 * @param	b	Blue Color Value
		 * @param	a	Alpha Channel value
		 *
		 * @returns	The color.
		 */

		static unsigned int GetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	};
}