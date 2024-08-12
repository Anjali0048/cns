#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
void encrypt(char plaintext[], char key[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i]))
                plaintext[i] = key[plaintext[i] - 'A'];
            else if (islower(plaintext[i]))
                plaintext[i] = tolower(key[plaintext[i] - 'a']);
        }
    }
}

void decrypt(char ciphertext[], char key[]) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i]))
                ciphertext[i] = 'A' + (strchr(key, ciphertext[i]) - key);
            else if (islower(ciphertext[i]))
                ciphertext[i] = 'a' + (strchr(key, tolower(ciphertext[i])) - key);
        }
    }
}

int main() {
    // char plaintext[] = "EARTH WORLD";
    // char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    char plaintext[256];
    char key[27];
    char ciphertext[256];

    printf("Enter the plaintext (uppercase letters and spaces only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    // Encrypt the plaintext
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key);
    printf("Decrypted Plaintext: %s\n", ciphertext);

    return 0;
}
