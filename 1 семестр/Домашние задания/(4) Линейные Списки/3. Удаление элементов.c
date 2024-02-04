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
	
	if (head == NULL) 
	{
		printf("NULL");
		return 0;
	}
	
	int k, n;
	getchar();
	scanf("%d %d", &k, &n);
	
	i = 1;
	while(head) // Проверка головы
	{
		if(i == k || i == n)
		{
			head = head->Next;
			i++; // Сместился индекс
		}
		else
		{
			i++; // Сместился индекс
			break;
		}
	}
	
	struct List *current = head, *prev;
	if(head)
	{
		while(current->Next) // Проверка всех остальных
		{
			prev = current->Next;
			if(i == k || i == n)
			{
				current->Next = prev->Next;
			}
			else
				current = current->Next;
			i++;
		}
	}
	
	current = head;
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
