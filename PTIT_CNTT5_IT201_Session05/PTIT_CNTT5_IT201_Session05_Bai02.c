#include <stdio.h>

int tongTu1DenN(int n) {
    if (n==0) return 0;
    return n + tongTu1DenN(n-1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int sum= tongTu1DenN(n);
    printf("Tong tu 1 den %d la:%d",n, sum);
    return 0;
}