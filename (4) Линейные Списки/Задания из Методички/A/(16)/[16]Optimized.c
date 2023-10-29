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
	int array[] = {1,-2,3,-4,5,1}; // {1,-2,3,-4,5,1,-100,-20,7,8,4};
	// {1,-2,3,-4,5,1,8,9,5,6};
	// {1,-2,3,-4,5,1,8};
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
	int count = 0;
	while(current)
	{
		count++; // Общее кол-во элементов в списке
		
		printf("%d ", current->data);
		current = current->Next;
	}
	
	// Значение count
	if(count % 2 == 0)
		count = count / 2;
	else
		count = (count / 2) + 1;
	
	// Деление списка пополам и запись первой половины элементов в новый (-New-)
	current = First;
	struct List* last = NULL;
	for(i = 0; i < count; i++)
	{
		addToList(&Second, current->data);
		current = current->Next;
	}
	
	// Удаление элементов из старого списка, которые добавили в новый (-Old-)
	struct List* previous = NULL;
	current = First;
	i = 0;
	
	while(current)
	{
		i++;
		if(previous == NULL && i <= count)
		{
			First = First->Next;
			current = current->Next;
			continue;
		}
		if(previous != NULL && i <= count)
		{
			previous->Next = current->Next;
			current = current->Next;
			continue;
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
