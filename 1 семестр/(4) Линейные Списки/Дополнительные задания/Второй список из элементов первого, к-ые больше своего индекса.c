// Создать второй список из элементов первого, которые больше своего порядкового номера(начало с 1).
// (Не используя глобальный указатель)
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
};

int addToList(struct List** head, int number)
{
	struct List* new_node = (struct List*)malloc(sizeof(struct List));
	
	if(new_node == NULL)
		return 1;

	new_node->data = number;
	new_node->Next = NULL;

	if(*head == NULL)
	{
		*head = new_node;
		return 0;
	}

	struct List* current = *head;
	while(current->Next != NULL)
	{
		current = current->Next;
	}
	current->Next = new_node;
	
	return 0;
}

// Освобождение памяти списка
void freeList(struct List** head)
{
	struct List* temp;
	while(*head)
	{
		temp = (*head)->Next;
		free(*head);
		*head = temp;
	}
}

int main()
{
	int num, index = 2; // 2 - проверяем следующий элемент
	struct List* head = NULL;
	
	while(scanf("%d", &num)) // Ввод первого списка
	{
		if(addToList(&head, num) == 1)
		{
			printf("Memory allocation error!");
			return 0;
		}
	}	
	
	struct List* current = head;
	struct List* current_next = NULL;
	struct List* twohead = NULL; // Второй список
	
	while(current != NULL && current->Next != NULL) // Пропускаем голову
	{
		current_next = current->Next;
		if(current_next->data > index)
		{
			current->Next = current_next->Next; // Удаление
			current_next->Next = NULL;
			
			// Второй список, элементы которого больше своего индекса
			if(twohead == NULL) // Создание второго списка
			{
				twohead = current_next;
			}
			else // Если второй список уже создан
			{
				struct List* elem = twohead;
				while(elem->Next) // Поиск последнего
					elem = elem->Next;
				
				elem->Next = current_next;
			}
		}
		else
			current = current_next;
		
		index++;
	}
	if(head->data > 1) // Проверка головы
	{
		struct List* tmp = head;
		head = head->Next;
		
		tmp->Next = twohead;
		twohead = tmp; // Новая голова
	}

	while(head) // Первый список
	{
		printf("%d ", head->data);
		head = head->Next;
	}
	
	printf("\n");
	if(twohead == NULL) // Второй список
	{
		freeList(&head);
		printf("Second List in NULL.");
		return 0;
	}
	else
	{
		while(twohead)
		{
			printf("%d ", twohead->data);
			twohead = twohead->Next;
		}
	}

	// Освобождение памяти
	freeList(&head);
	freeList(&twohead);
	
	return 0;
}
