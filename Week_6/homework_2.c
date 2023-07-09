#include <stdio.h>
#include <string.h>

int IsPalindrome(char* word) {
    int length = strlen(word);
    int i;

    for (i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Palindrome
}

int main() {
    char word[100];

    printf("Kelimeyi girin: ");
    scanf("%s", word);

    if (IsPalindrome(word)) {
        printf("Bu kelime bir palindromdur.\n");
    } else {
        printf("Bu kelime bir palindrom değildir.\n");
    }

    return 0;
}
