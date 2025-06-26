#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,x;
    int *arr;
    do {
        printf("Nhap so phan tu n:");
        scanf("%d", &n);
        if (n<=0 || n > 100) {
            printf("So phan tu khong hop le (n > 0).\n");
        }
    }while (n<=0 || n > 100);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Nhap phan tu khong hop le.\n");
        return 1;
    }

    printf("Nhap %d phan tu:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Nhap so can dem:");
    scanf("%d", &x);

    int count=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    printf("So %d xuat hien %d lan", x,count);
    free(arr);
    return 0;
}