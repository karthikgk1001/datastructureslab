#include <iostream>
#include <string>
#include "Stack1.h"

using namespace std;

class ParenthesisChecker {
public:
    bool isBalanced(const string& str) {
        CharStack stack;

        for (char ch : str) {
            if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                if (stack.isEmpty()) {
                    return false; // Unmatched closing parenthesis
                }
                stack.pop(); // Match found
            }
        }

        return stack.isEmpty(); // If stack is empty, parentheses are balanced
    }
};

int main() {
    ParenthesisChecker checker;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string input;
                cout << "Enter a string of parentheses: ";
                cin >> input;

                if (checker.isBalanced(input)) {
                    cout << "The parentheses are balanced." << endl;
                } else {
                    cout << "The parentheses are not balanced." << endl;
                }
                break;
            }
            case 2:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}