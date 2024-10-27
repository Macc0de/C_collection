// Элементы добавляются: в начало - число '+' Четное; В конец - число '+' НеЧетное.
// Удаляются: из начала - число '-' НеЧетное; C конца - число '-' Четное.
// 2 3 -2 1 -5 1.
// 2 0 0 -2.
#include <stdio.h>
#include <stdlib.h>

struct Deck
{
	int data;
	struct Deck* Next;
};

int right_push(struct Deck** head, int value) // Очередь и Список
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
	struct Deck *new_node;
	new_node = (struct Deck*)malloc(sizeof(struct Deck));
	
	new_node->Next = *head;
	new_node->data = value;
	
	*head = new_node;
}

void right_pop(struct Deck** head) // Очередь
{
	if((*head) != NULL && (*head)->Next == NULL) // 1 элемент остался
	{
		(*head) = NULL;
		return;
	}
	
	struct Deck* current = *head, *p_last = NULL;
	while(current->Next != NULL)
	{
		if(current->Next->Next == NULL)
		{
			p_last = current;
		}

		current = current->Next;
	}
	
	if(p_last == NULL)
		return;

	p_last->Next = NULL;
}

void left_pop(struct Deck** head) // Очередь
{
	struct Deck* temp = (*head);
	(*head) = (*head)->Next;
	free(temp);
}

int inputList(struct Deck** head) // Список
{
	int num, res;
	while(scanf("%d", &num))
	{
		res = right_push(head, num); // Добавление в список
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
	while(current != NULL) // Вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

void free_memory(struct Queue* head, struct Queue* twohead)
{
	struct Queue* temp, *current = head;

	while(current != NULL)
	{
		temp = current->Next;
		free(current);

		current = temp;
	}

	current = twohead;
	while(current != NULL)
	{
		temp = current->Next;
		free(current);

		current = temp;
	}
}

int main()
{
	struct Deck* head = NULL, *twohead = NULL, *current;
	inputList(&head); // Список
	getchar();
	
	int i, last, flag = 0;
	current = head;
	if(current == NULL) // Если список пуст
		print(head);
	
	while(current != NULL)
	{
		i = 0;
		last = 1;
		if(current->data > 0)
		{
			flag = 1; // 0 0 0
			if(current->data % 2 == 0) // Добавление слева
			{ // 2 - 1 2
				while(i < current->data)
				{ 
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
			flag = 1; // 0 0 0
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
					
					left_pop(&twohead); // Удаление
					i++;
				}
			}
		}
		else
		{
			current = current->Next;
			continue;
		}
		
		print(twohead); // Вывод текущий
		printf("\n");
		
		current = current->Next;
	}
	
	if(twohead == NULL && head != NULL && flag == 0)
		printf("0");
	
	// Очистка памяти
	free_memory(head, twohead);
	
	return 0;
}
