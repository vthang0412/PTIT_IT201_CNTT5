#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
}

bool isEmpty(Queue *q) {
    return q->front > q->rear;
}

int deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;
    return value;
}

int main() {
    Queue q1;
    initQueue(&q1, 5);
    deQueue(&q1);

    Queue q2;
    initQueue(&q2, 5);
    q2.arr[0] = 1;
    q2.arr[1] = 2;
    q2.arr[2] = 5;
    q2.rear = 2;

    int result = deQueue(&q2);
    if (result != -1) {
        printf("return value = %d;\n", result);
    }

    printf("queue = {\n");
    printf("   array = [");
    for (int i = 0; i <= q2.rear; i++) {
        printf("%d", q2.arr[i]);
        if (i < q2.rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q2.front);
    printf("   rear = %d,\n", q2.rear);
    printf("   capacity = %d\n", q2.capacity);
    printf("}\n");

    return 0;
}
