#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

namespace OP {

	std::string loadFile(const char* filePath) {
		std::ifstream is(filePath);

		if (is.is_open()) {
			is.seekg(0, is.end);
			int length = is.tellg();
			is.seekg(0, is.beg);

			std::stringstream buffer;
			buffer << is.rdbuf();

			if (!is) {
				std::cout << "error: file could not be read" << is.rdstate() << std::endl;
			}
			is.close();
			return buffer.str();
		}
		else {
			return '\0';
		}
	}

}