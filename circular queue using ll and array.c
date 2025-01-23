#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node *front, *rear;
};

// Function prototypes
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
int isFull(struct Queue* q); // This doesn't apply to a linked list implementation
int isEmpty(struct Queue* q);
void displayStatus(struct Queue* q);

int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    
    int choice, value;
    
    do {
        printf("\nQueue Operations (Linked List Implementation):\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check Status\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayStatus(&q);
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

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        newNode->next = q->front; // Circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // Maintain circular link
    }
    printf("Enqueued %d to the queue.\n", value);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Indicating an error
    } else {
        int dequeuedValue = q->front->data;
        if (q->front == q->rear) { // Only one element in the queue
            free(q->front);
            q->front = q->rear = NULL;
        } else {
            struct Node* temp = q->front;
            q->front = q->front->next;
            q->rear->next = q->front; // Maintain circular link
            free(temp);
        }
        return dequeuedValue;
    }
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to display the status of the queue
void displayStatus(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }
}
