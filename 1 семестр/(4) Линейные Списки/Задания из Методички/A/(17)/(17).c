#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
} *First, *Second;

void addToList(struct List** head, int value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
    new_List->data = value;
    new_List->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_List;
        return;
    }
	
    struct List* current = *head;
    while (current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_List;
}

int main()
{
	int array[] = {5,2,3,9,4,-4,0,-1}; // {1,-2,3,-4,5,1,-100,-20,7,8,4};
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First, array[i]);
	}
	
	// Первый вывод
	struct List* current = First;
	while(current)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	// Добавление в новый список элем. > порядк. номера из старого
	int index = 0;
	current = First;
	while(current)
	{
		if(current->data > index)
			addToList(&Second, current->data);
		
		index++;
		current = current->Next;
	}
	
	// Удаляем из первого списка элементы > порядк. номера
	index = 0;
	struct List* previous = NULL;
	current = First;
	
	while(current)
	{
		if(previous == NULL && current->data > index)
		{
			First = First->Next;
			index++;
			current = current->Next;
			continue;
		}
		if(previous != NULL && current->data > index)
		{
			previous->Next = current->Next;
			index++;
			current = current->Next;
			continue;
		}
		
		index++;
		previous = current;
		current = current->Next;
	}
	
	// Вывод
	printf("\n");
	current = First;
	while(current) // Первый список
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	printf("\n");
	struct List* elem = Second;
	while(elem) // Второй список
	{
		printf("%d ", elem->data);
		elem = elem->Next;
	}
	
	return 0;
}
