// gymstrengthtrackerapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <iomanip>

using namespace std;
// Struct to hold workout data 
struct Workout {
	string exercise;
	int sets;
	int reps;
	double weight;
	string date;
};

class StrengthTracker {
private:
	vector<Workout> workouts;// Vector to hold all workouts
	sqlite3* db; // Database object


