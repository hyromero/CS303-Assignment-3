//Hiram Romero
//CS303 Assignment 3

#include <iostream>  // For input/output stream
#include "Queue.h"   // include header file
#include <vector>    // Include the vector library

using namespace std; // For convenience

int main() {
    // This is where we initiate the queue and push 10 values to the queue
    Queue<int> q; // Create a Queue object q that stores integers

    cout << "Pushing 10 values into the queue: " << endl;
    for (int i = 1; i <= 10; ++i) { // Loop from 1 to 10
        q.push(i); // Push each value into the queue
    }

    // This is where we display all elements in the queue using the functions needed
    cout << "Queue elements after pushing 10 values: ";  // cout the values
    q.display();  // Displays all elements in queue
    cout << "Queue size: " << q.size() << endl; // Displays the size of the queue
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Checks if queue is emtpy or not
    cout << "Front element: " << q.front() << endl; // prints the front of the queue

    // Where we perform pop, push, move_to_rear and show the queue after each function
    cout << "\nAfter pop():" << endl;
    q.pop(); // Pops first element
    q.display(); //Print after Pop()
    cout << "Queue size: " << q.size() << endl; // Displays the size of the queue
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Checks if empty afyter popping
    cout << "Front element: " << q.front() << endl; // Displays the front

    cout << "\nAfter pushing 11:" << endl; // Uses 11 as an example of pushing to the queue
    q.push(11); // pushes 11 to queue
    q.display(); // prints updated queue
    cout << "Queue size: " << q.size() << endl; // prints updated size
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // checks if queues empty
    cout << "Front element: " << q.front() << endl; // Prints after pushing 11

    cout << "\nAfter move_to_rear():" << endl; // the function that moves front elemtn to rear
    q.move_to_rear(); //calls the function
    q.display(); // displays it
    cout << "Queue size: " << q.size() << endl; // Display the size of the queue after the operation
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Check if the queue is empty after function
    cout << "Front element: " << q.front() << endl; // Display the new front element after moving the front element to the rear

    // Linear Search for last occurrence portion of the code
    vector<int> items = {1, 2, 3, 4, 5, 2, 7, 8, 9, 2}; // Create a vector containing integers as an example
    int target = 2; // Set the target value to search for (in this case, 2), just as an example

    // Prints the vector
    cout << "\nVector contents: ";
    for (int item : items) { // Loops through the vector to print all elements
        cout << item << " "; //prints
    }
    cout << endl;

    cout << "\nLinear search (last occurrence) for target " << target << endl; //

    int lastIndex = q.linear_search_last(items, target); // Call the linear_search_last function

    cout << "Last occurrence of " << target << " is at index: " << lastIndex << endl; // Prints the index of the last of the last occurrence

    // Where we sort the queue using insertion sort
    cout << "\nBefore Insertion Sort:" << endl;
    q.display(); // Display the queue elements before sorting
    q.insertion_sort(); // Call the insertion_sort function
    cout << "After Insertion Sort:" << endl;  // Print a message after sorting
    q.display(); // Display the queue elements after sorting

    return 0;
}

