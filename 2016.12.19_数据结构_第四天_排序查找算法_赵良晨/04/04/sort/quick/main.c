#include "head.h"

int main(int argc, const char *argv[])
{
	int array[N] = {0};

	quick_input(array, N);
	quick_order(array, 0, N-1);
	quick_output(array, N);

	return 0;
}
