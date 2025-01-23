#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_STACK_SIZE 100

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Stack {
    Node* data[MAX_STACK_SIZE];
    int top;

    // Initialize stack
    Stack() : top(-1) {}

    // Push Node* to stack
    void push(Node* node) {
        if (top < MAX_STACK_SIZE - 1) {
            data[++top] = node;
        }
    }

    // Pop Node* from stack
    Node* pop() {
        if (top >= 0) {
            return data[top--];
        }
        return nullptr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Peek at top element
    Node* peek() {
        if (top >= 0) {
            return data[top];
        }
        return nullptr;
    }
};

Node* CreateNode(int val){
    Node* newNode=new Node();
    newNode->data=val;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
};

Node*  insertNode(Node* root,int val){
    if(root==nullptr){
        return CreateNode(val);
    }
    if(root->data<val){
        root->right=insertNode(root->right,val);
    }
    else if(root->data>val){
        root->left=insertNode(root->left,val);
    }
    return root;
}

void inorderTraversal(Node* root) {
    Stack stack;
    Node* current = root;

    while (current != nullptr || !stack.isEmpty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        current = stack.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void preorderTraversal(Node* root) {
    if (root == nullptr) return;

    Stack stack;
    stack.push(root);

    while (!stack.isEmpty()) {
        Node* current = stack.pop();
        cout << current->data << " ";

        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }
    }
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;

    Stack stack1, stack2;
    stack1.push(root);

    while (!stack1.isEmpty()) {
        Node* current = stack1.pop();
        stack2.push(current);

        if (current->left != nullptr) {
            stack1.push(current->left);
        }
        if (current->right != nullptr) {
            stack1.push(current->right);
        }
    }

    while (!stack2.isEmpty()) {
        cout << stack2.pop()->data << " ";
    }
}
int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\nBinary Search Tree Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insertNode(root, key);
                cout << "Inserted " << key << " into the BST.\n";
                break;

            case 2:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

