#include <stdio.h>

int insertionSort(int arr[], int n) {
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

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    insertionSort(arr, n);

    int target;
    printf("Nhap phan tu can tim:");
    scanf("%d", &target);

    int found = binarySearch(arr, 0, n - 1, target);
    if (found != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d", target, found);
    } else {
        printf("Phan tu %d khong ton tai", target);
    }
}
