#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS  20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrange(char* output, char const* input, int n_column, int const* columns);\

int main()
{
	int columns[MAX_COLS];
	int n_columns;
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	n_columns = read_column_numbers(columns,MAX_COLS);
	while(gets(input) != NULL){
		printf("Original input : %s\n",input);
		rearrange(output, input, n_columns, columns);
		printf("Rearranged line : %s\n",output);
	}
	return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
	int num;
	int ch;
	
	num = 0;
	while(num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0){
		num += 1;
	}
	
	while((ch = getchar()) != EOF && ch != '\n'){
		;
	}
	return num;
}

void rearrange(char* output, char const* input, int n_columns, int const* columns)
{	
	int len;
	int col;
	int nchars;
	int output_col;
	
	len = strlen(input);
	output_col = 0;
	
	if(n_columns % 2 == 0){
		for(col = 0; col < n_columns; col += 2){
			nchars = columns[col+1] - columns[col] + 1;
			if(columns[col] >= len){
				continue;
			}
			if(columns[col] + nchars - 1 >= len ){
				nchars = len - columns[col];
			}
			if(output_col == MAX_INPUT - 1){
				break;
			}
			if(output_col + nchars > MAX_INPUT - 1){
				nchars = MAX_INPUT - 1 -  output_col;
			}		
			strncpy(output + output_col, input + columns[col], nchars);
			output_col += nchars;
		}
	output[output_col] = '\0';
	}
	else{
		for(col = 0; col <= n_columns - 3; col += 2){
			nchars = columns[col+1] - columns[col] + 1;
			if(columns[col] >= len){
				continue;
			}
			if(columns[col] + nchars - 1 >= len){
				nchars = len - columns[col];
			}
			if(output_col + nchars > MAX_INPUT - 1){
				nchars = MAX_INPUT - 1 - output_col;
			}
			if(output_col == MAX_INPUT - 1){
				break;
			}
			strncpy(output + output_col, input + columns[col], nchars);
			output_col += nchars;	
		}
		output[output_col] = '\0';
		if(output_col == MAX_INPUT - 1){
			output[MAX_INPUT - 1] = '\0';
		}else{
			col = n_columns - 1;
			nchars = len - columns[col];
			if(columns[col] >= len ){
				return;
			}
			if(output_col + nchars > MAX_INPUT - 1){
				nchars = MAX_INPUT - 1 - output_col;
			}
			strncpy(output + output_col, input + columns[col], nchars);
			output_col += nchars;
			output[output_col] = '\0';
		}
	}
	
}
