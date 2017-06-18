#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[]){
    if (argc != 2){
        printf("Require exactly 1 command line arg\n");
        return 1;
    }
    int k = atoi(argv[1]);
    k = k % 26;
    
    printf("plaintext: ");
    string plainText = get_string();
    char newChar;
    
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plainText); i < n; i++){
        if (96 < plainText[i] && 123 > plainText[i]){
            int dif = 97 + ((plainText[i] + k - 97) % 26);
            newChar  = dif;
            printf ("%c", newChar);
        }
        else if (64 < plainText[i] && 91 > plainText[i]){
            newChar  = 65 + (plainText[i] + k - 65) % 26;
            printf ("%c", newChar);
        }
        else {
            printf("%c", plainText[i]);
        }
    }
    
    printf ("\n");
    
}