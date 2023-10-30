/*
Вводится последовательность целых чисел. Длина последовательности неизвестна. Конец последовательности – точка.

Сформировать из последовательности чисел однонаправленный линейный список, добавляя элементы в конец списка.
Если список пуст, вывести NULL и завершить работу программы.
Удалить из списка все четные элементы, стоящие на нечетной позиции, и вывести получившийся список на экран.

Если получившийся список пуст, вывести NULL.

Input:
2 4 6 -2 -4.
Output:
4 -2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

struct List
{
	int data;
	struct List* Next;
} *First;

void addToList(struct List** head, int value)
{
    struct List* new_node = (struct List*)malloc(sizeof(struct List));
	
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

void Reverse(struct List** head)
{
	struct List *prev, *cur, *temp;
	for (prev = NULL, cur = *head; cur; )
	{
		temp = cur->Next;
		
		cur->Next = prev;
		prev = cur;
		cur = temp;
	}
	*head = prev;
}

int main()
{
	int i, count = 0;
	char** array = (char**)malloc(N * sizeof(char*));
	for(i = 0; i < N; i++)
	{
		array[i] = (char*)malloc(N * sizeof(char));
	}
	
	for(i = 0; ; i++)
	{
		scanf("%s", array[i]);
		count++;
		if(array[i][strlen(array[i]) - 1] == '.')
		{
			
			array[i][strlen(array[i]) - 1] = '\0';
			break;
		}
	}

	for(i = 0; i < count && array[i][0]; i++)
	{
		addToList(&First, atoi(array[i]));
	}
	
	if (First == NULL) 
	{
		printf("NULL");
		return 0;
	}
	
	struct List* current = First;
	struct List* previous = NULL;
	i = 1;
	
	while(current)
	{
		i++; // Отсчёт элементов с 1
		if (i % 2 == 0 && current->data % 2 == 0 && previous == NULL)
		{
			current = current->Next;
			First = First->Next;
			continue;
		}
		if (i % 2 == 0 && current->data % 2 == 0 && previous != NULL)
			previous->Next = current->Next;
		
		previous = current;
		current = current->Next;
	}
	
	current = First;
	if(current == NULL) // Проверка измененного списка
	{
		printf("NULL");
		return 0;
	}
	
	while(current)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	while(First) 
	{
        struct List* temp = First->Next;
        free(First);
		First = temp;
    }
	for(i = 0; i < N; i++) 
	{
        free(array[i]);
    }
    free(array);
	
	return 0;
}
