///////////CIRCULAR DOUBLY/////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning\n", data);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    printf("Inserted %d at the end\n", data);
}

void insertAtLocation(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;
    while (current->next != *head && count < position - 1) {
        current = current->next;
        count++;
    }
    if (count < position - 1) {
        printf("Invalid position\n");
        return;
    }
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*head)->next == *head) {
        printf("Deleted %d from the beginning\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    (*head)->prev->next = (*head)->next;
    (*head)->next->prev = (*head)->prev;
    *head = (*head)->next;
    printf("Deleted %d from the beginning\n", temp->data);
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*head)->next == *head) {
        printf("Deleted %d from the end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = (*head)->prev;
    (*head)->prev = current->prev;
    current->prev->next = *head;
    printf("Deleted %d from the end\n", current->data);
    free(current);
}

void deleteAtLocation(struct Node** head, int position) {
    if (position <= 0 || *head == NULL) {
        printf("Invalid position or list is empty\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current->next != *head && count < position) {
        current = current->next;
        count++;
    }
    if (count < position) {
        printf("Invalid position\n");
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    printf("Deleted %d from position %d\n", current->data, position);
    free(current);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    printf("List elements (forward): ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
    
    current = head->prev;
    printf("List elements (backward): ");
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insertion
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtLocation(&head, 15, 2);

    // Displaying the list
    display(head);

    // Deletion
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAtLocation(&head, 2);

    // Displaying the list after deletion
    display(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////

