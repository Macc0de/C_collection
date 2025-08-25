// Шаблон для задания по Спискам
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int Value;
	struct List* Next;
} *First;

void addToList(int value)
{
    struct List* new_node = malloc(sizeof(struct List));
	
    new_node->Value = value;
    new_node->Next = NULL;
	
    if(First == NULL)
	{
        First = new_node;
        return;
    }
	
    struct List* cur = First;
    while(cur->Next != NULL)
	{
        cur = cur->Next;
    }
    cur->Next = new_node;
}

// void func() {...}

int main()
{
	int array[] = {3,1,4,1,6,1,1}; 
	int i, j;
	
	for(i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		addToList(array[i]);
	}
	
	struct List* cur = First;
	while(cur != NULL) // Первый вывод
	{
		printf("%d ", cur->Value);
		cur = cur->Next;
	}
	
	printf("\n");
	func();
	printf("\n");
	
	cur = First;
	while(cur != NULL) // Второй вывод
	{
		printf("%d ", cur->Value);
		cur = cur->Next;
	}

	return 0;
}
