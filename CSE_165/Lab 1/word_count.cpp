#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    int wordCount = 0;
    ifstream file("words.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            wordCount += count(line.begin(), line.end(), ' ') + 1;
        }
        file.close();
    }

    cout << "Number of words: " << wordCount << endl;

    return 0;
}