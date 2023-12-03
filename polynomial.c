#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);

    // If the polynomial is empty, set the new node as the head
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;

        // Traverse to the end of the polynomial
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Add the new node at the end
        temp->next = newNode;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        // Choose the term with higher exponent
        if (exp1 > exp2) {
            insertTerm(&result, coeff1, exp1);
            poly1 = poly1->next;
        } else if (exp1 < exp2) {
            insertTerm(&result, coeff2, exp2);
            poly2 = poly2->next;
        } else {
            // Exponents are equal, add coefficients
            insertTerm(&result, coeff1 + coeff2, exp1);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free the memory allocated for a polynomial
void freePolynomial(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Example polynomials: 3x^2 + 2x + 5 and 4x^3 + 2x^2 + 1
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 5, 0);

    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPolynomial(result);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}

