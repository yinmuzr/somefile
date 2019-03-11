#include "head.h"

int insert_input(int *array, int len)
{
	srand(time(NULL));
	int i = 0;

	for (i = 0;i < len;i++)
	{
		array[i] = rand() % 100;
	}
	return 0;
}

int insert_order(int *array, int len)
{
	int j = 0;
	int temp = 0;
	int i = 0;

	for (j = 1;j < len;j++)
	{
		temp = array[j];
		for (i = j;i > 0 && temp < array[i-1];i--)
		{
			array[i] = array[i-1];
		}
		array[i] = temp;
	}

	return 0;
}

int insert_output(int *array, int len)
{
	int i = 0;

	for (i = 0;i < len;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
