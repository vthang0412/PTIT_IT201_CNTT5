#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void countLeavesRef(Node *root, int *count) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        (*count)++;
    }
    countLeavesRef(root->left, count);
    countLeavesRef(root->right, count);
}


int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Duyet cay: ");
    inorder(root);
    int leafCount = 0;
    countLeavesRef(root, &leafCount);
    printf("So nut la trong cay: %d\n", leafCount);

    printf("\n");

    return 0;
}
