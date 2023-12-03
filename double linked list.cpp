#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* createDoublyLinkedList();
void displayList(struct Node* head);
int countNodes(struct Node* head);
struct Node* insertNode(struct Node* head, int data, int position);
struct Node* deleteNode(struct Node* head, int data);
struct Node* invertList(struct Node* head);
struct Node* sortList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        // Display menu
        printf("\nDoubly Linked List Operations\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Count Nodes\n");
        printf("4. Insert Node\n");
        printf("5. Delete Node\n");
        printf("6. Invert List\n");
        printf("7. Sort List\n");
        printf("8. Exit\n");

        // User input for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createDoublyLinkedList();
                printf("Doubly linked list created.\n");
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertNode(head, data, position);
                break;

            case 5:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;

            case 6:
                head = invertList(head);
                printf("List inverted.\n");
                break;

            case 7:
                head = sortList(head);
                printf("List sorted.\n");
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list
struct Node* createDoublyLinkedList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to count the number of nodes in the doubly linked list
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to insert a node at a specific position in the doubly linked list
struct Node* insertNode(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int count = 1;

    if (position < 1 || position > countNodes(head) + 1) {
        printf("Invalid position. Node not inserted.\n");
        return head;
    }

    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        while (count < position - 1) {
            current = current->next;
            count++;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    printf("Node inserted successfully.\n");
    return head;
}

// Function to delete a node with a specific data value from the doubly linked list
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found. Node not deleted.\n", data);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with data %d deleted successfully.\n", data);
    return head;
}

// Function to invert the doubly linked list
struct Node* invertList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    printf("List inverted successfully.\n");
    return head;
}

// Function to sort the doubly linked list
struct Node* sortList(struct Node* head) {
    struct Node *current, *index;
    int temp;

    if (head == NULL) {
        printf("List is empty. Nothing to sort.\n");
        return head;
    }

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    printf("List sorted successfully.\n");
    return head;
}

