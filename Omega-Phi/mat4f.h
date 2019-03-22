#pragma once


namespace OP {
	class mat4f {
	public:
		float data[16] = {};

		mat4f(){
			for (int i = 0; i < 16; i++) {
				data[i] = 0;
			}
		}

	static void glOrtho(
			const float &b, const float &t, const float &l, const float &r,
			const float &n, const float &f,
			mat4f &M)
		{
			// set OpenGL perspective projection matrix
			M.data[0] = 2 / (r - l);
			M.data[1] = 0;
			M.data[2] = 0;
			M.data[3] = 0;

			M.data[4] = 0;
			M.data[5] = 2 / (t - b);
			M.data[6] = 0;
			M.data[7] = 0;

			M.data[8] = 0;
			M.data[9] = 0;
			M.data[10] = -2 / (f - n);
			M.data[11] = 0;

			M.data[12] = -(r + l) / (r - l);
			M.data[13] = -(t + b) / (t - b);
			M.data[14] = -(f + n) / (f - n);
			M.data[15] = 1;
		}

	};
}