#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Preorder traversal
void preorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    cout << node->data << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "->";
}

// Inorder traversal
void inorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    inorderTraversal(node->left);
    cout << node->data << "->";
    inorderTraversal(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    int choice;
    while (true) {
        cout << "\nChoose the type of traversal: \n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << "NULL\n";
                break;
            case 2:
                cout << "Preorder traversal: ";
                preorderTraversal(root);
                cout << "NULL\n";
                break;
            case 3:
                cout << "Postorder traversal: ";
                postorderTraversal(root);
                cout << "NULL\n";
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
