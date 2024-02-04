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

void Reverse(struct List** head) // head - First
{
	struct List *prev, *cur, *temp;
	for (prev = NULL, cur = *head; cur; )
	{
		temp = cur->Next;
		
		cur->Next = prev;
		prev = cur;
		cur = temp;
	}
	*head = prev; // Справо-налево
	
	// Вывод
	printf("\n");
	cur = *head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->Next;
	}
}

int main()
{
	int array[] = {1,2,3,4,5}; 
	//int array[10];
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for (i = 0; i < 5; i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while (current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	Reverse(&First);

	return 0;
}
