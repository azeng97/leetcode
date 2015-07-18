#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main (int argc, char* argv[]){
	int size, returnsize;
	int x=0;
	printf("size of number:\n");
	scanf("%d",&size);
	int* num = malloc(size*sizeof(int));
	printf("enter number:\n");
	while (x<size){
		scanf("%d",&num[x]);
		x++;
	}
	printf("size of return:\n");
	scanf("%d",&returnsize);
	int returnsize2 = returnsize*sizeof(int);
	x=0;
	while (x<returnsize){
		printf("final: %d\n",plusOne(num,size,&returnsize2)[x]);
		x++;
	}
	printf("\n");
	return EXIT_SUCCESS;
}



int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int y = 0;
	printf("number:");
	while (y<digitsSize){
		printf("%d",digits[y]);
		y++;
	}
	printf("\n");
	int* num = malloc(*returnSize);
	int x = digitsSize-1;
	while(x>0){
		if (digits[x]!=9){
			digits[x]++;
			x=0;
			while (x<digitsSize){
				num[x]=digits[x];
				x++;
			}
			return num;	
		} else {
			digits[x]=0;
			digits[x-1]++;
			x--;
		} 
	}
	if (digits[0]!=9){
		digits[0]++;
		x=0;
		while (x<digitsSize){
			num[x]=digits[x];
			x++;
		}	
	} else {
		num[0]=1	;
		x=1;
		while (x<digitsSize+1){
			num[x]=0;
			x++;
		}
	}
	return num;   
}