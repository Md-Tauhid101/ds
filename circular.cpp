// Write a program to implement circular linked list as an ADT which supports the following operations:
// i. Insert an element x in the list
// ii. Remove an element from the list
// iii. Search for an element x in the list and return its pointer 

#include <iostream>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head->next;
        Node* temp;

        // Free memory for each node
        while (current != nullptr && current != head) {
            temp = current->next;
            delete current;
            current = temp;
        }

        delete head; // delete the head node
    }

    // Function to insert an element in the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head; // circular link to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to remove an element from the list
    void remove(int value) {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Traverse the list to find the node with the given value
        do {
            if (current->data == value) {
                if (prev == nullptr) {
                    // Removing the head node
                    if (head->next == head) {
                        // The list has only one node
                        delete head;
                        head = nullptr;
                    } else {
                        Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        delete head;
                        head = temp->next;
                    }
                } else {
                    // Removing a non-head node
                    prev->next = current->next;
                    delete current;
                }

                std::cout << "Element " << value << " removed from the list\n";
                return;
            }

            prev = current;
            current = current->next;
        } while (current != head);

        std::cout << "Element " << value << " not found in the list\n";
    }

    // Function to search for an element and return its pointer
    Node* search(int value) {
        if (head == nullptr) return nullptr;

        Node* current = head;

        // Traverse the circular list to find the node with the given value
        do {
            if (current->data == value) {
                return current;
            }

            current = current->next;
        } while (current != head);

        return nullptr; // Element not found
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* current = head;

        // Traverse the circular list and print each node's data
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);

    std::cout << "Original List: ";
    myList.display();

    myList.remove(2);
    std::cout << "List after removing 2: ";
    myList.display();

    int searchValue = 1;
    Node* searchResult = myList.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found at address " << searchResult << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the list\n";
    }

    return 0;
}
