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

int print(struct List* head)
{	
	if(head == NULL) // Список пуст
	{
		printf("the list is empty");
		return 1;
	}

	struct List* current = head;
	while(1) // Вывод
	{
		printf("%d ", current->data);
		
		if(current->Next == head)
			return 0;
		current = current->Next;
	}
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
	struct List* head = NULL, *current, *temp, *saved_found = NULL;
	inputList(&head);
	getchar();
	
	int k, n, i;
	scanf("%d", &k);
	getchar();
	scanf("%d", &n);

	if(print(head) == 1) // Вывод исходного списка
		return 0;
	
	current = head;
	while(1) // Проход по циклическому
	{
		if(current->data == k) // Поиск элемента =k
		{
			saved_found = current;
			i = 0;
			while(i <= n && current != NULL) // Удаление без головы
			{ // current != NULL(если удаление большего кол-ва элементов чем есть)
				if(current == head && i != 0) // Если голова тоже удаляется
					head = head->Next;
				
				i++;
				
				temp = current->Next; // Удаление
				current->Next = NULL;
				current = temp;
			}
			saved_found->Next = current; // Связь новая после удаления
			break;
		}
		else
			current = current->Next;
		
		if(current == head) // Конец циклического списка
			break;
	}

	printf("\n");
	print(head);
	
	if(head == NULL)
		return 0;
	
	free_memory(head);
	
	return 0;
}
