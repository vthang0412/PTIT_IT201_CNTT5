#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr = NULL;

    printf("Nhap so phan tu ban dau (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so phan tu muon them (m): ");
    scanf("%d", &m);
    if (m < 0 || (n + m) >= 1000) {
        printf("So phan tu them khong hop le!\n");
        free(arr);
        return 1;
    }

    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat lai bo nho that bai!\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        printf("Nhap phan tu moi thu %d: ", i + 1);
        scanf("%d", &arr[n + i]);
    }

    printf("Mang sau khi them:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
