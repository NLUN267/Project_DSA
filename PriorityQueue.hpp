#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <stdexcept>
#include <functional>
using namespace std;

template <typename T, typename Comp = less<T>>
class PriorityQueue {
private:
    T* heap;
    int count;
    int capacity;
    Comp cmp;

    void resize() {
        capacity *= 2;

        T* newHeap = new T[capacity];

        for (int i = 0; i < count; i++)
            newHeap[i] = heap[i];

        delete[] heap;
        heap = newHeap;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (!cmp(heap[parent], heap[index]))
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int best = index;

            if (left < count && cmp(heap[best], heap[left]))
                best = left;

            if (right < count && cmp(heap[best], heap[right]))
                best = right;

            if (best == index)
                break;

            swap(heap[index], heap[best]);
            index = best;
        }
    }

public:
    PriorityQueue(int cap = 10) {
        capacity = cap;
        count = 0;
        heap = new T[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    // Insert element
    void insert(const T& value) {
        if (count == capacity)
            resize();

        heap[count] = value;
        heapifyUp(count);
        count++;
    }

    // Extract highest priority
    T extract() {
        if (empty())
            throw underflow_error("PriorityQueue empty");

        T root = heap[0];
        heap[0] = heap[count - 1];
        count--;

        heapifyDown(0);

        return root;
    }

    // Peek top element
    T peek() const {
        if (empty())
            throw underflow_error("PriorityQueue empty");

        return heap[0];
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
