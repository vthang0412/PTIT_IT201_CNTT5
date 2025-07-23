#include <stdio.h>

int MATRIX[3][3];

void initMatrix() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            MATRIX[i][j] = 0;
}

void addEdge(int start, int end) {
    if (start >= 0 && start < 3 && end >= 0 && end < 3) {
        MATRIX[start][end] = 1;
    }
}

void printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initMatrix();

    addEdge(1, 0);
    addEdge(1, 2);
    addEdge(2, 0);

    printMatrix();

    return 0;
}
