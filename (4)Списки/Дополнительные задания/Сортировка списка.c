#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
} *First;

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
	int array[] = {1,-2,3,-4,5,1};
	//int array[10];
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for (i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while (current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	int flag;
	struct List* ptr2 = NULL;
	current = First;

	while(flag) // != 0
	{
		flag = 0;
		current = First;
		while (current->Next != ptr2) // != NULL
		{
			if (current->data > current->Next->data)
			{
				int temp = current->data;
				current->data = current->Next->data;
				current->Next->data = temp;
				
				flag = 1;
			}
			current = current->Next;
		}
		ptr2 = current; // Не нужно
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
