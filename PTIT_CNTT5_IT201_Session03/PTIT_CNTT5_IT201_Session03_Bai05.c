#include <stdio.h>
#include <stdlib.h>

int tongCheoChinh(int **arr,int n,int m);
int tongCheoPhu(int **arr,int n,int m);

int main() {
    int n,m;
    int **arr;
    do {
        printf("Nhap so hang cua mang:");
        scanf("%d",&n);
        printf("Nhap so cot cua mang:");
        scanf("%d",&m);
        if (n <= 0 || n > 100 || m <= 0 || m > 100) {
            printf("So phan tu khong hop le(0-100).Nhap lai! \n");
        }
    }while (n <= 0 || n > 100 || m <= 0 || m > 100);
    arr =(int **)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(m*sizeof(int));
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            printf("arr[%d][%d] = ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    int tongChinh = tongCheoChinh(arr,n,m);
    int tongPhu = tongCheoPhu(arr,n,m);

    printf("Tong duong cheo chinh: %d\n", tongChinh);
    printf("Tong duong cheo phu: %d\n", tongPhu);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

int tongCheoChinh(int **arr,int n,int m) {
    int sum=0;
    int minDim;
    if (n < m) {
        minDim = n;
    } else {
        minDim = m;
    }
    for (int i=0;i<minDim;i++) {
        sum+=arr[i][i];
    }
    return sum;
}

int tongCheoPhu(int **arr,int n,int m) {
    int sum=0;
    int minDim;
    if (n < m) {
        minDim = n;
    } else {
        minDim = m;
    }
    for (int i=0;i<minDim;i++) {
        sum+=arr[i][m-1-i];
    }
    return sum;
}