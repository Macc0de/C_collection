struct List* func(int data)
{ 
	struct List *cur, *cur_next;
	
	if(First == NULL) // Если список пуст
		return First;
	
	int flag = 0;
	if(First->Value == data)
		flag = 1; // Элемент встретили
	
	if(First != NULL)
	{
		cur = First;
		while(cur->Next != NULL) // Если не первый
		{
			cur_next = cur->Next;
			if(cur_next->Value == data)
			{	
				if(flag == 1)
					cur->Next = cur_next->Next;
				else // Этот элемент пропускаем
				{
					flag = 1;
					cur = cur->Next;
				}
			}
			else
				cur = cur->Next;
		}
	}
	
	return First;
}
