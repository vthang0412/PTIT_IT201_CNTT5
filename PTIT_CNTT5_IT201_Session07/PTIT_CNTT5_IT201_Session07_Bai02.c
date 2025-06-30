#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    do {
        printf("Nhap so luong phan tu:");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000) {
            printf("Phan tu khong hop le");
        }
    } while (n <= 0 || n >= 1000);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
