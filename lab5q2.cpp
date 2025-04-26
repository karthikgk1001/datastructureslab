#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;  // Points to the last node

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at the beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (!tail) {  // If list is empty
            tail = newNode;
            tail->next = tail;  // Point to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // Insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;  // Update tail
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    // Insert at a specific position
    void insertPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1 || !tail) {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = tail->next;
        for (int i = 1; temp != tail && i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode;  // Update tail if inserted at the end
        }

        cout << "Inserted " << value << " at position " << pos << ".\n";
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail->next;
        if (tail == tail->next) {  // If only one node exists
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
        cout << "Deleted node from the beginning.\n";
    }

    // Delete from the end
    void deleteEnd() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail->next;
        if (tail == temp) {  // Only one node
            delete tail;
            tail = nullptr;
            cout << "Deleted last node.\n";
            return;
        }

        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;  // Update tail
        cout << "Deleted node from the end.\n";
    }

    // Delete from a specific position
    void deletePosition(int pos) {
        if (!tail || pos <= 0) {
            cout << "Invalid position or list is empty!\n";
            return;
        }
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = tail->next;
        Node* prev = nullptr;
        for (int i = 1; temp != tail && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == tail) {  // If last node is deleted
            deleteEnd();
            return;
        }

        if (prev) {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Deleted node at position " << pos << ".\n";
    }

    // Search for a value
    void search(int value) {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail->next;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Element " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != tail->next);

        cout << "Element " << value << " not found.\n";
    }

    // Display the list
    void display() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail->next;
        cout << "List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

// Main function with menu
int main() {
    CircularLinkedList list;
    int choice, value, pos;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert at Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete at Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value and position to insert: ";
                cin >> value >> pos;
                list.insertPosition(value, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
