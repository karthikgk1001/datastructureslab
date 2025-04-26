#include <iostream>
using namespace std;

// Node structure for the tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) {
        data = value;
        left = right = nullptr;
    }
};


class BinaryTree {
private:
    TreeNode* root;

    
    TreeNode* insert(TreeNode* node, char value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    bool search(TreeNode* node, char key) {
        if (!node) return false;
        if (node->data == key) return true;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

public:
    BinaryTree() { root = nullptr; }

    void insert(char value) {
        root = insert(root, value);
        cout << value << " inserted successfully.\n";
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void search(char key) {
        if (search(root, key))
            cout << key << " found in the tree.\n";
        else
            cout << key << " NOT found in the tree.\n";
    }
};

// Main function with menu
int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        cout << "\nTree ADT (Binary Search Tree)\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
