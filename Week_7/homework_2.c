#include <stdio.h>

int main() {
    int num1, num2;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    printf("Birinci sayıyı girin: ");
    scanf("%d", ptr1);

    printf("İkinci sayıyı girin: ");
    scanf("%d", ptr2);

    printf("Birinci sayı: %d\n", *ptr1);
    printf("İkinci sayı: %d\n", *ptr2);

    return 0;
}
