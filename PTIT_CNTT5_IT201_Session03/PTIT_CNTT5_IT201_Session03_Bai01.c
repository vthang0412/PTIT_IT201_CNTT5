#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i;
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
        printf("Loi");
    }
    printf("Nhap %d so phan tu n:",n);
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (i=0; i<n; i++) {
        printf("So thu %d = %d \n",i+1, arr[i]);
    }
    free(arr);
    return 0;
}