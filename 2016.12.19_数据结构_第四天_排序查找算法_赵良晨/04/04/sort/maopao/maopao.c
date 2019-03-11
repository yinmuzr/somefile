#include "head.h"

int maopao_input(int *array, int len)
{
	srand(time(NULL));
	int i = 0;

	for (i = 0;i < len;i++)
	{
		array[i] = rand() % 100;
	}
	return 0;
}

int maopao_order(int *array, int len)
{
	int i = 0;
	int j = 0;

	for (j = 0;j < len-1;j++)
	{
		for (i = 0;i < len-1-j;i++)
		{
			if (array[i] > array[i+1])
			{
				array[i] = array[i] ^ array[i+1];
				array[i+1] = array[i] ^ array[i+1];
				array[i] = array[i] ^ array[i+1];
			}
		}
	}

	return 0;
}

int maopao_output(int *array, int len)
{
	int i = 0;

	for (i = 0;i < len;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
