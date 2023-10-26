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
	int array[] = {-18,-20,-21,3,4,-5,6,7,8}; 
	//int array[10];
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for (i = 0; i < 8; i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while (current)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	current = First;
	int min = First->data;
	while(current)
	{
		if (current->data % 2 != 0 && current->data < min)
			min = current->data;
		current = current->Next;
	}
	
	// Последний элемент списка
	// Без этого - current = Null
	current = First;
	while (current->Next != NULL) 
	{
        current = current->Next;
    }
	
	struct List* elem = First;
	struct List* previous = NULL;
	while (elem)
	{
		if (elem->data == min && previous == NULL) // Если минимальный самый первый
		{
			current->Next = elem; // current - последний элем в списке
			// current стал предпоследним
			First = First->Next; // Вместо самого первого элемента станет следующий элем. самым первым
			elem->Next = NULL;
			break;
		}
		if (elem->data == min && previous != NULL) // Если минимальный не самый первый
		{
			previous->Next = elem->Next;
			current->Next = elem; // Последний элемент = текущий
			
			//elem->Next = First; // Зациклить
			elem->Next = NULL; // Без этого по кругу указывает на друг-друга
			// Указываем что последний
			break;
		}
		previous = elem;
		elem = elem->Next;
	}
	
	printf("\n");
	current = First;
	while (current) // Второй вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	return 0;
}
