//counts prime numbers less than non-negative number, n
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int countPrimes(int n);


int main (int argc, char* argv[]){
    int n;
    printf ("enter non-negative number:\n");
    scanf ("%d",&n);
    assert (n>=0);
    int x = countPrimes(n);
    printf ("There are %d prime numbers less than %d\n",x,n);
    return EXIT_SUCCESS;
}


int countPrimes(int n) {
    int test = n-1;
    int x = 0;
    int yn;
	int d;
	
    while (test>2){
        yn = 1;
        test--;
        d = 2;
        while (d*d<=test){
		if (test%d == 0){
			yn = 0;
			d=test+1;
		}
		d++;
	    }
    	if (yn==1){
    		x++;
    	}
    	
    }
    return x;
}