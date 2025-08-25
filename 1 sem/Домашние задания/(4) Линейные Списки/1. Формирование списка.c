/*
Вводится последовательность целых чисел. Длина последовательности неизвестна. Конец последовательности – точка.

Сформировать из последовательности чисел однонаправленный линейный список, добавляя элементы 
в начало списка, и вывести список на экран.

Если список пуст, вывести NULL и завершить работу программы.

Input:
1 2 3 4 5.
Output:
5 4 3 2 1
*/
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
};

struct List* init(int number)
{
	struct List* First;
	First = (struct List*)malloc(sizeof(struct List));
	
	First->data = number;
	First->Next = NULL;
	
	return First;
}

void addToList(struct List** First, int number) // Добавление элементов в начало, а не в конец
{
	struct List *temp, *current;
	current = *First;
	temp = (struct List*)malloc(sizeof(struct List));
	
	temp->Next = current;
	temp->data = number;
	
	*First = temp;
}

int main()
{
	int i = 0, num;
	struct List* head = NULL;

	while(scanf("%d", &num))
	{
		if(i == 0)
		{
			head = init(num);
		}
		else 
			addToList(&head, num);
		
		i++;
	}
	
	if(head == NULL)
	{
		printf("NULL");
		return 0;
	}
	
	struct List* current = head;
	while(current)
	{
		printf("%d ", current->data);
		
		current = current->Next;
	}
	
	while(head)
	{
        struct List* temp = head->Next;
        free(head);
		head = temp;
    }
	
	return 0;
}
