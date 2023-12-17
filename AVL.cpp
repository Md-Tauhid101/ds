// Write a program to implement insert and search operation in AVL trees.

#include <iostream>
#include <algorithm>

// Node structure for the AVL Tree
template <typename T>
struct AVLNode {
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// AVLTree class
template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    // Private helper functions for AVL operations
    int getHeight(AVLNode<T>* node);
    int getBalance(AVLNode<T>* node);
    AVLNode<T>* rotateRight(AVLNode<T>* y);
    AVLNode<T>* rotateLeft(AVLNode<T>* x);
    AVLNode<T>* insertRecursive(AVLNode<T>* node, T value);
    AVLNode<T>* searchRecursive(AVLNode<T>* node, T value);

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Destructor to free memory
    ~AVLTree() {
        // Call a helper function to delete nodes recursively
        deleteTree(root);
    }

    // Function to insert an element into the AVL Tree
    void insert(T value) {
        root = insertRecursive(root, value);
    }

    // Function to search for an element in the AVL Tree
    AVLNode<T>* search(T value) {
        return searchRecursive(root, value);
    }

private:
    // Private helper function to delete nodes recursively
    void deleteTree(AVLNode<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

// Helper function to get the height of a node
template <typename T>
int AVLTree<T>::getHeight(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Helper function to get the balance factor of a node
template <typename T>
int AVLTree<T>::getBalance(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Helper function to perform a right rotation
template <typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* temp = x->right;

    x->right = y;
    y->left = temp;

    // Update heights
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

// Helper function to perform a left rotation
template <typename T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* temp = y->left;

    y->left = x;
    x->right = temp;

    // Update heights
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Helper function to insert a value recursively
template <typename T>
AVLNode<T>* AVLTree<T>::insertRecursive(AVLNode<T>* node, T value) {
    // Standard BST insertion
    if (node == nullptr) {
        return new AVLNode<T>(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    } else {
        // Duplicate values are not allowed
        return node;
    }

    // Update height of current node
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Left Heavy
    if (balance > 1) {
        // Left-Left Case
        if (value < node->left->data) {
            return rotateRight(node);
        }
        // Left-Right Case
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // Right Heavy
    else if (balance < -1) {
        // Right-Right Case
        if (value > node->right->data) {
            return rotateLeft(node);
        }
        // Right-Left Case
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

// Helper function to search for a value recursively
template <typename T>
AVLNode<T>* AVLTree<T>::searchRecursive(AVLNode<T>* node, T value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

int main() {
    // Example usage of the AVLTree class
    AVLTree<int> myAVL;

    myAVL.insert(50);
    myAVL.insert(30);
    myAVL.insert(70);
    myAVL.insert(20);
    myAVL.insert(40);
    myAVL.insert(60);
    myAVL.insert(80);

    int searchValue = 40;
    AVLNode<int>* searchResult = myAVL.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found in the AVL Tree\n";
    } else {
        std::cout << "Element " << searchValue << " not found in the AVL Tree\n";
    }

    return 0;
}
