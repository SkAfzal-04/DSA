#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Element %d inserted at the end.\n", value);
}

// Function to insert a node at the head of the circular linked list
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    printf("Element %d inserted at the head.\n", value);
}

// Function to insert a node at any position in the circular linked list
void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be greater than or equal to 1.\n");
        return;
    }

    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        printf("Element %d inserted at position %d.\n", value, position);
        return;
    }

    if (position == 1) {
        insertAtHead(head, value);
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count != position - 1) {
        printf("Position %d is greater than the number of elements in the list.\n", position);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Element %d inserted at position %d.\n", value, position);
    }
}

// Function to delete a node with a given value from the circular linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head
    if (temp->data == value) {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        if (*head == last) {
            *head = NULL;
        } else {
            last->next = temp->next;
            *head = temp->next;
        }

        free(temp);
        printf("Element %d deleted.\n", value);
        return;
    }

    // Search for the node to be deleted
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != value);

    // If the node is not found
    if (temp == *head) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted.\n", value);
}

// Function to display the elements of the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Circular Linked List: ");
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

// Function to count the number of elements in the circular linked list
int count(struct Node* head) {
    if (head == NULL) {
        return 0;
    }

    struct Node* temp = head;
    int count = 0;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Function to sort the circular linked list in ascending order
void sortLinkedList(struct Node** head) {
    struct Node *current, *index;
    int temp;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    for (current = *head; current != last; current = current->next) {
        for (index = current->next; index != *head; index = index->next) {
            if (current->data > index->data) {
                // Swap data if the current element is greater than the next element
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    printf("Circular Linked List sorted in ascending order.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Head\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Count\n");
        printf("7. Sort\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter the value to insert at the head: ");
                scanf("%d", &value);
                insertAtHead(&head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Number of elements in the list: %d\n", count(head));
                break;
            case 7:
                sortLinkedList(&head);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}

