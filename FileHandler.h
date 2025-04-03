#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//filehandler 
class FileHandler{
public:
	FileHandler();
	void writeToFile(std::string name, int age, float weight, float height);
};

