#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr=NULL;
    int n,i,pos,newVal;
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
    printf("Nhap vi tri muon them (0-%d):",n);
    scanf("%d", &pos);
    printf("Nhap gia tri muon them:");
    scanf("%d", &newVal);
    if (pos<0 || pos>n) {
        printf("Vi tri ko hop le");
        free(arr);
        return 1;
    }
    for (i=n-1; i>=pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = newVal;
    n++;
    printf("Mang sau khi them:");
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}