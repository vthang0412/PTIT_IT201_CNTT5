#include <stdio.h>

int tinhTong(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return n % 10 + tinhTong(n / 10);
}

int main() {
    int n;
    printf("nhap so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
        return 1;
    } else {
        int result = tinhTong(n);
        printf("Tong cac chu so cua %d la %d", n, result);
    }
    return 0;
}
