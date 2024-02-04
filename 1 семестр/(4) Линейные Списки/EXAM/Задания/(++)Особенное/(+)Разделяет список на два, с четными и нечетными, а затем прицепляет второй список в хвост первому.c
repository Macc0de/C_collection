// (+)Разделяет список на два, с четными и нечетными, а затем прицепляет второй список в хвост первому
struct List* func()
{
	// Первый список(Четные), Второй список(Нечетные)
	struct List* cur, *cur_next, *last, *Second = NULL;
	
	if(First == NULL)
		return First;
	
	while(First != NULL)
	{
		if(First->Value % 2 != 0) // Если первый
		{
			if (Second == NULL) // Second - второй список
			{
				Second = First;
				First = First->Next;
				
				last = Second; // Добавленный элемент - последний
				last->Next = NULL;
			}
			else // Если второй список не пуст
			{
				last->Next = First; // Добавляем во второй список
				
				last = First; // Последний элемент во втором списке
				First = First->Next;
				last->Next = NULL;
			}
		}
		else
			break;
	}
	
	if(First == NULL) // Если первый список стал пустым
	{
		First = Second;
		return First;
	}
	
	cur = First;
	while (cur->Next != NULL) // Все остальные
	{
		cur_next = cur->Next;
		if (cur_next->Value % 2 != 0) // cur_next - нужный элемент
		{
			if (Second == NULL)
			{
				cur->Next = cur_next->Next; // Удаление
				
				Second = cur_next; // Новая голова второго списка
				last = cur_next;
				last->Next = NULL;
			}
			else
			{
				cur->Next = cur_next->Next; // Удаление
				
				last->Next = cur_next;
				last = cur_next; // Последний элемент во втором списке
				last->Next = NULL;
			}
		}
		else
			cur = cur->Next;
	}
	
	cur = First;
	while(cur != NULL) // Поиск последнего элемента первого списка
	{
		if(cur->Next == NULL)
			last = cur;
		cur = cur->Next;
	}
	
	// Склеивание списков
	last->Next = Second;

	return First;
}
