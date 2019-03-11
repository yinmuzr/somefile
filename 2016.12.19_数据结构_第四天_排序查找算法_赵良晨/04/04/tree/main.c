#include "tree.h"
#include "seqqueue.h"

int main(int argc, const char *argv[])
{
	treenode *root = NULL;

	root = create_tree(1, 5);
	printf("前:");
	pre_show(root);
	printf("\n");
	printf("中:");
	mid_show(root);
	printf("\n");
	printf("后:");
	beh_show(root);
	printf("\n");
	printf("层:");
	ceng_show(root);
	printf("\n");

	destroy_tree(root);

	return 0;
}
