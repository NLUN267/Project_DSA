#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <functional>
#include <utility>
#include "AVL.hpp"
using namespace std;

template <typename K, typename V>
class HashTable {
private:
    struct Pair {
        K key;
        V value;

        Pair() {}

        Pair(K k, V v) {
            key = k;
            value = v;
        }

        bool operator<(const Pair& other) const {
            return key < other.key;
        }

        bool operator>(const Pair& other) const {
            return key > other.key;
        }

        bool operator==(const Pair& other) const {
            return key == other.key;
        }
    };

    static const int SIZE = 101;

    AVL<Pair>* table;
    int count;

    int hashFunc(const K& key) const {
        return hash<K>()(key) % SIZE;
    }

public:
    HashTable() {
        table = new AVL<Pair>[SIZE];
        count = 0;
    }

    ~HashTable() {
        delete[] table;
    }

    // Insert key-value
    void insert(const K& key, const V& value) {
        int idx = hashFunc(key);
        table[idx].insert(Pair(key, value));
        count++;
    }

    // Remove key
    void remove(const K& key) {
        int idx = hashFunc(key);
        table[idx].remove(Pair(key, V()));
        count--;
    }

    // Find key existence
    bool contains(const K& key) {
        int idx = hashFunc(key);
        return table[idx].search(Pair(key, V()));
    }

    // Alias of contains
    bool find(const K& key) {
        return contains(key);
    }

    // Return size
    int size() const {
        return count;
    }

    // Clear table
    void clear() {
        delete[] table;
        table = new AVL<Pair>[SIZE];
        count = 0;
    }
};

#endif
