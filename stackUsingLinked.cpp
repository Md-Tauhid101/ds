// Implement a stack as an ADT using the Linked List ADT. 

#include <iostream>

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Stack class using linked list
template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        Node<T>* current = top;
        Node<T>* nextNode;

        // Free memory for each node
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to push an element onto the stack
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return;
        }

        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Function to get the top element of the stack
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot peek.\n";
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    // Function to display the stack
    void display() const {
        Node<T>* current = top;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    // Example usage of the Stack class
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Original Stack: ";
    myStack.display();

    std::cout << "Top element: " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << "Stack after pop: ";
    myStack.display();

    return 0;
}
