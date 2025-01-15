#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    T *arr;
    int front, rear, size, capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        front = (front + 1) % capacity;
        size--;
    }

    T peek() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Queue<int> q(5);

        cout << "Enqueuing elements: 10, 20, 30, 40, 50" << endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.display();
        
        cout << "Attempting to enqueue 60 (should throw exception)" << endl;
        try {
            q.enqueue(60);
        } catch (const exception &e) {
            cerr << "Exception: " << e.what() << endl;
        }
        
        cout << "Dequeuing two elements." << endl;
        q.dequeue();
        q.dequeue();
        q.display();

        cout << "Front element: " << q.peek() << endl;
        
        cout << "Dequeuing all elements." << endl;
        q.dequeue();
        q.dequeue();
        q.dequeue();
        
        cout << "Attempting to dequeue from empty queue (should throw exception)" << endl;
        try {
            q.dequeue();
        } catch (const exception &e) {
            cerr << "Exception: " << e.what() << endl;
        }
    } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
