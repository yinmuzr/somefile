#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	int num;
	struct node *lchild;
	struct node *rchild;
}treenode;

int destroy_tree(treenode *root);
int beh_show(treenode *root);
int mid_show(treenode *root);
int pre_show(treenode *root);
treenode *create_tree(int start, int end);
treenode *create_treenode(int num);
int ceng_show(treenode *root);

#endif
