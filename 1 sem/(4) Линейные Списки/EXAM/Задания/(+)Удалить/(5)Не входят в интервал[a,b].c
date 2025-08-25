struct List* func(int a, int b)
{ 
	struct List *cur, *cur_next;	
	
	if(First == NULL || First->Next == NULL) 
		return First;
	
	while(First != NULL)
	{
		cur = First; // Для препода
		if(First->Value < a || First->Value > b)
			First = First->Next;
		else
			break;
	}
	
	if(First != NULL)
	{
		cur = First;
		while(cur->Next != NULL)
		{
			cur_next = cur->Next;
			if(cur_next->Value < a || cur_next->Value > b)
			{
				cur->Next = cur_next->Next; // Удаление
			}
			else
				cur = cur->Next;
		}
	}
	
	return First;
}
