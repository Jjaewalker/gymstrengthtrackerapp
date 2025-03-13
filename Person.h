#pragma once
#include <string>
#include <iostream>
//person class
class Person {
private:
   std::string name;
    int id;
    int ageInYears;
    float weightInKG; 
    float heightInCM;

public:
    //constructor
    Person(std::string name, int id, int age, float weight, float height);

    void printDetails();

};
