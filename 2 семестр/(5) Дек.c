#include <stdio.h>
#include <stdlib.h>

struct Deck
{
	int data;
	struct Deck* Next;
};

int right_push(struct Deck** head, int value)
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

int left_push(struct Deck** head, int value)
{
	struct Deck *new_node, *current;
	current = *head;
	new_node = (struct Deck*)malloc(sizeof(struct Deck));
	
	new_node->Next = current;
	new_node->data = value;
	
	*head = new_node;
}	

int right_pop(struct Deck** head) // Удаляет с начала
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

int left_pop(struct Deck** head) // Удаляет с начала
{
	int last = (*head)->data;
	(*head) = (*head)->Next;
	return last;
}

int inputList(struct Deck** head) // Создание очереди
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
	
	struct Deck* current = head, *last = NULL;
	while(last != head)
	{
		while(current->Next != last)
		{
			current = current->Next;
		}
		printf("%d ", current->data);
		last = current;
		current = head;
	}
}

int main()
{
	struct Deck* head = NULL, *twohead = NULL, *current;
	inputList(&head);
	getchar();
	
	int i, last;
	current = head;
	if(current == NULL) // ??
		print(twohead);
	
	while(current != NULL)
	{
		i = 0;
		last = 1;
		if(current->data > 0)
		{
			if(current->data % 2 == 0) // Добавление вправо
			{ // 2 - 1 2
				while(i < current->data)
				{
					right_push(&twohead, last);
					last++;
					i++;
				}
			}
			else // Добавление влево
			{ // 3 - 3 2 1
				while(i < current->data)
				{
					left_push(&twohead, last);
					last++;
					i++;
				}
			}
		}
		else if(current->data < 0)
		{
			if(current->data % 2 == 0) // Удаление влево
			{
				while(i < (current->data * (-1)))
				{
					if(twohead == NULL) // Нет элементов в очереди
						break;
						
					left_pop(&twohead);
					i++;
				}
			}
			else // Удаление вправо
			{
				while(i < (current->data * (-1)))
				{
					if(twohead == NULL) // Нет элементов в очереди
						break;
						
					if(right_pop(&twohead) == 0)
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
