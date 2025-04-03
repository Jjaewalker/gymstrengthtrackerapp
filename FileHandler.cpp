#include "FileHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

FileHandler::FileHandler(){
}

void FileHandler::writeToFile(string name, int age, float weight, float height)
{

	std::ofstream myFile("Database.txt");  //Opening a file for writing 

	if (myFile.is_open()) {
		myFile << "Person Details:\n";
		myFile << "------------------:\n";
		myFile << "Age: " << age << "years\n";
		myFile << "Weight" << weight << "KG\n";
		myFile << "Height" << height << "cm\n";
		myFile.close(); //close file
		std::cout << "Data written to file successfuly!\n";
	}
	else
	{
		std::cout << "Error opening file!." << endl;
	}
}

