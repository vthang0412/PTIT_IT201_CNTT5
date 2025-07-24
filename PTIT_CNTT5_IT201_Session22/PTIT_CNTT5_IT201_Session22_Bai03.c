//
// Created by Admin on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int MATRIX[MAX][MAX];
int n;

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *addEdge(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void matrix() {
   do {
       printf("Nhap so luong dinh:");
       scanf("%d",&n);
   }while (n<=0 || n>=100);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            MATRIX[i][j] = 0;
        }
    }
}

void displayMatrix() {
    printf("Ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",MATRIX[i][j]);
        }
        printf("\n");
    }
}

Node *adjacency[MAX];

void adjacencyMatrix(int U,int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;

    Node *newNode = addEdge(V);
    newNode->next = adjacency[U];
    adjacency[U] = newNode;

    newNode = addEdge(U);
    newNode->next = adjacency[V];
    adjacency[V] = newNode;
}
void displayList() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node *temp = adjacency[i];
        while (temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    matrix();
    for (int i = 0; i < n; i++) {
        adjacency[i] = NULL;
    }
    adjacencyMatrix(0,1 );
    adjacencyMatrix(0,2 );
    adjacencyMatrix(1,2 );
    adjacencyMatrix(3,2 );
    adjacencyMatrix(1,3 );
    adjacencyMatrix(3,4 );

    printf("\n");
    displayMatrix();
    printf("\n");
    displayList();

}