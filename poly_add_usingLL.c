#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* addPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node** temp = &result;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(temp, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } 
        else if (poly1->pow < poly2->pow) {
            insertNode(temp, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } 
        else {
            insertNode(temp, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        while (*temp != NULL) temp = &((*temp)->next);
    }

    while (poly1 != NULL) {
        insertNode(temp, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
        while (*temp != NULL) temp = &((*temp)->next);
    }
    while (poly2 != NULL) {
        insertNode(temp, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
        while (*temp != NULL) temp = &((*temp)->next);
    }

    return result;
}

void printPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct Node* readPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, pow;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter each term as: coefficient power\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        insertNode(&poly, coeff, pow);
    }

    return poly;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    printf("Enter first polynomial:\n");
    poly1 = readPolynomial();

    printf("Enter second polynomial:\n");
    poly2 = readPolynomial();

    printf("\nPolynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    sum = addPolynomial(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    return 0;
}
