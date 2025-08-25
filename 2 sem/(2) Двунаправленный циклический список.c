#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
	struct List* Previous;
};

int addToList(struct List** head, int value)
{
	struct List* new_node = (struct List*)malloc(sizeof(struct List));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
	new_node->Next = *head;
	new_node->Previous = *head;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->Next = *head;
		(*head)->Previous = *head;
		return 0;
	}

	struct List* current = *head;
	while (current->Next != *head)
		current = current->Next;
		
	new_node->Previous = current;
	current->Next = new_node;
	(*head)->Previous = new_node;

	return 0;
}

int inputList(struct List** head)
{
	int num, res;
	while (scanf("%d", &num))
	{
		res = addToList(head, num); // Добавление в список
		if (res == 1) // Ошибка выделения памяти
			return 1;
	}
	return 0;
}

void print(struct List* head)
{
	struct List* current = head;
	if(current == NULL)
		return;
	
	while (1) // Вывод в прямом
	{
		printf("%d ", current->data);
		
		if(current->Next == head)
			break;
		current = current->Next;
	}
	printf("\n");
	
	while (1) // Вывод в обратном
	{
		printf("%d ", current->data);
		
		if(current == head)
			break;
		current = current->Previous;
	}
	return;
}

void second_print(struct List* head, struct List* elem)
{
	if(elem == NULL) // Не найден элемент =k
	{
		print(head); // Вывод прямого и обратного
		return;
	}
	
	// Вывод с элемента, который =k
	struct List* current = elem;
	while (1) // 3 4 5 1 2
	{
		printf("%d ", current->data);
		
		if(current->Next == elem)
			break;
		current = current->Next;
	}
	printf("\n");
	
	current = elem;
	while (1) // 3 2 1 5 4
	{
		printf("%d ", current->data);
		
		if(current->Previous == elem)
			break;
		current = current->Previous;
	}
	return;
}

void free_memory(struct List* head)
{
	struct List* tmp, *current = head;
	do 
	{
		tmp = current->Next;
		free(current);
		current = tmp;
	}
	while(current != head);
}

int main()
{
	struct List* head = NULL, *current;
	inputList(&head);
	getchar();
	
	int k;
	scanf("%d", &k);
	
	if(head == NULL)
	{
		printf("0");
		return 0;
	}
	
	print(head); // Вывод прямого и обратного
	printf("\n\n");
	
	current = head;
	while (1)
	{
		if(current->data == k) // Поиск элемента =k
			break;
		
		if(current->Next == head)
		{
			current = NULL;
			break;
		}
		current = current->Next;
	}
	
	second_print(head, current);
	
	if(head == NULL)
		return 0;
	
	free_memory(head);
	
	return 0;
}
