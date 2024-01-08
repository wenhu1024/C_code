#include <stdio.h>


void *lsearch(void *key, void *base, int n, int elemSize,int (*cmp)(void* ,void*));
int cmp(void *key,void* elemAdder);

int main()
{
	int arr[5] = {1,2,3,4,5};
       	int n = 5;
	int key;
	int *aim;

	for(int i = 0; i < n; ++i){
		printf("%d\t",arr[i]);
	}
	putchar('\n');
	printf("Input searched_number:");
	scanf("%d",&key);

	if( (aim = (int*)(lsearch(&key, arr, n, sizeof(int),cmp))) != NULL ){
		printf("SUCCESS.\n%d\n",*aim);			
	}else{
		printf("FAILURE.\n");
	}
	return 0;
}

void *lsearch(void *key, void *base, int n, int elemSize, int (*cmp)(void* , void* ))
{
	for(int i = 0; i < n; ++i ){
		void* elemAddr = (char*)base + i*elemSize;
		if(cmp(key,elemAddr) == 0){
			return elemAddr;
		}
	}
	return NULL;
}

int cmp(void *key,void *elemAdder)
{
	int *vp1 = (int*)key; 
	int *vp2 = (int*)elemAdder;
	return *vp1 - *vp2;
}
