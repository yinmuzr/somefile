#include "head.h"

int select_input(int *array, int len)
{
	srand(time(NULL));
	int i = 0;

	for (i = 0;i < len;i++)
	{
		array[i] = rand() % 100;
	}
	return 0;
}

int select_order(int *array, int len)
{
	int j = 0;
	int i = 0;
	int min = 0;

	for (j = 0;j < len-1;j++)
	{
		min = j;
		for (i = j+1;i < len;i++)
		{
			if (array[min] > array[i])
				min = i;
		}
		if (j != min)
		{
			array[min] = array[min] ^ array[j];
			array[j] = array[min] ^ array[j];
			array[min] = array[min] ^ array[j];
		}
	}

	return 0;
}

int select_output(int *array, int len)
{
	int i = 0;

	for (i = 0;i < len;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
