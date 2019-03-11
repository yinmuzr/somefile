#include "tree.h"
#include "seqqueue.h"

treenode *create_treenode(int num)
{
	treenode *temp = NULL;

	temp = malloc(sizeof(treenode));
	if (NULL == temp)
	{
		perror("fail to malloc");
		return NULL;
	}
	temp->num = num;
	temp->lchild = NULL;
	temp->rchild = NULL;

	return temp;
}

treenode *create_tree(int start, int end)
{
	treenode *root = NULL;

	root = create_treenode(start);
	if (2*start <= end)
	{
		root->lchild = create_tree(2*start, end);
	}
	if (2*start+1 <= end)
	{
		root->rchild = create_tree(2*start+1, end);
	}
	return root;
}

int pre_show(treenode *root)
{
	printf("%d ", root->num);
	if (root->lchild != NULL)
		pre_show(root->lchild);
	if (root->rchild != NULL)
		pre_show(root->rchild);
	return 0;
}

int mid_show(treenode *root)
{
	if (root->lchild != NULL)
		mid_show(root->lchild);
	printf("%d ", root->num);
	if (root->rchild != NULL)
		mid_show(root->rchild);
	return 0;
}

int beh_show(treenode *root)
{
	if (root->lchild != NULL)
		beh_show(root->lchild);
	if (root->rchild != NULL)
		beh_show(root->rchild);
	printf("%d ", root->num);

	return 0;
}

int destroy_tree(treenode *root)
{
	if (root->lchild != NULL)
		destroy_tree(root->lchild);
	if (root->rchild != NULL)
		destroy_tree(root->rchild);
	free(root);

	return 0;
}

int ceng_show(treenode *root)
{
	seqqueue *queue = NULL;
	treenode *temp = NULL;

	queue = create_seqqueue(50);
	enter_seqqueue(queue,root);
	while (!is_empty_seqqueue(queue))
	{
		temp = quit_seqqueue(queue);
		printf("%d ", temp->num);
		if (temp->lchild != NULL)
			enter_seqqueue(queue, temp->lchild);
		if (temp->rchild != NULL)
			enter_seqqueue(queue, temp->rchild);
	}

	destroy_seqqueue(queue);

	return 0;
}
