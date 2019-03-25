#include "FileLoader.h"
namespace OP {

	bool hasExtension(std::string const &fileName, std::string const &extension) {
		if (fileName.length() >= extension.length()) {
			return (0 == fileName.compare(fileName.length() - extension.length(), extension.length(), extension));
		}
		else {
			return false;
		}
	}

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

	std::vector<std::string> getFiles(const char * dirPath, const char* fileExtension) {
		std::vector<std::string> Files;
		for (const auto & entry : std::filesystem::directory_iterator(dirPath))
			if (hasExtension(entry.path().string(), fileExtension))
				Files.push_back(entry.path().string());
		return Files;
	}

}