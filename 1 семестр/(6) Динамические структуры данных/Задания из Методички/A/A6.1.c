/* Содержимое файла:
studentname1 FIO1 5 1,3,3,5,2,5
studentname2 FIO2 2 2,4,3,2,2,5
studentname3 FIO3 5 4,5,2,4,2,3
studentname4 FIO4 8 5,4,5,5,5,2
studentname5 FIO5 9 5,5,2,5,5,5
studentname6 FIO6 2 4,4,4,4,3,4
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30

struct Student
{
	char last_name[N];
	char FIO[N];
	int num_group;
	int progress[N];
	
	struct Student* Next; // Указатель на след. структуру
} *First;

void addToList(struct Student** head, char* surname, char* initials, int n_group, int* grades)
{	
    struct Student* new_List = malloc(sizeof(struct Student));
	
	strcpy(new_List->last_name, surname); // Для слова из списка
	strcpy(new_List->FIO, initials);
	new_List->num_group = n_group;
	memcpy(new_List->progress, grades, 6 * sizeof(int)); // Оценки
    new_List->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_List;
        return;
    }
	
    struct Student* current = *head;
    while (current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_List;
}

int main()
{
	FILE* fp;
    char* line = NULL;
    int len = 0;
    int read;

    fp = fopen("file.txt", "r");
    if (fp == NULL)
		return 1;

	char reminder[1024];
    while ((read = getline(&line, &len, fp)) != -1) // -1 именно для getline()
	{			
		int temp_grades[N];
		char surname[N];
		char initials[N];
		char n_group[N];
		char grades[N];
		
        sscanf(line, "%s %s %s %s ", surname, initials, n_group, grades);
		sscanf(grades, "%d,%d,%d,%d,%d,%d", &temp_grades[0], &temp_grades[1], &temp_grades[2], &temp_grades[3], &temp_grades[4], &temp_grades[5]);
		
		addToList(&First, surname, initials, atoi(n_group), temp_grades);
    }                                                                                              
	
    fclose(fp);
    if (line) // Из-за getline()
        free(line);
	
	printf("(1) Students whose middle grade > 4:\n");
	
	struct Student* current = First;
	int i = 0, flag = 0;
	float mid_grade = 0;
	
	while(current)
	{
		mid_grade = 0;
		for (int i = 0; i < 6; i++)
		{
			mid_grade += current->progress[i];
		}
		
		printf("%.2f\n", mid_grade/6); // Для проверки
		
		if(mid_grade/6 > 4)
		{
			flag = 1;
			printf("%s %s %d\n", current->last_name, current->FIO, current->num_group);
		}
		current = current->Next;
	}
	if(flag == 0)
		printf("Not found\n");
	
	printf("\n(2) Students who have got grades '4' and '5':\n");
	
	current = First;
	int check = 0;
	flag = 0;
	
	while(current)
	{
		for(int i = 0; i < 6; i++)
		{
			flag = 0;
			if(current->progress[i] == 4 || current->progress[i] == 5)
			{
				if(current->progress[i] == 4) // Встретили 4 - ищем 5
				{
					for(int j = 0; j < 6; j++)
					{
						if(current->progress[j] == 5)
						{
							flag = 1;
							break;
						}
					}
				}
				else if(current->progress[i] == 5) // Встретили 5 - ищем 4
				{
					for(int j = 0; j < 6; j++)
					{
						if(current->progress[j] == 4)
						{
							flag = 1;
							break;
						}
					}
				}
			}
			if(flag)
			{
				check = 1;
				printf("%s %s %d\n", current->last_name, current->FIO, current->num_group);
				break;
			}
		}
		current = current->Next;
	}
	if(check == 0)
		printf("Not found.\n");
	
	printf("\n(3) Students who have got at least one grade '2':\n");
	
	flag = 0;
	check = 0;
	current = First;
	
	while(current)
	{
		flag = 0;
		for(int i = 0; i < 6; i++)
		{
			if(current->progress[i] == 2)
				flag = 1;
		}
		if(flag)
		{
			check = 1;
			printf("%s %s %d\n", current->last_name, current->FIO, current->num_group);
		}
		current = current->Next;
	}
	if(check == 0)
		printf("Not found.\n");
	
	return 0;
}
