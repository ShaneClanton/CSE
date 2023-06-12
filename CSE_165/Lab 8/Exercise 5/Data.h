#ifndef DATA_H
#define DATA_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Sortable.h"

class Data {
private:
std::vector<Sortable*> m_data; // changed int to Sortable*

public:
void add(Sortable* item) { // changed int to Sortable*
m_data.push_back(item);
}

void sort() {
    for (int i = 1; i < m_data.size(); i++){
        Sortable* key = m_data[i];
        int j = i;
        while (j > 0 && m_data[j - 1] -> compare(key) > 0){
            m_data[j] = m_data[j - 1];
            j--;
        }
        m_data[j] = key;
    }
}

void print() {
    for (int i = 0; i < m_data.size(); i++) {
        m_data[i]->print(); // using Sortable's print() method
    }
    std::cout << std::endl;
}

};
#endif