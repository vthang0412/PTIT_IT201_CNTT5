#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
