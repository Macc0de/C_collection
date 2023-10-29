#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List
{
	int a, b, c;
	float square;
	char type[70];
	struct List* Next;
} *First, *New;

struct List* addToList(struct List** head, int a, int b, int c)
{
    struct List* new_List = malloc(sizeof(struct List));
	
	// Для трех сторон
    new_List->a = a;
	new_List->b = b;
	new_List->c = c;
	
	if((a == b) && (b == c) && (a == c)) // Равносторонний	
	{
		strcat(new_List->type, "equilateral ");
		//strcpy(new_List->type, "equilateral");
	}
	else if((a == b) || (a == c) || (b == c)) // Равнобедренный
	{
		strcat(new_List->type, "isosceles ");
	}
	if((a*a)+(b*b)==(c*c) || (a*a)+(c*c)==(b*b) || (b*b)+(c*c)==(a*a)) // Прямоугольный
	{
		strcat(new_List->type, "right-angled");
	}
	else if((a*a > (b*b + c*c)) || (b*b > (a*a + c*c)) || (c*c > (a*a + b*b))) // Тупоугольный
	{
		strcat(new_List->type, "obtuse");
	}
	else if((a*a < (b*b + c*c)) || (b*b < (a*a + c*c)) || (c*c < (a*a + b*b))) // Остроугольный
	{
		strcat(new_List->type, "acute-angled");
	}
	
    new_List->Next = NULL;
	
    if(*head == NULL)
	{
        *head = new_List;
        return new_List;
    }
	
    struct List* current = *head;
    while(current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_List;
	
	// Возвращаем ссылку на новый элемент
	return new_List;
}

int main()
{
	// 2, 3, 1 - no
	int a = 1, b = 1, c = 1; // 2, 3, 2
	int count = 1;
	
	// Пользователь указывает тип треугольника
	char type1[] = "equilateral"; // Равносторонний
	
	printf("Enter sides:\n");
	while(a && b && c)
	{
		// Отрезки
		scanf("%d %d %d", &a, &b, &c);
		
		// Stop
		if((a == 0) || (b == 0) || (c == 0))
		{
			printf("End of input.\n\n");
			break;
		}
		
		// Можно ли составить ?
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			printf("Triangle exists. ");
		}
		else
		{
			printf("Triangle doesn't exist.\n");
			continue;
		}
		struct List* temp = addToList(&First, a, b, c); // Добавили
		
		printf("It is : %s\n", temp->type);
	}
	
	struct List* current = First;
	struct List* prev = NULL;
	while(current)
	{
		if(strstr(current->type, type1)) // (проверяем, ищем)
		{// В новый список добавляем типы треугольнико которые не соответствуют
			addToList(&New, current->a, current->b, current->c);
			if(prev) // Есть предыдущий
			{
				prev->Next = current->Next;
				current = current->Next;
			}
			else // Нет предыдущего
			{
				First = First->Next;
				current = current->Next;
			}
			continue;
		}
		prev = current;
		current = current->Next;
	}
	
	// Вывод старого списка
	printf("Old List:\n");
	current = First;
	while(current)
	{
		printf("%s\n", current->type);
		current = current->Next;
	}
	
	// Вывод нового списка с удаленными
	printf("\nNew List:\n");
	current = New;
	while(current)
	{
		printf("%s\n", current->type);
		current = current->Next;
	}

	return 0;
}
