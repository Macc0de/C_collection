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
	int array[] = {2,-1,19,23,-7,35,16,8,9,10,11}; // {1,-2,3,-4,5,1,-100,-20,7,8,4};
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First, array[i]);
	}
	
	// Первый вывод + Макс. четный элемент
	struct List* current = First;
	int max = current->data;
	while(current)
	{
		if(current->data % 2 == 0 && current->data > max)
			max = current->data;
		
		printf("%d ", current->data);
		current = current->Next;
	}
	
	current = First;
	struct List* previous = NULL;
	while(current)
	{
		if(current->data < max)
		{
			// Добавление в новый список все элем. < макс. четного из старого
			addToList(&Second, current->data);
			// Удаление из первого списка элементы < макс. четного
			if(previous == NULL)
			{
				First = First->Next;
				current = current->Next;
				continue;
			}
			if(previous != NULL)
			{
				previous->Next = current->Next;
				current = current->Next;
				continue;
			}
		}
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
