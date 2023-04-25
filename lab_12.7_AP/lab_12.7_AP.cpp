// lab_12.7_AP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Elem {
    Elem* next;
    string teamName;
    int points;
};

int main() {
    Elem* head = nullptr;
    int n;

    cout << "Enter 1 to input teams from a file or 2 to input teams from the console: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        string filename = "D://teams.txt";
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file" << endl;
            return -1;
        }
        file >> n;
        for (int i = 0; i < n; i++) {
            string name;
            int points;
            file >> name >> points;
            Elem* newElem = new Elem{ head, name, points };
            head = newElem;
        }
        file.close();
    }
    else if (choice == 2) {
        cout << "Enter the numbers of teams: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            string name;
            int points;
            cout << "Enter the name of teams: ";
            cin >> name;
            cout << "Enter the number of points ";
            cin >> points;
            Elem* newElem = new Elem{ head, name, points };
            head = newElem;
        }
    }

    cout << " First list of teams:" << endl;
    for (Elem* p = head; p != nullptr; p = p->next) {
        cout << p->teamName << " " << p->points << endl;
    }

    int stage = 0;
    while (n > 1) {
        stage++;
        cout << "Stages " << stage << ":" << endl;


        int half = n / 2;

        for (int i = 0; i < half; i++) {
            Elem* minElem = head;
            Elem* prevMinElem = nullptr;
            for (Elem* p = head, *prevP = nullptr; p != nullptr; prevP = p, p = p->next) {
                if (p->points < minElem->points) {
                    minElem = p;
                    prevMinElem = prevP;
                }
            }


            cout << "Deleted: " << minElem->teamName << " " << minElem->points << endl;
            if (prevMinElem == nullptr) {
                head = minElem->next;
            }
            else {
                prevMinElem->next = minElem->next;
            }
            delete minElem;

            n--;
        }


        cout << "Teams that stayed:" << endl;
        for (Elem* p = head; p != nullptr; p = p->next) {
            cout << p->teamName << " " << p->points << endl;
        }
    }
    cout << "Winner: " << head->teamName << " " << head->points << endl;
    cout << "The number of stages: " << stage << endl;

    return 0;
}
