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

    int average = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
       if (arr[i] % 2 == 0) {
           average += arr[i];
           count++;
       }
    }
    if (count==0) {
        printf("mang ko co phan tu");
    }
    int trungbinh= (float)average / count;
    printf("Trung binh cong so chan la:%d",trungbinh);
    free(arr);
    return 0;
}