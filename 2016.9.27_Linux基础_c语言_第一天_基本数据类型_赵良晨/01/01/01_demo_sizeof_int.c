/* 
 * 功能:测试int类型在系统中占用的字节数
 */

#include <stdio.h>

int main(void)
{
	int a = 0;

	a = sizeof(int);

	printf("a = %d\n", a);

	return 0;
}
