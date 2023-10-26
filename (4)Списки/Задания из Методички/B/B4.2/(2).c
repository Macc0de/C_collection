#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
	struct List* Previous;
} *First1, *First2, *New;

void addToList(struct List** head, int value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
    new_List->data = value;
    new_List->Next = NULL;
	new_List->Previous = NULL;
	
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
	new_List->Previous = current;
}

void merge(struct List* first, struct List** second)
{
    struct List* first_curr = first, *second_curr = *second;
  
    while(first_curr && second_curr)
    {
        struct List* first_next = first_curr->Next;
        struct List* second_next = second_curr->Next;
  
        second_curr->Next = first_next;
		second_curr->Previous = first_curr;
        first_curr->Next = second_curr;
		
		if(first_next)
			first_next->Previous = second_curr;
	
        first_curr = first_next;
        second_curr = second_next;
    }
	
	// (2) Добавление элементов в New, если есть лишние в первом списке
	if(first_curr) // (из первого списка)
	{
		while(first_curr)
		{
			addToList(&New, first_curr->data);
			first_curr = first_curr->Next;
		}
	}
	
	// Если есть оставшиеся элементы во втором списке
	if(second_curr) // (из второго списка)
	{
		struct List* current = first;
		while(current->Next) // Последний элемент результируюшего списка
		{
			current = current->Next;
		}
		// Склеивание: последний элемент основного списка + остаток второго
		current->Next = second_curr; // second_curr(8)->9->10(сразу несколько указателей)
	}
	*second = second_curr; // Присваиваем старое значение(Второй список) - чтобы оставались лишние элементы(если есть)
}

int main()
{
	// В результирующий список дописывает также, если есть, лишние элементы которые в array1
	int array1[] = {1,3,5}; //{1,3,5,8,9,10};
	int array2[] = {2,4,6}; //{2,4,6,8,9,10};
	
	int i;
	for (i = 0; i < sizeof(array1)/sizeof(int); i++)
	{
		addToList(&First1, array1[i]);
	}
	for (i = 0; i < sizeof(array2)/sizeof(int); i++)
	{
		addToList(&First2, array2[i]);
	}
	
	int count1 = 0, count2 = 0;
	struct List* current = First1;
	while(current) // Первый вывод
	{
		count1++;
		printf("%d ", current->data);
		
		if (current->Next)
			current = current->Next;
		else
			break;
	}
	
	printf("\n");
	current = First2;
	while(current) // Второй вывод
	{
		count2++;
		
		printf("%d ", current->data);
		current = current->Next;
	}
	
	merge(First1, &First2);
	
	// Вывод
	printf("\n");
	current = First1;
	while(current) 
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	// (2) Вывод New, если есть лишние элементы в первом списке
	current = New;
	if(current == NULL)
		printf("\nNo excessive elements in first list.");
	else
	{
		printf("\nNew list of first list: ");
		while(current)
		{
			printf("%d ", current->data);
			current = current->Next;
		}
	}
	
	// (2) Добавление в New лишних элементов из второго списка + Вывод
	current = First2;
	if(current == NULL)
		printf("\nNo excessive elements in second list.");
	else
	{
		printf("\nNew list of second list: ");
		while(current)
		{
			addToList(&New, current->data);
			current = current->Next;
		}
		
		current = New;
		while(current) // Вывод нового списка
		{
			printf("%d ", current->data);
			current = current->Next;
		}
	}
	
	return 0;
}
