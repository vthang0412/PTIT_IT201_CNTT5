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

    int found = -1;
    for (int i = 0; i < n/2; i++) {
        if (arr[i] == arr[n-1-i]) {
            printf("Cap doi xung (%d,%d)",arr[i],arr[n-1-i]);
            found = i;
        }
    }
    if (found == -1) {
        printf("Khong tim thay cap doi xung");
    }
    return 0;
}