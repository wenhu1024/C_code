#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void * a,void *b,int size);

int main()
{
	int a = 1;
	int b = 2;
	printf("a = %d  b = %d\n",a,b);
	swap(&a,&b,sizeof(int));
	printf("a = %d  b = %d\n",a,b);
	return 0;
}

void swap(void *a, void *b, int size)
{
	char *tmp =(char *) malloc(sizeof(char)*size);
	memcpy(tmp,a,size);
	memcpy(a,b,size);
	memcpy(b,tmp,size);
	free(tmp);
}
