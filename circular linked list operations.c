#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert after a user-defined element
void insertAfter(struct Node* head, int afterVal, int val) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* current = head;
    do {
        if (current->data == afterVal) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = val;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != head);
    printf("Element %d not found!\n", afterVal);
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int val) {
    if (*head == NULL) {
        insertAtBeginning(head, val);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
        printf("Linked list is emptied.\n");
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// Function to delete after a user-defined element
void deleteAfter(struct Node* head, int afterVal) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* current = head;
    do {
        if (current->data == afterVal) {
            struct Node* toDelete = current->next;
            if (toDelete == head) {
                printf("Can't delete after %d (next is head)!\n", afterVal);
                return;
            }
            current->next = toDelete->next;
            free(toDelete);
            return;
        }
        current = current->next;
    } while (current != head);
    printf("Element %d not found!\n", afterVal);
}

// Function to delete at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}

int main() {
    struct Node* head = NULL;
    int choice, value, afterValue;

    while (1) {
        printf("\nCircular Singly Linked List Operations:\n");
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
                printf("Exited\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
