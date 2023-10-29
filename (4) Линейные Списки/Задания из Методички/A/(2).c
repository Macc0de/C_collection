#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
} *First;

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

int main()
{
	int array[] = {20,20,-55,20,20,-5,6,20}; 
	//int array[10];
	int i, j;
	/*for(i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < 8; i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	current = First;
	int max = First->data;
	while(current)
	{
		if(current->data > max)
			max = current->data;
		current = current->Next;
	}
	
	current = First;
	struct List* elem = First;
	struct List* previous = NULL;
	while(elem)
	{
		if(elem->data == max && previous == NULL) // Если самый первый - max
		{ 
			First = First->Next;
			elem = elem->Next;
			continue;
		}
		if(elem->data == max && previous != NULL)
		{
			previous->Next = elem->Next;
			elem = elem->Next;
			continue;
		}
		previous = elem;
		elem = elem->Next;
	}
	
	printf("\n");
	current = First;
	while(current) // Второй вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	return 0;
}
