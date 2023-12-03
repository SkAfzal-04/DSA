#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for each element in the hash table
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Hash table structure
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// Function to initialize the hash table
void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
}

// Function to calculate the hash value for a given key
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hashFunction(key);

    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // Insert the new node into the hash table
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// Function to remove a key-value pair from the hash table
void removeElement(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);

    struct Node* current = hashTable->table[index];
    struct Node* previous = NULL;

    // Search for the key in the linked list at the specified index
    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    // If the key is found, remove the corresponding node
    if (current != NULL) {
        if (previous == NULL) {
            hashTable->table[index] = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to check the size of the hash table
int getSize(struct HashTable* hashTable) {
    int size = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = hashTable->table[i];

        while (current != NULL) {
            size++;
            current = current->next;
        }
    }

    return size;
}

// Function to display the hash table
void display(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);

        struct Node* current = hashTable->table[i];

        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }

        printf("\n");
    }
}

int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    int choice, key, value;

    do {
        printf("\n1. Insert\n2. Remove\n3. Check Size\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(&hashTable, key, value);
                break;
            case 2:
                printf("Enter key to remove: ");
                scanf("%d", &key);
                removeElement(&hashTable, key);
                break;
            case 3:
                printf("Size of hash table: %d\n", getSize(&hashTable));
                break;
            case 4:
                display(&hashTable);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

