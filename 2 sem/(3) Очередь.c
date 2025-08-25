// Удаляет элементы с начала и Добавляет в конец
// 2 3 -2 2 -6 1.
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int data;
	struct Queue* Next;
};

int push(struct Queue** head, int data) // Очередь и Список
{
	struct Queue* new_node = (struct Queue*)malloc(sizeof(struct Queue));

	if (new_node == NULL)
		return 1;

	new_node->data = data;
	new_node->Next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return 0;
	}

	struct Queue* current = *head;
	while (current->Next != NULL)
	{
		current = current->Next;
	}
	current->Next = new_node;

	return 0;
}

void pop(struct Queue** head) // Очередь
{
	struct Queue* temp = (*head);
	(*head) = (*head)->Next;
	free(temp);
}

int inputList(struct Queue** head) // Список
{
	int num, res;
	while(scanf("%d", &num))
	{
		res = push(head, num); // Добавление в список
		if (res == 1) // Ошибка выделения памяти
			return 1;
	}
	return 0;
}

void print(struct Queue* head)
{
	if(head == NULL) // Если удалили все элементы
	{
		printf("0");
		return;
	}
	
	struct Queue* current = head;
	while(current != NULL) // Вывод очереди
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
	struct Queue* head = NULL, *twohead = NULL, *current;
	int flag = 0;
	inputList(&head); // Список
	getchar();
	
	int i, last = 1;
	current = head;
	if(current == NULL) // Если список пуст
		print(head);
	
	while(current != NULL)
	{
		i = 0;
		if(current->data > 0)
		{
			flag = 1; // 0 0 0
			while(i < current->data)
			{
				push(&twohead, last);
				last++;
				i++;
			}
		}
		else if(current->data < 0)
		{
			flag = 1; // 0 0 0
			while(i < (current->data * (-1)))
			{
				if(twohead == NULL) // Не осталось элементов в очереди
					break;
				
				pop(&twohead);
				i++;
			}
		}
		else
		{
			current = current->Next;
			continue;
		}
		
		print(twohead); // Вывод текущий
		//if(current->Next != NULL)
		printf("\n");
		
		current = current->Next;
	}
	
	if(twohead == NULL && flag == 0) // 0 0 0
		printf("0");
	
	free_memory(head, twohead);
	
	return 0;
}
