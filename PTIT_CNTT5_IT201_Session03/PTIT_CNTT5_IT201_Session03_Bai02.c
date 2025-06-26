#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    do {
        printf("Nhap so phan tu n:");
        scanf("%d", &n);
        if (n<=0 || n>100) {
            printf("So phan tu khong hop le(0-100).Nhap lai! \n");
        }
    }while (n<=0 || n>100);
    arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Loi \n");
    }
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int max=arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    printf("So lon nhat trong mang vua nhap la:%d",max);
    free(arr);
    return 0;
}