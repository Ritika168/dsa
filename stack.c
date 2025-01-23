#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // Maximum size of the stack

// Structure to represent the stack
struct Stack {
    int top;
    int arr[MAX];
};

// Function prototypes
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
bool isFull(struct Stack* stack);
bool isEmpty(struct Stack* stack);
void displayStatus(struct Stack* stack);

int main() {
    struct Stack stack;
    stack.top = -1; // Initialize the stack as empty
    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Status\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                displayStatus(&stack);
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

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Indicating an error
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to display the status of the stack
void displayStatus(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty. Current top: %d\n", stack->top);
    }

    if (isFull(stack)) {
        printf("The stack is full.\n");
    } else {
        printf("The stack is not full.\n");
    }
}
