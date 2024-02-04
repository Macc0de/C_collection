struct List* func()
{	
	struct List *cur, *cur_next;
	int min;
	
	if (First == NULL || First->Next == NULL) 
		return First;

	min = First->Value;
	for (cur = First->Next; cur != NULL; cur = cur->Next) // Голову пропускаем
		if (cur->Value < min) 
			min = cur->Value; // Минимальный

	if (First->Value == min) // Если первый
	{
		cur = First->Next; // Для препода
		First->Next = cur->Next; // Удаление
	}
	else // Все остальные
	{
		for (cur = First; cur->Next != NULL; cur = cur->Next)
		{
			cur_next = cur->Next; // MIN
			if (cur_next->Value == min && cur_next->Next != NULL) // + Есть ли элемент после MIN
			{
				cur = cur_next->Next; // Элемент после MIN
				cur_next->Next = cur->Next; // Удаление
				break;
			}
		}
	}

	return First;
}
