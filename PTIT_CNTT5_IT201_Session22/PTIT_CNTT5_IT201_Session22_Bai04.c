#include <stdio.h>

#define MAX 100

int MATRIX[MAX][MAX];
int n;

void inputVertexCount() {
    do {
        printf("Nhap so dinh (0 < n < 100): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 100) {
            printf("So dinh khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n >= 100);
}

void inputAdjacencyMatrix() {
    printf("Nhap ma tran ke (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &MATRIX[i][j]);
        }
    }
}

int countEdges() {
    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (MATRIX[i][j] == 1) {
                edgeCount++;
            }
        }
    }
    return edgeCount;
}

void printMatrix() {
    printf("Ma tran ke vua nhap:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inputVertexCount();
    inputAdjacencyMatrix();
    printMatrix();

    int totalEdges = countEdges();
    printf("So canh cua do thi vo huong: %d\n", totalEdges);

    return 0;
}
