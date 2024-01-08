#include <stdio.h>
#include <stdlib.h>

char* find_char(char const *source, char *const chars );
int main()
{
	char const *source = "ABCDEF";

	char * const chars = "XRCQEF";

	printf("%d\n",find_char(source,chars));
	return EXIT_SUCCESS;
}
char* find_char(char const *source,char *const chars)
{
	char* ch =(char*)chars;
	if(source == NULL || chars == NULL){
		return NULL;
	}
	while(*source != '\0'){
		while(*ch != '\0'){
			if(*source == *ch){
				return (char*)source;
			}
			ch++;
		}
		source++;
		ch = (char*)chars;
	}
	return NULL;
}
