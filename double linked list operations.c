#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert after a user-defined element
void insertAfter(struct Node* head, int afterVal, int val) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->data == afterVal) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = val;
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element %d not found!\n", afterVal);
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete after a user-defined element
void deleteAfter(struct Node* head, int afterVal) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->data == afterVal) {
            struct Node* toDelete = current->next;
            if (toDelete == NULL) {
                printf("No node to delete after %d\n", afterVal);
                return;
            }
            current->next = toDelete->next;
            if (toDelete->next != NULL) {
                toDelete->next->prev = current;
            }
            free(toDelete);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found!\n", afterVal);
}

// Function to delete at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, afterValue;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert After Element\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete After Element\n");
        printf("6. Delete at End\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                printList(head);
                break;

            case 2:
                printf("Enter value after which to insert: ");
                scanf("%d", &afterValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfter(head, afterValue, value);
                printList(head);
                break;

            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printList(head);
                break;

            case 4:
                deleteAtBeginning(&head);
                printf("Deleted node at beginning.\n");
                printList(head);
                break;

            case 5:
                printf("Enter value after which to delete: ");
                scanf("%d", &afterValue);
                deleteAfter(head, afterValue);
                printList(head);
                break;

            case 6:
                deleteAtEnd(&head);
                printf("Deleted node at end.\n");
                printList(head);
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
