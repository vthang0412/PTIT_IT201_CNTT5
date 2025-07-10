#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int maxSize;
} Queue;

Queue createQueue() {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.maxSize = MAX;
    return q;
}

int main() {
    Queue q = createQueue();
    printf("Da khoi tao hang doi rong:\n");
    printf("Front = %d\n", q.front);
    printf("Rear = %d\n", q.rear);
    printf("Max size = %d\n", q.maxSize);
    return 0;
}
