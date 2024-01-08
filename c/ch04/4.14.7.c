#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void deblank(char string[]);
int main()
{	
	char string[MAX];
	while( gets(string) != NULL ){
		printf("input     : %s\n",string);
		deblank(string);
		printf("deblanked : %s\n",string);
	}
	return EXIT_SUCCESS;
}

void deblank(char string[])
{
	int blanks;
	int len;
	char ch[MAX];
	int j;

	len = strlen(string);
	blanks = 0;
	j = 0;

	for(int i = 0; i < len; ++i){
		if(string[i] == ' '){
			ch[j++] = string[i];
			
			while(string[i+1] == ' '){
				i++;
			}
		}
		else{
			ch[j++] = string[i]; 
		}
	}
	ch[j] = '\0';
	strcpy( string, ch);
}
