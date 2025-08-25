#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
} *First;

// Добавление элемента в список
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
	int array[] = {2,1,10,3,4,5,6,7,8};
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
	while (current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	current = First; // Чтобы снова был первым
	struct List* previous = NULL;
	while(current)
	{
		// Если два четных подряд - норм
		if (current->data % 2 == 0 && previous == NULL) // Если первый элемент четный
		{
			current = current->Next; //current = First->Next;
			First = First->Next; // Для первого элема
			continue;
		}
		if (current->data % 2 == 0 && previous != NULL)
			previous->Next = current->Next; // Для предыдущего элемента
		// current = current->Next;
		// continue; // или с if

		/* Для двух if надо if else(нечетное)
		if (current->data % 2 == 0)
		{
			previous->Next = current->Next;
		}
		else
			previous = current;
		current = current->Next;
		*/
		previous = current;
		current = current->Next;
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
