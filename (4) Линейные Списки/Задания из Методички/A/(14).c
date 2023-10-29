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

void swapLists(struct List** head, int elem, int elem_next)
{
	// Поиск первого элемента
    struct List* prev_elem = NULL;
	struct List* curr_elem = *head;
    while(curr_elem && curr_elem->data != elem) 
	{
        prev_elem = curr_elem;
		
        curr_elem = curr_elem->Next;
    }
 
    // Поиск второго элемента(после первого)
    struct List* prev_elem_next = NULL;
	struct List* curr_elem_next = *head;
    while(curr_elem_next && curr_elem_next->data != elem_next) 
	{
        prev_elem_next = curr_elem_next;
        curr_elem_next = curr_elem_next->Next;
    }
	
	// (1) Проверка на то вдруг prev_elem не является head списка
    if(prev_elem != NULL)
        prev_elem->Next = curr_elem_next;
    else // Иначе сделать его - head списка
		// Для переворота значений(взаимодействие с указателями)
        *head = curr_elem_next; // Начало списка - второй элемент(поменяли)
 
    // (2) Проверка на то вдруг prev_elem_next не является head списка
    if(prev_elem_next != NULL)
        prev_elem_next->Next = curr_elem;
    else // Иначе сделать его - head списка
        *head = curr_elem;
	
    // Процесс перестановки
    struct List* temp = curr_elem_next->Next;
	
    curr_elem_next->Next = curr_elem->Next;
    curr_elem->Next = temp;
}

int main()
{
	int array[] = {1,2,3,4,5,6,7}; // {5,4,10,8,1,3,7,2,100};
	// {1,2,3,4,5,6,10};
	int i;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	int razmer = sizeof(array)/sizeof(int);
	for(i = 0; i < razmer; i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	for(struct List* elem = First; elem && elem->Next; elem = elem->Next)
	{
		swapLists(&First, elem->data, elem->Next->data);
	}
	
	// Если кол-во элементов нечётное - удалить лишний
	if(razmer % 2 != 0)
	{
		struct List* previous = NULL;
		current = First;
		
		while(current->Next)
		{
			previous = current;
			current = current->Next;
		}
		previous->Next = NULL; // Последний элем
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
