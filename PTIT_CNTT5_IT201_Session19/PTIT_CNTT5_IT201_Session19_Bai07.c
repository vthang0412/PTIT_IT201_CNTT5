#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool isEmptyQueue(Queue *q) {
    return q->front == q->rear;
}

bool isFullQueue(Queue *q) {
    return q->rear == MAX;
}

void enQueue(Queue *q, Node *node) {
    if (isFullQueue(q)) return;
    q->items[q->rear++] = node;
}

Node *deQueue(Queue *q) {
    if (isEmptyQueue(q)) return NULL;
    return q->items[q->front++];
}

Node *createNode(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node != NULL) {
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void insertNode(Node *root, int value) {
    if (root == NULL) return;

    Node *newNode = createNode(value);
    if (newNode == NULL) return;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while (!isEmptyQueue(&q)) {
        Node *cur = deQueue(&q);

        if (cur->left == NULL) {
            cur->left = newNode;
            return;
        } else {
            enQueue(&q, cur->left);
        }

        if (cur->right == NULL) {
            cur->right = newNode;
            return;
        } else {
            enQueue(&q, cur->right);
        }
    }
}

void levelOrder(Node *root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while (!isEmptyQueue(&q)) {
        Node *cur = deQueue(&q);
        printf("%d ", cur->data);
        if (cur->left != NULL) {
            enQueue(&q, cur->left);
        }
        if (cur->right != NULL) {
            enQueue(&q, cur->right);
        }
    }
}

int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Cay truoc khi them: ");
    levelOrder(root);

    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printf("\nCay sau khi them: ");
    levelOrder(root);

    return 0;
}
