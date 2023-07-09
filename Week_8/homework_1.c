#include <stdio.h>

int findMaxNumber(int arr[], int size) {
    int max = arr[0];  // Başlangıçta en büyük sayıyı ilk eleman olarak varsayalım

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // Daha büyük bir sayı bulunduğunda max değerini güncelle
        }
    }

    return max;
}

int main() {
    int numbers[] = {5, 2, 9, 1, 7, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int maxNumber = findMaxNumber(numbers, size);

    printf("Dizideki en büyük sayı: %d\n", maxNumber);

    return 0;
}
