#include <stdio.h>

int tongTuAdenB(int a, int b) {
    if (a > b) return 0;
    return a + tongTuAdenB(a + 1, b);
}

int main() {
    int firstNumber,secondNumber;
    printf("Nhap so thu nhat:");
    scanf("%d", &firstNumber);
    printf("Nhap so thu hai:");
    scanf("%d", &secondNumber);

    if (firstNumber <= 0 || secondNumber <= 0) {
        printf("Vui long nhap hai so nguyen duong.\n");
        return 1;
    }

    int a,b;
    if (firstNumber < secondNumber) {
        a=firstNumber;
        b=secondNumber;
    }else {
        a=secondNumber;
        b=firstNumber;
    }

    int tong = tongTuAdenB(a,b);
    printf("Tong tu %d den %d la:%d",a,b,tong);
    return 0;
}