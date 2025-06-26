#include <stdio.h>

int main() {
    int n;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap vao tung phan tu cua mang: ");
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Nhap gia tri can tim:");
    scanf("%d", &target);

    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        printf("Gia tri %d xuat hien dau tien co chi so %d",target,found);
    }else {
        printf("Khong tim thay %d trong mang",target);
    }

    return 0;
}