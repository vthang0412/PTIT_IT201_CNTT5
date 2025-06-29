#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
        return 1;
    } else {
        int inNguoc;
        int check = 1;
        for (int i = n; i > 0; i--) {
            inNguoc = fibonacci(i);
            if (!check) printf(" ,");
            printf("%d", inNguoc);
            check = 0;
        }
    }
    return 0;
}
