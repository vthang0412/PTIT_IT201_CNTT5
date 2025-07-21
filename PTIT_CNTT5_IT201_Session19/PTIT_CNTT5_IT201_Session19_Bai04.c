#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inrorder(Node *root) {
    if (root != NULL) {
        inrorder(root->left);
        printf("%d ", root->data);
        inrorder(root->right);
    }
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Inorder Traversal:\n");
    inrorder(root);
    return 0;
}