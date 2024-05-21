#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// encrypt the message using Caesar Cipher
void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        // Encrypt uppercase letters
        if (isupper(message[i]))
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        // Encrypt lowercase letters
        else if (islower(message[i]))
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
    }
}

// decrypt the message using Caesar Cipher
void decrypt(char message[], int key) {
    // To decrypt, we just use the negative of the key
    encrypt(message, -key);
}

int main() {
    char message[] = "hello how are u";
    int key = 3; // Shift key for Caesar Cipher

    printf("Original Message: %s\n", message);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
