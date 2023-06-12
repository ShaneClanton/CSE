#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string word;
    cout << "Enter a word to search for: ";
    cin >> word;

    ifstream file("words.txt");
    string line;
    int count = 0;

    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
    }

    cout << "The word '" << word << "' appears " << count << " times in the file." << endl;
    return 0;
}