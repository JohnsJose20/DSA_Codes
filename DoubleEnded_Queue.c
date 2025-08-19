#include <stdio.h>
#define MAX 2

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int element) {
    if (front == 0) {
        printf("Cannot insert at front (Overflow)\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[front] = element;
    } else {
        front--;
        deque[front] = element;
    }
    printf("Inserted at Front: %d\n", element);
}

void insertRear(int element) {
    if (rear == MAX - 1) {
        printf("Cannot insert at rear (Overflow)\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[rear] = element;
    } else {
        rear++;
        deque[rear] = element;
    }
    printf("Inserted at Rear: %d\n", element);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("Deleted from Front: %d\n", deque[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void deleteRear() {
    if (rear == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("Deleted from Rear: %d\n", deque[rear]);
        if (front == rear)
            front = rear = -1;
        else
            rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
    } else {
        printf("Deque Elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    printf("Menu:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display Deque\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting program.\n");
            break; 
        }

        switch(choice) {
            case 1:
                if (rear == MAX - 1 && front == 0) {
                    printf("Deque is Full (Overflow)!\n");
                } else {
                    printf("Enter the element to insert at front: ");
                    scanf("%d", &element);
                    insertFront(element);
                }
                break;

            case 2:
                if (rear == MAX - 1) {
                    printf("Deque is Full (Overflow)!\n");
                } else {
                    printf("Enter the element to insert at rear: ");
                    scanf("%d", &element);
                    insertRear(element);
                }
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    
    return 0;
}
