#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXep(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] < 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 0) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    int n;
    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000) {
            printf("Gia tri khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n >= 1000);

    int arr[n];
    printf("Nhap cac phan tu (am, 0, duong):\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep: ");
    printArray(arr, n);

    sapXep(arr, n);

    printf("Mang sau khi sap xep (am -> 0 -> duong): ");
    printArray(arr, n);

    return 0;
}
