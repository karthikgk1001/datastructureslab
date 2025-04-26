#include <iostream>
using namespace std;

class Node {
public:
    int time;
    Node* next;

    Node(int t) {
        time = t;
        next = nullptr;
    }
};

class RoundRobinScheduler {
private:
    Node* tail; // Circular Queue Tail
    int timeSlot; // Fixed time quantum

public:
    RoundRobinScheduler(int slot) {
        tail = nullptr;
        timeSlot = slot;
    }

    // Insert a process (add to queue)
    void insertProcess(int time) {
        Node* newNode = new Node(time);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Process added with execution time: " << time << " units.\n";
    }

    // Execute processes in Round Robin fashion
    void execute() {
        if (!tail) {
            cout << "No processes to execute.\n";
            return;
        }

        cout << "\nExecuting processes...\n";
        while (tail) {
            Node* current = tail->next; // First process in queue
            cout << "Processing time: " << current->time << " units. ";

            current->time -= timeSlot; // Subtract time quantum

            if (current->time <= 0) {
                cout << "Process completed!\n";
                if (current == tail) { // If last node is deleted
                    delete tail;
                    tail = nullptr;
                } else {
                    tail->next = current->next;
                    delete current;
                }
            } else {
                cout << "Remaining time: " << current->time << " units.\n";
                tail = tail->next; // Move tail to next process
            }
        }
        cout << "All processes executed.\n";
    }

    // Display the process queue
    void displayQueue() {
        if (!tail) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Process Queue: ";
        do {
            cout << temp->time << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

// Main function with menu
int main() {
    int timeSlot;
    cout << "Enter the fixed time slot for Round Robin Scheduling: ";
    cin >> timeSlot;

    RoundRobinScheduler scheduler(timeSlot);
    int choice, time;

    while (true) {
        cout << "\n--- Round Robin Scheduling Menu ---\n";
        cout << "1. Insert Process\n2. Execute\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process execution time: ";
                cin >> time;
                scheduler.insertProcess(time);
                scheduler.displayQueue();
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
