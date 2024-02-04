// Добавление элементов в список, но без поиска последнего элемента, а с помощью *Last
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
}*First;

void addToList(int value, struct List** Last)
{
	struct List* new_node = malloc(sizeof(struct List));
	new_node->Next = NULL;
	new_node->data = value;
	
	if(First == NULL)
	{
		First = new_node;
		*Last = new_node;
		return;
	}
	
	(*Last)->Next = new_node;
	*Last = new_node;
}

int main()
{
	int i, arr[5] = {1,2,3,4,5};

	struct List* Last = NULL;
	for(i = 0; i < 5; i++)
		addToList(arr[i], &Last);
	
	struct List* elem = First;
	while(elem)
	{
		printf("%d ", elem->data);
		elem = elem->Next;
	}
	
	printf("\nLast elem: %p", Last->Next);
	
	return 0;
}
