#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isupper(message[i]))
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        else if (islower(message[i]))
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
    }
}

void decrypt(char message[], int key) {
    encrypt(message, -key);
}

int main() {
    char message[256]; 
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key: ");
    scanf("%d", &key); 

    printf("Original Message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
