#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int is_empty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to push an element to the queue
void push(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d pushed to the queue.\n", data);
}

// Function to pop an element from the queue
void pop(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty. Cannot pop.\n");
    } else {
        struct Node* temp = queue->front;
        queue->front = temp->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        printf("%d popped from the queue.\n", temp->data);
        free(temp);
    }
}

// Function to get the front element of the queue (stacktop)
int stacktop(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty. No stacktop.\n");
        return -1; // Assuming -1 as an indicator for an empty queue
    } else {
        return queue->front->data;
    }
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, data;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Stacktop\n");
        printf("4. Is Empty\n");
        printf("5. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                push(&queue, data);
                break;
            case 2:
                pop(&queue);
                break;
            case 3:
                printf("Stacktop element: %d\n", stacktop(&queue));
                break;
            case 4:
                if (is_empty(&queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                display(&queue);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

