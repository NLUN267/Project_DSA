#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& val)
            : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    // Constructor
    LinkedList() {
        head = tail = nullptr;
        count = 0;
    }

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Insert at front
    void insertFront(const T& value) {
        Node* node = new Node(value);

        if (!head) {
            head = tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        count++;
    }

    // Insert at back
    void insertBack(const T& value) {
        Node* node = new Node(value);

        if (!tail) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        count++;
    }

    // Insert at index
    void insertAt(int index, const T& value) {
        if (index < 0 || index > count)
            throw out_of_range("Invalid index");

        if (index == 0) {
            insertFront(value);
            return;
        }

        if (index == count) {
            insertBack(value);
            return;
        }

        Node* cur = head;

        for (int i = 0; i < index; i++)
            cur = cur->next;

        Node* node = new Node(value);

        node->next = cur;
        node->prev = cur->prev;

        cur->prev->next = node;
        cur->prev = node;

        count++;
    }

    // Remove first occurrence of value
    bool remove(const T& value) {
        Node* cur = head;

        while (cur) {
            if (cur->data == value) {
                if (cur == head)
                    head = head->next;

                if (cur == tail)
                    tail = tail->prev;

                if (cur->prev)
                    cur->prev->next = cur->next;

                if (cur->next)
                    cur->next->prev = cur->prev;

                delete cur;
                count--;
                return true;
            }

            cur = cur->next;
        }

        return false;
    }

    // Remove at index
    void removeAt(int index) {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index");

        Node* cur = head;

        for (int i = 0; i < index; i++)
            cur = cur->next;

        if (cur == head)
            head = head->next;

        if (cur == tail)
            tail = tail->prev;

        if (cur->prev)
            cur->prev->next = cur->next;

        if (cur->next)
            cur->next->prev = cur->prev;

        delete cur;
        count--;
    }

    // Find index of value
    int find(const T& value) const {
        Node* cur = head;
        int idx = 0;

        while (cur) {
            if (cur->data == value)
                return idx;

            cur = cur->next;
            idx++;
        }

        return -1;
    }

    // Return size
    int size() const {
        return count;
    }

    // Clear list
    void clear() {
        Node* cur = head;

        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }

        head = tail = nullptr;
        count = 0;
    }

    // Print from head
    void printForward() const {
        Node* cur = head;

        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }

        cout << endl;
    }

    // Print from tail
    void printBackward() const {
        Node* cur = tail;

        while (cur) {
            cout << cur->data << " ";
            cur = cur->prev;
        }

        cout << endl;
    }
};

#endif
