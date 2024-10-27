// 34 3 31 98 92 23.
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
		current = current->Next;
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
	struct Deck* current = *head, *p_last = NULL;
	while(current->Next != NULL)
	{
		if(current->Next->Next == NULL)
			p_last = current;
		current = current->Next;
	}
	
	if((p_last == NULL))
		return;

	p_last->Next = NULL;
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
		printf("deck is empty");
		return;
	}
	
	struct Deck* current = head;
	while(current != NULL) // Вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

void free_memory(struct Deck* head)
{
	if(head != NULL)
	{
		struct Deck* current = head, *temp;
		while(current != NULL)
		{
			temp = current;
			
			current = current->Next;
			free(temp);
			
		}
	}
}

int main()
{
	struct Deck* head = NULL, *twohead = NULL;
	inputList(&head); // Список
	getchar();
	
	int i, last;
	if(head == NULL) // Если список пуст
	{
		print(head);
		return 0;
	}
	
	while(head != NULL)
	{
		int tmp = head->data;
		left_pop(&head);
		
		while(twohead != NULL && twohead->data < tmp)
		{
			right_push(&head, twohead->data); // left_push
			left_pop(&twohead);
		}
	
		left_push(&twohead, tmp);
	}
	
	print(twohead);
	
	free_memory(head);
	free_memory(twohead);
	
	return 0;
}
