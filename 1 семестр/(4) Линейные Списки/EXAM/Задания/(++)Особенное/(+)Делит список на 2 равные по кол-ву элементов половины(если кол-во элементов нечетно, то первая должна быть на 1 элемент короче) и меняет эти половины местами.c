struct List* func()
{
	struct List* cur, *cur_next, *mid_elem, *last;
	int count, mid_count;
	
	if(First == NULL || First->Next == NULL) 
		return First;
	
	count = 0;
	cur = First;
	while(cur != NULL) // Подсчет кол-ва элементов
	{
		count++;
		cur = cur->Next;
	}
	mid_count = count / 2;
	
	count = 1;
	cur = First;
	while(cur != NULL)
	{
		if(count == mid_count)
			mid_elem = cur;
		if(cur->Next == NULL) // Последний элем.
			last = cur;
			
		count++;
		cur = cur->Next;
	}
	
	last->Next = First; // Склеивание
	First = mid_elem->Next; // Новая голова
	mid_elem->Next = NULL; // Новый последний
	
	return First;
}
