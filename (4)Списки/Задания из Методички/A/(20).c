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

	current = First;
	struct List* previous = NULL;
	while(current)
	{
		if(current->data < 0)
		{
			// Добавление '-' элементов в новый список из старого
			addToList(&Second, current->data);
			// Удаление '-' элементов из старого
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
	
	// Сортировка нового списка
	int flag;
	while(flag)
	{
		flag = 0;
		current = Second;
		while(current->Next != NULL)
		{
			if(current->data > current->Next->data)
			{
				int temp = current->data;
				current->data = current->Next->data;
				current->Next->data = temp;
				
				flag = 1;
			}
			current = current->Next;
		}
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
