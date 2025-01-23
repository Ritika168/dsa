#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for storing nodes
struct Stack {
    struct Node* data;
    struct Stack* next;
};

// Function Prototypes
struct Node* insert(struct Node* root, int value);
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);
void push(struct Stack** stack, struct Node* node);
struct Node* pop(struct Stack** stack);
int isEmpty(struct Stack* stack);

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Traversals Using Stack:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to insert a node in the Binary Search Tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to push a node to the stack
void push(struct Stack** stack, struct Node* node) {
    struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
    newStackNode->data = node;
    newStackNode->next = *stack;
    *stack = newStackNode;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack** stack) {
    if (*stack == NULL) {
        return NULL;
    }
    struct Node* temp = (*stack)->data;
    struct Stack* tempStack = *stack;
    *stack = (*stack)->next;
    free(tempStack);
    return temp;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack == NULL;
}

// Iterative Inorder Traversal
void inorder(struct Node* root) {
    struct Stack* stack = NULL;
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Iterative Preorder Traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right) {
            push(&stack, current->right);
        }
        if (current->left) {
            push(&stack, current->left);
        }
    }
}

// Iterative Postorder Traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack1 = NULL;
    struct Stack* stack2 = NULL;

    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* current = pop(&stack1);
        push(&stack2, current);

        if (current->left) {
            push(&stack1, current->left);
        }
        if (current->right) {
            push(&stack1, current->right);
        }
    }

    // Print the contents of stack2
    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}
