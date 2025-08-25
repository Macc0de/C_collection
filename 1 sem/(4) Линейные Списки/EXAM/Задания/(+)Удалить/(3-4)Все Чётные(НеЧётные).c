struct List* func()
{ 
	struct List *cur, *cur_next;
	
	if(First == NULL) // Если список пуст
		return First;
	
	// (2) Реализация
	while(First != NULL) // Если первый 
	{
		cur = First; // Для препода
		if(First->Value % 2 == 0) // != 0
			First = First->Next;
		else
			break;
	}
	
	if(First != NULL) // Все остальные
	{
		cur = First;
		while(cur->Next != NULL)
		{
			cur_next = cur->Next;
			if(cur_next->Value % 2 == 0) // != 0
				cur->Next = cur_next->Next;
			else
				cur = cur->Next;
		}
	}
	
	return First;
}
