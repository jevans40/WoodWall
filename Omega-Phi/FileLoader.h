#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>

namespace OP {

	bool hasExtension(std::string const &fileName, std::string const &extension);

	std::string loadFile(const char* filePath);

	std::vector<std::string> getFiles(const char * dirPath, const char* fileExtension = "");
	
}