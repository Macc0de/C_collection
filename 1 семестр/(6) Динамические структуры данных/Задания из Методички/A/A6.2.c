#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
/* Файл file.txt
Odessa 32 Transport
Kiev 234 Business
Poltava 59 Passenger
Kherson 12 Transport
Kiev 40 Passenger
*/
struct Aeroflot
{
	char name_finish[N];
	int number_flight;
	char type_plane[N];
	struct Aeroflot* Next;
} *First;

void addToList(struct Aeroflot** head, char* name_finish, int number_flight, char* type_plane)
{	
    struct Aeroflot* new_List = malloc(sizeof(struct Aeroflot));
	
	strcpy(new_List->name_finish, name_finish);
	new_List->number_flight = number_flight;
	strcpy(new_List->type_plane, type_plane);
    new_List->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_List;
        return;
    }
	
    struct Aeroflot* current = *head;
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
		char name_finish[N];
		char number_flight[N];
		char type_plane[N];
		
        sscanf(line, "%s %s %s", name_finish, number_flight, type_plane); // Именно строки
		addToList(&First, name_finish, atoi(number_flight), type_plane);
    }                                                                                              
	
    fclose(fp);
    if (line) // Из-за getline()
        free(line);
	
	printf("(1) Enter the aircraft destination:\n");
	char* town = malloc(N * sizeof(char));
	gets(town);
	
	struct Aeroflot* current = First;
	int flag = 0;
	while(current)
	{
		if(strcmp(current->name_finish, town) == 0)
		{
			printf("%d %s\n", current->number_flight, current->type_plane);
			flag = 1;
		}
		current = current->Next;
	}
	if(!flag)
		printf("Not found.\n");
	
	printf("\n(2) Enter the type of aircraft:\n");
	char* type = malloc(N * sizeof(char));
	gets(type);
	
	flag = 0;
	current = First;
	while(current)
	{
		if(strcmp(current->type_plane, type) == 0)
		{
			printf("%s %d\n", current->name_finish, current->number_flight);
			flag = 1;
		}
		current = current->Next;
	}
	if(!flag)
		printf("Not found.");
	
	free(town);
	free(type);
	
	return 0;
}
