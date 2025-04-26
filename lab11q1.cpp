#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                cout << "Hash table is full. Cannot insert.\n";
                return;
            }
        }
        table[index] = key;
        cout << "Inserted " << key << " at index " << index << ".\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << "Deleted " << key << " from index " << index << ".\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }

        cout << "Key " << key << " not found.\n";
    }

    void search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Found " << key << " at index " << index << ".\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }

        cout << "Key " << key << " not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == EMPTY)
                cout << "[" << i << "] : EMPTY\n";
            else if (table[i] == DELETED)
                cout << "[" << i << "] : DELETED\n";
            else
                cout << "[" << i << "] : " << table[i] << "\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
