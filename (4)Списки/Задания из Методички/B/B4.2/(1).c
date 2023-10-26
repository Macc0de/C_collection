#include <stdio.h>
#include <stdlib.h>

struct List // Двусвязный
{
	int data;
	struct List* Next;
	struct List* Previous;
} *First1, *First2;

void addToList(struct List** head, int value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
    new_List->data = value;
    new_List->Next = NULL;
	new_List->Previous = NULL;
	
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
	new_List->Previous = current;
}

/* Основная функция, которая вставляет узлы связанного списка second в first в альтернативных позициях. 
Поскольку заголовок первого списка никогда не меняется, а заголовок второго списка может измениться, 
нам нужен одиночный указатель для первого списка и двойной указатель для второго списка. */
void merge(struct List* first, struct List** second)
{
    struct List* first_curr = first, *second_curr = *second;
  
    // Пока элемент != NULL
    while(first_curr && second_curr)
    {
        // Сохраняем для след. итераций
        struct List* first_next = first_curr->Next;
        struct List* second_next = second_curr->Next;
  
		// second_curr - след. элемент после first_curr(Для них проверки пройдены)
        second_curr->Next = first_next;
		second_curr->Previous = first_curr; // Для двусвязного
        first_curr->Next = second_curr;
		
		if(first_next) // Для двусвязного
			first_next->Previous = second_curr;
	
        // Итерации
        first_curr = first_next;
        second_curr = second_next;
    }
	
	// Если есть оставшиеся элементы во втором списке
	if(second_curr) // (из второго списка)
	{
		struct List* current = first;
		while(current->Next) // Последний элемент результируюшего списка
		{
			current = current->Next;
		}
		// Склеивание: последний элемент основного списка + остаток второго
		current->Next = second_curr; // second_curr(8)->9->10(сразу несколько указателей)
	}
	*second = second_curr; // Присваиваем старое значение(Второй список) - остаются лишние элементы
}

int main()
{
	// В результирующий список дописывает также, если есть, лишние элементы которые в array1
	int array1[] = {1,3,5}; //{1,3,5,8,9,10};
	int array2[] = {2,4,6,7,8}; //{2,4,6,8,9,10};
	
	int i;
	for(i = 0; i < sizeof(array1)/sizeof(int); i++)
	{
		addToList(&First1, array1[i]);
	}
	for(i = 0; i < sizeof(array2)/sizeof(int); i++)
	{
		addToList(&First2, array2[i]);
	}
	
	int count1 = 0, count2 = 0;
	struct List* current = First1;
	while(current) // Первый вывод
	{
		count1++;
		printf("%d ", current->data);
		
		if(current->Next)
			current = current->Next;
		else
			break;
	}
	
	printf("\n");
	current = First2;
	while(current) // Второй вывод
	{
		count2++;
		
		printf("%d ", current->data);
		current = current->Next;
	}
	
	merge(First1, &First2);
	
	// Вывод
	printf("\n");
	current = First1;
	while(current)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	// Подсчёт лишних элементов в первом списке
	int result_count = 0;
	if(count1 > count2)
	{
		result_count = count1 - count2;
		printf("\nExcessive elements in first list: %d", result_count);
		
		return 0;
	}
	
	// Подсчет лишних элементов во втором списке
	int count = 0;
	current = First2;
	
	if(current == NULL)
		return 0;
	else
	{
		while(current)
		{
			count++;
			current = current->Next;
		}
		printf("\nExcessive elements in second list: %d", count);
	}
	
	return 0;
}
