#ifndef _PRINTER_ 
#define _PRINTER_
struct List
{
	int data;
	struct List* Next;
};

void Print(struct List* First)
{
	struct List* current = First;
	while(current)
	{
		printf("%d ", current->data);
		current = current->Next;
	}
}
#endif
