/* (Реверс списка)
Вводится последовательность целых чисел. Длина последовательности неизвестна. Конец последовательности – точка.

Сформировать из последовательности чисел однонаправленный линейный список, добавляя элементы в конец списка.
Если список пуст, вывести NULL и завершить работу программы.
Поменять местами в списке первый и последний элементы, второй и предпоследний и т.д., и вывести получившийся список на экран.

Обменивать нужно именно элементы списка, а не их информационные части.

Input:
2 3 5 4 1.
Output:
1 4 5 3 2
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

void addToList(struct List* First, int number)
{
	struct List *new_node;
	new_node = (struct List*)malloc(sizeof(struct List));
	
	new_node->data = number;
	new_node->Next = NULL;
	
	if(First == NULL)
	{
		First = new_node;
		return;
	}
	
	struct List* current = First;
	while(current->Next)
		current = current->Next;
	
	current->Next = new_node;
}

void Reverse(struct List** head)
{
	struct List *prev, *cur, *temp;
	int i = 0;
	for (prev = NULL, cur = *head; cur; )
	{
		temp = cur->Next;
		
		cur->Next = prev;
		prev = cur;
		cur = temp;
		i++;
	}
	*head = prev;
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
			addToList(head, num);
		i++;
	}
	
	if(head == NULL) 
	{
		printf("NULL");
		return 0;
	}
	
	Reverse(&head);
	
	struct List* current = head;
	if(current == NULL)
	{
		printf("NULL");
		return 0;
	}
	
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
