struct List* func()
{
	struct List* cur, *Third = NULL, *last1, *last2;
	int sum1 = 0, sum2 = 0;
	
	if(FirstA == NULL || FirstB == NULL)
		return FirstA;
	
	// Подсчет суммы
	cur = FirstA;
	while(cur != NULL)
	{
		if(cur->Next == NULL)
			last1 = cur;
		
		sum1 += cur->Value;
		cur = cur->Next;
	}
	cur = FirstB;
	while(cur != NULL)
	{
		if(cur->Next == NULL)
			last2 = cur;
		
		sum2 += cur->Value;
		cur = cur->Next;
	}

	if(sum1 >= sum2) // Если кол-во равно
	{
		last1->Next = FirstB;
		return FirstA;
	}
	else if(sum1 < sum2)
	{
		last2->Next = FirstA;
		return FirstB;
	}
}
