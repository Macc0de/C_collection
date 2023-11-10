#include <stdio.h>
#include <stdlib.h>
#include "print.h"

struct List* First;

void addToList(struct List** head, int value)
{
    struct List* new_node = malloc(sizeof(struct List));
	
    new_node->data = value;
    new_node->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_node;
        return;
    }
	
    struct List* current = *head;
    while (current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_node;
}

void Reverse(struct List** head, struct List* save_elem, int k)
{
	struct List* current = *head;
	for(int i = 0; current && i < k; )
	{
		struct List* temp = current->Next;
		
		current->Next = save_elem;
		save_elem = current;
		current = temp;
		i++;
	}
	*head = save_elem;
}

void Print(struct List* First)
{
	struct List* current = First;
	while(current)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

int main()
{
	int array[] = {1,2,3,4,5};

	int i;
	for (i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		addToList(&First, array[i]);
	}
	
	Print(First);
	printf("\n");
	
	int k;
	i = 0;
	struct List* current = First;
	while(scanf("%d", &k))
	{
		struct List* save_elem = NULL;
		
		// Нахождение следующего после последнего k-го
		current = First;
		i = 0;
		while(current && i <= k)
		{
			if(i + 1 == k)
			{
				save_elem = current->Next; // Для связи с оставшимися элементами
			}
			i++;
			current = current->Next;
		}
		
		Reverse(&First, save_elem, k);
		
		Print(First);
		printf("\n");
	}
	
	return 0;
}
