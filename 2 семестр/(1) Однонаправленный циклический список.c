#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
};

int addToList(struct List** head, int value)
{
	struct List* new_node = (struct List*)malloc(sizeof(struct List));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
	new_node->Next = *head;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->Next = *head;
		return 0;
	}

	struct List* current = *head;
	while (current->Next != *head)
		current = current->Next;
	current->Next = new_node;

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
	
	while (1)
	{
		printf("%d ", current->data);
		
		if(current->Next == head)
			return;
		current = current->Next;
	}
}
 
void second_print(struct List* head, struct List* elem)
{
	if(head == NULL) // Список пуст
	{
		printf("0");
		return;
	}
	
	if(elem == NULL) // Не найден элемент =k
	{
		print(head);
		return;
	}
	
	print(elem); // Найден элемент =k
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
	
	print(head);
	printf("\n");
	
	current = head;
	while (current != NULL)
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
