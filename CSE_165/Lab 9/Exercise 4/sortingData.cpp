#include <iostream>
#include <string>
#include "Circle.h"
#include "Participant.h"
#include "Data.h"

using namespace std;

int main() {
    Data data;
    char input;
    float radius;
    string name;
    int age;
    double score;
	cout << "Enter your choice of action (C)reate circle, (T)add participant, (S)ort, (P)rint, or (Q)uit: \n";
    while (true) {
        cin >> input;
        switch (input) {
            case 'c':
            case 'C':
                cin >> radius;
                data.add(new Circle(radius));
                cout << "Circle added" << endl;
                break;
            case 't':
            case 'T':
                cin >> name >> age >> score;
                data.add(new Participant(name, age, score));
                cout << "Participant added" << endl;
                break;
            case 's':
            case 'S':
                data.sort();
                cout << "Data sorted" << endl;
                break;
            case 'p':
            case 'P':
                data.print();
                break;
            case 'q':
            case 'Q':
                return 0;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
    }
    return 0;
}
