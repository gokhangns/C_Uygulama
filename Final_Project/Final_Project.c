#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    char name[50];
    int accountNumber;
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void registerAccount() {
    if (accountCount == MAX_ACCOUNTS) {
        printf("Maksimum hesap sayısına ulaşıldı.\n");
        return;
    }

    struct Account newAccount;

    printf("İsim: ");
    scanf("%s", newAccount.name);

    printf("Hesap Numarası: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Başlangıç Bakiyesi: ");
    scanf("%f", &newAccount.balance);

    accounts[accountCount++] = newAccount;

    printf("Hesap başarıyla oluşturuldu.\n");
}

void login() {
    int accountNumber;
    int found = 0;
    int index;

    printf("Hesap Numarası: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        float balance = accounts[index].balance;

        while (1) {
            int choice;
            float amount;

            printf("\n1. Bakiyeyi Görüntüle\n");
            printf("2. Para Yatır\n");
            printf("3. Para Çek\n");
            printf("4. Çıkış\n");
            printf("Seçiminizi yapın: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Bakiye: %.2f\n", balance);
                    break;
                case 2:
                    printf("Yatırılacak Miktar: ");
                    scanf("%f", &amount);
                    balance += amount;
                    printf("Yeni Bakiye: %.2f\n", balance);
                    break;
                case 3:
                    printf("Çekilecek Miktar: ");
                    scanf("%f", &amount);
                    if (amount > balance) {
                        printf("Yetersiz bakiye.\n");
                    } else {
                        balance -= amount;
                        printf("Yeni Bakiye: %.2f\n", balance);
                    }
                    break;
                case 4:
                    accounts[index].balance = balance;
                    printf("Çıkış yapılıyor...\n");
                    return;
                default:
                    printf("Geçersiz seçim. Tekrar deneyin.\n");
            }
        }
    } else {
        printf("Hesap bulunamadı. Lütfen geçerli bir hesap numarası girin.\n");
    }
}

void saveAccountsToFile() {
    FILE* file = fopen("accounts.txt", "w");

    if (file == NULL) {
        printf("Dosya oluşturulamadı.\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%s %d %.2f\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }

    fclose(file);

    printf("Hesaplar başarıyla dosyaya kaydedildi.\n");
}

void loadAccountsFromFile() {
    FILE* file = fopen("accounts.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı.\n");
        return;
    }

    while (!feof(file)) {
        struct Account loadedAccount;

        if (fscanf(file, "%s %d %f\n", loadedAccount.name, &loadedAccount.accountNumber, &loadedAccount.balance) == 3) {
            accounts[accountCount++] = loadedAccount;
        }
    }

    fclose(file);

    printf("Hesaplar başarıyla dosyadan yüklendi.\n");
}

void displayMenu() {
    printf("\n----- Banka Hesap Yönetimi Sistemi -----\n");
    printf("1. Hesap Oluştur\n");
    printf("2. Giriş Yap\n");
    printf("3. Hesapları Dosyaya Kaydet\n");
    printf("4. Hesapları Dosyadan Yükle\n");
    printf("5. Çıkış\n");
    printf("----------------------------------------\n");
    printf("Seçiminizi yapın: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                saveAccountsToFile();
                break;
            case 4:
                loadAccountsFromFile();
                break;
            case 5:
                printf("Programdan çıkılıyor...\n");
                return 0;
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    }

    return 0;
}
