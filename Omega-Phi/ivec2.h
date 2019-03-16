#pragma once

namespace OP {
	class ivec2 {
	public:
		int x;
		int y;



		/**
		 * @fn	ivec2::ivec2(int x = 0, int y = 0)
		 *
		 * @brief	Constructor
		 *
		 * @param	x	(Optional) The x coordinate.
		 * @param	y	(Optional) The y coordinate.
		 */

		ivec2(int x = 0, int y = 0);

		/**
		 * @fn	ivec2& ivec2::operator=(const ivec2& other);
		 *
		 * @brief	Assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	A shallow copy of this object.
		 */

		ivec2& operator=(const ivec2& other);

		/**
		 * @fn	ivec2& ivec2::operator+=(const ivec2& other);
		 *
		 * @brief	Addition assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		ivec2& operator+=(const ivec2& other);

		/**
		 * @fn	ivec2& ivec2::operator-=(const ivec2& other);
		 *
		 * @brief	Subtraction assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		ivec2& operator-=(const ivec2& other);

		/**
		 * @fn	bool ivec2::operator==(const ivec2& other);
		 *
		 * @brief	Equality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are considered equivalent.
		 */

		bool operator==(const ivec2& other);

		/**
		 * @fn	bool ivec2::operator!=(const ivec2& other);
		 *
		 * @brief	Inequality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are not considered equivalent.
		 */

		bool operator!=(const ivec2& other);

		/**
		 * @fn	int ivec2::dotProduct(const ivec2& other);
		 *
		 * @brief	Dot product
		 *
		 * @param	other	The other.
		 *
		 * @returns	An int.
		 */

		int dotProduct(const ivec2& other);
	};
}