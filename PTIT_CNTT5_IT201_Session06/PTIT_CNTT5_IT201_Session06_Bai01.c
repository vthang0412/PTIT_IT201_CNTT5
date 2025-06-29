#include <stdio.h>

int tinhNhiPhan(int n) {
    if (n == 0) return 0;
    return n % 2 + 10 * tinhNhiPhan((n / 2));
}

int main() {
    int n;
    printf("Nhap so bat ky:");
    scanf("%d", &n);

    if (n <= 0) {
    } else {
        printf("Nhi phan cua %d la: %d", n, tinhNhiPhan(n));
    }
    return 0;
}
