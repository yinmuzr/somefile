#include "head.h"

int main(int argc, const char *argv[])
{
	int array[N] = {0};

	maopao_input(array, N);
	maopao_order(array, N);
	maopao_output(array, N);

	return 0;
}
