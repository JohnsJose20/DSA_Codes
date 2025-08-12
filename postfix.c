#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;
}


void infixToPostfix(char infix[MAX], char postfix[MAX]) {
    int i = 0, j = 0;
    char current;

    while (infix[i] != '\0') {
        current = infix[i];

        if (isOperand(current)) {
  
            postfix[j++] = current;
        } else if (current == '(') {
           
            stack[++top] = current;
        } else if (current == ')') {
          
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  
        } else {
            
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = current;
        }
        i++;
    }

    
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
