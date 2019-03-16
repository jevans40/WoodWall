#pragma once

namespace OP {
	class fvec4 {
	public:
		int x;
		int y;
		int z;
		int w;



		/**
		 * @fn	fvec4::fvec4(int x = 0, int y = 0, int z = 0, int w = 0);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	(Optional) The x coordinate.
		 * @param	y	(Optional) The y coordinate.
		 * @param	z	(Optional) The z coordinate.
		 * @param	w	(Optional) The w coordinate.
		 */

		fvec4(int x = 0, int y = 0, int z = 0, int w = 0);

		/**
		 * @fn	fvec4& fvec4::operator=(const fvec4& other);
		 *
		 * @brief	Assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	A shallow copy of this object.
		 */

		fvec4& operator=(const fvec4& other);

		/**
		 * @fn	fvec4& fvec4::operator+=(const fvec4& other);
		 *
		 * @brief	Addition assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		fvec4& operator+=(const fvec4& other);

		/**
		 * @fn	fvec4& fvec4::operator-=(const fvec4& other);
		 *
		 * @brief	Subtraction assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		fvec4& operator-=(const fvec4& other);

		/**
		 * @fn	bool fvec4::operator==(const fvec4& other);
		 *
		 * @brief	Equality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are considered equivalent.
		 */

		bool operator==(const fvec4& other);

		/**
		 * @fn	bool fvec4::operator!=(const fvec4& other);
		 *
		 * @brief	Inequality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are not considered equivalent.
		 */

		bool operator!=(const fvec4& other);

		/**
		 * @fn	int fvec4::dotProduct(const fvec4& other);
		 *
		 * @brief	Dot product
		 *
		 * @param	other	The other.
		 *
		 * @returns	An int.
		 */

		int dotProduct(const fvec4& other);
	};
}