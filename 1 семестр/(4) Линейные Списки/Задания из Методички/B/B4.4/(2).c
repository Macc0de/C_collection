#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List
{
	char* data;
	struct List* Previous;
	struct List* Next;
} *First;

void addToList(struct List** head, char* value)
{
    struct List* new_List = malloc(sizeof(struct List));
	
	new_List->data = malloc(sizeof(char) * 20);
	strcpy(new_List->data, value);
	
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

int main()
{
	//"dog, jkl, ker, lom, mol, iop, god."
	//"xcv, dog, jkl, god, ker, lom, mol, iop."
	char str[] = "34, dog, jkl, ker, lom, mol, iop, god, god.";
	
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
	
	struct List* current = First;
	while (current)
	{
		int flag = 0;
		char temp[20] = {};
		struct List* sled = current->Next;
		
		while(sled) // Проходится по след. элементу
		{
			strcpy(temp, current->data); // temp = current->data
			strrev(temp);
			
			// Проверка следующего и текущего элементов + Удаление
			if(strcmp(sled->data, temp) == 0) // if equal, already reversed
			{
				if(current == First) // Если первый
				{
					// "dog, jkl, god, ker, iop, god, osl." - Не удаляет второй god (!!!)
					flag = 1;
					First = First->Next;
					current = current->Next;
					First->Previous = NULL;
					
					// Если удаляемый элемент - последний
					if(sled->Next) // Если есть след. элемент после предыдущего
						sled->Next->Previous = sled->Previous;
						
					sled->Previous->Next = sled->Next;
				}
				else // Если не первый
				{
					current->Next->Previous = current->Previous; // = Предыд.
					current->Previous->Next = current->Next; // Предыд. удаляем
					
					// Если удаляемый элемент - последний
					if(sled->Next) // Если есть след. элемент после предыдущего
						sled->Next->Previous = sled->Previous; // = Предыд.
						
					sled->Previous->Next = sled->Next; // След. удаляем
				}
			}
			/*if(flag) // Если элемент первый и break
			{
				flag = 0;
				continue;
			}*/
			sled = sled->Next;
		}
		current = current->Next;
	}
	
	printf("Result:\n");
	current = First;
	while(current)
	{
		printf("%s ", current->data);
		current = current->Next;
	}

	return 0;
}
