//
// Created by Admin on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n;
int MATRIX[MAX][MAX];
void matrix() {
    printf("Nhap so luong dinh:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
void adjacencyMatrix(int U,int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;
}
void displayMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",MATRIX[i][j]);
        }
        printf("\n");
    }
}
int main() {
    matrix();

    adjacencyMatrix(0,1 );
    adjacencyMatrix(0,2 );
    adjacencyMatrix(1,2 );
    adjacencyMatrix(3,2 );
    adjacencyMatrix(1,3 );
    adjacencyMatrix(3,4 );

    printf("\n");
    displayMatrix();
    return 0;
}
