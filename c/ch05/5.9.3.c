#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bits(unsigned int value);

int main()
{
	unsigned int value;
	unsigned int reversed;

	scanf("%u",&value);
	reversed = reverse_bits(value);
	printf("%u\n",reversed);
	return EXIT_SUCCESS;
}

unsigned int reverse_bits(unsigned int value)
{
	unsigned int i;
	unsigned int answer;

	answer = 0;
	for(i = 1; i != 0; i = i << 1){
		answer <<= 1;

		if(value & 1){
			answer |= 1;
		}
		value >>= 1;
	}
	return answer;

}

