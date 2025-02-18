// gymstrengthtrackerapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



// GymApp.cpp: Main program for workout tracking

#include <iostream>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <iomanip>

using namespace std;

// Struct to hold workout details
struct Workout{
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
        saveToDatabase(w);
    }
};