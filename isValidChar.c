#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s);

int main (int argc, char* argv[]){
	char s[1000];
	printf("enter string:\n");
	scanf("%s\n",s);
	printf("%d\n",isValid(s));
	return EXIT_SUCCESS;
}
bool isValid(char* s) {
	if (strlen(s)==0||strlen(s)==1){
		return false; 
	}
	char *c = malloc(sizeof(s));
	int x = 0;
	int y = 0;
	if (s[0]==41||s[0]==93||s[0]==125){
		return false;
	}
	c[0]=s[0];
	while (s[y]!=0 && s[y+1]!=0){
		y++;
		if ((c[x]==40&&s[y]==41)||(c[x]==91&&s[y]==93)||(c[x]==123&&s[y]==125)){
			if (x==0){
				c[x]=s[y+1];
				y++;	
			} else {
				x--;
			}

		} else {
			x++;
			c[x]=s[y];
		}
	}
	if (c[0]==0){
		return true;
	} else {
		return false;
	}
		
	
}
