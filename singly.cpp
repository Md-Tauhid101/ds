// Write a program to implement singly linked list as an ADT that supports the following oper-ations:
// i. Insert an element x at the beginning of the singly linked list
// ii. Insert an element x at ith position in the singly linked list
// iii. Remove an element from the beginning of the doubly linked list
// iv. Remove an element from ith position in the singly linked list.
// vi. Search for an element x in the singly linked list and return its pointer

#include <iostream>

// Node structure for the singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;

        // Free memory for each node
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to insert an element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert an element at the ith position in the list
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            std::cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Invalid position\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to remove an element from the beginning of the list
    void removeFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to remove an element from the ith position in the list
    void removeFromPosition(int position) {
        if (position < 0 || head == nullptr) {
            std::cout << "Invalid position or list is empty\n";
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 0; i < position && current != nullptr; ++i) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Invalid position\n";
            return;
        }

        previous->next = current->next;
        delete current;
    }

    // Function to search for an element and return its pointer
    Node* search(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }

        return nullptr; // Element not found
    }

    // Function to display the linked list
    void display() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList myList;

    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    std::cout << "Original List: ";
    myList.display();

    myList.insertAtPosition(4, 2);
    std::cout << "List after inserting 4 at position 2: ";
    myList.display();

    myList.removeFromBeginning();
    std::cout << "List after removing from the beginning: ";
    myList.display();

    myList.removeFromPosition(1);
    std::cout << "List after removing from position 1: ";
    myList.display();

    int searchValue = 4;
    Node* searchResult = myList.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found at position " << searchResult << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the list\n";
    }

    return 0;
}
