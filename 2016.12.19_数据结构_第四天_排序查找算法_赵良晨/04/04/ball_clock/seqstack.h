#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype;
typedef struct stack {
	datatype *head;
	int tlen;
	int top;
}seqstack;

seqstack *create_seqstack(int len);
int destroy_seqstack(seqstack *stack);
int is_empty_seqstack(seqstack *stack);
int is_full_seqstack(seqstack *stack);
int push_seqstack(seqstack *stack, datatype data);
datatype pop_seqstack(seqstack *stack);

#endif
