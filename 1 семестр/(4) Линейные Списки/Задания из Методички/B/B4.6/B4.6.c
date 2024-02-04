/* Допустим множество это одинаковые элементы (5;5), с ними и работаем
   (A)
 1 2
 3 6
 8 2
 5 5
 0 0
   (B)
 3 5
 1 1
 5 5
 1 2
 0 0
*/
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int x, y;
	struct List* Next;
} *First, *Second, *Union, *Cross, *Diff;

void addToList(struct List** head, int x, int y)
{
    struct List* new_node = malloc(sizeof(struct List));
	
	new_node->x = x;
	new_node->y = y;
    new_node->Next = NULL;
	
    if(*head == NULL)
	{
        *head = new_node;
        return;
    }
	
    struct List* current = *head;
    while(current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_node;
}

int main()
{
	int x_A, y_A;
	int x_B, y_B;
	
	printf("Enter x and y for A:\n");
	while(x_A != 0 && y_A != 0)
	{
		scanf("%d %d", &x_A, &y_A);
		if(x_A != 0 && y_A != 0) // 0 - Чтобы закончить ввод
			addToList(&First, x_A, y_A);
	}
	
	printf("Enter x and y for B:\n");
	while(x_B != 0 && y_B != 0)
	{
		scanf("%d %d", &x_B, &y_B);
		
		if(x_B != 0 && y_B != 0)
			addToList(&Second, x_B, y_B);
	}
	
	// Объединение
	// Создание Union, добавление элементов
	struct List* current = First;
	while(current)
	{
		addToList(&Union, current->x, current->y);
		current = current->Next;
	}
	current = Second;
	while(current)
	{
		addToList(&Union, current->x, current->y);
		current = current->Next;
	}
	
	// Вывод 1
	printf("Union of A and B:\n");
	current = Union;
	while(current)
	{
		printf("(%d %d) ", current->x, current->y);
		current = current->Next;
	}
	
	// Пересечение
	current = First;
	struct List* current2 = NULL;
	while(current)
	{
		current2 = Second;
		while(current2)
		{
			if(current->x == current2->x && current->y == current2->y)
			{
				// Добавляем в Cross одинаковые точки
				addToList(&Cross, current->x, current->y);
			}
			current2 = current2->Next;
		}
		current = current->Next;
	}
	
	// Удаление повторяющихся точек, чтобы не было повторов, только оригиналы
	current = Cross;
	struct List* prev = NULL;
	while(current)
	{
		current2 = Cross;
		while(current2)
		{
			if(prev != NULL && current != current2 && (current->x == current2->x && current->y == current2->y))
			{
				prev->Next = current2->Next;
				current2 = current2->Next;
				continue;
			}
			prev = current2;
			current2 = current2->Next;
		}
		current = current->Next;
	}
	
	// Вывод 2
	printf("\nCross of A and B:\n");
	current = Cross;
	while(current)
	{
		printf("%d %d ", current->x, current->y);
		current = current->Next;
	}
	
	// Разность
	// Ищем уникальные в первом списке // Или добавить в один список элементы и удалить повторяющиеся элементы
	current = First;
	int flag;
	while(current)
	{
		current2 = Second;
		flag = 0;
		while(current2)
		{
			if(current->x == current2->x && current->y == current2->y)
			{
				// Добавляем в Cross одинаковые точки
				flag = 1;
				break;
			}
			current2 = current2->Next;
		}
		if(flag == 0) // Нет повторов
		{
			addToList(&Diff, current->x, current->y);
		}
		current = current->Next;
	}
	
	// Ищем уникальные во втором списке (Копия кода сверху, PS: разные списки)
	current = Second;
	while(current)
	{
		current2 = First;
		flag = 0;
		while(current2)
		{
			if(current->x == current2->x && current->y == current2->y)
			{
				// Добавляем в Cross одинаковые точки
				flag = 1;
				break;
			}
			current2 = current2->Next;
		}
		if(flag == 0) // Нет повторов
		{
			addToList(&Diff, current->x, current->y);
		}
		current = current->Next;
	}
	
	// Вывод 3
	printf("\nDiff of A and B:\n");
	current = Diff;
	while(current)
	{
		printf("%d %d ", current->x, current->y);
		current = current->Next;
	}
	
	return 0;
}
