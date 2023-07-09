#include <stdio.h>

void findDuplicateElements(int arr[], int size) {
    int hash[100] = {0};  // Hash tablosu oluştur

    for (int i = 0; i < size; i++) {
        hash[arr[i]]++;  // Elemanları hash tablosunda takip et

        if (hash[arr[i]] > 1) {
            printf("%d tekrar eden bir elemandır.\n", arr[i]);
        }
    }
}

int main() {
    int numbers[] = {2, 5, 7, 2, 8, 7, 3, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    findDuplicateElements(numbers, size);

    return 0;
}
