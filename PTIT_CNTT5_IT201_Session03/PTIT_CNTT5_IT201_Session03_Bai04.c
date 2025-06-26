#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n;
    int **arr;
    do {
        printf("Nhap vao so dong cua mang:");
        scanf("%d", &n);
        printf("Nhap vao so cot cua mang:");
        scanf("%d", &m);
        if (n <= 0 || n > 100 || m <= 0 || m > 100) {
            printf("So phan tu khong hop le(0-100).Nhap lai! \n");
        }
    }while (n <= 0 || n > 100 || m <= 0 || m > 100);

    arr = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m*sizeof(int));
    }
    if (arr == NULL) {
        printf("Loi \n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int max = arr[0][0];
    int min = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }

    printf("\nGia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    free(arr);
    return 0;
}