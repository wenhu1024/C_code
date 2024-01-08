#include <stdio.h>
#include <stdlib.h>
#define MAX 30
void reverse_string(char* string);


int main()
{
	char *string = (char*)malloc(sizeof(char)*MAX);
	char *s = string;
	int i;
	char ch;
	while((ch = getchar()) != '\n' ){
		*s++ = ch;	
	}
	*s = '\0';
	reverse_string(string);
	printf("%s\n",string);
	return 0;
}

void reverse_string(char* string)
{
	int n;
	char *str = string;
	for(n = 0; *str != '\0'; n++){
		str++;
	}
	char t;
	for(int i = 0; i < n/2; ++i ){
		   t = *(string+i);
		   *(string+i) = *(string+n-1-i);
		   *(string+n-1-i) = t;
	}

}
