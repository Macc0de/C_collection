/* (Реализация через список)
Вводится предложение, содержащее слова, разделенные пробелами. Слова состоят из букв латинского алфавита. 
Первое слово в предложении начинается с большой буквы. Ввод предложения заканчивается точкой.
Далее вводится слово, состоящее из строчных букв латинского алфавита.

Написать программу, которая удаляет из предложения все слова, совпадающие с заданным словом, и выводит результат на печать.
Если все слова в предложении удалены, напечатать Empty.

При проверке совпадения слов регистр букв не учитывается.

Input:
Mama mila ramy.
mama
Output:
Mila ramy.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct List
{
	char data[60];
	struct List *Next;
} *First;

void addToList(struct List** head, char* word)
{
    struct List* new_node = (struct List*)malloc(sizeof(struct List));
	
	strcpy(new_node->data, word);
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

void low_reg(char* word) // Перевод в нижний регистр
{
	while(*word)
	{
		*word = tolower(*word);
		word++;
	}
}

int main()
{
	int i, j;
	const int n = 500;
	char sentence[n];
	fgets(sentence, n, stdin);
	
	for(i = 0; sentence[i]; i++)
		if(sentence[i] == '.')
			sentence[i] = '\0';
	
	char* token = strtok(sentence, " ");
	while(token)
	{
		low_reg(token);
		addToList(&First, token);	
		token = strtok(NULL, " ");
	}
	
	char word[n];
	scanf("%s", word);
	low_reg(word);
	
	while(First) // Проверка головы
	{
		if(strcmp(First->data, word) == 0)
		{
			First = First->Next;
		}
		else
			break;
	}
	
	struct List* current;
	if(First)
	{
		struct List *temp;
		current = First;
		
		while(current->Next) // Проверка всех остальных
		{
			temp = current->Next;
			if(strcmp(temp->data, word) == 0)
			{
				current->Next = temp->Next;
			}
			else
				current = current->Next;
		}
	}
	
	current = First;
	if(current == NULL)
	{
		printf("Empty");
		return 0;
	}
	
	current->data[0] = toupper(current->data[0]); // Первое слово с большой буквы
	while(current)
	{
		if(current->Next == NULL)
			printf("%s.", current->data);
		else
			printf("%s ", current->data);
		current = current->Next;
	}
	
	return 0;
}
