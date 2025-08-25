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
	int array[] = {1,8,10,3,4,2,3,7,-3,20};
	//int array[10];
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First, array[i]);
	}
	
	int count = 0, sum = 0;
	struct List* current = First;
	
	while(current) // Первый вывод
	{
		count++;
		sum += current->data;
		
		printf("%d ", current->data);
		current = current->Next;
	}
	
	/* Проверки :
	printf("\n|%d|", count);
	printf("\n*%d* mid: %d", sum, sum/count); */
	
	current = First;
	struct List* previous = NULL;
	
	printf("\n");
	while(current)
	{
		if(current->data > sum/count)
			printf("%d ", current->data);
		/* if(current->data <= sum/count && previous == NULL)
		{
			First = First->Next;
			current = current->Next;
			continue;
		}
		if(current->data <= sum/count && previous != NULL)
		{
			previous->Next = current->Next;
			current = current->Next;
			continue;
		}
		previous = current; */
		
		current = current->Next;
	}
	
	/*printf("\n");
	current = First;
	while(current) // Второй вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}*/
	
	return 0;
}
