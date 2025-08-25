#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>

struct Stack
{
	char data;
	struct Stack* Next;
};

int push(struct Stack** head, char data) // Стек
{
	struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
	
	if (new_node == NULL)
		return 1;
	
	new_node->data = data;
	new_node->Next = *head;
	*head = new_node; // Последний добавленный элемент - голова
	
	return 0;
}

void pop(struct Stack** head)
{
	if((*head) == NULL)
		return;
	
	struct Stack* temp = (*head);
	(*head) = (*head)->Next;
	free(temp);
}

int clean(struct Stack** head) // Стек
{
	if((*head) == NULL)
		return 0;
	
	struct Stack* tmp = (*head)->Next;
	free(*head);
	(*head) = tmp;
	
	return 1;
}

int is_latin(char symb)
{// a || A
	return (symb >= 65 && symb <= 90) || (symb >= 97 && symb <= 122);
}

int inputList(struct Stack** head, struct Stack** twohead) // Список
{
	char symb, res;
	while(scanf("%c", &symb))
	{
		if(symb == '.') // Конец
			return 1;
		
		res = push(head, symb);
		
		if(is_latin(symb)) // isalpha(symb)
		{
			push(twohead, ')');
			res = push(twohead, symb);
			push(twohead, '(');
		}
		else
			res = push(twohead, symb);

		if (res == 1) // Ошибка выделения памяти
			return 1;
	}
	return 0;
}

int print(struct Stack* head)
{
	if(head == NULL) // Если удалили все элементы
	{
		printf("stack is empty");
		return 1;
	}
	
	struct Stack* current = head;
	while(current != NULL)  // Вывод
	{
		printf("%c", current->data);
		current = current->Next;
	}
	return 0;
}

int main()
{
	struct Stack* head = NULL, *twohead = NULL;
	inputList(&head, &twohead);
	
	if(print(head) == 1)
		return 0;
	
	/*while(head != NULL) Ненужная очистка
	{
		pop(&head);	
	}*/
	printf("\n");
	print(twohead);
	
	while(clean(&head) == 1) // Не явл. NULL
	{	}
	
	return 0;
}
