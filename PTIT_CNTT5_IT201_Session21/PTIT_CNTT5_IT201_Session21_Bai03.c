//
// Created by Admin on 7/23/2025.
//
#include <stdio.h>
#include <stdlib.h>
int MATRIX[3][3];
typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *creatNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void initMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
void addEdge(int start, int end) {
    if (start >= 0 && start < 3 && end >= 0 && end < 3) {
        MATRIX[start][end] = 1;
    }
}
void printMatrix() {
    printf("Ma tran ke:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initMatrix();

    int startNode = 1;
    int endNode = 2;

    addEdge(startNode, endNode);
    printMatrix();

    return 0;
}
