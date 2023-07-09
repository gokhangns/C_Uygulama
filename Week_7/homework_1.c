#include <stdio.h>

unsigned long long int Factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

int main() {
    int number;

    printf("Bir sayı girin: ");
    scanf("%d", &number);

    unsigned long long int result = Factorial(number);

    printf("%d sayısının faktöriyeli: %llu\n", number, result);

    return 0;
}
