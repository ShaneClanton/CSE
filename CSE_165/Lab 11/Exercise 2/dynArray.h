#ifndef dynArray_h
#define dynArray_h

#include <iostream>
#include <stdexcept>

template<class T>
class DynArray
{
private:
    T* arr;
    int size;
    int capacity;

public:
    DynArray()
    {
        size = 0;
        capacity = 4;
        arr = new T[capacity];
    }

    ~DynArray()
    {
        delete[] arr;
    }

    int getSize() const
    {
        return size;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    void add(const T& element)
    {
        if (size == capacity)
        {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            capacity *= 2;
            delete[] arr;
            arr = temp;
        }
        arr[size] = element;
        size++;
    }
    
    T* begin() const {
        return arr;
    }
    
    T* end() const {
        return arr + size;
    }
};

template<class C, class T>
class Iterator {
private:
    T* current;
    int index;

public:
    Iterator(C& container) : current(container.begin()), index(0) {}

    void begin(C& container) {
        current = container.begin();
        index = 0;
    }

    bool at_end(C& container) {
        return current == container.end();
    }

    void advance() {
        current++;
        index++;
    }

    void print() {
        std::cout << index << ": " << *current << std::endl;
    }
};

#endif /* dynArray_h */


