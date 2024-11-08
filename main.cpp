//Hiram Romero
//CS303 Assignment 3

#include <iostream>  // Include the standard input/output stream library for console I/O operations
#include "Queue.h"   // Include the custom header file for the Queue class
#include <vector>    // Include the vector library to use the std::vector container

using namespace std; // Use the standard namespace to avoid needing to prefix standard functions with "std::"

int main() {
    // Part (a) Instantiate the queue with integers and push 10 values into the queue
    Queue<int> q; // Create a Queue object q that will store integers (template instantiation for int)

    cout << "Pushing 10 values into the queue: " << endl; // Print a message indicating we're adding elements to the queue
    for (int i = 1; i <= 10; ++i) { // Loop from 1 to 10 (inclusive)
        q.push(i); // Push each value (from 1 to 10) into the queue one by one
    }

    // Part (b) Display all elements in the queue using the provided functions
    cout << "Queue elements after pushing 10 values: ";  // Print a message about displaying the queue elements
    q.display();  // Call the display method to print all elements in the queue
    cout << "Queue size: " << q.size() << endl; // Display the current size of the queue
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Check if the queue is empty and display the result
    cout << "Front element: " << q.front() << endl; // Display the front element of the queue

    // Part (c) Perform pop, push, move_to_rear and show the queue state after each
    cout << "\n--- After pop() ---" << endl;  // Print a message indicating a pop operation will occur
    q.pop(); // Call the pop method to remove the front element of the queue
    q.display(); // Display the queue after the pop operation
    cout << "Queue size: " << q.size() << endl; // Display the updated size of the queue
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Check if the queue is empty after popping an element
    cout << "Front element: " << q.front() << endl; // Display the new front element of the queue

    cout << "\n--- After pushing 11 ---" << endl; // Print a message indicating that we will push 11 to the queue
    q.push(11); // Push the value 11 into the queue
    q.display(); // Display the queue after pushing 11
    cout << "Queue size: " << q.size() << endl; // Display the updated size of the queue
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Check if the queue is empty after the push
    cout << "Front element: " << q.front() << endl; // Display the front element of the queue after pushing 11

    cout << "\n--- After move_to_rear() ---" << endl; // Print a message indicating that we will move the front element to the rear
    q.move_to_rear(); // Call the move_to_rear method to move the front element to the rear of the queue
    q.display(); // Display the updated queue after moving the front element to the rear
    cout << "Queue size: " << q.size() << endl; // Display the size of the queue after the operation
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Check if the queue is empty after the move_to_rear operation
    cout << "Front element: " << q.front() << endl; // Display the new front element after moving the front element to the rear

    // Additional functionality: Linear Search for last occurrence
    vector<int> items = {1, 2, 3, 4, 5, 2, 7, 8, 9, 2}; // Create a vector containing integers
    int target = 2; // Set the target value to search for (in this case, 2)
    cout << "\n--- Linear search (last occurrence) for target " << target << " ---" << endl; // Print a message
    int lastIndex = q.linear_search_last(items, target); // Call the linear_search_last method to find the last occurrence of target in the vector
    cout << "Last occurrence of " << target << " is at index: " << lastIndex << endl; // Display the index of the last occurrence of the target

    // Sorting the queue using insertion sort
    cout << "\n--- Before Insertion Sort ---" << endl;  // Print a message before sorting
    q.display(); // Display the queue elements before sorting
    q.insertion_sort(); // Call the insertion_sort method to sort the queue elements
    cout << "--- After Insertion Sort ---" << endl;  // Print a message after sorting
    q.display(); // Display the queue elements after sorting

    return 0; // End of the program, return 0 to indicate successful execution
}

