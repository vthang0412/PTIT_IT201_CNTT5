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

    printf("Nhap phan tu vi tri muon sua (0-%d):",n-1);
    scanf("%d", &pos);

    if (pos<0 || pos>n) {
        printf("Vi tri khong hop le");
        return 1;
    }
    printf("Nhap vi tri moi tai vi tri %d la : ",pos);
    scanf("%d",&newVal);

    arr[pos]=newVal;
    printf("Mang sau khi cap nhat:");
    for (i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}