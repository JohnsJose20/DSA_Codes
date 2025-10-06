#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

typedef struct StackNode {
    Node *treeNode;
    struct StackNode *next;
} StackNode;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void push(StackNode** top_ref, Node* t) {
    StackNode* new_stack_node = (StackNode*)malloc(sizeof(StackNode));
    new_stack_node->treeNode = t;
    new_stack_node->next = (*top_ref);
    (*top_ref) = new_stack_node;
}

Node* pop(StackNode** top_ref) {
    if (*top_ref == NULL) return NULL;
    Node *res = (*top_ref)->treeNode;
    StackNode *temp = *top_ref;
    *top_ref = (*top_ref)->next;
    free(temp);
    return res;
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1;
    int k = 0;

    for (int i = 0; infix[i]; ++i) {
        if (isOperand(infix[i])) {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') {
                top--;
            }
        }
        else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
}

Node* constructTree(char postfix[]) {
    StackNode *stack = NULL;
    Node *t, *t1, *t2;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            t = newNode(postfix[i]);
            push(&stack, t);
        } else {
            t = newNode(postfix[i]);
            t1 = pop(&stack);
            t2 = pop(&stack);
            t->right = t1;
            t->left = t2;
            push(&stack, t);
        }
    }
    t = pop(&stack);
    return t;
}

void printPostfix(Node* node) {
    if (node == NULL) return;
    printPostfix(node->left);
    printPostfix(node->right);
    printf("%c ", node->data);
}

void printPrefix(Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    printPrefix(node->left);
    printPrefix(node->right);
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    
    printf("\nInfix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    Node* root = constructTree(postfix);
    
    printf("\n--- Tree Traversal ---\n");
    
    printf("Postorder Traversal of the Tree: ");
    printPostfix(root);
    printf("\n");

    printf("Preorder Traversal of the Tree:  ");
    printPrefix(root);
    printf("\n");

    return 0;
}