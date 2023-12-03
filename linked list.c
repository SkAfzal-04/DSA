#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to count the number of elements in the linked list
int count(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to insert a node at the head of the linked list
struct Node* insertAtHead(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at a specified position in the linked list
struct Node* insertAtPos(struct Node* head, int value, int position) {
    if (position < 1 || (position > 1 && head == NULL)) {
        printf("Invalid position for insertion!\n");
        return head;
    }
    struct Node* newNode = createNode(value);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position for insertion!\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node with a specific value from the linked list
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found!\n", value);
        return head;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return head;
}

// Function to sort the linked list in ascending order
struct Node* sortList(struct Node* head) {
    struct Node* current = head;
    struct Node* index = NULL;
    int temp;

    if (head == NULL) {
        return head;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    return head;
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\n---- Linked List Operations ----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Insert at Head\n");
        printf("5. Insert at End\n");
        printf("6. Insert at Position\n");
        printf("7. Delete\n");
        printf("8. Sort\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a linked list
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = createNode(value);
                break;

            case 2:
                // Display the linked list
                display(head);
                break;

            case 3:
                // Count the number of elements in the linked list
                printf("Number of elements: %d\n", count(head));
                break;

            case 4:
                // Insert at the head of the linked list
                printf("Enter the value to insert at head: ");
                scanf("%d", &value);
                head = insertAtHead(head, value);
                break;

            case 5:
                // Insert at the end of the linked list
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 6:
                // Insert at a specified position in the linked list
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                head = insertAtPos(head, value, position);
                break;

            case 7:
                // Delete a node with a specific value
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;

            case 8:
                // Sort the linked list
                head = sortList(head);
                printf("Linked list sorted!\n");
                break;

            case 9:
                // Exit the program
                freeList(head);
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}

