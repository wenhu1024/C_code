#include <stdio.h>
#include <stdlib.h>

int count_one_bits(unsigned value);

int main()
{
	unsigned value;
	int counts;

	scanf("%u", &value);

	counts = count_one_bits(value);
	printf("%d\n",counts);
	return EXIT_SUCCESS;
}

int count_one_bits(unsigned value)
{
	int ones;

	for(ones = 0; value != 0; value = value >> 1 ){
		if(value & 1){
			ones++;
		}
	}
	return ones;
}

