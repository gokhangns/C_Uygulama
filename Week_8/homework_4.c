#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[100];
    struct Node* next;
};

void findWordsStartingWith(struct Node* head, char* prefix) {
    struct Node* current = head;

    while (current != NULL) {
        if (strncmp(current->word, prefix, strlen(prefix)) == 0) {
            printf("%s\n", current->word);
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->word, "apple");
    head->next = second;

    strcpy(second->word, "application");
    second->next = third;

    strcpy(third->word, "banana");
    third->next = NULL;

    char prefix[100];
    printf("Bir metin girin: ");
    scanf("%s", prefix);

    findWordsStartingWith(head, prefix);

    return 0;
}
