#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int max = findMax(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}

int findMin(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int min = findMin(arr, n - 1);
    return (arr[n - 1] < min) ? arr[n - 1] : min;
}

int main(void) {
    int n;
    printf("Nhap so nguyen bat ky:");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le");
        return 1;
    }
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Cap nhat bo nho that bai");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    int maxVal = findMax(arr, n);
    int minVal = findMin(arr, n);

    printf("Gia tri nho nhat:%d\n", minVal);
    printf("Gia tri lon nhat:%d", maxVal);
    free(arr);
    return 0;
}
