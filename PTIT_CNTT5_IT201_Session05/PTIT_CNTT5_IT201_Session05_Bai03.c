#include <stdio.h>

int giaithua(int n) {
    if (n==0 || n==1) return 1;
    return n * giaithua(n-1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n<0) {
        printf("Khong hop le");
    }else {
        int gt= giaithua(n);
        printf("%d! = %d",n,gt);
    }
    return 0;
}