#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
private:
    int arr[SIZE];  
    int front, rear; // Front and rear pointers

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;  // Initialize front if first element is added
        }
        rear = (rear + 1) % SIZE; 
        arr[rear] = value;
        cout << value << " enqueued successfully.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        if (front == rear) {
            front = rear = -1; // Reset queue when last element is removed
        } else {
            front = (front + 1) % SIZE;  // Circular increment
        }
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No front element.\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};


int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                q.display();
                break;
            case 2:
                q.dequeue();
                q.display();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
