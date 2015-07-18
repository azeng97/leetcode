//compare version numbers


#include <stdio.h>
#include <stdlib.h>

int compareVersion(char* version1, char* version2);
int extract (char *s,int x);


int main (int argc, char* argv[]){
	char v1[1000];
	char v2[1000];
	printf("enter first version number:\n");
	scanf("%s\n",v1);
	printf("enter second version number:\n");
	scanf("%s\n",v2);
	//printf("%s,%s\n",v1,v2);
	printf("result: %d\n",compareVersion(v1,v2));
	return EXIT_SUCCESS;
}

int compareVersion(char* version1, char* version2) {
	int x = 0;
	int y = 0;
	if (extract(version1,x)>extract(version2,y)){
		return 1;
	} else if (extract(version1,x)<extract(version2,y)){
		return -1;
	}
	while (version1[x]!=0 && version2[y]!=0){
		while (version1[x]!=46&&version1[x+1]!=0){
			x++;
		}
		while (version2[y]!=46&&version2[y+1]!=0){
			y++;
		}
		x++;
		y++;
		if (extract(version1,x)>extract(version2,y)){
				return 1;
			} else if (extract(version1,x)<extract(version2,y)){
				return -1;
			}
	}
	return 0;	    
}


int extract (char *s,int x){
	int num = 0;
	while (s[x]!=46 && s[x]!=0){
		num = 10*num + s[x]-48;
		x++;
	}
	printf("%d\n",num);
	return num;
}