#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int line;
	int ch;
	int at_beginning;

	line = 0;
	at_beginning = 1;

	while( (ch = getchar() ) != EOF) {
		if(at_beginning == 1){
			line += 1;
			at_beginning = 0;
			printf("%d ",line);
		}	
		putchar(ch);

		if(ch == '\n' ){
			at_beginning = 1;
		}
	}
	return EXIT_SUCCESS;
}	
