#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

// Structure to represent the queue
struct Queue {
    int front, rear;
    int arr[MAX];
};

// Function prototypes
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
int isFull(struct Queue* q);
int isEmpty(struct Queue* q);
void displayStatus(struct Queue* q);

int main() {
    struct Queue q;
    q.front = -1; // Initialize the queue as empty
    q.rear = -1;
    
    int choice, value;
    
    do {
        printf("\nQueue Operations:\n");
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
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // If the queue was empty, set front to 0
        }
        q->rear = (q->rear + 1) % MAX; // Circular increment
        q->arr[q->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Indicating an error
    } else {
        int dequeuedValue = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Queue becomes empty
        } else {
            q->front = (q->front + 1) % MAX; // Circular increment
        }
        return dequeuedValue;
    }
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to display the status of the queue
void displayStatus(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
        printf("Front: %d, Rear: %d\n", q->front, q->rear);
    }

    if (isFull(q)) {
        printf("The queue is full.\n");
    } else {
        printf("The queue is not full.\n");
    }
}
