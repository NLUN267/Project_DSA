#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

    void resize() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];

        for (int i = 0; i < count; i++)
            newData[i] = data[(frontIndex + i) % capacity];

        delete[] data;

        data = newData;
        capacity = newCap;
        frontIndex = 0;
        rearIndex = count;
    }

public:
    Queue(int cap = 10) {
        capacity = cap;
        data = new T[capacity];

        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    ~Queue() {
        delete[] data;
    }

    // Add element
    void enqueue(const T& item) {
        if (count == capacity)
            resize();

        data[rearIndex] = item;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
    }

    // Remove front element
    T dequeue() {
        if (empty())
            throw underflow_error("Queue empty");

        T val = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return val;
    }

    // Get front element
    T front() const {
        if (empty())
            throw underflow_error("Queue empty");

        return data[frontIndex];
    }

    // Check empty
    bool empty() const {
        return count == 0;
    }

    // Return size
    int size() const {
        return count;
    }
};

#endif
