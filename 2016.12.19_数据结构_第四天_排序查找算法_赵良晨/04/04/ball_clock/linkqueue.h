#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}queuenode;
typedef struct queuenode
{
	queuenode *data;
	queuenode *head;
	queuenode *tail;
	int tlen;
	int clen;
}linkqueue;

linkqueue *create_linkqueue(int len);
int is_empty_linkqueue(linkqueue *queue);
int is_full_linkqueue(linkqueue *queue);
int destroy_linkqueue(linkqueue *queue);
datatype quit_linkqueue(linkqueue *queue);
int enter_linkqueue(linkqueue *queue, datatype data);
#endif
