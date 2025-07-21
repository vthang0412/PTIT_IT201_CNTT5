//
// Created by Admin on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode() {
    int x;
    printf("Nhap gia tri cho node:");
    scanf("%d", &x);
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int main() {
    Node *root = createNode();
    if (root == NULL) {
        printf("Cap phat bo nho that bai");
        return 1;
    }
    printf("Data:%d\n", root->data);
    printf("Left:%s\n ", root->left == NULL ? "NULL" : "not NULL");
    printf("Right:%s\n ", root->right == NULL ? "NULL" : "not NULL");
    free(root);
    return 0;
}
