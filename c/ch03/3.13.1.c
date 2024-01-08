#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	printf("singed_char : MAX:%d\t MIN:%d\n",SCHAR_MAX,SCHAR_MIN);
	printf("unsigned_char : MAX:%d\t MIN:%d\n",UCHAR_MAX,0);
	putchar('\n');
	printf("signed_short_int : MAX:%d\t MIN:%d\n",SHRT_MAX,SHRT_MIN);
	printf("unsigned_short_int : MAX:%d\t MIN:%d\n",USHRT_MAX,0);
	putchar('\n');
	printf("signed_int : MAX:%d\t MIN:%d\n",INT_MAX,INT_MIN);
	printf("unsigned_int : MAX:%d\t MIN:%d\n",UINT_MAX,0);
	putchar('\n');
	printf("signed_long_int : MAX:%ld\t MIN:%ld\n",LONG_MAX,LONG_MIN);
	printf("unsigned_long_int : MAX:%llu\t MIN:%llu\n",ULONG_MAX,0);
	return EXIT_SUCCESS;
}
