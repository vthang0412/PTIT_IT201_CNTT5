#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
} queue;

queue initQueue() {
    queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}
