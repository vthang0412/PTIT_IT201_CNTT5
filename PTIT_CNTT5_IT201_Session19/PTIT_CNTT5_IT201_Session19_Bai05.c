#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool dfsSearch(Node *root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->data == target) {
        return true;
    }
    if (dfsSearch(root->left, target)) {
        return true;
    }
    if (dfsSearch(root->right, target)) {
        return true;
    }
    return false;
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    if (dfsSearch(root, value)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
