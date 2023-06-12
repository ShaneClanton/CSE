#ifndef DATA_H
#define DATA_H

#include <vector>
#include <iostream>
#include <algorithm>

class Data {
private:
    std::vector<int> m_data;

public:
    void add(int number) {
        m_data.push_back(number);
    }

    void sort() {
        std::sort(m_data.begin(), m_data.end());
    }

    void print() {
        for (int i = 0; i < m_data.size(); i++) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif