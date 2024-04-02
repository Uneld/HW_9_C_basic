#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findNums(char *str, int nums[])
{
	int i = 0, j = 0, num = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = atoi(&str[i]);
			nums[j++] = num;
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
		}
		i++;
	}

	return j;
}

void sort_array(int size, int a[])
{
	int i;
	int tmp;
	int flag;

	do
	{
		flag = 0;
		for (i = 1; i < size; i++)
		{
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				flag = 1;
			}
		}
	} while (flag);
}

const int MAX_LINE_SIZE = 1000 + 1;
const int MAX_NUMS = 500;

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";
	
	char inputString[MAX_LINE_SIZE];
	int nums[MAX_NUMS];

	FILE *fi = fopen(input_fn, "r");
	
	fscanf(fi, "%[^\n]", inputString);
	
	fclose(fi);

	int size = findNums(inputString, nums);
	sort_array(size, nums);

	FILE *fo = fopen(output_fn, "w");
	
	for (int i = 0; i < size; ++i)
	{
		fprintf(fo, "%d ", nums[i]);
	}

	fclose(fo);

	return 0;
}
