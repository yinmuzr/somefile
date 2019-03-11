#include "seqstack.h"

seqstack *create_seqstack(int len)
{
	seqstack *stack = NULL;

	stack = malloc(sizeof(seqstack));
	if (NULL == stack)
	{
		perror("fail to malloc");
		return NULL;
	}
	stack->head = malloc(len * sizeof(datatype));
	if (NULL == stack->head)
	{
		perror("fail to malloc");
		return NULL;
	}
	stack->tlen = len;
	stack->top = 0;
	
	return stack;
}

int is_empty_seqstack(seqstack *stack)
{
	return stack->top == 0;
}

int is_full_seqstack(seqstack *stack)
{
	return stack->top == stack->tlen;
}

int push_seqstack(seqstack *stack, datatype data)
{
	if (is_full_seqstack(stack))
	{
		printf("栈满!\n");
		return -1;
	}
	stack->head[stack->top++] = data;
	return 0;
}

datatype pop_seqstack(seqstack *stack)
{
	if (is_empty_seqstack(stack))
	{
		printf("栈空!\n");
		return -1;
	}
	return stack->head[--stack->top];
}

int destroy_seqstack(seqstack *stack)
{
	free(stack->head);
	free(stack);

	return 0;
}
