#include <iostream>
#include <stack>
using namespace std;

// Definition of a Node in BST
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    
    Node* insert(Node* node, char val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    bool search(Node* node, char val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

public:
    BST() : root(nullptr) {}

    void insert(char val) { root = insert(root, val); }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(char val) { return search(root, val); }

    // Construct Expression Tree from Postfix Expression
    void constructExpressionTree(string postfix) {
        stack<Node*> st;
        for (char ch : postfix) {
            if (isalnum(ch)) {
                st.push(new Node(ch));
            } else {
                Node* newNode = new Node(ch);
                newNode->right = st.top(); st.pop();
                newNode->left = st.top(); st.pop();
                st.push(newNode);
            }
        }
        root = st.top();
    }
};

int main() {
    BST tree;
    int choice;
    string postfix;
    
    while (true) {
        cout << "\nExpression Tree Menu" << endl;
        cout << "1. Enter Postfix Expression" << endl;
        cout << "2. Construct Expression Tree" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter valid postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                tree.constructExpressionTree(postfix);
                cout << "Expression tree constructed successfully!" << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}