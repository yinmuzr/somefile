#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

typedef treenode * datatype;
typedef struct queue
{
	datatype *data;
	int head;
	int tail;
	int tlen;
}seqqueue;

int destroy_seqqueue(seqqueue *queue);
datatype quit_seqqueue(seqqueue *queue);
int enter_seqqueue(seqqueue *queue, datatype data);
int is_full_seqqueue(seqqueue *queue);
int is_empty_seqqueue(seqqueue *queue);
seqqueue *create_seqqueue(int len);
#endif
