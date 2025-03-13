#pragma once
#include <string>
//filehandler 

class FileHandler{
public:
	FileHandler();
	void writeToFile(std::string name, int age, float weight, float height);
};

