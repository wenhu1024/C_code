#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1001

int main()
{
	int ch;
	int max;
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	max = 0; 
	while(gets(input) != NULL){
		if(max < strlen(input)){
			strcpy(output, input);
		}
	}
	putchar('\n');
	puts(output);
	return EXIT_SUCCESS;
}
