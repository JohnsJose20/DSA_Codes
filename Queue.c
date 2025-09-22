/* AUTHORE: JOHNS JOSE
   ROLL NO: 45
   CLASS  : CSE A
*/

#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
        printf("Enqueued: %d\n", element);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    printf("Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program.\n");
            break; 
        }

        switch(choice) {
            case 1:
                if (rear == MAX - 1) {
                    printf("Queue is full, cannot enqueue!\n");
                } else {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &element);
                    enqueue(element);
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    
    return 0;
}
