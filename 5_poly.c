#include <stdio.h>
#include <string.h>

// Function to perform encryption using Polyalphabetic Cipher
void encrypt(char plaintext[], char key[]) {
    int keyLen = strlen(key);
    int plaintextLen = strlen(plaintext);
    char ciphertext[plaintextLen + 1];
    
    for (int i = 0; i < plaintextLen; i++) {
        // Shift the plaintext character by the corresponding key character
        ciphertext[i] = ((plaintext[i] + key[i % keyLen] - 2 * 'a') % 26) + 'a';
    }
    ciphertext[plaintextLen] = '\0'; // Add null terminator
    printf("Encrypted message: %s\n", ciphertext);
}

// Function to perform decryption using Polyalphabetic Cipher
void decrypt(char ciphertext[], char key[]) {
    int keyLen = strlen(key);
    int ciphertextLen = strlen(ciphertext);
    char plaintext[ciphertextLen + 1];
    
    for (int i = 0; i < ciphertextLen; i++) {
        // Shift the ciphertext character back by the corresponding key character
        plaintext[i] = ((ciphertext[i] - key[i % keyLen] + 26) % 26) + 'a';
    }
    plaintext[ciphertextLen] = '\0'; // Add null terminator
    printf("Decrypted message: %s\n", plaintext);
}

int main() {
    char key[100], plaintext[100], ciphertext[100];

    // Take key and plaintext input from the user
    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    
    // Encrypt the plaintext
    encrypt(plaintext, key);
    
    // Take ciphertext input from the user for decryption
    printf("Enter the ciphertext to decrypt: ");
    scanf("%s", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key);
    
    return 0;
}
