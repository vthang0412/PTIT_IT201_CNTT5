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

    int min = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    printf("Phan tu nho nhat dau tien trong mang la:%d",index);
    return 0;
}