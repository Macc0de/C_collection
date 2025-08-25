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
		
	if(First->Value == max) // Если первый
	{
		cur = First; // Для препода
		First = First->Next;
	}
	else // Если не первый
	{
		for(cur = First; cur->Next != NULL; cur = cur->Next)
		{
			cur_next = cur->Next;
			if(cur_next->Value == max)
			{
				cur->Next = cur_next->Next; // Удаление
				break;
			}
		}
	}
	
	return First;
}
