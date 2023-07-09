#include <stdio.h>

void SortIntArr(int* arr, int length) {
    int i, j, temp;

    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100];
    int length, i;

    printf("Dizinin uzunluğunu girin: ");
    scanf("%d", &length);

    printf("Dizinin elemanlarını girin:\n");
    for (i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    SortIntArr(arr, length);

    printf("Sıralanmış dizi: ");
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
