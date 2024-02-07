// Добавляет и удаляет элементы с начала
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

int pop(struct Stack** head) // Стек
{
	int last = (*head)->data;
	(*head) = (*head)->Next;
	return last;
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
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}

int main()
{
	struct Stack* head = NULL, *twohead = NULL, *current;
	inputList(&head); // Список
	getchar();
	
	int i, last = 1;
	current = head;
	if(current == NULL) // Если список пуст
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
				if(twohead == NULL) // Нет элементов в стеке
					break;
				
				if(pop(&twohead) == 0)
				{
					twohead = NULL;
					last--;
					break;
				}
				last--;
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
