#include <stdio.h>
#include <string.h>

int main() {
    struct SinhVien {
        int id;
        char name[50];
        int age;
    };
    struct SinhVien sinhvien[3];
    for (int i = 0; i < 3; i++) {
        printf("Nhap id:");
        scanf("%d", &sinhvien[i].id);
        getchar();
        printf("Nhap name:");
        fgets(sinhvien[i].name, 50, stdin);
        sinhvien[i].name[strlen(sinhvien[i].name) - 1] = '\0';
        printf("Nhap age:");
        scanf("%d", &sinhvien[i].age);
    }
    int id;
    printf("Nhap id can tim kiem:");
    scanf("%d", &id);
    for (int i = 0; i < 3; i++) {
        if (sinhvien[i].id == id) {
            printf("Id:%d\n Name:%s\n Age:%d",sinhvien[i].id,sinhvien[i].name,sinhvien[i].age);
            return 0;
        }
    }
    printf("Khong tim thay");
    return 0;
}
