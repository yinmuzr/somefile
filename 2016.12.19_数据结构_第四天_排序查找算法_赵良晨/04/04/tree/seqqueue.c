#include "seqqueue.h"

seqqueue *create_seqqueue(int len)
{
	seqqueue *queue = NULL;

	queue = malloc(sizeof(seqqueue));
	if (NULL == queue)
	{
		perror("fail to malloc");
		return NULL;
	}
	queue->data = malloc(len * sizeof(datatype));
	if (NULL == queue->data)
	{
		perror("fail to malloc");
		return NULL;
	}
	queue->tlen = len;
	queue->head = queue->tail = 0;

	return queue;
}

int is_empty_seqqueue(seqqueue *queue)
{
	return queue->head == queue->tail;
}

int is_full_seqqueue(seqqueue *queue)
{
	return ((queue->tail + 1) % queue->tlen) == queue->head;
}

int enter_seqqueue(seqqueue *queue, datatype data)
{
	if (is_full_seqqueue(queue))
	{
		printf("队列已满!\n");
		return -1;
	}
	queue->data[queue->tail] = data;
	queue->tail = (queue->tail + 1) % queue->tlen;
	return 0;
}

datatype quit_seqqueue(seqqueue *queue)
{
	datatype data;

	if (is_empty_seqqueue(queue))
	{
		printf("空队!\n");
		return NULL;
	}
	
	data = queue->data[queue->head];
	queue->head = (queue->head + 1) % queue->tlen;

	return data;
}

int destroy_seqqueue(seqqueue *queue)
{
	free(queue->data);
	free(queue);
	return 0;
}
