#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int find_char(char **strings, char value);

int main()
{
	char **strings;
	char value;
	int r;
	int c;
	int i;

	r = 4;
	c = 10;
	scanf("%c",&value);

	strings = (char**)malloc(sizeof(char*)*r);
	for(i = 0; i < r-1; ++i){
		strings[i] = (char*)malloc(sizeof(char)*c); 
	}
	strings[r-1] = NULL;

	for(i = 0; i < r-1; ++i){
		scanf("%s", strings[i]);
	}

	if(find_char(strings,value)){
		printf("SUCCESS.\n");
	}else{
		printf("FAILURE.\n");
	}
	
}
int find_char(char **strings, char value)
{
	char *string;

	while( (string = *strings++) != NULL ){
		while(*string != '\0'){
			if(*string++ == value){
				return TRUE;
			}		
		}
	}
	return FALSE;
}

