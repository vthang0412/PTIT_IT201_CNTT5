#include <stdio.h>

int soCach(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return soCach(n - 1) + soCach(n - 2);
}

int main() {
    int n;
    printf("Nhap so bac cua cau thang:");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le");
        return 1;
    }
    int check = soCach(n);
    printf("Cau thang co %d thi co %d cach", n, check);
    return 0;
}
