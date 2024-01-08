#include <stdio.h>
#include <stdlib.h>

#define MAX 30
int del_substr(char* str, char const* substr);

int main()
{
	char* str = (char*)malloc(sizeof(char)*MAX);
	char* _str = str;
	char const* substr = "CD";
	int i;
	char ch;
	while ((ch = getchar()) != '\n') {
		*_str++ = ch;
	}
	*_str = '\0';
		
	 i = del_substr(str, substr);
	if (i) {
		printf("SUCCESS.\n");
		printf("%s\n", str);
	}
	else {
		printf("FAILURE.\n");
	}
	return EXIT_SUCCESS;
}

int del_substr(char* str, char const* substr)
{
	char* sub1 = (char*)substr;
	char* sub2 = (char*)substr;
	char* str1 = str;
	char* str2 = str;
	int  i;
	int  n;
	int  n_str;
	int  n_sub;
	int  n_same;

	n = 0;

	for (n_str = 0; *str2 != '\0'; n_str++) {
		str2++;
	}
	if (n_str == 0) {
		return 0;
	}



	for (n_sub = 0; *sub1 != '\0'; n_sub++) {
		sub1++;
	}
	if (n_sub == 0) {
		return 1;
	}



	while (*str1 != '\0' && *str1 != *substr) {
		str1++;
		n++;
	}
	if (*str1 == '\0') {
		return 0;
	}



	for (str2 = str1, n_same = 0, i = 0; i < n_sub && *str2 != '\0'; i++, ++str2, ++sub2) {
		if (*str2 == *sub2) {
			n_same++;
		}
	}
	if (n_same != n_sub) {
		return 0;
	}



	for (int j = 0; j < n_str - n_sub - n; j++, ++str1) {
		*str1 = *(str1 + n_sub);
	}
	*(str + n_str - n_sub) = '\0';
	return 1;
}



