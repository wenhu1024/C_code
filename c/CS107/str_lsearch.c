#include <stdio.h>
#include <string.h>

void* lsearch(void *key, void *base, int n, int elemSize, int (*cmp)(void* ,void*));
int cmp(void* ,void*);

int main()
{	char *str[5] = { "ab",
		      	 "cd",
		      	 "ef",
		      	 "gh",
			 "ij"	
		       };
	char *key = "gh";
	char **s;
	int n = 5;

	for(int i = 0; i < n; i++){
		printf("%s\t",str[i]);
	}

	putchar('\n');
	
	if((s = (char**) lsearch(&key, str, n, sizeof(char*), cmp)) != NULL ){
		printf("SUCCESS.\n%s\n",*s);
	}else{
		printf("FAILURE.\n");
	}
	return 0;
}

void* lsearch(void* key, void* base, int n, int elemSize, int (*cmp)(void*, void*))
{
	for(int i = 0; i < n; i++){
		void *elemAddr = (char*)base + i*elemSize;
		if(cmp(key,elemAddr) == 0){
			return elemAddr;
		}
	}
	return NULL;
}

int cmp(void* vp1, void* vp2)
{
	char *elem1 = *(char**)vp1;
	char *elem2 = *(char**)vp2;
	return strcmp(elem1,elem2);
}	
