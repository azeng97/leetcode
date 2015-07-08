//returns length of last word in a string

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define SPACE 32


int lengthOfLastWord(char* s);

int main (int argc, char* argv[]){
    char *s = malloc(100000);
    printf ("enter string\n");
    scanf ("%[^\n]s\n",s);
    printf ("length of last word is %d\n",lengthOfLastWord(s));
    
    return EXIT_SUCCESS;
}

int lengthOfLastWord(char* s) {
	 if (strlen(s)==0){
        return 0;
    }
    int x = strlen(s)-1;
    int counter = 0;
    while (s[x] == SPACE){
    	if (x == 0){
    		return 0;
    	} else {
    		x--;
    	}
    }

    while (s[x]!= SPACE && x>=0){
    	counter ++;
    	x--;
    }
    return counter;
}