//determines if integer is a power of two
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool isPowerOfTwo (int n);

int main (int argc, char* argv[]){
    int n;
    printf ("enter non-negative number:\n");
    scanf ("%d",&n);
    assert (n>=0);
    if (isPowerOfTwo(n) == true){
   		printf ("yes\n");
   	} else {
   		printf ("no\n");
   	}
    return EXIT_SUCCESS;
}

bool isPowerOfTwo (int n){
	int y=1;
	while (y<n){
		y=y*2;
	}
	if (y==n){
		return true;
	} else {
		return false;
	}
}