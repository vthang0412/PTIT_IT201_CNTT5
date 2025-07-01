#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    do {
        printf("Nhap so luong phan tu cua mang:");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000) {
            printf("So luong phan tu khong hop le");
        }
    } while (n <= 0 || n >= 1000);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Nhap phan tu can tim:");
    scanf("%d", &target);

    int found = linearSearch(arr, n, target);
    if (found != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d", target, found);
    } else {
        printf("Phan tu %d khong ton tai", target);
    }
}
