// Write a program to implement Binary Search Tree as an ADT which supports the following operations:
// i. Insert an element x
// ii. Delete an element x
// iii. Search for an element x in the BST
// iv. Display the elements of the BST in preorder, inorder, and postorder traversal

#include <iostream>

// Node structure for the Binary Search Tree
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class
template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;

    // Private helper functions for the operations
    TreeNode<T>* insertRecursive(TreeNode<T>* node, T value);
    TreeNode<T>* deleteRecursive(TreeNode<T>* node, T value);
    TreeNode<T>* findMin(TreeNode<T>* node);
    TreeNode<T>* searchRecursive(TreeNode<T>* node, T value);
    void displayPreorder(TreeNode<T>* node) const;
    void displayInorder(TreeNode<T>* node) const;
    void displayPostorder(TreeNode<T>* node) const;

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor to free memory
    ~BinarySearchTree() {
        // Call a helper function to delete nodes recursively
        deleteTree(root);
    }

    // Function to insert an element into the BST
    void insert(T value) {
        root = insertRecursive(root, value);
    }

    // Function to delete an element from the BST
    void remove(T value) {
        root = deleteRecursive(root, value);
    }

    // Function to search for an element in the BST
    TreeNode<T>* search(T value) {
        return searchRecursive(root, value);
    }

    // Function to display the elements of the BST in preorder traversal
    void displayPreorder() const {
        displayPreorder(root);
        std::cout << std::endl;
    }

    // Function to display the elements of the BST in inorder traversal
    void displayInorder() const {
        displayInorder(root);
        std::cout << std::endl;
    }

    // Function to display the elements of the BST in postorder traversal
    void displayPostorder() const {
        displayPostorder(root);
        std::cout << std::endl;
    }

private:
    // Private helper function to delete nodes recursively
    void deleteTree(TreeNode<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

// Helper function to insert a value recursively
template <typename T>
TreeNode<T>* BinarySearchTree<T>::insertRecursive(TreeNode<T>* node, T value) {
    if (node == nullptr) {
        return new TreeNode<T>(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

// Helper function to delete a value recursively
template <typename T>
TreeNode<T>* BinarySearchTree<T>::deleteRecursive(TreeNode<T>* node, T value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = deleteRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = deleteRecursive(node->right, value);
    } else {
        if (node->left == nullptr) {
            TreeNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode<T>* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteRecursive(node->right, temp->data);
    }

    return node;
}

// Helper function to find the minimum value node in a subtree
template <typename T>
TreeNode<T>* BinarySearchTree<T>::findMin(TreeNode<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Helper function to search for a value recursively
template <typename T>
TreeNode<T>* BinarySearchTree<T>::searchRecursive(TreeNode<T>* node, T value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

// Helper function to display the elements in preorder traversal
template <typename T>
void BinarySearchTree<T>::displayPreorder(TreeNode<T>* node) const {
    if (node != nullptr) {
        std::cout << node->data << " ";
        displayPreorder(node->left);
        displayPreorder(node->right);
    }
}

// Helper function to display the elements in inorder traversal
template <typename T>
void BinarySearchTree<T>::displayInorder(TreeNode<T>* node) const {
    if (node != nullptr) {
        displayInorder(node->left);
        std::cout << node->data << " ";
        displayInorder(node->right);
    }
}

// Helper function to display the elements in postorder traversal
template <typename T>
void BinarySearchTree<T>::displayPostorder(TreeNode<T>* node) const {
    if (node != nullptr) {
        displayPostorder(node->left);
        displayPostorder(node->right);
        std::cout << node->data << " ";
    }
}

int main() {
    // Example usage of the BinarySearchTree class
    BinarySearchTree<int> myBST;

    myBST.insert(50);
    myBST.insert(30);
    myBST.insert(70);
    myBST.insert(20);
    myBST.insert(40);
    myBST.insert(60);
    myBST.insert(80);

    std::cout << "Inorder Traversal: ";
    myBST.displayInorder();

    std::cout << "Preorder Traversal: ";
    myBST.displayPreorder();

    std::cout << "Postorder Traversal: ";
    myBST.displayPostorder();

    int searchValue = 40;
    TreeNode<int>* searchResult = myBST.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found in the BST\n";
    } else {
        std::cout << "Element " << searchValue << " not found in the BST\n";
    }

    myBST.remove(30);
    std::cout << "BST after deleting 30:\n";
    std::cout << "Inorder Traversal: ";
    myBST.displayInorder();

    return 0;
}
    