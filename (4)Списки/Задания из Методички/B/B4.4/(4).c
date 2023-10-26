// Пока просто удаляет слова не соответствующие заданной длине
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

/*int hammingDist(char* str1, char* str2)
{
    int i = 0, count = 0;
    while (str1[i]) 
	{
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}*/

int main()
{
	// "xor, zen, addon, brick, man, keeper."
	// "ban xx van ban xx ban xx iop van xx."
	// "kio hello bnmc 123456 world kotli fghcvbn."
	
	// zxcvb kio hello bnmc 123456 world kotli fghcvbn.
	char str[] = "5555 123 9999 88888 2222 7777.";
	
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
	
	int dlina = 4; // Заданная длина
	struct List* prev = NULL;
	struct List* current = First;
	
	// Удаление повторов
	while(current)
	{
		if(strlen(current->data) != dlina)
		{
			if(prev != NULL)
			{
				prev->Next = current->Next;
				current = current->Next;
			}
			else if(prev == NULL)
			{
				First = First->Next;
				current = current->Next;
			}
			continue;
		}
		prev = current;
		current = current->Next;
	}
	
	/* Расстояние
	current = First; 
	struct List* word1 = NULL;
	struct List* word2 = NULL;
	int max_word = 0;
	while(current)
	{
		struct List* current2 = First;
		while(current2)
		{
			int res = hammingDist(current->data, current2->data); 
			if(res > max_word)
			{
				max_word = res;
				word1 = current;
				word2 = current2;
			}
			current2 = current2->Next;
		}
		current = current->Next;
	}*/
	
	current = First;
	while (current) // Вывод
	{
		printf("%s ", current->data);
		current = current->Next;
	}
	//printf("\nMax word: %d\nWord1: %s, Word2: %s.", max_word, word1->data, word2->data);
	
	return 0;
}
