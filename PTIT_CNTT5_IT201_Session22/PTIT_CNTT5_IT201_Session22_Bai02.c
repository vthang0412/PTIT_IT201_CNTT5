#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

Node *adjacency[MAX];
int n;

Node *createAdjacency(int U,int V) {
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
    printf("Nhap so dinh: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adjacency[i] = NULL;
    }
    createAdjacency(0,1 );
    createAdjacency(0,2 );
    createAdjacency(1,2 );
    createAdjacency(3,2 );
    createAdjacency(1,3 );
    createAdjacency(3,4 );

    printf("\n");
    displayList();
}