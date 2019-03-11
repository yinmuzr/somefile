#include "linkqueue.h"

linkqueue *create_linkqueue(int len)
{
	linkqueue *queue = NULL;
	queue = malloc(sizeof(linkqueue));
	if (NULL == queue)
	{
		perror("fail to malloc");
		return NULL;
	}
	queue->data = malloc(sizeof(queuenode));
	if (NULL == queue->data)
	{
		perror("fail to malloc");
		return NULL;
	}
	queue->head = queue->tail = queue->data;
	queue->tlen = len;
	queue->clen = 0;

	return queue;
}

int is_empty_linkqueue(linkqueue *queue)
{
	return queue->clen == 0;
}

int is_full_linkqueue(linkqueue *queue)
{
	return queue->clen == queue->tlen;
}

int enter_linkqueue(linkqueue *queue, datatype data)
{
	queuenode *temp = NULL;

	if (is_full_linkqueue(queue))
	{
		printf("队满!\n");
		return -1;
	}
	temp = malloc(sizeof(queuenode));
	temp->data = data;
	temp->next = NULL;
	queue->tail->next = temp;
	queue->tail = temp;
	queue->clen++;
	
	return 0;
}

datatype quit_linkqueue(linkqueue *queue)
{
	datatype data;
	queuenode *temp = NULL;

	if (is_empty_linkqueue(queue))
	{
		perror("队空!\n");
		return -1;
	}
	temp = queue->head->next;
	queue->head->next = temp->next;
	data = temp->data;
	free(temp);
	queue->clen--;
	if (queue->clen == 0)
		queue->tail = queue->data;

	return data;
}

int destroy_linkqueue(linkqueue *queue)
{
	queuenode *point = NULL;
	queuenode *temp = NULL;

	point = queue->data;
	temp = point;
	while (point != NULL)
	{
		point = point->next;
		free(temp);
		temp = point;
	}
	free(queue);

	return 0;
}
