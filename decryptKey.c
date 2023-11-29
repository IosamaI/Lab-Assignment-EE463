#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to print a BIGNUM value in hexadecimal format
void printBN(char *msg, BIGNUM *tmp){
    char *number_str = BN_bn2hex(tmp);
    printf("%s%s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main(int argc, char *argv[]){
    // Initialize context for OpenSSL functions
    BN_CTX *ctx = BN_CTX_new();

    // Initialize BIGNUM variables for RSA key components and messages
    BIGNUM *e = BN_new(); // Public key exponent
    BIGNUM *d = BN_new(); // Private key
    BIGNUM *n = BN_new(); // Modulus
    BIGNUM *phi_n = BN_new(); // Totient of n
    BIGNUM *C = BN_new(); // Encrypted message (ciphertext)
    BIGNUM *D = BN_new(); // Decrypted message

    // Assign values to public key exponent (e) and modulus (n) from hexadecimal strings
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
    BN_hex2bn(&phi_n, "E103ABD94892E3E74AFD724BF28E78348D52298BD687C44DEB3A81065A7981A4");

    // Calculate the private key (d) using modular inverse of e and phi_n
    BN_mod_inverse(d, e, phi_n, ctx);

    char *CC = malloc(100 * sizeof(char));
    printf("\nEnter your Encrypted Message:\n");
    scanf("%s", CC); // Read the encrypted message from user input
    BN_hex2bn(&C, CC); // Convert the input to BIGNUM format

    // Decrypt the ciphertext using RSA decryption formula: D = C^d mod n
    BN_mod_exp(D, C, d, n, ctx);

    // ... [earlier parts of the program]

// Convert the decrypted message from BIGNUM to hexadecimal string
printf("\nOriginal Message:\n");
char str1[500] = "print(bytes.fromhex(\"";
char *str2 = BN_bn2hex(D);
char str3[] = "\").decode('utf-8'))";
strcat(str1, str2);
strcat(str1, str3);
char* args[] = {"python3", "-c", str1, NULL};
execvp("python3", args); // Execute Python3 command to convert hex to ASCII

// ... [rest of the program]


    // Free allocated memory for BIGNUM variables and context
    BN_free(e);
    BN_free(d);
    BN_free(n);
    BN_free(phi_n);
    BN_free(C);
    BN_free(D);
    BN_CTX_free(ctx);
    free(CC);

    return EXIT_SUCCESS;

    
}
