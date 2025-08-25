struct List* func()
{	
	struct List *cur, *cur_next;
	int sum = 0, count = 0;
	float avg_num = 0.0;

	if (First == NULL || First->Next == NULL) 
		return First;

	// Подсчёт суммы и кол-ва элементов
	for (cur = First; cur != NULL; cur = cur->Next)
	{
		sum += cur->Value;
		count++;
	}

	avg_num = sum / count;
	cur = First;
	while (cur->Next != NULL)
	{
		cur_next = cur->Next;
		if (cur_next->Value < avg_num)
		{
			cur->Next = cur_next->Next; // Удаление
			
			cur_next->Next = First;
			First = cur_next; // Новая голова
		}
		else
			cur = cur->Next;
	}

	return First;
}
