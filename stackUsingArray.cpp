// Implement a stack as an ADT using Arrays.

#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor
    Stack() : top(-1) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow: Cannot push element " << value << ", stack is full.\n";
            return;
        }

        arr[++top] = value;
        std::cout << "Pushed " << value << " onto the stack.\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow: Cannot pop from an empty stack.\n";
            return;
        }

        std::cout << "Popped " << arr[top--] << " from the stack.\n";
    }

    // Function to get the top element of the stack without popping
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return -1; // Assuming -1 as an invalid value in this example
        }

        return arr[top];
    }

    // Function to display the elements of the stack
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }

        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myStack.display();

    std::cout << "Top element: " << myStack.peek() << "\n";

    myStack.pop();
    myStack.display();

    return 0;
}
