#include "head.h"

int quick_input(int *array, int len)
{
	srand(time(NULL));
	int i = 0;

	for (i = 0;i < len;i++)
	{
		array[i] = rand() % 100;
	}
	return 0;
}

int quick_order(int *array, int low, int high)
{
	int key = 0;
	int i = 0;
	int j = 0;

	key = array[low];
	i = low;
	j = high;

	while (i < j)
	{
		while (array[j] >= key && i < j)
			j--;
		if (i < j)
		{
			array[i] = array[j];
		}
		while (array[i] <= key && i < j)
			i++;
		if (i < j)
		{
			array[j] = array[i];
		}
	}
	array[i] = key;
	if (i-1 > low)
		quick_order(array, low, i-1);
	if (i+1 < high)
		quick_order(array, i+1, high);

	return 0;
}

int quick_output(int *array, int len)
{
	int i = 0;

	for (i = 0;i < len;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
