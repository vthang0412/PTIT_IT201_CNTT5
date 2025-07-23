#include <stdio.h>

int MATRIX[4][4];

void matrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            MATRIX[i][j] = 0;
        }
    }
}

void adjacency(int U, int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;
}

void displayMatrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    matrix();
    adjacency(0, 1);
    adjacency(0, 2);
    adjacency(1, 2);
    adjacency(2, 3);
    displayMatrix();
    return 0;
}
