#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

int stackTop() {
    if (top == -1) {
        printf("Stack is empty. No top element.\n");
        return -1; // Return an invalid value
    } else {
        return stack[top];
    }
}

int isEmpty() {
    return top == -1;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Stack Top\n");
        printf("4. Is Empty\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                value = stackTop();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
