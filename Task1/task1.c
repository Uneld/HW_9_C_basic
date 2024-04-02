#include <stdio.h>
#include <string.h>

const int MAX_LINE_SIZE = 100 + 1;

void findUniqueChars(char *input_fn, char *output_fn)
{
	char word1[MAX_LINE_SIZE];
	char word2[MAX_LINE_SIZE];

	FILE *fi = fopen(input_fn, "r");
	fscanf(fi, "%s %s", word1, word2);
	fclose(fi);

	int count1[26] = {0};
	int count2[26] = {0};
	int len1 = strlen(word1);
	int len2 = strlen(word2);

	for (int i = 0; i < len1; i++)
	{
		count1[word1[i] - 'a']++;
	}

	for (int i = 0; i < len2; i++)
	{
		count2[word2[i] - 'a']++;
	}

	FILE *fo = fopen(output_fn, "w");
	for (int i = 0; i < 26; i++)
	{
		if (count1[i] == 1 && count2[i] == 1)
		{
			fprintf(fo, "%c ", i + 'a');
		}
	}
	fclose(fo);
}

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";

	findUniqueChars(input_fn, output_fn);

	return 0;
}
