#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

class CharNode {
public:
    char data;
    CharNode* next;
    CharNode(char value) : data(value), next(nullptr) {}
};

class CharStack {
private:
    CharNode* top;

public:
    CharStack() : top(nullptr) {}

    ~CharStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(char value) {
        CharNode* newNode = new CharNode(value);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        CharNode* temp = top;
        char poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    char peek() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

#endif // STACK_H