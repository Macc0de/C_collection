#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List
{
	char* data;
	struct List* Next;
} *First;

void addToList(struct List** head, char* value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
	new_List->data = malloc(sizeof(char) * 20);
	strcpy(new_List->data, value); // Для слова из списка
	
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

	return current; // Возвращает указатель на структуру элемента по нужному index
}

int main()
{
	// "xor, zen, addon, brick, man, keeper."
	// "dome, bone, aiogram."
	char str[] = "xor, zen, addon, brick, man, keeper.";
	
	// Нужно также учести \n если будет использован fgets
	int len = strlen(str);
	if(str[len - 1] != '.')	
	{
		printf("No!");
		return 1;
	}
	str[len - 1] = '\0';
	
	char* token = strtok(str, " ,@*"); // Разделители
	int count = 0;
	while(token)
	{
		count++;
		addToList(&First, token);
		
		token = strtok(NULL, " ,@*");
	}
	
	// Сортировка слов по алфавиту
	struct List* temp1 = NULL;
	struct List* temp2 = NULL;
	
	char ChTemp[20] = {};
	int i, j;
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < (count - 1); j++) // count - 1 - чтобы не выйти за границы массива
		{
			temp1 = Get_ElementByIndex(First, j); // temp1->data хранит слово
			temp2 = Get_ElementByIndex(First, j + 1);
			if(strcmp(temp1->data, temp2->data) > 0) // По возрастанию
			{
				strcpy(ChTemp, temp1->data); // Временный элемент для хранения chTemp
				strcpy(temp1->data, temp2->data);
				strcpy(temp2->data, ChTemp);
			}
		}
	}
	
	struct List* arr_ptr[100] = {}; // Массив указаталей на структуры
	i = 0; // Для массива указателей индекс
	
	printf("Increasing order:\n");
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		arr_ptr[i] = current; // Запись в массив указателя на узел
		printf("%s ", current->data);
		
		current = current->Next;
		
		if(current) // Если есть следующий элемент -> i вместо 6 стало 5
			i++;
	}
	
	printf("\nDescending order:\n");
	for(; i >= 0; i--)
	{
		printf("%s ", arr_ptr[i]->data);
	}

	return 0;
}
