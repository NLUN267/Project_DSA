#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int topIndex;
    int capacity;

    void resize() {
        capacity *= 2;

        T* newData = new T[capacity];

        for (int i = 0; i <= topIndex; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
    }

public:
    Stack(int cap = 10) {
        capacity = cap;
        data = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    // Push element
    void push(const T& item) {
        if (topIndex + 1 == capacity)
            resize();

        data[++topIndex] = item;
    }

    // Pop element
    T pop() {
        if (empty())
            throw underflow_error("Stack empty");

        return data[topIndex--];
    }

    // Get top element
    T top() const {
        if (empty())
            throw underflow_error("Stack empty");

        return data[topIndex];
    }

    // Check empty
    bool empty() const {
        return topIndex == -1;
    }

    // Return size
    int size() const {
        return topIndex + 1;
    }
};

#endif
