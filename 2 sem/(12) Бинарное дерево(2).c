#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	int data;
	struct Tree* L;
	struct Tree* R;
};

void createTree(struct Tree* elem)
{
	struct Tree* current;
	int value;
	
	scanf("%d", &value);

	if(value == 1) // L
	{
		current = (struct Tree*)malloc(sizeof(struct Tree));
		current->L = NULL;
		current->R = NULL;

		elem->L = current;
		createTree(current);
	}
	
	scanf("%d", &value);
	
	if(value == 1) // R
	{
		current = (struct Tree*)malloc(sizeof(struct Tree));
		current->L = NULL;
		current->R = NULL;

		elem->R = current;
		createTree(current);
	}
}

void give_values(struct Tree* elem)
{	
	if(elem == NULL)
		return;

	int num;
	scanf("%d", &num);
	elem->data = num;
	
	if(elem->L != NULL)
		give_values(elem->L);
	if(elem->R != NULL)
		give_values(elem->R);
}

int find_node(struct Tree* elem, int k, int count)
{	
	if(elem == NULL)
		return count;

	if(elem->data == k)
		count++;
	
	count = find_node(elem->L, k, count);
    count = find_node(elem->R, k, count);
	
	return count;
}

int level_nodes(struct Tree* elem, int k)
{	
	int L_count, R_count;
	if(elem == NULL)
		return 0;
	
	if(k == 1 && elem->R == NULL && elem->L == NULL)
		return 0;
	
	if(k == 0)
		return 1;
	
	L_count = level_nodes(elem->L, k - 1);
    R_count = level_nodes(elem->R, k - 1);
	
	return L_count + R_count;
}

struct Tree* find_internal(struct Tree* elem, struct Tree* saved)
{
	struct Tree* check1 = NULL, *check2 = NULL;
	if(elem == NULL)
		return NULL;
	
	if((elem->L != NULL || elem->R != NULL) && elem != saved)
		return elem;
	
	check1 = find_internal(elem->L, saved);
	check2 = find_internal(elem->R, saved);
	
	if(check1 != NULL)
		return check1;
	else if(check2 != NULL)
		return check2;
	
	return NULL;
}

int max_value(struct Tree* elem, int max, struct Tree* saved)
{	
	int L_max, R_max;
	if(elem == NULL)
		return max;

	if((elem->L != NULL || elem->R != NULL) && elem != saved)
	{
		if(elem->data > max)
			max = elem->data;
	}
	
	L_max = max_value(elem->L, max, saved);
    R_max = max_value(elem->R, max, saved);
	
	if(L_max > max)
		max = L_max;
	if(R_max > max)
		max = R_max;
	
	return max;
} 

void format_print(struct Tree* root)
{
	if(root == NULL)
		return;
	
	printf("%d", root->data);

    if(root->L != NULL || root->R != NULL) 
	{
        printf("(");

        if(root->L != NULL)
            format_print(root->L);

        if(root->R != NULL) 
		{
			printf(",");
            format_print(root->R);
        }
		else if(root->R == NULL)
			printf(",");

        printf(")");
    }
}

void free_tree(struct Tree* elem)
{
	if(elem == NULL)
		return;
	
	free_tree(elem->L);
	free_tree(elem->R);
	
	free(elem);
}	

int main()
{
	struct Tree* root, *check;
	int value, k_nodes = 0, count_nodes = 0, max, choice;
	
	scanf("%d", &value);
	
	if(value == 0)
		return 0;
	
	root = (struct Tree*)malloc(sizeof(struct Tree));
	root->L = NULL;
	root->R = NULL;
	
	createTree(root);
	give_values(root);
	
	scanf("%d", &value);
	k_nodes = find_node(root, value, 0);
	printf("%d\n", k_nodes);
	
	count_nodes = level_nodes(root, value);
	printf("%d\n", count_nodes);
	
	check = find_internal(root, root);
	if(check == NULL)
		printf("not found\n");
	else
	{
		max = max_value(root, check->data, root);
		printf("%d\n", max);
	}
	
	format_print(root);
	
	free_tree(root);
	
	return 0;
}
