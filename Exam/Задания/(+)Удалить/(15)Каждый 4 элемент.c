struct List* func()
{	
	struct List *cur, *cur_next;
	int i;

	if (First == NULL) // First->Next->Next->Next == NULL
		return First;

	i = 1;
	cur = First;
	while (cur != NULL)
	{
		if((i + 1) % 4 == 0)
		{
			cur_next = cur->Next;
			if(cur_next != NULL)
				cur->Next = cur_next->Next; // Удаление
			i = 0;
		}
		
		i++;
		cur = cur->Next;
	}
	
	return First;
}
