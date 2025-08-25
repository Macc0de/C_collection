struct List* func()
{	
	// Second - второй список, не глобальный - голову возвращаем на 2й список
	struct List *Second = NULL, *cur, *cur_next, *last;
	int i;
	
	if (First == NULL) // Первый список, проверка
		return Second;

	i = 1;
	while (First != NULL)  // Голова 
	{
		if (First->Value > i)
		{
			if (Second == NULL) // Если второй список пуст
			{
				Second = First; // Second - второй список
				First = First->Next;
				
				last = Second; // Добавленный элемент - последний
				last->Next = NULL;
				
				i++;
			}
			else // Если второй список не пуст
			{
				last->Next = First; // Добавляем во второй список
				
				last = First; // Последний элемент во втором списке
				First = First->Next;
				last->Next = NULL;
				
				i++;
			}
		}
		else 
			break;
	}
	
	if(First == NULL) // Если первый список стал пустым
		return Second; // Возвращаем второй список
	
	cur = First;
	while (cur->Next != NULL) // Все остальные
	{
		cur_next = cur->Next;
		i++;
		if (cur_next->Value > i) // cur_next - нужный элемент
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
	
	return Second;
}
