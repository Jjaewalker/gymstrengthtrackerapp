#include "Person.h"

Person::Person(std::string name, int id, int age, float weight, float height) 
	: name{ name }, id{ id }, ageInYears{ age }, weightInKG{ weight }, heightInCM{ height }
{
}

void Person::printDetails()
{
	std::cout << "This person's name is: " << name <<"\n";
	std::cout << "User ID is: " << id << "\n";
	std::cout << "Age: " << ageInYears << " Years\n";
	std::cout << "This Person's Weight is: " << weightInKG << " KG\n";
	std::cout << "This Person's Height is: " << heightInCM << " CM\n";

	//Complete the rest yourself
}
