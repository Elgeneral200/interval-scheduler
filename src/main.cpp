#include <iostream>
#include <vector>
#include <windows.h>
#include "interval.hpp"

using namespace std;

void clearScreen() {
    system("CLS");
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printBoxSeparator() {
    setColor(14);
    cout << "+----------------------------------------------------+" << endl;
    setColor(7);
}

void printCenteredText(string text) {
    int width = 50;
    int padding = (width - text.length()) / 2;
    string paddingStr(padding, ' ');
    setColor(10);
    cout << "| " << paddingStr << text << paddingStr;
    if (text.length() % 2 != 0) cout << " ";
    cout << " |" << endl;
    setColor(7);
}

void printWelcome() {
    printBoxSeparator();
    printCenteredText("Welcome to the Interval Scheduler App");
    printBoxSeparator();
}

void printMenu() {
    setColor(11);
    cout << "| 1. Enter Intervals                                 |" << endl;
    cout << "| 2. View Results                                    |" << endl;
    cout << "| 3. Exit                                            |" << endl;
    printBoxSeparator();
    setColor(7);
}

bool validateInterval(int start, int end) {
    if (start >= end) {
        setColor(9);
        cout << "Error: End time must be greater than start time!" << endl;
        setColor(7);
        return false;
    }
    return true;
}

int main() {
    clearScreen();
    printWelcome();

    vector<Interval> intervals;
    Scheduler scheduler;
    int choice;

    while (true) {
        printMenu();

        setColor(9);
        cout << "Enter your choice: ";
        setColor(7);
        cin >> choice;

        switch (choice) {
            case 1: {
                setColor(14);
                int n;
                cout << "\nEnter the number of intervals: ";
                setColor(7);
                cin >> n;

                intervals.clear();
                for (int i = 0; i < n; i++) {
                    int start, end;
                    setColor(9);
                    cout << "Enter start time and end time for interval " << i + 1 << ": ";
                    setColor(7);
                    cin >> start >> end;

                    while (!validateInterval(start, end)) {
                        setColor(9);
                        cout << "Enter valid start time and end time for interval " << i + 1 << ": ";
                        cin >> start >> end;
                        setColor(7);
                    }

                    intervals.push_back(Interval(start, end));
                }
                break;
            }
            case 2: {
                if (intervals.empty()) {
                    setColor(12);
                    cout << "No intervals entered yet!" << endl;
                    setColor(7);
                    break;
                }

                int result = scheduler.intervalPartitioning(intervals);
                printBoxSeparator();
                setColor(13);
                cout << "| Minimum number of rooms needed: " << result << "\t\t     |" << endl;
                printBoxSeparator();
                setColor(7);
                break;
            }
            case 3:
                setColor(12);
                cout << "| Exiting the program...                             |" << endl;
                printBoxSeparator();
                setColor(10);
                cout << "Goodbye, see you soon next time!" << endl;
                setColor(7);
                return 0;
            default:
                cout << "| Invalid choice, please try again!                    |" << endl;
                printBoxSeparator();
        }

        setColor(10);
        cout << "| Press any key to continue...                       |" << endl;
        printBoxSeparator();
        setColor(7);

        cin.ignore();
        cin.get();
        clearScreen();
    }

    return 0;
}