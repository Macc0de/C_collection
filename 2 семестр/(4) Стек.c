#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int data;
	struct Stack* Next;
};

int push(struct Stack** head, int value)
{
	struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
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

int pop(struct Stack** head) // Удаляет с начала
{
	struct Stack* current = *head, *p_last = NULL;
	while(current->Next != NULL)
	{
		if(current->Next->Next == NULL)
			p_last = current;
		current = current->Next;
	}
	
	if(p_last == NULL) // В стеке остался 1 элемент
		return 0;

	int last = current->data;
	p_last->Next = NULL;
	return last; // Удаляемый последний(инфо. часть) сохраняем
}

int inputList(struct Stack** head) // Создание очереди
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

void print(struct Stack* head)
{
	if(head == NULL) // Если удалили все элементы
	{
		printf("0");
		return;
	}
	
	struct Stack* current = head, *last = NULL;
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
	struct Stack* head = NULL, *twohead = NULL, *current;
	inputList(&head);
	getchar();
	
	int i, last = 1;
	current = head;
	if(current == NULL) // ??
		print(twohead);
	
	while(current != NULL)
	{
		if(current->data > 0)
		{
			i = 0;
			while(i < current->data)
			{
				push(&twohead, last);
				last++;
				i++;
			}
		}
		else if(current->data < 0)
		{
			i = 0;
			while(i < (current->data * (-1)))
			{
				if(twohead == NULL) // Нет элементов в очереди
					break;
					
				if(pop(&twohead) == 0)
				{
					twohead = NULL;
					last--; // Уменьшаем значение текущего элемента
					break;
				}
				last--; // Уменьшаем значение текущего элемента
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
