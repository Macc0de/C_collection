#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Queue
{
	char data;
	struct Queue* Next;
};

int push(struct Queue** head, char data) // Очередь и Список
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
		current = current->Next;
	current->Next = new_node;

	return 0;
}

int inputList(struct Queue** head) // Список
{
	char symb, res;
	while(scanf("%c", &symb)) // Ввод посимвольный
	{
		if(symb == '.') // Конец
			return 1;
		
		res = push(head, symb); // Добавление в список
		if (res == 1) // Ошибка выделения памяти
			return 1;
	}
	return 0;
}

int print(struct Queue* head)
{
	if(head == NULL) // Если удалили все элементы
	{
		printf("the queue is empty");
		return 1;
	}
	
	struct Queue* current = head;
	while(current != NULL) // Вывод
	{
		printf("%c", current->data);
		current = current->Next;
	}
	return 0;
}

char pop(struct Queue** head) // Очередь
{
	if((*head) == NULL)
		return 0;
	
	struct Queue* temp = (*head);
	char last = (*head)->data;
	(*head) = (*head)->Next;
	free(temp);
	return last;
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
	inputList(&head); // Список
	
	int i, last = 1;
	if(print(head) == 1) // Если список пуст
		return 0;
	printf("\n");
	
	char current_symbol;
	while((current_symbol = pop(&head)) != 0)
	{
		if(isalpha(current_symbol)) // Только латиница
			push(&twohead, current_symbol);
	}	
	
	/*current = head;
	while(current != NULL)
	{
		if(isalpha(current->data))
			push(&twohead, current->data);
		
		current = current->Next;
	}*/
	
	print(twohead);
	
	free_memory(head, twohead);
	
	return 0;
}
