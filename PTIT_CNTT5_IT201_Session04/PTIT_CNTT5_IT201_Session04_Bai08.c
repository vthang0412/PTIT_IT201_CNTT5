#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d:", i+1);
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Nhap so can tim:");
    scanf("%d", &target);

    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Gia tri %d xuat hien tai vi tri la:%d\n  ",target,i);
            found = i;
        }
    }
    if (found != -1) {
        printf("Khong tim thay phan tu trong mang");
    }
    printf("\n");
    return 0;
}