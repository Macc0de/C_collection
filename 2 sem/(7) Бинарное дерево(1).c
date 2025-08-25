#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	int data;
	struct Tree* L;
	struct Tree* R;
};

int createTree(struct Tree* elem)
{
	struct Tree* current;
	int value, count_nodes = 1;
	
	scanf("%d", &value);

	if(value == 1) // L
	{
		current = (struct Tree*)malloc(sizeof(struct Tree));
		current->L = NULL;
		current->R = NULL;

		elem->L = current;
		count_nodes += createTree(current);
	}
	
	scanf("%d", &value);
	
	if(value == 1) // R
	{
		current = (struct Tree*)malloc(sizeof(struct Tree));
		current->L = NULL;
		current->R = NULL;

		elem->R = current;
		count_nodes += createTree(current);
	}
	
	return count_nodes;
}

int count(struct Tree* root, int count_leaves)
{	
	if(root->L == NULL && root->R == NULL)
		count_leaves++;
	
	if(root->L != NULL)
		count_leaves = count(root->L, count_leaves);
	if(root->R != NULL)
		count_leaves = count(root->R, count_leaves);
	
	return count_leaves;
}

int height(struct Tree* root)
{
	if(root == NULL)
		return 0;

	int height_L = height(root->L);
	int height_R = height(root->R);
	
	int max_height = height_L;
	if(height_R > max_height)
		max_height = height_R;
	
	return max_height + 1;
}

int count_left(struct Tree* root)
{
	if(root == NULL)
		return 0;
	
	int left_nodes = 0;
	if(root->L != NULL)
	{
		left_nodes++;
		left_nodes += count_left(root->L);
	}
	left_nodes += count_left(root->R);
	
	return left_nodes;
}

void free_tree(struct Tree* root)
{
	if(root == NULL)
		return;
	
	free_tree(root->L);
	free_tree(root->R);
	
	free(root);
}	

int main()
{
	struct Tree* root;
	int value, count_nodes = 0, count_leaves = 0, height_tree = 0, left_nodes = 0;
	
	scanf("%d", &value);
	
	if(value == 0)
	{
		printf("%d\n%d\n%d\n%d", count_nodes, count_leaves, height_tree, left_nodes);
		return 0;
	}
	
	root = (struct Tree*)malloc(sizeof(struct Tree));
	root->L = NULL;
	root->R = NULL;
	
	count_nodes = createTree(root);
	printf("%d", count_nodes);
	
	count_leaves = count(root, count_leaves);
	printf("\n%d", count_leaves);
	
	height_tree = height(root);
	printf("\n%d", --height_tree);
	
	left_nodes = count_left(root);
	printf("\n%d", left_nodes);
	
	free_tree(root);
	
	return 0;
}
