#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct {
    Node *items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = queue->rear = 0;
}

bool isEmptyQueue(Queue *queue) {
    return (queue->front == queue->rear);
}

bool isFullQueue(Queue *queue) {
    return (queue->rear == MAX);
}

void enQueue(Queue *queue, Node *node) {
    if (isFullQueue(queue)) return;
    queue->items[queue->rear++] = node;
}

Node *deQueue(Queue *queue) {
    if (isEmptyQueue(queue)) return NULL;
    return queue->items[queue->front++];
}

bool bfsSearch(Node *root, int target) {
    if (root == NULL) return false;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while (!isEmptyQueue(&q)) {
        Node *cur = deQueue(&q);
        if (cur->data == target) {
            return true;
        }
        if (cur->left != NULL) {
            enQueue(&q, cur->left);
        }
        if (cur->right != NULL) {
            enQueue(&q, cur->right);
        }
    }
    return false;
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    if (bfsSearch(root, x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
