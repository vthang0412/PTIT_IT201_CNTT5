#include <stdio.h>
#include <stdlib.h>
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

int isEmptyQueue(Queue *q) {
    return q->front == q->rear;
}

void enQueue(Queue *q, Node *node) {
    if (q->rear < MAX)
        q->items[q->rear++] = node;
}

Node *deQueue(Queue *q) {
    if (!isEmptyQueue(q))
        return q->items[q->front++];
    return NULL;
}

Node *createNode(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int treeHeight(Node *root) {
    if (root == NULL) return -1;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    int height = -1;

    while (!isEmptyQueue(&q)) {
        int levelSize = q.rear - q.front;
        height++;
        for (int i = 0; i < levelSize; i++) {
            Node *cur = deQueue(&q);
            if (cur->left != NULL) enQueue(&q, cur->left);
            if (cur->right != NULL) enQueue(&q, cur->right);
        }
    }

    return height;
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Chieu cao cua cay la:%d\n", treeHeight(root));

    return 0;
}
