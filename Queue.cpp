// Queue.cpp
#include "Queue.h"

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node(value);
    if (rearNode == nullptr) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    queueSize++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty, cannot pop." << endl;
        return;
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    queueSize--;
}

template <typename T>
T Queue<T>::front() {
    if (!empty()) {
        return frontNode->data;
    }
    throw out_of_range("Queue is empty");
}

template <typename T>
int Queue<T>::size() {
    return queueSize;
}

template <typename T>
bool Queue<T>::empty() {
    return frontNode == nullptr;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (empty() || frontNode == rearNode) {
        return;
    }

    T frontValue = front(); // Get the front value
    pop(); // Pop the front element
    push(frontValue); // Push it to the rear
}

template <typename T>
void Queue<T>::display() {
    if (empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* current = frontNode;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Explicit template instantiation for common types
template class Queue<int>;  // Add other types if needed (e.g., double, string)
