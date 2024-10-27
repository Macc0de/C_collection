// Добавляет элементы в начало и Удаляет с начала
// 2 3 -2 1 -5 1.
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int data;
	struct Stack* Next;
};

int addToList(struct Stack** head, int data) // Список
{
	struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
	
	if (new_node == NULL)
		return 1;
	
	new_node->data = data;
	new_node->Next = NULL;
	
	if (*head == NULL)
	{
		*head = new_node;
		return 0;
	}
	
	struct Stack* current = *head;
	while (current->Next != NULL)
	{
		current = current->Next;
	}
	current->Next = new_node;
	
	return 0;
}

int push(struct Stack** head, int data) // Стек
{
	struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
	
	if (new_node == NULL)
		return 1;
	
	new_node->data = data;
	new_node->Next = *head;
	*head = new_node; // Последний добавленный элемент - голова
	
	return 0;
}

void pop(struct Stack** head) // Стек
{
	struct Stack* temp = (*head);
	(*head) = (*head)->Next;
	free(temp);
}

int inputList(struct Stack** head) // Список
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

void print(struct Stack* head)
{
	if(head == NULL) // Если удалили все элементы
	{
		printf("0");
		return;
	}
	
	struct Stack* current = head;
	while(current != NULL) // Вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

void free_memory(struct Stack* head, struct Stack* twohead)
{
	struct Stack* temp, *current = head;

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
	struct Stack* head = NULL, *twohead = NULL, *current;
	inputList(&head); // Список
	getchar();
	
	int i, last = 1, flag = 0;
	current = head;
	if(current == NULL) // Если список пуст
		print(head); 
	
	while(current != NULL)
	{
		i = 0;
		if(current->data > 0)
		{
			flag = 1;
			while(i < current->data)
			{
				push(&twohead, last);
				last++;
				i++;
			}
		}
		else if(current->data < 0)
		{
			flag = 1;
			while(i < (current->data * (-1)))
			{
				if(twohead == NULL) // Не осталось элементов в Стеке
					break;
				
				pop(&twohead); // Удаление
				
				last--; // Из-за того что в начало элементы добавляются
				i++;
			}
		}
		else
		{
			current = current->Next;
			continue;
		}
		
		print(twohead); / Вывод текущий
		printf("\n");
		
		current = current->Next;
	}
	
	if(twohead == NULL && head != NULL && flag == 0) // .
		printf("0");
	
	// Очистка памяти
	free_memory(head, twohead);
	
	return 0;
}
