#include <stdio.h>
#include <stdlib.h>

#define n 5

int queue[n];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear + 1) % n == front);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    queue[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        return -1;
    }
    int dequeuedValue = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}
void display() {
    if (isEmpty()) {
        return;
    }
    printf("Queue elements are:\n"); 
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
    } while (i != (rear + 1) % n);
    printf("\n");
}

int main() {
  enqueue(20);
  enqueue(30);
  enqueue(60);
  enqueue(40);
  enqueue(10);
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  display();
  enqueue(50);
  display();
}