struct List* func()
{	
	struct List *cur, *cur_next, *last;
	int min;

	if (First == NULL || First->Next == NULL) 
		return First;

	// Поиск минимального значения
	min = First->Value;
	for (cur = First->Next; cur != NULL; cur = cur->Next) // Голову пропускаем
	{
		if (cur->Value < min) 
			min = cur->Value;
		
		if (cur->Next == NULL) // Последний элемент
			last = cur;
	}
	
	if (First->Value == min) // Если первый
	{
		last->Next = First; // В конец
		First = First->Next; // Новая голова
		
		last = last->Next; // Новый последний элемент
		last->Next = NULL;
	}
	else // Если не первый
	{
		cur = First;
		while (cur->Next != last) // Пока не дошли до последнего элемента
		{
			cur_next = cur->Next;
			if (cur_next->Value == min) // Если cur_next - минимальный
			{
				cur->Next = cur_next->Next; // Удаление
				last->Next = cur_next;
				
				last = cur_next; // Новый последний элемент
				last->Next = NULL;
				break;
			}
			else  
				cur = cur->Next;
		}
	}

	return First;
}
