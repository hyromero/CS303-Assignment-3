// Hiram Romero
// CS303 Assignment 3

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>  // For standard input/output
#include <stdexcept> // For out_of_range exception when accessing elements from the queue
#include <vector>    // For using vectors, which are required for some of the operations
using namespace std;

// Template class for the Queue data structure
template <typename T>
class Queue {
private:
    // Definition of the Node structure that holds the data and the pointer to the next node
    struct Node {
        T data;        // Data held by the node (of type T, which can be any data type)
        Node* next;    // Pointer to the next node in the queue
        Node(T value)  // Constructor to initialize a node with a given value
                : data(value), next(nullptr) {}
    };

    Node* frontNode;  // Points to the front of the queue
    Node* rearNode;   // Points to the rear of the queue
    int queueSize;    // Keeps track of the queue size

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

    // Function to perform a recursive linear search for the last occurrence of a target
    int linear_search_last(const vector<T>& items, const T& target, size_t pos_first = 0);

    // Function to perform insertion sort on the queue
    void insertion_sort();
};

#endif // QUEUE_H
