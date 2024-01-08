#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct {
        void *elems;
        int elemSize;
        int alloclength;
        int logicalLen;
        void (*freefn)(void*);
}stack;

void stackNew(stack *s, int elemSize,void (*freefn) (void*));

void stackPush(stack *s, void *elemAddr);

void stackPop(stack *s,void *elemAddr);

void stackDispose(stack *s);

static void stackGrow(stack *s);

void stringfree(void* vp);

int main()
{
	const char *str[] = {"ab","cd","ef"};
	stack s;
	stackNew(&s,sizeof(char*),stringfree);
	char *copy;
	for(int i=0;i<3;i++){
		copy = strdup(str[i]);
		stackPush(&s,&copy);
	}
	char *name;
	for(int j=0;j<3;j++){
		stackPop(&s,&name);
		printf("%s\t",name);
		free(name);
	}
	putchar('\n');
	stackDispose(&s);
	return 0;
}

void stackNew(stack *s, int elemSize,void (*freefn) (void*))
{
	s->alloclength = 3;
	s->logicalLen  = 0;
	s->elemSize = elemSize;
	s->elems = malloc(s->elemSize * s->alloclength);
}

void stackPush(stack *s,void* elemAddr)
{
	if(s->logicalLen == s->alloclength){
		stackGrow(s);
	}
	void* target = (char*)s->elems + s->elemSize * s->logicalLen;
	memcpy(target,elemAddr,s->elemSize);
	s->logicalLen++;
}

static void stackGrow(stack *s)
{
	s->alloclength *=2;
	s->elems = realloc(s->elems,s->elemSize*s->alloclength);
}

void stackPop(stack *s,void *elemAddr)
{
	assert(s->logicalLen>0);
	void *source = (char*)s->elems + (s->logicalLen - 1)*s->elemSize;
	memcpy(elemAddr,source,s->elemSize);
	s->logicalLen--;
}

void stackDispose(stack *s)
{
	if(s->freefn != NULL ){
		for(int i = 0; i < s->logicalLen; i++){
			s->freefn((char*)s->elems + s->elemSize*i);
		}
	}
	free(s->elems);
}

void stringfree(void *vp)
{
	free(*(char**)vp);
}
