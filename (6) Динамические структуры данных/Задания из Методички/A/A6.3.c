#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // localtime()
#define N 100
/* Файл file.txt
Alexeev,M.A. programmer 2022
Mikheev,A.T. admin 2021
Romanov,K.P. director 2012
Makarov,R.E. programmer 2020
Alexandrov,A.E. admin 2010
*/
struct Worker
{
	char surname_initials[N]; // Через запятую
	char post[N];
	int year_start;
	struct Worker* Next;
} *First;

void addToList(struct Worker** head, char* surname_initials, char* post, int year_start)
{	
    struct Worker* new_List = malloc(sizeof(struct Worker));
	
	strcpy(new_List->surname_initials, surname_initials);
	strcpy(new_List->post, post);
	new_List->year_start = year_start;
    new_List->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_List;
        return;
    }
	
    struct Worker* current = *head;
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
		char surname[N];
		char initials[N];
		char surname_initials[N];
		char data[N] = {}; // Нужно инициализировать
		char post[N];
		char year_start[N];
		
		sscanf(line, "%s %s %s", surname_initials, post, year_start);
		
		char* token = strtok(surname_initials, ",");
		strcat(data, token);
		strcat(data, ", "); // Разделитель между двумя токенами
		token = strtok(NULL, ","); // Для след. слова
		strcat(data, token);
		
		addToList(&First, data, post, atoi(year_start));
    }                                                                                              
	
    fclose(fp);
    if (line) // Из-за getline()
        free(line);
	
	// Время для текущего года
	time_t seconds = time(NULL);
    struct tm* current_time = localtime(&seconds); 
	
	int experience, current_experience, current_year = (current_time->tm_year + 1900), flag = 0;
	
	printf("Enter the employee's experience:\n");
	scanf("%d", &experience);
	printf("(1) Workers whoose excperience exceeds this value:\n");
	
	struct Worker* current = First;
	while(current)
	{
		current_experience = current_year - current->year_start;
		if(current_experience > experience)
		{
			printf("%s %s\n", current->surname_initials, current->post);
			flag = 1;
		}
		current = current->Next;
	}
	if(!flag)
		printf("No such workers found!\n");
	
	int start_period, end_period;
	
	printf("\nEnter the start and end of the period:\n"); 
	scanf("%d %d", &start_period, &end_period);
	printf("(2) Workers who started working during this period:\n");
	
	current = First, flag = 0;
	while(current)
	{
		if(current->year_start >= start_period && current->year_start <= end_period)
		{
			printf("%s %s\n", current->surname_initials, current->post);
			flag = 1;
		}
		current = current->Next;
	}
	if(!flag)
		printf("No such workers found!\n");
	
	return 0;
}
