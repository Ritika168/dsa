#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* CreateNode(int val){
    Node* newNode=new Node();
    newNode->data=val;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
};

Node* Search(int target,Node* root){
    if(root->data==target or root==nullptr){
        return root;
    }
    if(root->data<target){
        return Search(target,root->right);
    }
    return Search(target,root->left);
}

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

Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* DeleteNode(Node* root,int val){
    
    if (root == nullptr) {
        return root;
    }
    if (val < root->data) {
        root->left = DeleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = DeleteNode(root->right, val);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;

}


void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\nBinary Search Tree Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
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
                cout << "Enter key to delete: ";
                cin >> key;
                root = DeleteNode(root, key);
                cout << "Deleted " << key << " from the BST.\n";
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (Search(key, root)) {
                    cout << key << " found in the BST.\n";
                } else {
                    cout << key << " not found in the BST.\n";
                }
                break;

            case 4:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    

    
    

    return 0;
}


