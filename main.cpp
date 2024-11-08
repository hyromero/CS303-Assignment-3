// main.cpp
#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    // Part (a) Instantiate the queue with integers and push 10 values into the queue
    Queue<int> q;

    cout << "Pushing 10 values into the queue: " << endl;
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // Part (b) Display all elements in the queue using the provided functions
    cout << "Queue elements after pushing 10 values: ";
    q.display();
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Front element: " << q.front() << endl;

    // Part (c) Perform pop, push, move_to_rear and show the queue state after each
    cout << "\n--- After pop() ---" << endl;
    q.pop();
    q.display();
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Front element: " << q.front() << endl;

    cout << "\n--- After pushing 11 ---" << endl;
    q.push(11);
    q.display();
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Front element: " << q.front() << endl;

    cout << "\n--- After move_to_rear() ---" << endl;
    q.move_to_rear();
    q.display();
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Front element: " << q.front() << endl;

    return 0;
}
