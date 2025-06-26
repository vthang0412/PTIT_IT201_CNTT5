#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr=NULL;
    int n,i,pos;
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

    printf("Nhap phan tu vi tri muon xoa (0-%d):",n-1);
    scanf("%d", &pos);

    if (pos<0 || pos>n) {
        printf("Vi tri khong hop le");
        return 1;
    }
    for (i=pos; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    printf("Mang sau khi xoa:\n");
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}