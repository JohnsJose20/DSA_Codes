#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[256];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;

void displayMenu();
void visitPage();
void goBack();
void goForward();
void displayCurrent();
void freeHistory();

int main() {
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n\n");
            
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                visitPage();
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrent();
                break;
            case 5:
                printf("Exiting navigation...\n");
                freeHistory(); 
                return 0;     
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    }

    return 0;
}

void displayMenu() {
    
    printf("------------------------------------\n");
    printf("Browser Navigation Menu\n");
    printf("------------------------------------\n");
    printf("1. Visit new page      🌐\n");  
    printf("2. Go back             ◀️\n");
    printf("3. Go forward          ▶️\n");
    printf("4. Display current page📄\n");
    printf("5. Exit                ❌\n");
    printf("Enter your choice: ");
}

void visitPage() {
    char new_url[256];
    printf("Enter the URL to visit: ");
    
    while (getchar() != '\n');
    fgets(new_url, sizeof(new_url), stdin);

    new_url[strcspn(new_url, "\n")] = 0;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->url, new_url);

    if (current != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            struct Node* nodeToDelete = temp;
            temp = temp->next;
            free(nodeToDelete);
        }
        
        newNode->prev = current;
        current->next = newNode;
    } else {
        newNode->prev = NULL;
    }

    newNode->next = NULL;
    
    current = newNode;
    printf("Successfully visited URL: %s\n\n", current->url);
}

void goBack() {
   
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back.\n\n");
    } else {
        
        current = current->prev;
        printf("Moved back to URL: %s\n\n", current->url);
    }
}

void goForward() {
   
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward.\n\n");
    } else {
        current = current->next;
        printf("Moved forward to URL: %s\n\n", current->url);
    }
}

void displayCurrent() {
    if (current == NULL) {
        printf("No page visited yet.\n\n");
    } else {
        printf("Current page is: %s\n\n", current->url);
    }
}

void freeHistory() {
    
    while (current != NULL && current->prev != NULL) {
        current = current->prev;
    }

    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}