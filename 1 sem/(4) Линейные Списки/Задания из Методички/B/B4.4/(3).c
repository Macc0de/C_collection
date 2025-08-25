#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List
{
	char* data;
	int count;
	struct List* Next;
} *First;

void addToList(struct List** head, char* value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
	new_List->data = malloc(sizeof(char) * 20);
	strcpy(new_List->data, value);

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

struct List* Get_ElementByIndex(struct List* head, int index)
{
	struct List* current = head;
	for(int i = 0; i < index && current; i++, current = current->Next)
	{	}

	return current;
}

int main()
{
	// "xor, zen, addon, brick, man, keeper."
	// "dome, bone, aiogram."
	
	// xx xx xx xx ban ban ban van van iop -> xx ban van iop
	char str[] = "ban xx van ban xx ban xx iop van xx.";
	
	int len = strlen(str);
	if(str[len - 1] != '.')	
	{
		printf("No!");
		return 1;
	}
	str[len - 1] = '\0';
	
	char* token = strtok(str, " ,@*");
	int count = 0;
	while(token)
	{
		count++;
		addToList(&First, token);
		token = strtok(NULL, " ,@*");
	}
	
	// Считаем кол-во повторов
	struct List* current = First;
	while(current)
	{
		struct List* current2 = First;
		while(current2)
		{
			if(strcmp(current->data, current2->data) == 0)
			{
				current->count++;
			}
			current2 = current2->Next;
		}
		current = current->Next;
	}
	
	// Сортировка слов 
	struct List* temp1 = NULL;
	struct List* temp2 = NULL;
	char chTemp[20] = {};
	int count_temp = 0;
	
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < (count - 1); j++) // count - 1 - Чтобы не выйти за границы массива
		{
			temp1 = Get_ElementByIndex(First, j);
			temp2 = Get_ElementByIndex(First, j + 1);
			if (temp1->count < temp2->count) // descending order - (<) // Если текущий элемент больше чем следующий
			{
				count_temp = temp1->count;
				temp1->count = temp2->count;
				temp2->count = count_temp;
				
				strcpy(chTemp, temp1->data);
				strcpy(temp1->data, temp2->data);
				strcpy(temp2->data, chTemp);
			}
		}
	}
	
	// Удаление повторов
	struct List* prev = NULL;
	current = First;
	while(current)
	{
		if(prev != NULL && strcmp(prev->data, current->data) == 0)
		{
			prev->Next = current->Next;
			current = current->Next;
			continue;
		}
		prev = current;
		current = current->Next;
	}
	
	current = First;
	while(current) // Вывод
	{
		printf("%s ", current->data);
		current = current->Next;
	}
	
	return 0;
}
