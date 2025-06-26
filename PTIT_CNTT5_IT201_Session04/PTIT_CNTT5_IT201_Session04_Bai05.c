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
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int target;
    printf("Nhap phan tu can tim:");
    scanf("%d", &target);

    int left = 0, right = n - 1;
    int found = -1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            found = mid;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d trong mang da sap xep.\n", target, found);
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", target);
    }


    return 0;
}