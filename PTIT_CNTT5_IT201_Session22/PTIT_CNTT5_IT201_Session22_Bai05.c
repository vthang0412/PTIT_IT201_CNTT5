#include <stdio.h>
#define MAX 100

int MATRIX[MAX][MAX];
int n, v;

void inputVertexAndEdges() {
    do {
        printf("Nhap so dinh (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);

    do {
        printf("Nhap so canh (0 < v < 100): ");
        scanf("%d", &v);
    } while (v <= 0 || v >= 100);
}

void inputEdges() {
    int u, w;
    printf("Nhap %d canh (0 1):\n", v);
    for (int i = 0; i < v; i++) {
        scanf("%d %d", &u, &w);
        MATRIX[u][w] = 1;
        MATRIX[w][u] = 1;
    }
}

int countAdjacentVertices(int k) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        if (MATRIX[k][j] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    inputVertexAndEdges();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            MATRIX[i][j] = 0;
        }
    }
    inputEdges();

    int k;
    do {
        printf("Nhap dinh k (0 <= k < %d) de dem so dinh lien ke: ", n);
        scanf("%d", &k);
    } while (k < 0 || k >= n);

    int result = countAdjacentVertices(k);
    printf("\nSo dinh lien ke voi dinh %d la: %d\n", k, result);

    return 0;
}
