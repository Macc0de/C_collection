#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int data;
	struct Queue* Next;
};

int push(struct Queue** head, int value)
{
	struct Queue* new_node = (struct Queue*)malloc(sizeof(struct Queue));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
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

int pop(struct Queue** head) // Удаляет с начала
{
	int last = (*head)->data;
	(*head) = (*head)->Next;
	return last;
}

int inputList(struct Queue** head) // Создание очереди
{
	int num, res;
	while (scanf("%d", &num))
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
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

int main()
{
	struct Queue* head = NULL, *twohead = NULL, *current;
	inputList(&head);
	getchar();
	
	int i, last = 1;
	current = head;
	if(current == NULL) // ??
		print(twohead);
	
	while(current != NULL)
	{
		i = 0;
		if(current->data > 0)
		{
			while(i < current->data)
			{
				push(&twohead, last);
				last++;
				i++;
			}
		}
		else if(current->data < 0)
		{
			while(i < (current->data * (-1)))
			{
				if(twohead == NULL) // Нет элементов в очереди
					break;
					
				pop(&twohead);
				i++;
			}
		}
		
		print(twohead); // Вывод текущий
		//if(current->Next != NULL)
		printf("\n");
		
		current = current->Next;
	}
	
	return 0;
}
