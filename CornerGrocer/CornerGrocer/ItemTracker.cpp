#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void ItemTracker::LoadData(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open input file: " << filename << endl;
        exit(1);
    }

    string item;
    while (inFile >> item) {
        itemFrequency[item]++;
    }

    inFile.close();
}

void ItemTracker::WriteBackup(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not create backup file: " << filename << endl;
        return;
    }

    for (auto const& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}

int ItemTracker::GetItemFrequency(const string& item) {
    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency[item];
    }
    return 0;
}

void ItemTracker::PrintAllFrequencies() {
    for (auto const& pair : itemFrequency) {
        cout << setw(12) << left << pair.first << " " << pair.second << endl;
    }
}

void ItemTracker::PrintHistogram() {
    for (auto const& pair : itemFrequency) {
        cout << setw(12) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}