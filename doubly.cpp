// Write a program to implement doubly linked list as an ADT that supports the following operations:
// i. Insert an element x at the beginning of the doubly linked list
// ii. Insert an element x at the end of the doubly linked list
// iii. Remove an element from the beginning of the doubly linked list
// iv. Remove an element from the end of the doubly linked list

#include <iostream>

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
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

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert an element at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to remove an element from the beginning of the list
    void removeFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            // List is now empty
            tail = nullptr;
        }

        delete temp;
    }

    // Function to remove an element from the end of the list
    void removeFromEnd() {
        if (tail == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            // List is now empty
            head = nullptr;
        }

        delete temp;
    }

    // Function to display the doubly linked list
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
    DoublyLinkedList myList;

    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    std::cout << "Original List: ";
    myList.display();

    myList.insertAtEnd(4);
    std::cout << "List after inserting 4 at the end: ";
    myList.display();

    myList.removeFromBeginning();
    std::cout << "List after removing from the beginning: ";
    myList.display();

    myList.removeFromEnd();
    std::cout << "List after removing from the end: ";
    myList.display();

    return 0;
}
