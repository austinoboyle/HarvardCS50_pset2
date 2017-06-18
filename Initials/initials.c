#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void) {
    string str = get_string();
    
    for (int i = 0, n = strlen(str); i < n; i++){
        if ((i == 0 || str[i-1] == ' ') && str[i] != ' '){
           printf ("%c",toupper(str[i]));
        }
    }
    printf("\n");
    
}