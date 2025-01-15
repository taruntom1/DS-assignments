#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
private:
    int top;
    int capacity;
    T *arr;

public:
    // Constructor
    Stack(int size)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // Push operation
    void push(T value)
    {
        if (top == capacity - 1)
        {
            throw overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    // Pop operation
    T pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack Underflow");
        }
        return arr[top--];
    }

    // Peek operation
    T peek()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is Empty");
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }
};

// Main function for testing
int main()
{
    cout << "Testing Stack implementation" << endl;
    Stack<int> stack(3);

    // Test pushing elements
    cout << "Pushing elements: 10, 20, 30" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Test overflow condition
    cout << "Attempting to push 40 (should cause overflow)" << endl;
    try
    {
        stack.push(40);
    }
    catch (const exception &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    // Test peek operation
    cout << "Top element (should be 30): " << stack.peek() << endl;

    // Test popping elements
    cout << "Popping elements: " << stack.pop() << " " << stack.pop() << endl;
    cout << "Top element after popping (should be 10): " << stack.peek() << endl;

    // Test popping until empty
    cout << "Popping last element: " << stack.pop() << endl;
    cout << "Attempting to pop from empty stack (should cause underflow)" << endl;
    try
    {
        stack.pop();
    }
    catch (const exception &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}