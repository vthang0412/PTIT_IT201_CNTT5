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
    printf("Nhap phan tu can tim:");
    scanf("%d", &target);

    int lastIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            lastIndex = i;
        }
    }

    if (lastIndex != -1) {
        printf("Chi so cuoi cung cua gia tri %d trong mang la: %d\n", target, lastIndex);
    } else {
        printf("Khong tim thay gia tri %d trong mang.\n", target);
    }

    return 0;
}