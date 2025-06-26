#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr=NULL;
    int n,i,soBatKy;
    do {
        printf("Nhap so phan tu 1-100:");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("So phan tu khong hop le (n > 0).\n");
        }
    }while (n <= 0 || n > 100);

    arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("So phan tu khong hop le (n > 0).\n");
        return 1;
    }
    for (i=0; i<n; i++) {
        printf("Nhap phan tu %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Nhap so nguyen bat ky:");
    scanf("%d", &soBatKy);

    int check=0;
    for (i=0; i<n; i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i] + arr[j] == soBatKy) {
                check=1;
                printf("%d,%d",arr[i],arr[j]);
            }
        }
    }
    if (!check) {
        printf("Khong tim thay so vua nhap");
    }
    free(arr);
    return 0;
}