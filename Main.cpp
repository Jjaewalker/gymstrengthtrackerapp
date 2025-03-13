// GymApp.cpp: Main program for workout tracking

#include <iostream>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <iomanip>
#include "Person.h"
#include "FileHandler.h"
using namespace std;



// Struct to hold workout details

struct Workout {
    string exercise;
    int sets;
    int reps;
    double weight;
    string date;

};

// Class to handle strength tracking

class StrengthTracker {
private:
    vector<Workout> workouts;
    sqlite3* db;

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
        // saveToDatabase(w);
    }
};

int main()
{
    Person Charlie ("Charlie", 69, 123, 117.3, 192.3);
    FileHandler Data;
    Data.writeToFile(Charlie.name, Charlie.ageInYears, Charlie.weightInKG, Charlie.heightInCM);
    return 0;
}

