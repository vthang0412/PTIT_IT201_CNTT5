#include <stdio.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enQueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Mang hang doi da day");
        return;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

void printQueue(Queue *q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);
    enQueue(&queue, 4);
    enQueue(&queue, 5);
    printQueue(&queue);
    return 0;
}
