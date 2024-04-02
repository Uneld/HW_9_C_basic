#include <stdio.h>
#include <ctype.h>

void replaceLetters(char *input)
{
	while (*input)
	{
		if (*input == 'a')
		{
			*input = 'b';
		}
		else if (*input == 'b')
		{
			*input = 'a';
		}
		else if (*input == 'A')
		{
			*input = 'B';
		}
		else if (*input == 'B')
		{
			*input = 'A';
		}

		input++;
	}
}

const int MAX_LINE_SIZE = 1000 + 1;

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";
	char inputString[MAX_LINE_SIZE];

	FILE *fi = fopen(input_fn, "r");
	fscanf(fi, "%[^\n]", inputString);
	fclose(fi);

	replaceLetters(inputString);

	FILE *fo = fopen(output_fn, "w");
	fprintf(fo, "%s", inputString);

	fclose(fo);

	return 0;
}
