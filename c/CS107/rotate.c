#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void rotate(void* front, void* middle, void* end);

int main()
{
	int a[5] = {1,2,3,4,5};
	for(int i = 0; i < 5; i++)
	printf("%d\t",a[i]);
	putchar('\n');
	rotate(a,a+2,a+5);
	for(int i = 0; i < 5; i++)
	printf("%d\t",a[i]);
	putchar('\n');
	return 0;
}

void rotate(void* front,void* middle, void* end)
{
		int frontsize = (char*)middle - (char*)front;
		int backsize  = (char*)end - (char*)middle;
		char *buffer  = (char*)malloc(backsize);
		memcpy(buffer,front,frontsize);
		memmove(front,middle,backsize);
		memcpy((char*)end - frontsize,buffer,frontsize);
}

