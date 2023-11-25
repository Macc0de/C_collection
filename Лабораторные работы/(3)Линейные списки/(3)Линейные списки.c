/* B4.2(1)
Двусвязный список. Требуется организовать процедуру, которая осуществляет "склеивание" двух таких списков, адресуемых
указателями First1 и First2, в следующем порядке: сначала идет первый элемент первого списка, затем первый элемент второго
списка и тд. При этом, если один из списков окажется длинее, то требуется:
1) Дописать остаток в конец результирующего списка и вывести на печать сообщение о кол-ве "лишних" элементов.

1 2 3.
4 5 6.
O: 1 4 2 5 3 6
///////////
1 2.
3 4 5 6 7.
O: 1 3 2 4 (5) (6) (7)
/////////////
1 2 3 4 5.
6 7 8.
O: 1 6 2 7 3 8 4 (5)
///////////////
.
.
Both Lists are NULL!
///////////////
1 2 3 4 5.
.
1 (2) (3) (4) (5)
///////////////
.
1 2 3 4 5.
(1) (2) (3) (4) (5)
///////////////
*/

// После перестановки: Элементы остаются во втором списке, если в нем есть лишние элементы
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
	struct List* Previous;
};

// Добавление элементов в список
int addToList(struct List** head, int value)
{
	struct List* new_node = (struct List*)malloc(sizeof(struct List));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
	new_node->Next = NULL;
	new_node->Previous = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return 0;
	}

	struct List* current = *head;
	while (current->Next)
	{
		current = current->Next;
	}
	current->Next = new_node;
	new_node->Previous = current;

	return 0;
}

// Заполнение списка
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

int count_elements(struct List* head) // Подсчёт кол-ва элементов в списке
{
	int i = 0;
	while (head)
	{
		i++;
		head = head->Next;
	}
	return i;
}

// Дописывание остатка второго списка в конец результирующего списка
void addRestToEnd(struct List** head, struct List* second_list)
{
	if(*head == NULL) // Если первый список пуст
	{
		*head = second_list;
		return;
	}
	
	// Если первый список не пуст
	struct List* first_list = *head;
	while (first_list->Next) // Поиск последнего элемента первого списка
	{
		first_list = first_list->Next;
	}
	first_list->Next = second_list; // Добавление в первый
}

// "Склеивание" двух списков + Поиск лишних элементов
int merge(struct List** First, struct List** Second)
{
	struct List* first_current = *First, *second_current = *Second;
	int count = 0;
	
	while (first_current && second_current)
	{
		struct List* first_next = first_current->Next;
		struct List* second_next = second_current->Next;
		
		// Проверка и подсчёт лишних элементов в списках
		if (first_next != NULL && first_next->Next != NULL && second_next == NULL) // Лишние элементы в первом
		{
			struct List* temp_current = first_next->Next;
			while (temp_current) // Проход по остатку первого
			{
				count++;
				temp_current = temp_current->Next;
			}
		}
		else if (first_next == NULL && second_next != NULL) // Лишние элементы во втором
		{
			struct List* temp_current = second_next;
			while (temp_current) // Проход по остатку второго
			{
				count++;
				temp_current = temp_current->Next;
			}
		}

		// Перестановки
		second_current->Next = first_next; // NULL <- 3 -> 2 
		second_current->Previous = first_current; // 1 <- 3 -> 2
		first_current->Next = second_current; // 1 <-> 3 -> 2

		if (first_next) // Без этого NULL может указывать на элемент
		{
			first_next->Previous = second_current; // // 1 <-> 3 <-> 2
		}

		// Следующие элементы при итерации
		first_current = first_next;
		second_current = second_next;
	}

	/* Если во втором списке остались лишние элементы после перестановки,
	то дописываем их в конец первого */
	if (second_current)
	{
		addRestToEnd(First, second_current);
		second_current = NULL; // Второй список пуст
	}

	*Second = second_current; // Корень второго списка

	// count > 0, если есть лишние элементы
	return count;
}

// Освобождение памяти списка
void freeList(struct List** head)
{
	struct List* temp;
	while (*head)
	{
		temp = (*head)->Next;
		free(*head);
		*head = temp;
	}
}

int main()
{
	struct List *First1 = NULL, *First2 = NULL;

	// Заполнение двух списков + Проверка на значение элемента и на выделение памяти ему
	printf("Enter the elements of the First List:\n");
	int check1 = inputList(&First1);
	getchar();
	printf("Enter the elements of the Second List:\n");
	int check2 = inputList(&First2);

	if (check1 || check2)
	{
		printf("Memory allocation Error!");
		return 0;
	}
	
	// Запись длины каждого списка
	int len1 = count_elements(First1);
	int len2 = count_elements(First2);
	
	// Проверка обоих списков на NULL
	if (First1 == NULL && First2 == NULL)
	{
		printf("\nBoth Lists are NULL!");
		return 0;
	}
	
	/* "Склеивание" двух списков + Запись остатка в конец результирующего списка
	+ Поиск лишних элементов */
	int res = merge(&First1, &First2);

	int i = 1, diff = 0;
	if (len1 > len2) // Лишние элементы в первом
		diff = len1 - len2 - 1;
	else if (len2 > len1) // Лишние элементы во втором
		diff = len2 - len1;
	
	// Вывод результирующего списка с выделенной частью лишних элементов
	printf("\nResult list:\n");
	struct List* current = First1;
	while (current)
	{
		if (i > (len1 + len2) - diff)
			printf("(%d) ", current->data);
		else
			printf("%d ", current->data);
		i++;
		current = current->Next;
	}
	
	// Кол-во лишних элементов
	if (len2 == 0 && len1 > 1) // Второй список пуст
		printf("\nExtra elements in the First List: %d", len1 - 1);
	else if (len1 == 0)
		printf("\nExtra elements in the Second List: %d", len2);
	else if (len1 - 1 > len2)
		printf("\nExtra elements in the First List: %d", res);
	else if (len1 < len2)
		printf("\nExtra elements in the Second List: %d", res);

	// Освобождение памяти
	freeList(&First1);

	return 0;
}
