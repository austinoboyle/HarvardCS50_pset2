#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[]){
    if (argc != 2){
        printf("Need exactly 1 command line arg!\n");
        return 1;
    }
    
    string key = argv[1];
    int lenKey = strlen(key);
        
    for (int i = 0; i < lenKey; i++){
        //check for non-alpha characters
        if (!isalpha(key[i])){
            printf("Must be all alpha key");
            return 1;
        }    
        //make key all lower case and convert to the equivalent int being added to the plaintext
        key[i] = tolower(key[i]) % 97;
    }
    
    printf("plaintext: ");
    string pText = get_string();
    printf("ciphertext: ");
    int numNonAlpha = 0; //count num of non-alpha keys hit so far
    
    for (int i = 0, n = strlen(pText); i < n; i++){
        
        int keyIndex = (i - numNonAlpha) % lenKey;
        
        //if lowercase letter
        if (islower(pText[i])){
            char newChar = 97 + ((pText[i] + key[keyIndex] - 97) % 26);
            printf ("%c", newChar);
            
        //if upper case letter
        }else if (isupper(pText[i])){
            char newChar = 65 + (pText[i] + key[keyIndex] - 65) % 26;
            printf ("%c", newChar);
            
        //if non-alpha
        }else {
            numNonAlpha++;
            printf("%c", pText[i]);
        }
    }
    printf ("\n");
}