#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	10

struct node {
	int data;
	struct node *next;
}* array[N];

int insert_hash_table(int data)
{	
	int index = 0;
	struct node **point = NULL;
	struct node *temp = NULL;

	index = data % 10;
	for (point = &array[index];*point;point = &(*point)->next)
	{
		if (data <= (*point)->data)
			break;
	}
	temp = malloc(sizeof(struct node));
	if (NULL == temp)
	{
		perror("fail to malloc");
		return -1;
	}
	temp->data = data;
	temp->next = *point;
	*point = temp;
	
	return 0;
}

int show_hash_table()
{
	int i = 0;
	struct node **point = NULL;

	for (i = 0;i < N;i++)
	{
		printf("%d:", i);
		for (point = &array[i];*point;point = &(*point)->next)
		{
			printf("%d ", (*point)->data);
		}
		printf("\n");
	}

	return 0;
}

int find_hash_table(int data)
{
	int index = 0;
	struct node **point = NULL;

	index = data % 10;
	for (point = &array[index];*point;point = &(*point)->next)
	{
		if (data == (*point)->data)
			return 1;
		else if (data < (*point)->data)
		{
			return 0;
		}
	}
	
	return 0;
}

int destroy_hash_table()
{
	struct node *point = NULL;
	struct node *temp = NULL;
	int i = 0;

	for (i = 0;i < N;i++)
	{
		point = array[i];
		temp = point;
		while (point != NULL)
		{
			point = point->next;
			free(temp);
			temp = point;
		}
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int a[10] = {1,13,15,19,25,28,39,46,52,15};
	int i = 0;

	for (i = 0;i < 10;i++)
	{
		insert_hash_table(a[i]);
	}

	show_hash_table();
	
	if (find_hash_table(18))
	{
		printf("25存在!\n");
	}
	else
	{
		printf("18不存在!\n");
	}

	destroy_hash_table();

	return 0;
}
