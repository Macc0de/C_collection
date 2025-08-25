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
	int array[] = {3,6,3,5,33,33,20,5}; 
	//int array[10];
	int i, j;
	/*for (i = 0; i < 8; i++)
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
	
	struct List* elem = First;
	struct List* previous = NULL;
	struct List* first = NULL;
	struct List* posledniy = NULL;
	int flag = 0; // Только для первого элемента
	
	while(elem) // Нашли первый и последний
	{
		if(flag == 0 && elem->data % 2 == 0)
		{
			first = elem;
			flag = 1;
		}
		
		if(elem->data % 2 == 0)
		{
			posledniy = elem;
		}
		elem = elem->Next;
	}
	
	elem = First;
	while(elem)
	{
		if(elem == first) // Для самого первого - обрабатываем 2 случая
		{
			if(previous == NULL)
			{
				First = First->Next;
				elem = elem->Next;
				continue;
			}
			else
			{
				previous->Next = elem->Next;
				elem = elem->Next;
				continue;
			}
		}
		
		if(elem == posledniy)
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
