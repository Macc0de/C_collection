/*
Вводится последовательность целых чисел. Длина последовательности неизвестна. Конец последовательности – точка.
Далее вводятся два целых числа k и n.

Сформировать из последовательности чисел однонаправленный линейный список, добавляя элементы в конец списка.
Если список пуст, вывести NULL и завершить работу программы.
Удалить из списка элементы с номерами k и n и вывести получившийся список.

Если получившийся список пуст, вывести NULL.
Если в списке нет элементов с номерами k и n, вывести исходный список.
Если в списке только есть только один элемент с номером k или с номером n, удаляется один элемент.

Input:
5 4 3 2 1.
2 3
Output:
5 2 1
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
	
	int k, n;
	scanf("%d %d", &k, &n);
	
	struct List* current = First;
	struct List* previous = NULL;
	i = 1;
	
	while(current)
	{
		if (i == k || i == n) // Проверка индекса элемента(отсчёт с 1)
		{
			i++;
			if(previous == NULL)
			{
				current = current->Next;
				First = First->Next;
				continue;
			}
			else if(previous != NULL)
			{
				previous->Next = current->Next;
				current = current->Next;
				continue;
			}
		}
		
		previous = current;
		i++;
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
