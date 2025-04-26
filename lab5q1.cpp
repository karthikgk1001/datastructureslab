#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Insert at the beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {  // If list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // Insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {  // If list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    // Insert at a specific position
    void insertPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of range!\n";
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        if (!newNode->next) {  // If inserted at the last position
            tail = newNode;
        }

        cout << "Inserted " << value << " at position " << pos << ".\n";
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;  // If list becomes empty
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
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;  // If list becomes empty
        }
        delete temp;
        cout << "Deleted node from the end.\n";
    }

    // Delete from a specific position
    void deletePosition(int pos) {
        if (!head || pos <= 0) {
            cout << "Invalid position or list is empty!\n";
            return;
        }
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp && i < pos; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of range!\n";
            return;
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;  // If last node is deleted
        }

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;  // If first node is deleted
        }

        delete temp;
        cout << "Deleted node at position " << pos << ".\n";
    }

    // Search for a value
    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Element " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element " << value << " not found in the list.\n";
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function with menu
int main() {
    DoublyLinkedList list;
    int choice, value, pos;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
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
