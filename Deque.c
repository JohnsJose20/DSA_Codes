#include <stdio.h>
#define MAX 5

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
    insertRear(10);
    insertFront(20);
    insertRear(30);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}

