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

void createNode(queue *q, int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void display(queue q) {
    printf("queue = {\n  front->");
    node *temp = q.front;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n  rear->");
    if (q.rear != NULL)
        printf("%d->NULL\n", q.rear->data);
    else
        printf("NULL\n");
    printf("}\n\n");
}

void peekFront(queue q) {
    if (q.front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", q.front->data);
    }
}

int main() {
    queue q;
    q.front = q.rear = NULL;
    int n, x;

    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        createNode(&q, x);
    }

    display(q);
    peekFront(q);

    return 0;
}
