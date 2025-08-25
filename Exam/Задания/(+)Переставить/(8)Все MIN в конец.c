struct List* func()
{	
	struct List *cur, *cur_next, *last, *p_last;
	int min;

	if (First == NULL || First->Next == NULL) 
		return First;
	
	// Поиск минимального значения
	min = First->Value;
	for (cur = First->Next; cur != NULL; cur = cur->Next)
	{
		if (cur->Value < min) 
			min = cur->Value;
		
		if (cur->Next == NULL) // Последний элемент
			p_last = last = cur;
	}

	while (First != last) // Проверка головы
	{
		if (First->Value == min)
		{
			p_last->Next = First; // В конец
			First = First->Next; // Новая голова
			
			p_last = p_last->Next; // Новый последний элемент
			p_last->Next = NULL;
		}
		else
			break;
	}
	
	if (First != last) // Если голова - не последний элемент
	{
		cur = First;
		while (cur->Next != last) // Пока не дошли до последнего элемента
		{
			cur_next = cur->Next;
			if (cur_next->Value == min) // Если cur_next - минимальный
			{
				cur->Next = cur_next->Next; // Удаление
				p_last->Next = cur_next;
				
				p_last = cur_next; // Новый последний элемент
				p_last->Next = NULL;
			}
			else  
				cur = cur->Next;
		}
	}

	return First;
}
