// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept> // for out_of_range exception

using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode; // Points to the front of the queue
    Node* rearNode;  // Points to the rear of the queue
    int queueSize;   // Keeps track of the queue size

public:
    // Constructor
    Queue();

    // Destructor to free the allocated memory
    ~Queue();

    // Push a value into the queue
    void push(T value);

    // Pop the front element from the queue
    void pop();

    // Get the front element of the queue
    T front();

    // Get the size of the queue
    int size();

    // Check if the queue is empty
    bool empty();

    // Function to move the front element to the rear of the queue
    void move_to_rear();

    // Function to display all the elements in the queue
    void display();
};

#endif // QUEUE_H
