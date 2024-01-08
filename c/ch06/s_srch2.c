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

	r = 4;
	c = 10;
	
	strings = (char**)malloc(sizeof(char*)*r);
	
	for(int i = 0; i < r-1; ++i){
		strings[i] = (char*)malloc(sizeof(char)*c);
	}
	strings[r-1] = NULL;

	scanf("%c",&value);

	for(int i = 0; i < r-1; ++i){
		scanf("%s",strings[i]);
	}


	if(find_char(strings,value)){
		printf("SUCCESS.\n");
	}
	else{
		printf("FAILURE.\n");
	}
	return EXIT_SUCCESS;
}

int find_char(char **strings,char value)
{
	while(*strings != NULL){
		while(**strings != '\0'){
			if(*(*strings)++ == value){
				return TRUE;
			}
		
		}
	strings++;
	}
	return FALSE;
}
