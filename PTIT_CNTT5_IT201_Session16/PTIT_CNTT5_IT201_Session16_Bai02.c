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

void addReady(queue *q, int value) {
    node *newnode = (node *) malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

queue initQueue() {
    queue q;
    q.front = q.rear = NULL;
    addReady(&q, 1);
    addReady(&q, 2);
    addReady(&q, 5);
    return q;
}

node *createNode() {
    int value;
    printf("Nhap so nguyen: ");
    scanf("%d", &value);
    node *newnode = (node *) malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void enQueue(queue *q) {
    node *newnode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

void display(queue q) {
    printf("Queue = {\n  front->");
    node *temp = q.front;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n  rear->");
    if (q.rear != NULL) {
        printf("%d->NULL\n", q.rear->data);
    } else {
        printf("NULL\n");
    }
    printf("}\n");
}

int main() {
    queue q = initQueue();
    display(q);

    int n;
    printf("Nhap so lan them phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        enQueue(&q);
        display(q);
    }
    return 0;
}
