#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void generate_aes_key(unsigned char *key, int key_length) {
    FILE *urandom = fopen("/dev/urandom", "r");
    fread(key, 1, key_length, urandom);
    fclose(urandom);
}

void aes_encrypt(unsigned char *plaintext, unsigned char *ciphertext, unsigned char *key) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_encrypt(plaintext, ciphertext, &aes_key);
}

void aes_decrypt(unsigned char *ciphertext, unsigned char *decryptedtext, unsigned char *key) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_decrypt(ciphertext, decryptedtext, &aes_key);
}

int main() {
    unsigned char plaintext[100];
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char ciphertext[AES_BLOCK_SIZE];
    unsigned char decryptedtext[AES_BLOCK_SIZE];

    generate_aes_key(key, AES_BLOCK_SIZE);

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    aes_encrypt(plaintext, ciphertext, key);

    aes_decrypt(ciphertext, decryptedtext, key);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}