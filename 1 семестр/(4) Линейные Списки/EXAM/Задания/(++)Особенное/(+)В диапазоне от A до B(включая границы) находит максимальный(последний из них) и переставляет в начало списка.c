// Если их несколько, то последний из них
// Если первый из них, то: if(cur->Value > max && cur->Value >= a && cur->Value <= b)
struct List* func(int a, int b)
{
	struct List* cur, *cur_next, *max_last;
	
	if(First == NULL || First->Next == NULL) 
		return First;
	
	// Поиск максимального элемента, к-ый входит в диапазон
	int max = First->Value;
	for(cur = First->Next; cur != NULL; cur = cur->Next) // First пропускаем
	{
		if(cur->Value >= max && cur->Value >= a && cur->Value <= b) // Первый из макс. - (> max)
		{
			max = cur->Value;
			max_last = cur;
		}
	}
	
	if(First == max_last) // Если стоит уже в начале
		return First;
	
	cur = First;
	while(cur->Next != NULL)
	{
		cur_next = cur->Next;
		if(cur_next == max_last)
		{
			cur->Next = cur_next->Next; // Удаление
			
			max_last->Next = First; // В начало
			First = max_last;
			break;
		}
		else
			cur = cur->Next;
	}
	
	return First;
}
