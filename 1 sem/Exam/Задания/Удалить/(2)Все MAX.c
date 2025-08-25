struct List* func()
{ 
	struct List *cur, *cur_next;
	int max;
	
	if(First == NULL) // Если список пуст
		return First;
	
	// Поиск максимального элемента
	max = First->Value;
	for(cur = First->Next; cur != NULL; cur = cur->Next) // First пропускаем
		if(cur->Value > max) 
			max = cur->Value;
	
	while(First != NULL) // Проверка First
	{
		cur = First; // Для препода
		if(First->Value == max) // Если первый
			First = First->Next;
		else
			break;
	}
	
	if(First != NULL) // Если First существует
	{
		cur = First;
		while(cur->Next != NULL) // Если не первый
		{
			cur_next = cur->Next;
			if(cur_next->Value == max)
				cur->Next = cur_next->Next; // Удаление
			else
				cur = cur->Next;
		}
	}
	
	return First;
}
