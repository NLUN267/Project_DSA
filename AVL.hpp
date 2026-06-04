#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
using namespace std;

template <typename T>
class AVL {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;

        Node(const T& val) {
            data = val;
            left = right = nullptr;
            height = 1;
        }
    };

    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void update(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        update(y);
        update(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        update(x);
        update(y);

        return y;
    }

    Node* insert(Node* node, const T& key) {
        if (!node)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);

        else if (key > node->data)
            node->right = insert(node->right, key);

        else
            return node;

        update(node);

        int bf = balance(node);

        if (bf > 1 && key < node->left->data)
            return rotateRight(node);

        if (bf < -1 && key > node->right->data)
            return rotateLeft(node);

        if (bf > 1 && key > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && key < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValue(Node* node) {
        while (node->left)
            node = node->left;

        return node;
    }

    Node* remove(Node* node, const T& key) {
        if (!node)
            return node;

        if (key < node->data)
            node->left = remove(node->left, key);

        else if (key > node->data)
            node->right = remove(node->right, key);

        else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;

                if (!temp) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }

                delete temp;
            }
            else {
                Node* temp = minValue(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (!node)
            return node;

        update(node);

        int bf = balance(node);

        if (bf > 1 && balance(node->left) >= 0)
            return rotateRight(node);

        if (bf > 1 && balance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && balance(node->right) <= 0)
            return rotateLeft(node);

        if (bf < -1 && balance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool search(Node* node, const T& key) const {
        if (!node)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);

        return search(node->right, key);
    }

    void clear(Node* node) {
        if (!node)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    AVL() {
        root = nullptr;
    }

    ~AVL() {
        clear(root);
    }

    // Insert value
    void insert(const T& key) {
        root = insert(root, key);
    }

    // Remove value
    void remove(const T& key) {
        root = remove(root, key);
    }

    // Search value
    bool search(const T& key) const {
        return search(root, key);
    }
};

#endif
