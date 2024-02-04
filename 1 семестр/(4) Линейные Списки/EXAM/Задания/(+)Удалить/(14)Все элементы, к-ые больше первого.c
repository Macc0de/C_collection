struct List* func()
{	
	struct List *cur, *cur_next;

	if (First == NULL || First->Next == NULL) 
		return First;

	cur = First;
	while (cur->Next != NULL) // Пропускаем голову
	{
		cur_next = cur->Next;
		if (cur_next->Value > First->Value)
			cur->Next = cur_next->Next;
		else 
			cur = cur_next;
	}

	return First;
}
