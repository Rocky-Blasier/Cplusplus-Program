#include "ItemTracker.h"
#include <iostream>
using namespace std;

void PrintMenu() {
    cout << "\nCorner Grocer Item Tracker\n";
    cout << "--------------------------\n";
    cout << "1. Look up frequency for a specific item\n";
    cout << "2. Print all items with purchase counts\n";
    cout << "3. Print histogram of all items\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ItemTracker tracker;

    // Load input file
    tracker.LoadData("CS210_Project_Three_Input_File.txt");

    // Create backup file
    tracker.WriteBackup("frequency.dat");

    int choice = 0;
    while (choice != 4) {
        PrintMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter item to search for: ";
            cin >> item;
            int count = tracker.GetItemFrequency(item);
            cout << item << " " << count << endl;
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
