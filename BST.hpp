#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST {
protected:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& val)
            : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const T& value) {
        if (!node)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    bool search(Node* node, const T& value) const {
        if (!node)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    Node* minNode(Node* node) {
        while (node && node->left)
            node = node->left;

        return node;
    }

    Node* remove(Node* node, const T& value) {
        if (!node)
            return nullptr;

        if (value < node->data)
            node->left = remove(node->left, value);

        else if (value > node->data)
            node->right = remove(node->right, value);

        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    void inorder(Node* node) const {
        if (!node)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) const {
        if (!node)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) const {
        if (!node)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void clear(Node* node) {
        if (!node)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        clear(root);
    }

    // Insert value
    void insert(const T& value) {
        root = insert(root, value);
    }

    // Remove value
    void remove(const T& value) {
        root = remove(root, value);
    }

    // Search value
    bool search(const T& value) const {
        return search(root, value);
    }

    // Print inorder
    void inorder() const {
        inorder(root);
        cout << endl;
    }

    // Print preorder
    void preorder() const {
        preorder(root);
        cout << endl;
    }

    // Print postorder
    void postorder() const {
        postorder(root);
        cout << endl;
    }
};

#endif
