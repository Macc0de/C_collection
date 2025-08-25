struct List* func()
{	
	struct List *cur, *cur_next, *elem;
	int min;
	
	if (First == NULL || First->Next == NULL) 
		return First;

	min = First->Value;
	for (cur = First->Next; cur != NULL; cur = cur->Next) // Голову пропускаем
		if (cur->Value < min) 
			min = cur->Value; // Минимальный
	
	cur = First->Next;
	if(cur->Value == min) // Если первый MIN
	{
		cur = First; // Для препода
		First = First->Next;
	}
	else // Все остальные
	{
		cur = First;
		cur_next = First->Next;
		while(cur_next->Next != NULL)
		{
			elem = cur_next->Next; // MIN
			if (elem->Value == min)
			{
				cur->Next = cur_next->Next; // cur_next - элемент перед MIN
				break;
			}
			else
			{ // Итерации
				cur = cur_next;
				cur_next = elem;
			}
		}
	}

	return First;
}
