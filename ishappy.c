//determines whether number is happy or not
//Avan
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isHappy(int n);

int main (int argc, char* argv[]){
	int n;
	printf("enter number:\n");
	scanf("%d",&n);
	if (isHappy(n)==true){
		printf("happy\n");
	} else {
		printf("not happy\n");
	}
	return EXIT_SUCCESS;
}


bool isHappy(int n) {
	int temp = n;
	int y;
	int new = 0;
	int counter = 1;

	while (temp>=10){
		temp = temp/10;
		counter = counter*10;
	}
	temp = n;

	while (temp%counter!=0 || ((temp/counter)!=1 && (temp/counter)!=4)){
		
		while(temp!=0){
			y = temp%10;
			new = new + y*y;
			temp = (temp-temp%10)/10;
		}
		temp = new;

		counter = 1;
		while (temp>=10){
		temp = temp/10;
		counter = counter*10;
		}
		temp = new;
		new = 0;
		printf ("%d\n",temp);
	}

	if (temp/counter==1){
		return true;
	} else {
		return false;
	}
}