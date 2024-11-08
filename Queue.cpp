// Hiram Romero
// CS303 Assignment 3

#include "Queue.h"  // Includes header file

// Constructor for Initializing the queue
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

// Destructor:
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {  // While the queue is not empty
        pop();  // Pop the front element
    }
}

// push(): Function that adds a new element to the back of the queuee
template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node(value);  // where we create a new node with the given value
    if (rearNode == nullptr) {  // If the queue is empty (no rear node)
        frontNode = rearNode = newNode;  // The front and rear nodes both point to the new node
    } else {
        rearNode->next = newNode;  // Link the current rear node to the new node
        rearNode = newNode;  // Update the rear node to be the new node
    }
    queueSize++;  // Increment the size of the queue
}

// pop(): The Function that Removes the front element from the queue
template <typename T>
void Queue<T>::pop() {
    if (empty()) {  // If the queue is empty
        cout << "Queue is empty, cannot pop." << endl;  // Prints the error message
        return;
    }
    Node* temp = frontNode;  // Temporarily stores the current front node
    frontNode = frontNode->next;  // Updates the front node to the next node
    delete temp;  // Deletes the old front node
    if (frontNode == nullptr) {  // If the queue is now empty (no front node)
        rearNode = nullptr;  // Set the rear node to nullptr as well
    }
    queueSize--;  // Decrement the size of the queue
}

// front(): function that returns the front element of the queue
template <typename T>
T Queue<T>::front() {
    if (!empty()) {  // If the queue is not empty
        return frontNode->data;  // Return the data of the front node
    }
    throw out_of_range("Queue is empty");  // Throw an exception if the queue is empty
}

// size(): function that returns the current number of elements in the queue
template <typename T>
int Queue<T>::size() {
    return queueSize;  // Return the queue size
}

// empty(): function that checks if the queue is empty
template <typename T>
bool Queue<T>::empty() {
    return frontNode == nullptr;  // If the front node is nullptr, the queue is empty
}

// move_to_rear(): fucntion that moves the front element to the rear of the queue
template <typename T>
void Queue<T>::move_to_rear() {
    if (empty() || frontNode == rearNode) {  // if the queue is empty or has only one element
        return;
    }

    T frontValue = front();  // Get the value of the front element
    pop();  // Pop the front element from the queue
    push(frontValue);  // Push it to the rear of the queue
}

// display(): function that prints all the elements in the queue
template <typename T>
void Queue<T>::display() {
    if (empty()) {  // If the queue is empty
        cout << "Queue is empty" << endl;  // Print a message indicating the queue is empty
        return;
    }

    Node* current = frontNode;  // Start from the front of the queue
    while (current != nullptr) {  // go through the entire queue
        cout << current->data << " ";  // Print the data of each node
        current = current->next;  // Move to the next node in the queue
    }
    cout << endl;
}

// The Recursive Linear Search portion of the code that finds the last occurrence of a target
template <typename T>
int Queue<T>::linear_search_last(const vector<T>& items, const T& target, size_t pos_first) {
    // Base case: if we reached the end of the vector, return -1  which means its not found
    if (pos_first == items.size()) {
        return -1;
    }

    // Recurse to the next element
    int result = linear_search_last(items, target, pos_first + 1);

    // If result is still -1 and we found a match, return this position
    if (result == -1 && items[pos_first] == target) {
        return pos_first;
    }

    return result;  // If no match was found, it returns the previous result
}

// Insertion Sort  portion for the queue - Used a linked list for this
template <typename T>
void Queue<T>::insertion_sort() {
    if (empty()) return;  // If the queue is empty, no need to sort

    // Creates a vector to hold the queue elements
    vector<T> elements;
    while (!empty()) {  // While the queue is not empty
        elements.push_back(front());  // Push the front element to the vector
        pop();  // Pop the front element from the queue
    }

    // Performs insertion sort on the vector
    int n = elements.size();  // Get the size of the vector
    for (int j = 1; j < n; ++j) {  // Start from the second element
        T key = elements[j];  // Store the current element (key)
        int i = j - 1;  // Compare with the previous elements
        while (i >= 0 && elements[i] > key) {  // While elements are greater than the key
            elements[i + 1] = elements[i];  // Shift the elements to the right
            --i;  // Move the index to the left
        }
        elements[i + 1] = key;  // Place the key in the correct position
    }

    // Push the sorted elements back into the queue
    for (T element : elements) {  // For each element in the sorted vector
        push(element);  // Push the element back to the queue
    }
}


template class Queue<int>;