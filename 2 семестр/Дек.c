// Элементы добавляются: в начало - число '+' Четное; В конец - число '+' НеЧетное.
// Удаляются: из начала - число '-' НеЧетное; C конца - число '-' Четное.
// 2 3 -2 1 -5 1.
#include <stdio.h>
#include <stdlib.h>

struct Deck
{
	int data;
	struct Deck* Next;
};

int addToList(struct Deck** head, int data) // Список
{
	struct Deck* new_node = (struct Deck*)malloc(sizeof(struct Deck));
	
	if (new_node == NULL)
		return 1;
	
	new_node->data = data;
	new_node->Next = NULL;
	
	if (*head == NULL)
	{
		*head = new_node;
		return 0;
	}
	
	struct Deck* current = *head;
	while (current->Next != NULL)
	{
		current = current->Next;
	}
	current->Next = new_node;
	
	return 0;
}

int right_push(struct Deck** head, int value) // Очередь
{
	struct Deck* new_node = (struct Deck*)malloc(sizeof(struct Deck));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
	new_node->Next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return 0;
	}

	struct Deck* current = *head;
	while (current->Next != NULL)
	{
		current = current->Next;
	}
	current->Next = new_node;

	return 0;
}

int left_push(struct Deck** head, int value) // Очередь
{
	struct Deck *new_node, *current;
	current = *head;
	new_node = (struct Deck*)malloc(sizeof(struct Deck));
	
	new_node->Next = current;
	new_node->data = value;
	
	*head = new_node;
}

int right_pop(struct Deck** head) // Очередь
{
	struct Deck* current = *head, *p_last = NULL;
	while(current->Next != NULL)
	{
		if(current->Next->Next == NULL)
			p_last = current;
		current = current->Next;
	}
	
	if((p_last == NULL))
		return 0;

	int last = current->data;
	p_last->Next = NULL;
	return last; // Удаляемый последний(инфо. часть) сохраняем
}

int left_pop(struct Deck** head) // Очередь
{
	int last = (*head)->data;
	(*head) = (*head)->Next;
	return last;
}

int inputList(struct Deck** head) // Список
{
	int num, res;
	while(scanf("%d", &num))
	{
		res = addToList(head, num); // Добавление в список
		if (res == 1) // Ошибка выделения памяти
			return 1;
	}
	return 0;
}

void print(struct Deck* head)
{
	if(head == NULL) // Если удалили все элементы
	{
		printf("0");
		return;
	}
	
	struct Deck* current = head;
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

int main()
{
	struct Deck* head = NULL, *twohead = NULL, *current;
	inputList(&head); // Список
	getchar();
	
	int i, last;
	current = head;
	if(current == NULL) // Если список пуст
		print(twohead);
	
	while(current != NULL)
	{
		i = 0;
		last = 1;
		if(current->data > 0)
		{
			if(current->data % 2 == 0) // Добавление слева
			{
				while(i < current->data)
				{ // 2 - 1 2
					left_push(&twohead, last);
					last++;
					i++;
				}
			}
			else // Добавление справа - НеЧетное
			{ // 3 - 3 2 1
				while(i < current->data)
				{
					right_push(&twohead, last);
					last++;
					i++;
				}
			}
		}
		else if(current->data < 0)
		{
			if(current->data % 2 == 0) // Удаление справа
			{
				while(i < (current->data * (-1)))
				{
					if(twohead == NULL) // Нет элементов в очереди
						break;
						
					right_pop(&twohead);
					i++;
				}
			}
			else // Удаление слева - НеЧетное
			{
				while(i < (current->data * (-1)))
				{
					if(twohead == NULL) // Нет элементов в очереди
						break;
					
					if(left_pop(&twohead) == 0)
					{
						twohead = NULL;
						break;
					}
					i++;
				}
			}
		}
		
		print(twohead); // Вывод текущий
		//if(current->Next != NULL)
		printf("\n");
		
		current = current->Next;
	}
	
	return 0;
}
