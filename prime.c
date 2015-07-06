//counts prime numbers less than non-negative number, n
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int countPrimes(int n);
int isPrime (int n);

int main (int argc, char* argv[]){
	int n;
	printf ("enter non-negative number:\n");
	scanf ("%d",&n);
	assert (n>=0);
	int x = countPrimes(n-1);
	printf ("There are %d prime numbers less than %d\n",x,n);
	return EXIT_SUCCESS;
}



int countPrimes(int n) {
    int x = 0;
    
    while (n>1){
    	if (isPrime(n)==TRUE){
    		x++;
    	}
    	n--;
    }
    return x;
}

int isPrime (int n){
	int yn = TRUE;
	int d = n-1; 
	while (d>1){
		if (n%d == 0){
			yn = FALSE;
			d=-1;
		}
		d--;
	}
	return yn;
}