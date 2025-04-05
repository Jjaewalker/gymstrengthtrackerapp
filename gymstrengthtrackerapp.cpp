// gymstrengthtrackerapp.cpp 
//Main program for workout tracking

#include <iostream>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <iomanip>

using namespace std;
//User Class
class user {
public:
    std::string name;
    int age;
    float weight;

    User(std:string name, int age, float weight) : name(std::move(name)), age(age), weight(weight) {}
	};

//Struct to hold workout details
struct Workout{
    string exercise;
    int sets;
    int reps;
    double weight;
    string date;

};

//Class to handle strength tracking data
class StrengthTracker {
private:
    vector<Workout> workouts;
    sqlite3* db;

//Exercise class to hold exercise details
class Exercisee {
public:
    std::string name;
    float weight;
    int reps;
    int sets;
    std::string date;

 //constructor with a member initializer
    Exercise(std::string name, float weight, int reps, int sets, std::string date)
		: name(std::move(name)), weight(weight), reps(reps), sets(sets), date(std::move(date)) {}
	
};

public:
    StrengthTracker() {
        if (sqlite3_open("workouts.db", &db)) {
            cerr << "Error opening database!" << endl;
        }
        else {
            createTable();
        }
    }

    ~StrengthTracker() {
        sqlite3_close(db);
    }
	//create table 
    void createTable() {
        string sql = "CREATE TABLE IF NOT EXISTS Workouts ("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "Exercise TEXT, Sets INTEGER, Reps INTEGER, Weight REAL, Date TEXT);";

        char* errMsg;
        if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
            cerr << "Error creating table: " << errMsg << endl;
            sqlite3_free(errMsg);
        }
    }
	// allows the user to log a workout entry and saves it to both memory, stores all data in (w) i.e workout object.
    void logWorkout() {
        Workout w;
        cout << "Enter exercise: ";
        cin >> w.exercise;
        cout << "Enter sets: ";
        cin >> w.sets;
        cout << "Enter reps: ";
        cin >> w.reps;
        cout << "Enter weight: ";
        cin >> w.weight;
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> w.date;
        workouts.push_back(w);
        saveToDatabase(w);
    }
};


