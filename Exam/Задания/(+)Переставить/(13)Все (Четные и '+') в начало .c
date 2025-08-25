// Число является четным и положительным
struct List* func()
{	
	struct List *cur, *cur_next;

	if (First == NULL || First->Next == NULL) 
		return First;

	cur = First;
	while (cur->Next != NULL)
	{
		cur_next = cur->Next;
		if (cur_next->Value > 0 && cur_next->Value % 2 == 0)
		{
			cur->Next = cur_next->Next; // Удаление
			
			cur_next->Next = First;
			First = cur_next; // Новая голова
		}
		else
			cur = cur->Next;
	}

	return First;
}
