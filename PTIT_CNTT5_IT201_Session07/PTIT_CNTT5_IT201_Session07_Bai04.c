#include <stdio.h>
#include <string.h>

void sapxepAZ(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[1000];
    do {
        printf("Nhap mot chuoi:");
        fgets(str, sizeof(str),stdin);
        str[strcspn(str, "\n")] = '\0';
        if (strlen(str) == 0) {
            printf("Chuoi ko duoc de trong");
        }
    } while (strlen(str) == 0);
    int n = strlen(str);
    sapxepAZ(str, n);
    printf("Chuoi sau khi sap xep A - Z la: %s",str);
    return 0;
}
