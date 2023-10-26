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
	int array[] = {5,4,10,8,1,3,7,0,-2,-4,-6,5,7,6}; // {1,8,10,3,4,-24,3,7,-3,-20};
	// {5,4,10,8,1,3,7,2};
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	current = First;
	while(current->Next) // Последний элемент списка
	{
		current = current->Next;
	}
	
	// Для цикла
	struct List* temp = NULL;
	int min = First->data + 1; // (самый первый элемент списка чтобы был < min)
	int count = 0;

	struct List* elem = First;
	struct List* previous = NULL;
	while(elem)
	{
		// Первый минимальный, проверяем меньше ли след. элемент чем он и тд.
		if(elem->data < min && previous == NULL && count < 5) // Если минимальные елементы - первые(идут друг за другом в начале списка)
		{
			min = elem->data;
			temp = First->Next;
			
			current->Next = First; // следующий элем после последнего - это First(min)
			First->Next = NULL; // самый последний элемент списка указывает на NULL
			
			current = First; // Переставляем указатель на конец списка
			First = temp; // Указатель на первый элемент
			elem = temp; // Для след. итераций
			
			count++; // Счетчик
			continue;
		}
		if(elem->data < min && previous != NULL && count < 5) // Если минимальные не чередуются друг за другом
		{
			min = elem->data;
			
			previous->Next = elem->Next; // Удаляем элемент из позиции
			current->Next = elem; // Добавляем в конец
			elem->Next = NULL; // Последний элемент списка указывает на NULL
			
			current = elem; // Переставляем указатель на конец списка
			elem = previous->Next; // elem = elem->Next
			
			count++;
			continue;
		}
		previous = elem;
		elem = elem->Next;
	}
	
	printf("\n");
	current = First;
	while(current) // Второй вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	return 0;
}
