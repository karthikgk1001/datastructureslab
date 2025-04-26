#include <iostream>
#include <string>
#include <cctype>
#include "Stack.h"

using namespace std;

class InfixPostfixConverter {
public:
    string infix;
    string postfix;

    void getInfix() {
        cout << "Enter a valid infix expression: ";
        cin >> infix;
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    void convertInfixToPostfix() {
        CharStack stack;
        postfix = "";

        for (char ch : infix) {
            if (isalnum(ch)) {
                postfix += ch; // Add operand to postfix
            } else if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix += stack.pop();
                }
                stack.pop(); // Pop '('
            } else { // Operator
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                    postfix += stack.pop();
                }
                stack.push(ch);
            }
        }

        while (!stack.isEmpty()) {
            postfix += stack.pop();
        }

        cout << "Postfix expression: " << postfix << endl;
    }

    int evaluatePostfix() {
        CharStack stack;

        for (char ch : postfix) {
            if (isdigit(ch)) {
                stack.push(ch); // Push character directly
            } else {
                int right = stack.pop() - '0'; // Convert char to int
                int left = stack.pop() - '0'; // Convert char to int
                switch (ch) {
                    case '+': stack.push(left + right + '0'); break; // Convert back to char
                    case '-': stack.push(left - right + '0'); break; // Convert back to char
                    case '*': stack.push(left * right + '0'); break; // Convert back to char
                    case '/': stack.push(left / right + '0'); break; // Convert back to char
                }
            }
        }

        return stack.pop() - '0'; // Convert final result back to int
    }
};

int main() {
    InfixPostfixConverter converter;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                converter.getInfix();
                break;
            case 2:
                converter.convertInfixToPostfix();
                break;
            case 3:
                cout << "Postfix evaluation result: " << converter.evaluatePostfix() << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}