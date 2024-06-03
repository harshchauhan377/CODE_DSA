#include<iostream>
using namespace std;

// Implement queue using array
class Queue {
    int *arr;
    int front, rear, size;

public:
    // Constructor
    Queue(int n) {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    // if Queue is Empty or Not
    bool isEmpty() {
        return front == -1;
    }

    // Queue is full or not
    bool isFull() {
        return rear == size - 1;
    }

    // Push element into Queue, end
    void push(int x) {
        // empty
        if (isEmpty()) {
            cout << "pushed " << x << " into the Queue\n";
            front = rear = 0;
            arr[0] = x;
        }
        // full
        else if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        // insert
        else {
            rear++;
            arr[rear] = x;
            cout << "pushed " << x << " into the Queue\n";
        }
    }

    // Pop element, starting
    void pop() {
        // empty
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        // pop kar do
        else {
            if (front == rear) {
                cout << "popped " << arr[front] << " from the Queue\n";
                front = rear = -1;
            }
            else {
                cout << "popped " << arr[front] << " from the Queue\n";
                front++;
            }
        }
    }

    // Start ma konsa element rakha h
    int start() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        else {
            return arr[front];
        }
    }
};

int main() {
    Queue a(5);
    a.push(5);
    a.push(15);
    a.push(34);
    a.pop();
    a.pop();
    a.pop();
    int x = a.start();
    if (!a.isEmpty())
        cout << "Starting element: " << x << "\n";

    return 0;
}
