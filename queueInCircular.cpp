// Implement Queue as an ADT using the circular Arrays

#include <iostream>

template <typename T>
class CircularQueue {
private:
    T* array;
    int front;
    int rear;
    int capacity;
    int size;

public:
    // Constructor
    CircularQueue(int capacity) : front(0), rear(0), capacity(capacity), size(0) {
        array = new T[capacity];
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] array;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() const {
        return size == capacity;
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(T value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        array[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        front = (front + 1) % capacity;
        size--;
    }

    // Function to get the front element of the queue
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek.\n";
            exit(EXIT_FAILURE);
        }
        return array[front];
    }

    // Function to display the queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        do {
            std::cout << array[i] << " ";
            i = (i + 1) % capacity;
        } while (i != rear);

        std::cout << std::endl;
    }
};

int main() {
    // Example usage of the CircularQueue class
    CircularQueue<int> myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Original Queue: ";
    myQueue.display();

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    myQueue.dequeue();
    std::cout << "Queue after dequeue: ";
    myQueue.display();

    return 0;
}
