#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P 23 // Prime number
#define G 5  // Primitive root modulo

int mod_exp(int base, int exp, int modulus)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

// Function to perform Diffie-Hellman Key Exchange
void diffie_hellman(int private_key, int *public_key)
{
    *public_key = mod_exp(G, private_key, P);
}

int main()
{
    int private_key_client, private_key_server;
    int public_key_client, public_key_server;
    int shared_secret_client, shared_secret_server;

    printf("Enter private key for client: ");
    scanf("%d", &private_key_client);

    if (private_key_client < 1 || private_key_client >= P)
    {
        printf("Invalid private key for client. It must be in the range [1, %d).\n", P);
        return 1;
    }

    printf("Enter private key for server: ");
    scanf("%d", &private_key_server);

    if (private_key_server < 1 || private_key_server >= P)
    {
        printf("Invalid private key for server. It must be in the range [1, %d).\n", P);
        return 1;
    }

    diffie_hellman(private_key_client, &public_key_client);

    diffie_hellman(private_key_server, &public_key_server);

    shared_secret_client = mod_exp(public_key_server, private_key_client, P);
    shared_secret_server = mod_exp(public_key_client, private_key_server, P);

    printf("Client shared secret: %d\n", shared_secret_client);
    printf("Server shared secret: %d\n", shared_secret_server);

    return 0;
}
