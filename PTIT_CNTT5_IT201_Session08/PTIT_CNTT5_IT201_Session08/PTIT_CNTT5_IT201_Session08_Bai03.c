#include <stdio.h>

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    do {
        printf("Nhap so luong phan tu:");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000) {
            printf("So luong khong hop le");
        }
    } while (n <= 0 || n >= 1000);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
