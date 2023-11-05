// Создание и вывод двусвязного списка
#include <stdio.h>
#include <stdlib.h>

struct List // Двусвязный список
{
	int data;
	struct List* Next;
	struct List* Previous;
} *First1, *First2;

// Добавление элемента в список
void addToList(struct List** head, int value)
{
    struct List* new_node = malloc(sizeof(struct List));
	
    new_node->data = value;
    new_node->Next = NULL;
	new_node->Previous = NULL;
	
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
	new_node->Previous = current;
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
	
	// Добавление элементов из массива в узел списка
	for (i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First1, array[i]);
	}
	
	struct List* current = First1;
	while (current) // Первый вывод в прямом порядке через Next
	{
		printf("%d ", current->data);
		if (current->Next)
			current = current->Next;
		else
			break;
	}
	
	printf("\n");
	while (current) // Второй вывод в обратном порядке через Previous
	{
		printf("%d ", current->data);
		current = current->Previous;
	}
	
	return 0;
}
