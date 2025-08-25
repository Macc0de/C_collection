struct List* func()
{	
	struct List *cur, *cur_next, *last, *p_last;
	
	if (First == NULL || First->Next == NULL) 
		return First;
	
	for (cur = First->Next; cur != NULL; cur = cur->Next)
	{
		if (cur->Next == NULL) // Последний
			last = cur;
	}

	p_last = last;
	while (First != last) // Проверка головы
	{
		if (First->Value > 0)
		{
			cur = First;
			First = First->Next; // Новая голова
			
			p_last->Next = cur;
			p_last = cur; // Новый последний
			cur->Next = NULL;
		}
		else 
			break;
	}

	if (First != last)
	{
		cur = First;
		while (cur->Next != last) // Проверка остальных
		{
			cur_next = cur->Next;
			if (cur_next->Value > 0)
			{
				cur->Next = cur_next->Next; // Удаление
				
				p_last->Next = cur_next;
				p_last = cur_next; // Новый последний
				cur_next->Next = NULL;
			}
			else
				cur = cur->Next;
		}
	}

	return First;
}
