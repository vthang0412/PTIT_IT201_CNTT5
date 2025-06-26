#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr=NULL;
    int n,i;
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
    printf("Cac phan tu lon hon tat ca cac phan tu dung sau:\n");
    for (i=0; i<n; i++) {
        int lonHon =1;
        for (int j=i+1;j<n;j++) {
            if (arr[i] <= arr[j]) {
                lonHon = 0;
                break;
            }
        }
        if (lonHon) {
            printf("%d,", arr[i]);
        }
    }
    printf("\n");
    free(arr);
    return 0;
}