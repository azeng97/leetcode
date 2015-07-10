//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


 
bool isPalindrome (char *string);
 
int main (int argc, char *argv[]) {
    char *s = malloc(10000);
    printf("enter a word:\n");
    scanf("%[^\n]s",s);
    if (isPalindrome(s) == true){
        printf("%s is a palindrome\n", s);
    } else {
        printf("%s is not a palindrome\n", s);
    }
    return EXIT_SUCCESS;
}
 
bool isPalindrome (char *string) {
    int n = 0;
    int k = 0;
    char *filtered = malloc((strlen(string)+1)*sizeof(char));
    while (string[n]!=0){
        if ((string[n]>=97 && string[n]<=122)||(string[n]>=65 && string[n]<=90)||(string[n]>=48 && string[n]<=57)){
            filtered[k] = string[n];
            k++;
        }
        n++;
    }
    filtered[k+1]=0;
    int length = strlen(filtered);
    n=0;
    while (n<=length/2){
        if((filtered[n]!=filtered[length-n-1])&&(filtered[n]!=filtered[length-n-1]+32)&&(filtered[n]!=filtered[length-n-1]-32)){
            return false;
        }
        n++;
    }
    return true;
}
