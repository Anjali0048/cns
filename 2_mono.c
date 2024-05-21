#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
// Function to encrypt the message using a monoalphabetic cipher
void encrypt(char plaintext[], char key[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            // Convert uppercase letters to corresponding key letters
            if (isupper(plaintext[i]))
                plaintext[i] = key[plaintext[i] - 'A'];
            // Convert lowercase letters to corresponding key letters
            else if (islower(plaintext[i]))
                plaintext[i] = tolower(key[plaintext[i] - 'a']);
        }
    }
}

// Function to decrypt the message using a monoalphabetic cipher
void decrypt(char ciphertext[], char key[]) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            // Find the index of the character in the key and convert it to its corresponding letter
            if (isupper(ciphertext[i]))
                ciphertext[i] = 'A' + (strchr(key, ciphertext[i]) - key);
            else if (islower(ciphertext[i]))
                ciphertext[i] = 'a' + (strchr(key, tolower(ciphertext[i])) - key);
        }
    }
}

int main() {
    char plaintext[] = "EARTH WORLD";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char ciphertext[strlen(plaintext) + 1];

    printf("Original Plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    strcpy(ciphertext, plaintext); // Make a copy of the plaintext
    encrypt(ciphertext, key);
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key);
    printf("Decrypted Plaintext: %s\n", ciphertext);

    return 0;
}
