//
// Created by Admin on 6/26/2025.
//
#include <stdio.h>

int tinhTong(int arr[],int index) {
    if (index < 0) {
        return 0;
    }
    return  arr[index] + tinhTong(arr,index-1);
}

int main() {
    int n;
    printf("Nhap so phan tu:");
    scanf("%d", &n);
    if (n<0) {
        printf("So luong phan tu phai lon hon 1");
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("Nhap phan tu arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int tong = tinhTong(arr,n-1);
    printf("Tong la:%d",tong);
    return 0;

}