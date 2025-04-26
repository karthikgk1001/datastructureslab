#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// Queue class using a linked list
class Queue {
private:
    Node* front; // Points to the front element
    Node* rear;  // Points to the rear element

public:
    Queue() {
        front = rear = nullptr; // Initialize empty queue
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(); // Create new node
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode; 
        } else {
            rear->next = newNode; // Link new node to rear
            rear = newNode; // Update rear
        }
        cout << value << " enqueued successfully.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued successfully.\n";
        front = front->next; // Move front to the next node

        if (front == nullptr) { 
            rear = nullptr;
        }
        delete temp; 
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No front element.\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function with menu
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations (Linked List Implementation):\n";
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
