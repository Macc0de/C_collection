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
	int array[] = {-18,-20,-21,3,4,5,6,7,8}; // {-18,-20,-21,3,4,5,6,7,8};
	// {-9,-5,-3,1,-6,2};
	// {3,2,-4,0,-9,2,-1,4}
	
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	// Последний элемент
	current = First;
	while (current->Next) 
	{
        current = current->Next;
    }
	
	struct List* elem = First;
	struct List* previous = NULL;
	int flag = 1;
	struct List* last = current;
	
	while(flag) // Когда дойдет до последнего элемента проверка, то цикл не выполн. (чтобы не зациклилось)
	{
		// Сравнивает указатель
		if(elem == last) // Вдруг последний элемент положительный
			flag = 0;
		
		if(elem->data < 0 && elem->data % 2 != 0)
		{
			if(previous == NULL)
			{
				struct List* tmp = First->Next;
				
				current->Next = First;
				First->Next = NULL; 
				current = First;
				
				First = tmp;
				elem = tmp;
				continue;
			}
			if(previous != NULL)
			{
				struct List* tmp = elem->Next;
				previous->Next = tmp;
				
				elem->Next = NULL;
				current->Next = elem;
				
				current = current->Next;
				elem = tmp; // Текущий 
				continue;
			}
			// Если без continue - else { previous=elem; elem=elem->Next; }
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
