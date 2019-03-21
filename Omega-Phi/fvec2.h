#pragma once

namespace OP {
	class fvec2 {
	public:
		float x;
		float y;

		/**
		 * @fn	fvec2::fvec2(float x = 0, float y = 0);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	(Optional) The x coordinate.
		 * @param	y	(Optional) The y coordinate.
		 */

		fvec2(float x = 0, float y = 0);

		/**
		 * @fn	fvec2& fvec2::operator=(const fvec2& other);
		 *
		 * @brief	Assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	A shallow copy of this object.
		 */

		fvec2& operator=(const fvec2& other);

		/**
		 * @fn	fvec2& fvec2::operator+=(const fvec2& other);
		 *
		 * @brief	Addition assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		fvec2& operator+=(const fvec2& other);

		/**
		 * @fn	fvec2& fvec2::operator-=(const fvec2& other);
		 *
		 * @brief	Subtraction assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		fvec2& operator-=(const fvec2& other);

		/**
		 * @fn	bool fvec2::operator==(const fvec2& other);
		 *
		 * @brief	Equality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are considered equivalent.
		 */

		bool operator==(const fvec2& other);

		/**
		 * @fn	bool fvec2::operator!=(const fvec2& other);
		 *
		 * @brief	Inequality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are not considered equivalent.
		 */

		bool operator!=(const fvec2& other);

		/**
		 * @fn	int fvec2::dotProduct(const ivec2& other);
		 *
		 * @brief	Dot product
		 *
		 * @param	other	The other.
		 *
		 * @returns	An int.
		 */

		float dotProduct(const fvec2& other);
	};
}