#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coeff, int power) {
    struct Node* temp = *poly;
    if (temp == NULL) {
        *poly = createNode(coeff, power);
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(coeff, power);
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff1, power1, coeff2, power2;

        if (poly1 != NULL) {
            coeff1 = poly1->coeff;
            power1 = poly1->power;
            poly1 = poly1->next;
        } else {
            coeff1 = 0;
            power1 = 0;
        }

        if (poly2 != NULL) {
            coeff2 = poly2->coeff;
            power2 = poly2->power;
            poly2 = poly2->next;
        } else {
            coeff2 = 0;
            power2 = 0;
        }

        int result_coeff = 0;
        int result_power = 0;

        if (power1 == power2) {
            result_coeff = coeff1 + coeff2;
            result_power = power1;
        } else if (power1 > power2) {
            result_coeff = coeff1;
            result_power = power1;
        } else {
            result_coeff = coeff2;
            result_power = power2;
        }

        insertTerm(&result, result_coeff, result_power);
    }
    return result;
}

void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int n, coeff, power;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter the terms for Polynomial 1 (coeff power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly1, coeff, power);
    }

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the terms for Polynomial 2 (coeff power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly2, coeff, power);
    }

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
