#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i;
    int *arr=NULL;
    do {
        printf("Nhap so phan tu 1-100:");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("So phan tu khong hop le (n > 0).\n");
        }
    }while (n <= 0 || n > 100);
    arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap phan tu %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Mang sau khi dao nguoc:");
    for (i = n-1; i >=0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}