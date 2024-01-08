#include <stdio.h>
#include <stdlib.h>

long int gcd(long int M,long int N);

int main()
{
	long int M,N;
	scanf("%ld %ld",&M,&N);
	printf("%ld\n",gcd(M,N));
	return 0;
}

long int gcd( long int M, long int N)
{
	long int ANS;
	long int R;
	long int t;

	if(M < 0 || N < 0){
		ANS = 0;
		return ANS;
	}
	
	if(M < N){
		t = N;
		N = M;
		M = t;
	}

	R = M%N;
	if(R == 0){
		ANS = N;
		return ANS;
	}else {	
		M = N;
		N = R;
		gcd(M,N);
	}
	
}
