#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
	struct List* Previous;
} *First1, *First2;

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
  
		// second_curr - след. элемент после first_curr(Для них проверки пройдены)
        second_curr->Next = first_next;
		second_curr->Previous = first_curr;
        first_curr->Next = second_curr;
		
		if (first_next)
			first_next->Previous = second_curr;
	
        first_curr = first_next;
        second_curr = second_next;
    }
	
	// (3) Удаление лишних элементов первого и второго списка(+free()), если есть
	struct List* temp = NULL;
	if(first_curr)
	{
		first_curr->Previous->Next = NULL;
		while(first_curr)
		{
			temp = first_curr->Next;
			free(first_curr); // Тут теряем Next, по этому исп. temp
			first_curr = temp;
		}
	}
	if(second_curr)
	{
		second_curr->Previous->Next = NULL;
		while(second_curr)
		{
			temp = second_curr->Next;
			free(second_curr);
			second_curr = temp;
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
	for(i = 0; i < sizeof(array1)/sizeof(int); i++)
	{
		addToList(&First1, array1[i]);
	}
	for(i = 0; i < sizeof(array2)/sizeof(int); i++)
	{
		addToList(&First2, array2[i]);
	}
	
	struct List* current = First1;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	printf("\n");
	current = First2;
	while(current) // Второй вывод
	{
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
	
	return 0;
}
