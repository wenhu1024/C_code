#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct 
{
  	int *elems;
  	int logicalLen;
  	int alloclenth;
}Stack;

void stackNew(Stack *s);

void stackDispose(Stack *s);

void stackPush(Stack *s, int value);

int stackPop(Stack *s);


int main()
{
	Stack s;
	stackNew(&s);

	for(int i = 0; i < 4; i++){
		stackPush(&s,i);
	}

	for(int j = 0; j < 4; j++ ){
		int tar = stackPop(&s);
		printf("%d\t",tar);
	}
	putchar('\n');
	stackDispose(&s);

	return 0;
}

void stackNew(Stack *s)
{
	s->alloclenth = 4;
	s->logicalLen = 0;
	s->elems = (int*)malloc(sizeof(int)*s->alloclenth);
	assert(s->elems!=NULL);
}

void stackPush(Stack* s,int value)
{
	if(s->logicalLen == s->alloclenth){
		s->alloclenth *= 2;
		s->elems =(int*)realloc(s->elems, s->alloclenth*sizeof(int));
	}
	assert(s->elems != NULL);
	s->elems[s->logicalLen] = value;
	s->logicalLen++;
}

int stackPop(Stack *s)
{
	assert(s->logicalLen > 0);
	s->logicalLen--;
	return s->elems[s->logicalLen];
}

void stackDispose(Stack *s)
{
	free(s->elems);
}
