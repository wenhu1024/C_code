#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
size_t strlen(char *string);

int main()
{
	char string[MAX];
	
	gets(string);
	printf("%lu\n",strlen(string));

	return EXIT_SUCCESS;
}	

size_t strlen(char * string)
{
	int lenth;

	lenth = 0;

	while(*string++ != '\0'){
		lenth+=1;
	}
	return lenth;

}
