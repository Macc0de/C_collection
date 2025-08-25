int func()
{
	struct List* cur;
	int cur_len = 1, max_len = 0;
	
	if(First == NULL)
		return max_len;
	
	cur = First;
	while(cur != NULL && cur->Next != NULL)
	{
		if((cur->Value >= 0 && cur->Next->Value >= 0) || (cur->Value < 0 && cur->Next->Value < 0))
		{
			cur_len++;
		}
		else
		{
			if(cur_len > max_len)
			{
				max_len = cur_len;
			}
			cur_len = 1; // Сброс
		}
		
		cur = cur->Next;
	}
	
	if(cur_len > max_len) // Последняя цепочка
		max_len = cur_len;
	
	return max_len;
}
