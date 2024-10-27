#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
	struct List* Previous;
};

int addToList(struct List** head, int value)
{
	struct List* new_node = (struct List*)malloc(sizeof(struct List));

	if (new_node == NULL)
		return 1;

	new_node->data = value;
	new_node->Next = *head;
	new_node->Previous = *head;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->Next = *head;
		(*head)->Previous = *head;
		return 0;
	}

	struct List* current = *head;
	while (current->Next != *head)
	{
		current = current->Next;
	}
	new_node->Previous = current;
	current->Next = new_node;
	(*head)->Previous = new_node;

	return 0;
}

int inputList(struct List** head)
{
	int num, res;
	while (scanf("%d", &num))
	{
		res = addToList(head, num); 
		if (res == 1) 
			return 1;
	}
	return 0;
}

void second_print(struct List* head)
{
	struct List* current = head;
	while (1) 
	{
		printf("%d ", current->data);
		
		if(current->Next == head || current->Next == NULL)
			break;
		current = current->Next;
	}
}

int print(struct List* head)
{	
	if(head == NULL) 
	{
		printf("the list is empty");
		return 1;
	}

	struct List* current = head;
	while (1) 
	{
		printf("%d ", current->data);
		
		if(current->Next == head)
			break;
		current = current->Next;
	}
	printf("\n");
	
	while (1) 
	{
		printf("%d ", current->data);
		
		if(current == head)
			break;
		current = current->Previous;
	}
	return 0;
}

void delete(struct List** head, struct List* k) 
{ 
    if (*head == NULL) 
        return; 
  
    struct List *current = *head, *prev = NULL; 
    while (current != k) 
	{ 
        if (current->Next == *head) 
            return;
  
        prev = current; 
        current = current->Next; 
    } 
  
    if (current->Next == *head && prev == NULL) 
	{ 
        (*head) = NULL; 
        free(current); 
        return; 
    } 
  
    if (current == *head) 
	{ 
        prev = (*head)->Previous; 
        *head = (*head)->Next; 
  
        prev->Next = *head; 
        (*head)->Previous = prev; 
        free(current); 
    } 
    else if (current->Next == *head) 
	{ 
        prev->Next = *head; 
        (*head)->Previous = prev; 
        free(current); 
    } 
    else 
	{ 
        struct List* temp = current->Next; 
  
        prev->Next = temp; 
        temp->Previous = prev; 
        free(current); 
    } 
}

void free_memory(struct List* head)
{
	if(head != NULL)
	{
		struct List* current = head, *temp;
		while (1) 
		{
			temp = current;
			
			if(current->Next == head)
				break;
			current = current->Next;
			free(temp);
		}
	}
}

int main()
{
	struct List* head = NULL, *current, *saved_found = NULL;
	inputList(&head);
	getchar();
	
	if(head == NULL)
	{
		printf("the list is empty");
		return 0;
	}
	
	int k, n;
	scanf("%d", &k);
	getchar();
	scanf("%d", &n);

	print(head);
	printf("\n");
	
	int i, flag = 0, is_k = 0;
	current = head;
	
	if(n % 2 == 0) // Next
	{
		while(1)
		{
			if(current->data == k)
			{
				is_k = 1;
				while(current->Next != current)
				{
					if(flag == 0)
					{
						i = 0;
						flag = 1;
					}
					else
						i = 1;
					
					while(i <= n)
					{
						saved_found = current;
						current = current->Next;
						
						i++;
					}
					
					current = saved_found->Next;
					delete(&head, saved_found);
				}
				
				break;
			}
			current = current->Next;
			if(is_k == 0 && current == head)
				break;
		}
	}
	else // Previous
	{
		while(1)
		{
			if(current->data == k)
			{
				is_k = 1;
				while(current->Previous != current)
				{
					if(flag == 0)
					{
						i = 0;
						flag = 1;
					}
					else
						i = 1;
					
					while(i <= n)
					{
						saved_found = current;
						current = current->Previous;
						
						i++;
					}
					
					current = saved_found->Previous;
					delete(&head, saved_found);
				}
				break;
			}
			current = current->Previous;
			if(is_k == 0 && current == head)
				break;
		}
	}
	
	if(is_k == 0)
	{
		printf("not found");
		return 0;
	}
	
	second_print(head);
	
	free_memory(head);
	
	return 0;
}
