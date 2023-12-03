#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void insertAtTail(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    if (position < 0) {
        printf("Invalid position for deletion.\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* current = *head;
    int count = 0;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    if (current->next == NULL) {
        printf("Position not found for deletion.\n");
        return;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void sort(struct Node** head) {
    int swapped, temp;
    struct Node* current;
    struct Node* lptr = NULL;

    if (*head == NULL)
        return;

    do {
        swapped = 0;
        current = *head;

        while (current->next != lptr) {
            if (current->data > current->next->data) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Tail\n");
        printf("2. Delete at Position\n");
        printf("3. Count Elements\n");
        printf("4. Display List\n");
        printf("5. Sort List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 3:
                printf("Number of elements in the list: %d\n", countElements(head));
                break;

            case 4:
                display(head);
                break;

            case 5:
                sort(&head);
                printf("List sorted.\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
