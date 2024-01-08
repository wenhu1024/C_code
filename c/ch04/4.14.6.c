#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void substr(char dst[], char src[], int start, int len);

int main()
{
	int start;
	int len;
	char dst[MAX];
	char src[MAX];
	printf("src   : ");
	scanf("%s", src);
	printf("start : ");
	scanf("%d", &start);
	printf("len   : ");
	scanf("%d", &len);

	substr(dst, src, start, len);
	printf("dst   : %s", dst);

	return EXIT_SUCCESS;
}

void substr(char dst[], char src[], int start, int len)
{
	int len_src;
	len_src = strlen(src);

	if ( start >= len_src || start < 0 || len < 0){
                strcpy(dst, "");
        }
	else{
		int i;
		for(i = 0; i < len ; i++){
			dst[i] = src[start + i];
		}
		dst[len] = '\n';
	
	}
        
		
	
}
