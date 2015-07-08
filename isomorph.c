//determines if two strings are isomorphic
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t);


int main (int argc, char* argv[]){
    char *s = malloc(100000);
    char *t = malloc(100000);
    printf ("enter string 1:\n");
    scanf ("%s\n",s);
    printf ("enter string 2:\n");
    scanf ("%s\n",t);
    assert (strlen(s)==strlen(t));
    if (isIsomorphic(s,t)==true){
    	printf ("strings are isomorphic\n");
    } else {
    	printf ("strings are not isomorphic\n");
    }
    
    return EXIT_SUCCESS;
}


bool isIsomorphic(char* s, char* t) {
	int x = 0;
	int y = 1;
	while (x<strlen(s)){
		while (y<strlen(s)){
			if (s[x]==s[y] && t[x]!=t[y]){
                    return false;
            } else {
                y++;
            }
		}
        x++;
        y=x+1;
	}
    return true;
}