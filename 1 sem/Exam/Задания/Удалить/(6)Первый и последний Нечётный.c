struct List* func()
{
	struct List *cur, *cur_next, *odd = NULL;
	
	if(First == NULL || First->Next == NULL)
		return First;
	
	// Поиск первого нечетного
	if(First->Value % 2 != 0) // Если первый
	{
		cur = First; // Для препода
		First = First->Next;
	}	
	else // Если не первый
	{
		cur = First;
		while(cur->Next != NULL)
		{
			cur_next = cur->Next;
			if(cur_next->Value % 2 != 0)
			{
				cur->Next = cur_next->Next;
				break;
			}
			else
				cur = cur->Next;
		}
	}
	
	// (Поиск) последнего нечетного
	cur = First; // Случай - {1,3,4}
	while(cur != NULL) // Все остальные
	{
		if(cur->Value % 2 == 0)
			cur = cur->Next;
		else // Нечетный
		{
			odd = cur;
			cur = cur->Next;
		}
	}
	
	if(odd != NULL) // (Удаление) последнего нечетного элемента
	{
		if(odd == First) // Если первый(голова могла поменяться)
			First = First->Next;
		else
		{
			cur = First;
			while(cur->Next != NULL) // Если не первый
			{
				if(cur->Next == odd)
					cur->Next = odd->Next; // Удаление
				else
					cur = cur->Next;
			}
		}
	}
	
	return First;
}
