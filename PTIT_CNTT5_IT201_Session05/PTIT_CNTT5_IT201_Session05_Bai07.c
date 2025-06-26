#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
        return 1;
    }

    int result[n];
    int first = 1;
    for (int i = 0; i < n; i++) {
        result[i] = fibonacci(i);
        if (!first) printf(", ");
        printf("%d", result[i]);
        first = 0;
    }

    printf("\n");
    return 0;
}
