#include <iostream>
#include <list>

using namespace std;

// In this lab we will be implementing Hash Table with Chaining.

int m;
std::list<int> *hashTable; // saves address of array thats created in hashTable.

int hashFunct (int k){
    return k % m; // used k mod m like how the lab said to do so.
}

void cHashInsert(int key){
    // Just inserts a new element in this case key into the front of the list.
    hashTable[hashFunct(key)].push_front(key);
}

void cHashDelete(int key){
    int c = 0;
    // std::list<int>::iterator is so every element at a single time.
    std::list<int>::iterator i;
    // i in the for loop will equal each element within the list;
    for(i = hashTable[hashFunct(key)].begin(); i != hashTable[hashFunct(key)].end(); i++){
        if (*i == key){
            i = hashTable[hashFunct(key)].erase(i);
            cout << key << ":DELETED;\n";
            return;
        }
        c++;
    }
    cout << key << ":DELETE_FAILED;\n";
}

void cHashSearch(int key){ // cHashSearch is very much similar to cHashDelete but with slight differences.
    int j = 0;
    std::list<int>::iterator i;
    for(i = hashTable[hashFunct(key)].begin(); i != hashTable[hashFunct(key)].end(); i++){
        if (*i == key){
            cout << key << ":FOUND_AT" << hashFunct(key) << "," << j << ";\n";
            return;
        }
        j++;
    }
    cout << key << ":NOT_FOUND;\n";
}


int main(){ 
    // Here we just get the inputs and then print the results
    //
    cin >> m;
    hashTable = new std::list<int>[m]; // Creates an array of list<int>[m] and stores them in hashTable
    char function; // Chose function as the name since i, d and s each call one of the functions above.
    
    while (function != 'e'){
        int key;
        cin >> function;
        
        switch (function){
            case 'i':
            cin >> key;
            cHashInsert(key);
            break;

            case 'd':
            cin >> key;
            cHashDelete(key);
            break;

            case 's':
            cin >> key;
            cHashSearch(key);
            break;

            case 'o':
            for(int i = 0; i < m; i++){
                cout << i << ":";
                for (auto x : hashTable[i]){
                    cout << x << "->";
                }
                cout << ";" << endl;
            }
            break;
        }
    }
}