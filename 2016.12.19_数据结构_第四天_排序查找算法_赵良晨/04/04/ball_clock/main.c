#include "seqstack.h"
#include "linkqueue.h"

#define MAXBALL			27
#define MAX_ONE_MIN		4
#define MAX_FIVE_MIN	11
#define MAX_ONE_HOUR	11	

int is_end(linkqueue *queue)
{
	int i = 0;
	queuenode *point = queue->data->next;

	for (i = 1;i <= MAXBALL;i++)
	{
		if (i == point->data)
		{
			point = point->next;
		}
		else
			return 0;
	}
	return 1;
}

int main(int argc, const char *argv[])
{
	linkqueue *queue = NULL;
	seqstack *stack_one_min = NULL;
	seqstack *stack_five_min = NULL;
	seqstack *stack_one_hour = NULL;
	int i = 0;
	datatype data;
	int time = 0;

	queue = create_linkqueue(MAXBALL);
	stack_one_min = create_seqstack(MAX_ONE_MIN);
	stack_five_min = create_seqstack(MAX_FIVE_MIN);
	stack_one_hour = create_seqstack(MAX_ONE_HOUR);
	for (i = 1;i < 28;i++)
	{
		enter_linkqueue(queue, i);
	}

	while (1)
	{
		data = quit_linkqueue(queue);
		if (!is_full_seqstack(stack_one_min))
		{
			push_seqstack(stack_one_min, data);
			continue;
		}
		else
		{
			while (!is_empty_seqstack(stack_one_min))
			{
				enter_linkqueue(queue, pop_seqstack(stack_one_min));
			}
		}
		if (!is_full_seqstack(stack_five_min))
		{
			push_seqstack(stack_five_min, data);
			continue;
		}
		else
		{
			while (!is_empty_seqstack(stack_five_min))
			{
				enter_linkqueue(queue, pop_seqstack(stack_five_min));
			}
		}
		if (!is_full_seqstack(stack_one_hour))
		{
			push_seqstack(stack_one_hour, data);
			continue;
		}
		else
		{
			while (!is_empty_seqstack(stack_one_hour))
			{
				enter_linkqueue(queue, pop_seqstack(stack_one_hour));
			}
		}
		enter_linkqueue(queue, data);
		time++;	
		if (is_end(queue))
			break;
	}

	printf("time = %d\n", time);
	printf("day: %dd-%dh\n", time/2, time%2*12);

	destroy_seqstack(stack_one_min);
	destroy_seqstack(stack_five_min);
	destroy_seqstack(stack_one_hour);
	destroy_linkqueue(queue);

	return 0;
}
