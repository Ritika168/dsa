#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure for queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure for stack
struct Stack {
    struct StackNode* top;
};

// Structure for queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Stack Function Prototypes
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
int isStackEmpty(struct Stack* stack);

// Queue Function Prototypes
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
int isQueueEmpty(struct Queue* queue);

// Utility Functions
void displayStackStatus(struct Stack* stack);
void displayQueueStatus(struct Queue* queue);

int main() {
    struct Stack stack;
    stack.top = NULL;  // Initialize stack to be empty
    
    struct Queue queue;
    queue.front = queue.rear = NULL;  // Initialize queue to be empty
    
    int choice, value;
    
    do {
        printf("\nChoose an operation:\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:  // Stack Operations
                printf("\nStack Operations:\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Peek\n");
                printf("4. Check if Stack is Empty\n");
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
                        value = peek(&stack);
                        if (value != -1) {
                            printf("Top value: %d\n", value);
                        }
                        break;
                    case 4:
                        displayStackStatus(&stack);
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
                break;
            
            case 2:  // Queue Operations
                printf("\nQueue Operations:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Check if Queue is Empty\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        printf("Enter value to enqueue: ");
                        scanf("%d", &value);
                        enqueue(&queue, value);
                        break;
                    case 2:
                        value = dequeue(&queue);
                        if (value != -1) {
                            printf("Dequeued value: %d\n", value);
                        }
                        break;
                    case 3:
                        displayQueueStatus(&queue);
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
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

// Stack Functions

// Push an element to the stack
void push(struct Stack* stack, int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d to the stack.\n", value);
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;  // Indicating an error
    } else {
        struct StackNode* temp = stack->top;
        int poppedValue = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return poppedValue;
    }
}

// Peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

// Check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Display stack status
void displayStackStatus(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }
}

// Queue Functions

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d to the queue.\n", value);
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;  // Indicating an error
    } else {
        struct QueueNode* temp = queue->front;
        int dequeuedValue = temp->data;
        queue->front = queue->front->next;
        
        if (queue->front == NULL) {  // If queue becomes empty
            queue->rear = NULL;
        }
        
        free(temp);
        return dequeuedValue;
    }
}

// Check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Display queue status
void displayQueueStatus(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }
}
