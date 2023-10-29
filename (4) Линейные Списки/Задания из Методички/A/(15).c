#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
} *First;

void addToList(struct List** head, int value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
    new_List->data = value;
    new_List->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_List;
        return;
    }
	
    struct List* current = *head;
    while (current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_List;
}

void Reverse(struct List** head, int count)
{
	struct List *prev, *cur, *temp;
	struct List* nextAfterFunc = NULL;
	int i;
	
	// Нахождение элемента который должен быть после 5 элемента
	for(cur = *head, i = 0; i < count && cur; i++, cur = cur->Next)
	{	} // Для cur
	nextAfterFunc = cur; // Элемент после 5-го элемента(Для след. итерации)

	// Сортировка(наоборот)
	for(i = 0, prev = NULL, cur = *head; i < count && cur; i++)
	{
		temp = cur->Next;
		cur->Next = prev;
		prev = cur;
		cur = temp;
	}
	*head = prev; // Справо-налево
	
	// Уже отсортированные 5 элементов, последний 5-й элемент указывает на первый элем след. пары
	for(cur = *head; cur && cur->Next; cur = cur->Next) 
	{	}
	cur->Next = nextAfterFunc; // Указывает на правильный след. элемент(после 5-го)
	// Пишем потому что используем сначала для первых 5-ти элементов, и нужно знать в цикле while с чего начинать
}

void printer(struct List* elem)
{
	while(elem)
	{
		printf("%d ", elem->data);
		elem = elem->Next;
	}
}

int main()
{
	int array[] = {1,2,3,4}; // {1,2,3,4,5,6,7,8,9,10,0};
	// {1,2,3,4,5,6,7};
	int i;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	int razmer = sizeof(array)/sizeof(int);
	for(i = 0; i < razmer; i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	printf("\n");
	
	// Проверка на кол-во элементов для пары из 5-ти элементов
	int count = 0;
	current = First;
	
	while(current)
	{
		count++;
		current = current->Next;
	}
	if(count >= 5)
		// Для самой первой пятерки элементов(5 4 3 2 1)
		Reverse(&First, 5);
	else
		return 1;
	
	// Сортировка остальных пар
	current = First->Next->Next->Next->Next; // Указатель на 5-й элемент
	while(current)
	{
		// Сортируем элементы если их > 1(Если не полная пара)
		if(current->Next) // Указатель на первый элемент новой пары
			Reverse(&current->Next, 5);
		else // Если остался один элемент - сортировать его не нужно
			break;
		
		// Если можно отсортировать следующую пару
		if(current->Next && current->Next->Next && current->Next->Next->Next && current->Next->Next->Next->Next && current->Next->Next->Next->Next->Next)
			current = current->Next->Next->Next->Next->Next;
		else // Нельзя
			break;
	}
	
	// Вывод
	printer(First);

	return 0;
}
