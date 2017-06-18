#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <crypt.h>

#define _XOPEN_SOURCE
#define MAXLENGTH 4


/**
 * Written by: Austin O'Boyle
 * 
 * Brute force password cracking method - Uses a method analogous to a clock:
 * Cycles through all possible values for the outermost index of the password.
 * If max value of current char is reached, current char value is reset to min value
 * and the character 1 to the left is incremented (eg - Azz --> BAA)
 * if all characters in the password are at the max value, all characters are reset and one is added to the end of the password
 * (eg zzz --> AAAA).  Program stops when correct password is found, or if all allowed passwords exhausted
 * 
 * Main Args:
 *      hash key of password to crack:
 *          password must be all alpha characters and have max length of MAXLENGTH
 * Prints:
 *      Password if it is found
 *      else: "Password longer than max length or non-alphabetical"
 * 
 */

int main (int argc, string argv[]){
    if (argc != 2){
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    //
    char salt[3];
    memset(salt, '\0', sizeof(salt));
    
    const string hash = argv[1];
    strncpy (salt, hash, 2);
    salt[2] = '\0';
    
    char currentPas[MAXLENGTH + 1];
    currentPas[0] = 65;
    int currentIndex = 0;
    
    while (strlen(currentPas) <= MAXLENGTH){
            
        //This loop checks if the current index is
        while (currentPas[currentIndex] < 123){
            if (strcmp(crypt(currentPas,salt), hash) == 0){
                printf("%s\n", currentPas);
                return 0;
            }
            currentPas[currentIndex]++;
        }

        while (currentIndex >= 1 && currentPas[currentIndex] >= 122) {
            currentPas[currentIndex] = 65;
            currentIndex --;
        }

        
        if (currentIndex == 0 && currentPas[0] >= 122){
            currentPas[strlen(currentPas)] = 65;
            currentPas[0] = 65;
        }
        else {
            currentPas[currentIndex]++;
        }
        currentIndex = strlen(currentPas) - 1;
    }
    printf("Password Not Alphabetic and 4 or fewer characters\n");
}