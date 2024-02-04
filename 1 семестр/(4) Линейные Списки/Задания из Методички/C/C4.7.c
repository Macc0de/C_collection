/* 
Лежат:
1 1
2 1
3 1

Не лежат:
1 1
2 1
4 -5

Три точки лежат, две удаляется
1 1
2 1
3 1
4 -5
2 2
*/
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int x, y;
	struct List* Next;
} *First;

void addToList(struct List** head, int x, int y)
{
    struct List* new_node = malloc(sizeof(struct List));
	
	new_node->x = x;
	new_node->y = y;
    new_node->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_node;
        return;
    }
	
    struct List* current = *head;
    while (current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_node;
}

// Лежат ли точки на одной прямой?
int Check_Points(struct List* current, struct List* current2, struct List* elem)
{
	return ((elem->x - current->x) * (current2->y - current->y) - (current2->x - current->x) * 
	(elem->y - current->y) == 0); // return true
}

int main()
{
	int x_A, y_A;
	int x_B, y_B;
	
	printf("Enter x and y:\n");
	while(x_A != 0 && y_A != 0)
	{
		scanf("%d %d", &x_A, &y_A);
		if(x_A != 0 && y_A != 0)
			addToList(&First, x_A, y_A);
	}
	
	struct List* current = NULL;
	struct List* first = NULL;
	struct List* second = NULL;
	int max = 0;
	
	for(current = First; current; current = current->Next)
	{
		// Проход по First, но по следующему элементу
		for(struct List* current2 = current->Next; current2; current2 = current2->Next)
		{
			int max_current = 0;
			for(struct List* elem = First; elem; elem = elem->Next)
			{
				if(Check_Points(current, current2, elem)) // Точки, которые лежат на одной прямой
				{
					//printf("(%d %d) ", elem->x, elem->y);
					//printf("Yes\n");
					max_current++;
				}
				/*else 
				{
					printf("(%d %d) ", elem->x, elem->y);
					printf("No\n");
				}*/
			}
			
			if(max_current > max) // Максимум кол-ва точек, которые лежат между этими двумя точками
			{	
				max = max_current;
				first = current; // Начальная точка и последняя точка, можно провести прямую
				second = current2;
			}
		}
	}
	
	// Удаление лишних точек, оставляем минимальное кол-во точек
	struct List* prev = NULL;
	current = First;
	while(current)
	{
		if(!Check_Points(first, second, current)) // false
		{
			if(prev == NULL)
			{
				First = First->Next;
				current = current->Next;
				continue;
			}
			else if(prev != NULL)
			{
				prev->Next = current->Next;
				current = current->Next;
				continue;
			}
		}
		prev = current;
		current = current->Next;
	}
	
	// Вывод точек из которых можно прямую сделать
	printf("\n");
	current = First;
	while(current)
	{
		printf("Dot: %d %d\n", current->x, current->y);
		current = current->Next;
	}
	
	return 0;
}
