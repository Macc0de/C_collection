struct List* func()
{
	struct List* one, *cur;
	int flag = 0;
	
	if(First == NULL)
		return First;
	
	if(First->Value % 2 == 0) // Голова
	{
		one = malloc(sizeof(struct List));
		one->Next = First;
		one->Value = 1;
		
		First = one; // Новая голова
		flag = 1;
		
		one = NULL;
	}
	
	cur = First;
	if(flag == 1) // Чтобы не ставить вторую единицу перед первым четным
		cur = cur->Next;
	
	while(cur) // Все остальные
	{
		if(cur->Next && cur->Next->Value % 2 == 0)
		{
			one = malloc(sizeof(struct List));
			one->Next = cur->Next;
			cur->Next = one;
			one->Value = 1;
			
			one = NULL;
			
			cur = cur->Next->Next;
			continue;
		}
		
		cur = cur->Next;
	}
	
	return First;
}
