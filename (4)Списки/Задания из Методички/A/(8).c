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

// Подсчёт кол-ва элементов списка
int count_list(struct List* head)
{
	int count = 0;
	struct List* current = head;
	while (current)
	{
		count++;
		current = current->Next;
	}
	return count;
}

int main()
{
	int array[] = {2,3,4,5,6}; // {2,3,4,5,6,7} 
	//int array[10];
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < 5; i++) // 6
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	int len_list = count_list(First);
	struct List* elem = First;
	struct List* previous = NULL;
	
	if(len_list % 2 == 0)
	{
		int index_first = (len_list / 2) - 1; // Если 2 средних
		i = 0;
		
		while(elem)
		{
			if(i == index_first)
			{
				previous->Next = elem->Next->Next;
				break;
			}
			
			i++; // Индекс элементов
			previous = elem;
			elem = elem->Next;
		}
	}
	else // Нечётное
	{
		int index_first = len_list / 2;
		i = 0;
		
		while(elem)
		{
			if(i == index_first)
			{
				previous->Next = elem->Next;
				break;
			}
			
			i++;
			previous = elem;
			elem = elem->Next;
		}
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
