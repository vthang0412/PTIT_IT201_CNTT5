#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Cấu trúc danh sách kề
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjacency[MAX];
int visited[MAX];
int v, e;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int w) {
    Node* nodeW = createNode(w);
    nodeW->next = adjacency[u];
    adjacency[u] = nodeW;

    Node* nodeU = createNode(u);
    nodeU->next = adjacency[w];
    adjacency[w] = nodeU;
}

void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjacency[start];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    do {
        printf("Nhap so dinh (0 < v < 100): ");
        scanf("%d", &v);
    } while (v <= 0 || v >= 100);

    do {
        printf("Nhap so canh (0 < e < 100): ");
        scanf("%d", &e);
    } while (e <= 0 || e >= 100);

    for (int i = 0; i < v; i++) {
        adjacency[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap danh sach %d canh (0 1):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    int start;
    do {
        printf("Nhap dinh bat dau DFS (0 <= start < %d): ", v);
        scanf("%d", &start);
    } while (start < 0 || start >= v);

    printf("DFS bat dau tu dinh %d:\n", start);
    DFS(start);
    printf("\n");

    return 0;
}
