#include "head.h"

int main(int argc, const char *argv[])
{
	int array[N] = {0};

	select_input(array, N);
	select_order(array, N);
	select_output(array, N);

	return 0;
}
