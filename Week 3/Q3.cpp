#include <iostream>
#include <vector>

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node(T val, Node* n = NULL) : data(val), next(n) {}
};

template <typename T>
class LinkedList
{
private:
    size_t size;
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : size(0), head(nullptr), tail(nullptr) {}

    LinkedList(const T* arr, size_t len) : size(0), head(nullptr), tail(nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            append(arr[i]);
        }
    }

    ~LinkedList()
    {
        while (head)
        {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void append(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAtFront(T val)
    {
        head = new Node<T>(val, head);
        if (!tail)
            tail = head;
        size++;
    }

    bool insertAt(size_t pos, T val)
    {
        if (!head || pos >= size)
            return false;

        Node<T>* temp = head;
        for (size_t i = 0; i < pos - 1; ++i)
        {
            temp = temp->next;
        }
        temp->next = new Node<T>(val, temp->next);
        if (temp == tail)
            tail = temp->next;

        size++;
        return true;
    }

    bool deleteAt(size_t pos)
    {
        if (!head || pos >= size)
            return false;

        Node<T>* temp = head;
        if (pos == 0)
        {
            head = head->next;
            delete temp;
            if (!head)
                tail = nullptr;
            size--;
            return true;
        }

        Node<T>* prev = nullptr;
        for (size_t i = 0; i < pos; ++i)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail)
            tail = prev;
        delete temp;
        size--;
        return true;
    }

    T& operator[](const int index)
    {
        if (index >= 0 && index < size)
        {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }

    std::vector<size_t> find(T element)
    {
        std::vector<size_t> indices;
        Node<T>* temp = head;
        for (int i = 0; i < size; i++)
        {
            if (temp->data == element)
            {
                indices.push_back(i);
            }
            temp = temp->next;
        }

        return indices;
    }

    void reverse()
    {
        Node<T>* prev = nullptr, * current = head, * next = nullptr;

        std::swap(head, tail);
        for (int i = 0; i < size; i++)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }

    void printList() const
    {
        Node<T>* temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void sort()
    {
        head = mergeSort(head);

        // Update tail
        if (!head)
        {
            tail = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        tail = temp;
    }

    Node<T>* mergeSortedLists(Node<T>* left, Node<T>* right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        if (left->data < right->data)
        {
            left->next = mergeSortedLists(left->next, right);
            return left;
        }
        else
        {
            right->next = mergeSortedLists(left, right->next);
            return right;
        }
    }

    Node<T>* mergeSort(Node<T>* head)
    {
        if (!head || !head->next)
            return head;

        Node<T>* slow = head, * fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node<T>* mid = slow->next;
        slow->next = nullptr;

        Node<T>* left = mergeSort(head);
        Node<T>* right = mergeSort(mid);

        return mergeSortedLists(left, right);
    }
};


int main()
{
    // Test default constructor
    LinkedList<int> list;

    // Test append function
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
	list.append(50);
    list.append(30);
    std::cout << "List after append: ";
    list.printList();

    // Test insertAtFront
    list.insertAtFront(5);
    std::cout << "List after inserting at front: ";
    list.printList();

    // Test insertAt
    list.insertAt(2, 15);
    std::cout << "List after inserting 15 at position 2: ";
    list.printList();

    // Test deleteAt
    list.deleteAt(3);
    std::cout << "List after deleting element at position 3: ";
    list.printList();

    // Test operator[]
    try
    {
        std::cout << "Element at index 2: " << list[2] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test find function
    std::vector<size_t> indices = list.find(30);
    std::cout << "Indices of element 30: ";
    for (size_t index : indices)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Test reverse function
    list.reverse();
    std::cout << "List after reversing: ";
    list.printList();

    // Test sorting function
    list.sort();
    std::cout << "List after sorting: ";
    list.printList();

    return 0;
}