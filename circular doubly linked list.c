#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* temp = (*head)->prev;
        newNode->next = *head;
        newNode->prev = temp;
        (*head)->prev = newNode;
        temp->next = newNode;
        *head = newNode; // Update the head to the new node
    }
    printf("Inserted %d at the beginning.\n", value);
}

// Insert at the end of the circular doubly linked list
void insertAtEnd(struct Node** head, int value) {
    if (*head == NULL) {
        insertAtBeginning(head, value);
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        struct Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
        printf("Inserted %d at the end.\n", value);
    }
}

// Insert after a specific value in the circular doubly linked list
void insertAfterValue(struct Node** head, int afterValue, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    do {
        if (temp->data == afterValue) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            printf("Inserted %d after %d.\n", value, afterValue);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Value %d not found.\n", afterValue);
}

// Delete the node at the beginning of the circular doubly linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
    } else {
        struct Node* tail = (*head)->prev;
        struct Node* temp = *head;
        *head = (*head)->next;
        (*head)->prev = tail;
        tail->next = *head;
        free(temp);
    }
    printf("Deleted node at the beginning.\n");
}

// Delete the node at the end of the circular doubly linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = (*head)->prev;
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
        free(temp);
    }
    printf("Deleted node at the end.\n");
}

// Delete the node after a specific value in the circular doubly linked list
void deleteAfterValue(struct Node** head, int afterValue) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    do {
        if (temp->data == afterValue) {
            struct Node* delNode = temp->next;
            if (delNode == *head) { // Prevent deleting the head node
                printf("Cannot delete head node after %d.\n", afterValue);
                return;
            }
            temp->next = delNode->next;
            delNode->next->prev = temp;
            free(delNode);
            printf("Deleted node after %d.\n", afterValue);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Value %d not found.\n", afterValue);
}

// Display the circular doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function to test the operations
int main() {
    struct Node* head = NULL;
    int choice, value, afterValue;

    do {
        printf("\n1. Insert at Beginning\n2. Insert After Value\n3. Insert at End\n");
        printf("4. Delete at Beginning\n5. Delete After Value\n6. Delete at End\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                display(head);
                break;

            case 2:
                printf("Enter the value after which to insert: ");
                scanf("%d", &afterValue);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAfterValue(&head, afterValue, value);
                display(head);
                break;

            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                display(head);
                break;

            case 4:
                deleteAtBeginning(&head);
                display(head);
                break;

            case 5:
                printf("Enter the value after which to delete: ");
                scanf("%d", &afterValue);
                deleteAfterValue(&head, afterValue);
                display(head);
                break;

            case 6:
                deleteAtEnd(&head);
                display(head);
                break;

            case 0:
                printf("Exited\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
