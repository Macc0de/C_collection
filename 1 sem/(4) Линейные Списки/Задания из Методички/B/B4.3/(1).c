#include <stdio.h>
#include <stdlib.h>

struct List
{
	int Info;
	struct List* Next;
	struct List* Previous;
} *First;

void addToList(struct List** head, int value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
    new_List->Info = value;
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

int main()
{
	int array1[] = {6,80,8,9,10,11}; //{1,3,5,8,9,10};
	//{2,3,4,5,6,7,8};
	int i;
	for (i = 0; i < sizeof(array1)/sizeof(int); i++)
	{
		addToList(&First, array1[i]);
	}
	
	struct List* current = First;
	while (current) // Первый вывод
	{
		printf("%d ", current->Info);
		current = current->Next;
	}

	// Проверка на то отсортирован ли
	current = First;
	int flag = 0;
	
	while(current->Next)
	{
		if(current->Next->Info < current->Info)
		{
			flag = 1;
			break;
		}
		current = current->Next;
	}
	if(flag) // Не отсортирован -> Сортируем
	{
		printf("\nList is not sorted.\n");
		printf("Result of sorting list: ");
		while(flag)
		{
			flag = 0;
			current = First;
			while(current->Next)
			{
				if (current->Info > current->Next->Info)
				{
					int temp = current->Info;
					current->Info = current->Next->Info;
					current->Next->Info = temp;
					
					flag = 1;
				}
				current = current->Next;
			}
		}
		
		// Вывод уже отсортированного
		current = First;
		while(current) 
		{
			printf("%d ", current->Info);
			current = current->Next;
		}
	}
	else
		printf("\nList is sorted.");
	
	// Ввод K и L + удаление
	int K = 5, L = 9; //scanf
	if(K < L) // Проверка K < L
	{
		current = First;
		while(current)
		{
			if(current->Info > K && current->Info < L) // > 0 и < 5 -> Удалить
			{
				if(current->Previous && current->Next)
				{
					current->Previous->Next = current->Next;
					current->Next->Previous = current->Previous;
				}
				else if(current->Previous && !current->Next) // Для последнего элемента, если удовл. условие
				{
					current->Previous->Next = NULL;
				}
				else // Для самого первого элемента(нет предыдущего элемента)
				{
					current = current->Next;
					current->Previous = NULL; // Предыдущего элемента нету -> текущий элемент самый первый
					First = current; // Переприсваиваем самое начало списка на следующий элемент
					continue;
				}
			}
			current = current->Next;
		}
	}
	else
		printf("Incorrect values of K, L.");
	
	// Вывод
	printf("\n");
	current = First;
	while(current) 
	{
		printf("%d ", current->Info);
		current = current->Next;
	}
	
	return 0;
}
