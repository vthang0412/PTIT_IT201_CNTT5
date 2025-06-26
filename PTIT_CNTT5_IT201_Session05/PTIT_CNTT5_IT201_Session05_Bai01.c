#include <stdio.h>

void inTu1DenN(int n) {
    if (n==0) return;
    inTu1DenN(n-1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    inTu1DenN(n);
    return 0;
}