#include <stdio.h>

int main() {
    FILE *file;
    char text[100];

    // Dosyayı yazma modunda aç
    file = fopen("metin.txt", "w");

    if (file == NULL) {
        printf("Dosya oluşturulamadı.");
        return 1;
    }

    printf("Bir metin girin: ");
    fgets(text, sizeof(text), stdin);

    // Metni dosyaya yaz
    fprintf(file, "%s", text);

    // Dosyayı kapat
    fclose(file);

    // Dosyayı okuma modunda aç
    file = fopen("metin.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı.");
        return 1;
    }

    // Metni oku ve ekrana yazdır
    printf("Dosyadan okunan metin: ");
    fgets(text, sizeof(text), file);
    printf("%s", text);

    // Dosyayı kapat
    fclose(file);

    return 0;
}
